//RefListType.h
#ifndef __RefListType__
#define __RefListType__


#include <iostream>
#include <list>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/DefaultHandler.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include "RefType.h"
#include "RefListType.h"
#include <String.h>
#include <sys/time.h>

#define REF "Ref"
#define REF_LIST "RefList"


using namespace Poco::JSON;
using namespace Poco::Dynamic;
using namespace std;


class RefListType{
private:
    
public:
    RefListType(istream &stream);
    RefListType(string jsonString);
    ~RefListType();
    void deserialize(istream &stream);
    void deserialize(string jsonString);
    list<RefType> refs;

    
};

#endif /* defined(__RefListType__) */

