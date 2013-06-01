//GetOperation.java

package com.example.javajsonparsernet;
 
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;


import com.google.gson.stream.JsonReader;
import com.google.gson.stream.JsonToken;
import com.sogeti.droidnetworking.NetworkEngine.HttpMethod;
import com.sogeti.droidnetworking.NetworkOperation;

public class GetOperation extends NetworkOperation {
    public interface GetOperationListener {
        void onCompletion(final RefListType refList);
        void onError(final IOException exception);
    }

    private RefListType refList;
    private IOException exception;

    public GetOperation() {
        this(null);
    }

    public GetOperation(final GetOperationListener listener) {
        super();
        

        setUrlString("http://users.student.lth.se/et08dc0/exjobbjail/se_sv_capitals.json");

        setHttpMethod(HttpMethod.GET);


        
        refList = new RefListType();
        setParser(new ResponseParser() {
            @Override
            public void parse(final InputStream is, final long size) throws IOException {
                try {
                	InputStreamReader isr = new InputStreamReader(is);
                    JsonReader reader = new JsonReader(isr);
                    reader.beginObject();
                    while (reader.hasNext()) {
                        if (reader.peek() == JsonToken.NAME) {
                            String name = reader.nextName();

                            if (name.equalsIgnoreCase("RefList")) {
                                refList.deserialize(reader);
                            }
                        } else {
                            reader.skipValue();
                        }
                    }

                    reader.endObject();
                    reader.close();

                } catch (IOException e) {
                	//Parse error
                	System.out.println(e.getMessage());
                } catch (IllegalArgumentException e) {
                	System.out.println(e.getMessage());
                    // This Exception occurs when aString To Enum conversion fails .
                }
            }
        });

        if (listener != null) {
            setListener(new OperationListener() {
                @Override
                public void onCompletion(final NetworkOperation operation) {
                    if (exception == null) {
                        listener.onCompletion(refList);
                    } else {
                        listener.onError(exception);
                    }
                }

                @Override
                public void onError(final NetworkOperation operation) {
                    listener.onError(new IOException());
                }
            });
        }
    }

}
