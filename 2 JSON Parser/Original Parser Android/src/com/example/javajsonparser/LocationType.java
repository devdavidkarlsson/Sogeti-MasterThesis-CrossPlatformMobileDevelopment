//LocationType.java
package com.example.javajsonparser;

import java.io.IOException;
import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonToken;

public class LocationType {
    private static final String LATITUDE = "Latitude";
    private static final String LONGITUDE = "Longitude";

    private double longitude;
    private double latitude;

    public LocationType() {
    }

    public LocationType(final JsonReader reader) throws IOException {
        deserialize(reader);
    }

    public double getLongitude() {
        return longitude;
    }

    public void setLongitude(final double longitude) {
        this.longitude = longitude;
    }

    public double getLatitude() {
        return latitude;
    }

    public void setLatitude(final double latitude) {
        this.latitude = latitude;
    }

    public void deserialize(final JsonReader reader) throws IOException {
        reader.beginObject();

        while (reader.hasNext()) {
            if (reader.peek() == JsonToken.NAME) {
                String name = reader.nextName();

                if (LATITUDE.equalsIgnoreCase(name)) {
                    reader.beginObject();
                    reader.nextName();
                    this.latitude = reader.nextDouble();
                    reader.endObject();
                }

                if (LONGITUDE.equalsIgnoreCase(name)) {
                    reader.beginObject();
                    reader.nextName();
                    this.longitude = reader.nextDouble();
                    reader.endObject();
                }
            } else {
                reader.skipValue();
            }
        }
        reader.endObject();
    }
}
