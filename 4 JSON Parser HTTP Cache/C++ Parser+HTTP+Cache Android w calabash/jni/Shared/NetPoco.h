//NetPoco.h

#ifndef __NetPoco__
#define __NetPoco__

#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/StreamCopier.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <Poco/Exception.h>
#include <Poco/StringTokenizer.h>
#include <iostream>
#include <string>
#include <sstream>
#include "RefListType.h"
#include "LRUPersistentCache.h"
#include <fstream>



using namespace Poco::Net;
using namespace Poco;
using namespace std;



class NetPoco{
private:
    string cachePath;
    
public:
    bool usingCached;
    NetPoco(string cachePath);
    ~NetPoco();
    RefListType* getRefListType();
    LRUPersistentCache<string, pair<map<string,string>, string > > *clientCache;
    void storeCache();
    void clearCache();
    string makeKeyFromResponse(string urlAddress);
    void checkCache(string headKey, string path, HTTPClientSession *session);
    void httpRequest(string request,HTTPClientSession * session ,string path, string headKey);
};

#endif /* defined(__NetPoco__) */
