//MainActivity.java
package com.example.javajsonparsernet;

import java.io.IOException;
import java.util.ArrayList;

import com.example.javajsonparsernet.R;
import com.example.javajsonparsernet.GetOperation.GetOperationListener;
import com.sogeti.droidnetworking.NetworkEngine;

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

public class MainActivity extends Activity {
	private ArrayAdapter<RefType> listAdapter;
	private ArrayList<RefType> list;
	ListView mainListView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		list = new ArrayList<RefType>();
		mainListView = (ListView) findViewById(R.id.mainListView);
		listAdapter = new ArrayAdapter<RefType>(this, R.layout.simplerow, list);   
	    mainListView.setAdapter(listAdapter);
		
		NetworkEngine.getInstance().init(this);

		try{
			GetOperation op = new GetOperation(new GetOperationListener(){
		        @Override
				public void onCompletion(final RefListType refList) {
		        	list.clear();
		        	list.addAll(refList.getRefs());
		        	listAdapter.notifyDataSetChanged();
		        	System.out.println(Debug.getNativeHeapAllocatedSize() / 1049L);
				}

				@Override
				public void onError(IOException exception) {
					System.out.println("An IOException was thrown");
				}
			}); 

			NetworkEngine.getInstance().enqueueOperation(op); 
			
		}catch(Exception e){
			System.out.println("Error somewhere during the call of NetworkEngine.getInstance().executeOperation(op), exception message: " + e.getMessage());
			e.printStackTrace(System.out);
			}
			 	        
		    mainListView.setOnItemClickListener(new OnItemClickListener (){

				@Override
				public void onItemClick(AdapterView<?> arg0, View arg1,
						int row, long arg3) {
					AlertDialog alertDialog = new AlertDialog.Builder(MainActivity.this).create();
					alertDialog.setTitle(list.get(row).getNo() + " " + list.get(row).toString());
					alertDialog.setMessage("Latitude: " + list.get(row).getLocation().getLatitude() + "\n Longitude: "+ list.get(row).getLocation().getLongitude());
					alertDialog.show();			
				}
		    });
		
	}
		
	
	

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

}
