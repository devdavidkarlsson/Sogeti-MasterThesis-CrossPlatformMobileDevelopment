//NetPoco.cpp
#include "NetPoco.h"


RefListType* NetPoco::getRefListType(){

	try
	  {
	    // prepare http-session
        URI uri("http://users.student.lth.se/et08dc0/exjobbjail/se_sv_capitals.json");
	    HTTPClientSession session(uri.getHost(), uri.getPort());

	    // prepare path
	    string path(uri.getPathAndQuery());
	    if (path.empty()) path = "/";

	    // send request
	    HTTPRequest req(HTTPRequest::HTTP_GET, path, HTTPMessage::HTTP_1_0);
        //If headers are needed set them here : req.set("KEY", "VALUE");

          
	    session.sendRequest(req);

	    // get response
	    HTTPResponse res;
        istream &is = session.receiveResponse(res);
          
          
        // consume response
        if (is) {
            return  new RefListType(is);
        }
          
	  }
	  catch (Exception &ex)
	  {
	    cerr << ex.displayText() << endl;
	  }

	}

