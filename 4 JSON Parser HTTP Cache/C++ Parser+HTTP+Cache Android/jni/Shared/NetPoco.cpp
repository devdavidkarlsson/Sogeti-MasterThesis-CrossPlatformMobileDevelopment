//NetPocco.cpp
//Provides a cache and a http interface for creating RefLists from JSON

#include "NetPoco.h"
#define printnet(...) printf(__VA_ARGS__);
#define convertToMicro(s) s*1000000;

NetPoco::NetPoco(string cachePath){
	/*init empty memory cache with size 3
	 * and fill with data from persistent cache file
	 * if available.
	 */
    
    //Cache should store a headkey, the header-response-map and a string of data. 
    
	this->clientCache = new LRUPersistentCache<string, pair<map<string, string>, string > >(3,cachePath);
    cout << "created cache!" << "\n";
}

NetPoco::~NetPoco(){
	//Free temporary memory cache.
	delete clientCache;
    clientCache = 0;
}

void NetPoco::storeCache(){
    this->clientCache->saveCache();
}





RefListType* NetPoco::getRefListType(){
	//Creates a RefListType from clientCache or Server response.
	try
	{	//Prepare session and path and request header

        //string url = "http://192.168.1.5/se_sv_capitals.json";
		string url = "http://10.225.113.152/se_sv_capitals.json";
        //Test server is to contain the json for parsing, make sure to have se_sv_capitals.json
        // in your apache www-directory and that the IP is correct
        //10.225.113.87
        string headKey = makeKeyFromResponse(url);
        
        
        
        
        URI uri(url);
        HTTPClientSession session(uri.getHost(), uri.getPort());
        string path(uri.getPathAndQuery());
        if (path.empty()) path = "/";

		checkCache(headKey, path, &session);
		return new RefListType(this->clientCache->get(headKey)->second);
	}
	catch (Exception &ex){
		cerr << ex.displayText() << endl;
        return 0;
	}
}


void NetPoco::clearCache(){
    this->clientCache->clear();
}



string NetPoco::makeKeyFromResponse(string urlAddress){
	// make cache-key from URL:
    string headKey =(urlAddress);
	for(int i=0; i<headKey.length(); i++){
		if(headKey[i] == ','||headKey[i] == '.'||headKey[i] == ':'||headKey[i] == ' ') {
			headKey.erase(i,1);
			i--;
		}}
	cout << endl << headKey << endl;
	return headKey;
}

void NetPoco::checkCache(string headKey, string path, HTTPClientSession *session){
    //Checks if a header-value pair is in the cache, if it is not its fetched from HTTP.
	Poco::SharedPtr<pair<map<string,string>, string > > dataFromCache = clientCache->get(headKey);
    this->httpRequest(HTTPRequest::HTTP_GET, session, path, headKey);
	if(this->usingCached){
        //Header is in cache Request data, check response expires/modified:
        //cout << "usingCache!";
	}else{
		// get response
		HTTPResponse res;
		istream &is = session->receiveResponse(res);
		// cache response
		// consume response
        //cout << "Got data from server" << endl;
        string dataToCache;
        // 304 = not modified since last request
        if(res.getStatus()!= 304 && is){
                cout << "Data from server was updated!" << "\n";
                StreamCopier::copyToString(is, dataToCache);
        }else{
            dataToCache = this->clientCache->get(headKey)->second;
            cout << "Data from server was not updated since last caching, falling back on cache and updating expires!" << "\n";
        }
        //cout << dataToCache << "\n";
        map<string, string> headersMap;
        string name;
        string value;
        NameValueCollection::ConstIterator i = res.begin();
        while(i!=res.end()){
            
            name=i->first;
            value=i->second;
            //cout << name << "=" << value << endl << endl << flush;
            headersMap.insert(pair<string, string>(name, value));
            ++i;
        }
            
        pair<map<string,string>, string> pairToCache = make_pair(headersMap,dataToCache);
        clientCache->add(headKey, pairToCache);
        
	}
}


void NetPoco::httpRequest(string request, HTTPClientSession  *session,string path, string headKey){
    
    //Expires defaults to NOW. Will be reset if Expires or max-age headers are found!
    DateTime expires;
    
    cout << "DateTime now : " << DateTimeFormatter::format(expires.timestamp(), DateTimeFormat::RFC1123_FORMAT) << "\n";
    
	HTTPRequest headReq(request, path, HTTPMessage::HTTP_1_1);
    Poco::SharedPtr<pair<map<string,string>, string > > dataFromCache = clientCache->get(headKey);
    if (!dataFromCache.isNull()) {
        map<string,string> cachedHeaders = dataFromCache->first;
        //cout << "HEADERS: \n";
        
        //First check expires (HTTP 1.0):
        map<string,string>::iterator pos = cachedHeaders.find("Expires");
        if (pos != cachedHeaders.end()) {
            cout << "Expires found" << pos->second << "\n";
            DateTime dt;
            int tzd;
            DateTimeParser::parse(DateTimeFormat::RFC1123_FORMAT, pos->second , dt, tzd);
            expires = dt;
        }
        
        
        //Replace result with max-age if found (HTTP 1.1):
        pos = cachedHeaders.find("Cache-Control");
        if (pos != cachedHeaders.end()) {
            StringTokenizer cacheControlPairs(pos->second, ",", StringTokenizer::TOK_TRIM);
            //cout << "Control pairs : " << cacheControlPairs.count() << "\n";
            for(StringTokenizer::Iterator it = cacheControlPairs.begin(); it != cacheControlPairs.end(); ++it) {
                //cout << "Inspecting : "<< * it << "\n";
                if(string::npos != it->find("max-age")){
                    StringTokenizer maxAgePair(pos->second, "=", StringTokenizer::TOK_TRIM);
                    if (maxAgePair.count()==2) {
                        unsigned int secondsMaxAge = atoi(maxAgePair[1].c_str());
                        cout << "Found max-age : " <<  secondsMaxAge << "\n";
                        //cout << DateTime().dayOfWeek() << "\n";
                        //Set expires to max-age:
                        map<string,string>::iterator pos = cachedHeaders.find("Date");
                        if (pos != cachedHeaders.end()) {
                            cout << "Date found : " << pos->second << "\n";
                            DateTime dt;
                            int tzd;
                            DateTimeParser::parse(DateTimeFormat::RFC1123_FORMAT, pos->second , dt, tzd);
                            dt+=convertToMicro(secondsMaxAge);
                            cout << "expires : " << DateTimeFormatter::format(dt.timestamp(), DateTimeFormat::RFC1123_FORMAT) << "\n";
                            expires = dt;
                        }
               
                        
                    }else{
                        cout << "Error invalid max-age" << "\n";
                    }
                    break;
                }
                
            }
            
        }
        
        DateTime now;
        //If not Expired use cache:
        if (now < expires ) {
            cout << "now < expires" << endl;
            this->usingCached = true;
            return;
        }else{
            cout << "now > expires" << endl;
            this->usingCached = false;
            //Append Last-Modified and ETag to request headers:
            pos = cachedHeaders.find("Last-Modified");
            if (pos != cachedHeaders.end()) {
                headReq.set("IF-MODIFIED-SINCE", pos->second);
            }
        
            pos = cachedHeaders.find("ETag");
            if (pos != cachedHeaders.end()) {
                headReq.set("IF-NONE-MATCH", pos->second);
            }
        }
    }
    else{
        //No data in cache:
        this->usingCached = false;
        cout << "Cache was empty" << "\n";

    }
    cout << "send Request! \n";
    session->sendRequest(headReq);

}







