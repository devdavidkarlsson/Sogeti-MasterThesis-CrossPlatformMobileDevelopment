//MainActivity.java
package com.example.prototype1android;

import android.app.Activity;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends Activity {
	
	static{
	System.loadLibrary("Prototype1Android");
	}
	
	public native static String transform(String input); //added static
	public static String javaTransform(String input){return JavaTransform.transform(input);}
	
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		//String s = transform("ABC");
		//System.out.println(s);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}
	
	public void actionGo(View v) {
		TextView txtOutput = (TextView) findViewById(R.id.txtOutput);
        EditText txtInput = (EditText) findViewById(R.id.txtInput);
        txtOutput.setText(transform(txtInput.getText().toString()));
        //txtOutput.setText(String.format("%d",transform((long)42)));
	}
	
	
	
}
