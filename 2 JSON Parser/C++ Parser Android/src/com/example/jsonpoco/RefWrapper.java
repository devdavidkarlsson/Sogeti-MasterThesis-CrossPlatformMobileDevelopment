//RefWrapper.java
package com.example.jsonpoco;

public class RefWrapper {
	String mNo;
	String mName;
	String mUrl;
	double mLongitude;
	double mLatitude;

	RefWrapper(String no, String name,String url, double lat, double lon){
		this.mNo = no;
		this.mName = name;
		this.mUrl = url;
		this.mLongitude = lon;
		this.mLatitude = lat;
	}
	
	public String toString(){
		return mName;
	}

}
