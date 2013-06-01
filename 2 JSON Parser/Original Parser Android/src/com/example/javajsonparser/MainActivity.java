//MainActivity.java
package com.example.javajsonparser;

import java.util.ArrayList;

import android.os.Bundle;
import android.os.Debug;
import android.app.Activity;
import android.app.AlertDialog;
import android.view.Menu;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.content.Context;



public class MainActivity extends Activity {
	private static Context context; 
	private ArrayAdapter<RefType> listAdapter;
	private ArrayList<RefType> list;
	ListView mainListView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		MainActivity.context = getApplicationContext();
			for(int i = 0 ; i<99; i++){
				ReadFileClass.readJsonFile(context);
			}
			list = ReadFileClass.readJsonFile(context).getRefs();
			mainListView = (ListView) findViewById( R.id.mainListView );  
		    listAdapter = new ArrayAdapter<RefType>(this, R.layout.simplerow, list);   
		    mainListView.setAdapter(listAdapter);	        
		    mainListView.setOnItemClickListener(new OnItemClickListener (){

				@Override
				public void onItemClick(AdapterView<?> arg0, View arg1,
						int row, long arg3) {
					AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this).create();
					alertDialog.setTitle(list.get(row).getNo() + " " + list.get(row).toString());
					alertDialog.setMessage("Latitude: " + list.get(row).getLocation().getLatitude() +"\n" +"Longitude: "+ list.get(row).getLocation().getLongitude());
					alertDialog.show();			
				}
		    });
		    System.out.println(Debug.getNativeHeapAllocatedSize() / 1049L);

	}
	
	

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
