//LocationType.h
#ifndef __LocationType__
#define __LocationType__

#include <iostream>
#include <Poco/JSON/JSON.h>
#include <Poco/JSON/Array.h>
#include <Poco/JSON/Parser.h>
#include <Poco/JSON/DefaultHandler.h>
#include <Poco/JSON/Object.h>
#include <Poco/Dynamic/Var.h>
#include <cstdio>
#include <string>


#define LONGITUDE "Longitude"
#define LATITUDE "Latitude"

using namespace Poco::JSON;
using namespace Poco::Dynamic;
using namespace std;


class LocationType
{
private:
    
    
    double longitude;
    double latitude;
    
public:
    LocationType();
    ~LocationType();
    LocationType(Object::Ptr locationRaw);
    double getLongitude();
    void setLongitude(double longitude);
    double getLatitude();
    void setLatitude(double latitude);
    void deserialize(Object::Ptr object);
    
};
#endif /* defined(__LocationType__) */
