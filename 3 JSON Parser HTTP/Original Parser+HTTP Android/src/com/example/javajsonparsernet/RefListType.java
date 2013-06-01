//RefListType.java
package com.example.javajsonparsernet;

import java.io.IOException;
import java.util.ArrayList;
import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonToken;

public class RefListType {
	private static final String REF = "Ref";

	private ArrayList<RefType> refs;

	public RefListType() {
	}

	public RefListType(final JsonReader reader) throws IOException {
		deserialize(reader);
	}

	public ArrayList<RefType> getRefs() {
		if (refs == null) {
			refs = new ArrayList<RefType>();
		}
		return refs;
	}

	public void deserialize(final JsonReader reader) throws IOException {
		
		reader.beginObject();
		while (reader.hasNext()) {
			if(reader.peek() == JsonToken.NAME){
				String nameL = reader.nextName();

						if (REF.equalsIgnoreCase(nameL)) {
							if (reader.peek() == JsonToken.BEGIN_ARRAY) {
								reader.beginArray();
								while (reader.hasNext()) {
									RefType ref = new RefType(reader);
									getRefs().add(ref);
								}
								reader.endArray();
							} else {
								RefType ref = new RefType(reader);
								getRefs().add(ref);
							}
						}
					} else {
						reader.skipValue();
					}

	}
}

}