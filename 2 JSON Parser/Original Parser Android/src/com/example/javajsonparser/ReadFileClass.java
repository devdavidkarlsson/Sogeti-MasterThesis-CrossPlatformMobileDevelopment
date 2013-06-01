//ReadFileClass.java
package com.example.javajsonparser;

import com.google.gson.stream.JsonReader;
import java.io.BufferedInputStream;
import java.io.InputStream; 
import java.io.InputStreamReader;
import android.content.Context;


public class ReadFileClass{
	//Read file: 

	public static RefListType readJsonFile(Context context){ //Innan InputStream som output
		JsonReader reader = null;

		try{ 			
			InputStream inStream = context.getResources().openRawResource(R.raw.se_sv_capitals); 
			BufferedInputStream bufferedStream = new BufferedInputStream(
					inStream);
			InputStreamReader streamReader = new InputStreamReader(
					bufferedStream);
			reader = new JsonReader(streamReader);
			RefListType ref= new RefListType(reader);
			return ref;
		}catch(Exception e){ 
			System.out.println("Could not read/parse Json-file..");
		}
		return null;


	}


}
