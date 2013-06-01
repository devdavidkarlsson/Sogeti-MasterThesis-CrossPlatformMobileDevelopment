//MainActivity.java
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
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;

public class MainActivity extends Activity {
	
	static
	{
	System.loadLibrary("JsonPoco");
	}
	
	public native void json_parse(String str);
	private ArrayList<RefWrapper> list;
	private ListView mainListView ;
	private ArrayAdapter<RefWrapper> listAdapter ;
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
	    mainListView = (ListView) findViewById(R.id.mainListView);

		
		
		Debug.startMethodTracing("jsonjavanc_profiling");
		json_parse("null");
		Debug.stopMethodTracing();
	    listAdapter = new ArrayAdapter<RefWrapper>(this, R.layout.simplerow, this.list);
	    mainListView.setAdapter( listAdapter ); 
	    mainListView.setOnItemClickListener(new OnItemClickListener (){

			@Override
			public void onItemClick(AdapterView<?> arg0, View arg1, int row,
					long arg3) {
				AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this).create();
				alertDialog.setTitle(list.get(row).mNo + " " + list.get(row).toString());
				alertDialog.setMessage("Latitude: " + list.get(row).mLatitude + "\n Longitude: "+ list.get(row).mLongitude);
				alertDialog.show();
			}});
	    System.out.println(Debug.getNativeHeapAllocatedSize() / 1049L);
	}
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	
	public void add(String no, String name,String url, double lat, double lon){
		if(this.list==null){
			this.list = new ArrayList<RefWrapper>();
		}
		this.list.add(new RefWrapper(no, name, url, lat, lon));
		
	}


}
