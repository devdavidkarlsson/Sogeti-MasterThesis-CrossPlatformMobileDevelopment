package com.example.jsonpoco;

import java.io.InputStream;
import java.util.ArrayList;
import android.os.Bundle;
import android.os.Debug;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.res.Resources;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	static
	{
	System.loadLibrary("JsonPoco"); 
	}
	
	public native long json_create(String str);
	public native boolean json_parse(long pointer);
	public native void json_store(long pointer);
	public native void json_flush(long pointer);
	public native void json_destroy(long pointer);
	
	private ArrayList<RefWrapper> list;
	private ListView mainListView ;
	private ArrayAdapter<RefWrapper> listAdapter ;
	private long pointerToNetHelper;
	private boolean usingCached;
	
	@Override
	protected void onDestroy(){
		json_destroy(pointerToNetHelper);
		super.onDestroy();

	}
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	    mainListView = (ListView) findViewById( R.id.mainListView );

		
		
		Debug.startMethodTracing("jsonjavanc_profiling");
		pointerToNetHelper = json_create(getApplicationContext().getFilesDir().getAbsolutePath());
		usingCached = json_parse(pointerToNetHelper);
		if(usingCached){ 
			setTitle("Using Cached");
		}else{
			setTitle("Using HTTP");
		}
		Debug.stopMethodTracing();
		listAdapter = new ArrayAdapter<RefWrapper>(this, R.layout.simplerow, this.list);
		mainListView.setAdapter( listAdapter ); 
	    mainListView.setOnItemClickListener(new OnItemClickListener (){

			@Override
			public void onItemClick(AdapterView<?> arg0, View arg1, int row,
					long arg3) {
				AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this).create();
				alertDialog.setTitle(list.get(row).mNo + " " + list.get(row).toString());
				alertDialog.setMessage("Latitude:" + list.get(row).mLatitude + " Longitude:"+ list.get(row).mLongitude);
				alertDialog.show();
				TextView textView = (TextView) alertDialog.findViewById(android.R.id.message);
			    textView.setTextSize(14);
				
			}});
	    System.out.println(Debug.getNativeHeapAllocatedSize() / 1049L);
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	  @Override
	    public boolean onOptionsItemSelected(MenuItem item) {
	 
	        super.onOptionsItemSelected(item);
	 
	        switch(item.getItemId()){
	            case R.id.action_refresh:
	                Toast.makeText(getBaseContext(), "Refresh", Toast.LENGTH_SHORT).show();
	                list.clear();
	                usingCached = json_parse(pointerToNetHelper);
	            	if(usingCached){ 
	        			setTitle("Using Cached");
	        		}else{
	        			setTitle("Using HTTP");
	        		}
	            	
	                listAdapter.notifyDataSetChanged();
	                break;
	 
	            case R.id.action_save:
	                Toast.makeText(getBaseContext(), "Save", Toast.LENGTH_SHORT).show();
	                json_store(pointerToNetHelper);
	                break;
	 
	            case R.id.action_flush:
	                Toast.makeText(getBaseContext(), "Flush", Toast.LENGTH_SHORT).show();
	                json_flush(pointerToNetHelper);	            
	                list.clear();
	                setTitle("Empty");
	                listAdapter.notifyDataSetChanged();
	                break;
	 

	 
	        }
	        return true;
	 
	    }
	
	public static String readJsonFile(Context context){
		String jsonTest; 
		try{ 
			Resources res = context.getResources();
			InputStream is = res.openRawResource(R.raw.se_sv_capitals); //	
			//BufferedReader reader = new BufferedReader(new InputStreamReader(is));
			byte[] buffer = new byte[is.available()];
			is.read(buffer);
			jsonTest= new String(buffer);
			//System.out.println(jsonTest);
			return jsonTest; 
		}
		catch(Exception e){
			jsonTest= ""; 
			System.out.println("Nothing read!");
			return null;
		}
	}
	
	public void add(String no, String name,String url, double lat, double lon){
		if(this.list==null){
			this.list = new ArrayList<RefWrapper>();
		}
		this.list.add(new RefWrapper(no, name, url, lat, lon));
		
	}
	

	
	

}
