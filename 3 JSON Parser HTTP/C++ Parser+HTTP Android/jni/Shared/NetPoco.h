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
#include <iostream>
#include <string>
#include <sstream>
#include "RefListType.h"

using namespace Poco::Net;
using namespace Poco;
using namespace std;


class NetPoco{
private:
public:
    static RefListType* getRefListType();
};

#endif /* defined(__NetPoco__) */
