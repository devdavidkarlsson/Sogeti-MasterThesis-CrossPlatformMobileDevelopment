//RefType.java
package com.example.javajsonparser;

import java.io.IOException;
import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonToken;

public class RefType {
    private static final String NUMBER = "No";
    private static final String NAME = "Name";
    private static final String URL = "Url";
    private static final String LOCATION = "Location";

    private String mNo;
    private String mName;
    private String mUrl;
    private LocationType mLocation;

    public RefType() {
    }

    public RefType(final JsonReader reader) throws IOException {
        deserialize(reader);
    }

    public String getNo() {
        return mNo;
    }

    public void setNo(final String No) {
        this.mNo = No;
    }

    public String getName() {
        return mName;
    }

    public void setName(final String name) {
        this.mName = name;
    }

    public String getUrl() {
        return mUrl;
    }

    public void setUrl(final String url) {
        this.mUrl = url;
    }

    public LocationType getLocation() {
        return mLocation;
    }

    public void setLocation(final LocationType location) {
        this.mLocation = location;
    }

    public void deserialize(final JsonReader reader) throws IOException {
        reader.beginObject();

        while (reader.hasNext()) {
            if (reader.peek() == JsonToken.NAME) {
                String name = reader.nextName();

                if (NAME.equalsIgnoreCase(name)) {
                    reader.beginObject();
                    reader.nextName();
                    this.mName = reader.nextString();
                    reader.endObject();
                }

                if (NUMBER.equalsIgnoreCase(name)) {
                    reader.beginObject();
                    reader.nextName();
                    this.mNo = reader.nextString();
                    reader.endObject();
                }

                if (URL.equalsIgnoreCase(name)) {
                    reader.beginObject();
                    reader.nextName();
                    this.mUrl = reader.nextString();
                    reader.endObject();
                }

                if (LOCATION.equalsIgnoreCase(name)) {
                    this.mLocation = new LocationType(reader);
                }
            } else {
                reader.skipValue();
            }
        }
        reader.endObject();
    }
    
    public String toString(){
    	return this.mName;
    }
}
