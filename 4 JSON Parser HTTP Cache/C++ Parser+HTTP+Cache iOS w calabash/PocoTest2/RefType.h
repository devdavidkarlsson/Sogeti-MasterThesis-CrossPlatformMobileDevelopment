//RefType.h
#ifndef __RefType__
#define __RefType__

#include <iostream>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/DefaultHandler.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include "LocationType.h"
#include <assert.h>

#define NUMBER "No"
#define NAME "Name"
#define URL "Url"
#define LOCATION "Location"


using namespace Poco::JSON;
using namespace Poco::Dynamic;
using namespace std;




class RefType
{
private:

    
	string mNo;
	string mName;
	string mUrl;
	LocationType *mLocation;
    
public:
    RefType();
	RefType(Object::Ptr object);
    ~RefType();
    
	string getNo();
    
	void setNo(string no);
    
	string getName();
    
	void setName(string name);
    
	string getUrl();
    
	void setUrl(string url);
    
	LocationType *getLocation();
    
	void setLocation(LocationType* location);
    
	void deserialize(Object::Ptr object);
};
#endif /* defined(__RefType__) */

