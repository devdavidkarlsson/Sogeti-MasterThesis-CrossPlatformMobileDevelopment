//LocationType.cpp
#include "LocationType.h"


LocationType::LocationType(){
}
LocationType::~LocationType(){
}

LocationType::LocationType(Object::Ptr locationRaw){
    deserialize(locationRaw);
}

double LocationType::getLongitude() {
    return this->longitude;
}

void LocationType::setLongitude(double longitude) {
    this->longitude = longitude;
}

double LocationType::getLatitude() {
    return this->latitude;
}

void LocationType::setLatitude(double latitude) {
    this->latitude = latitude;
}

void LocationType::deserialize(Object::Ptr object){

    if(object->has(LONGITUDE) && !object->isNull(LONGITUDE)){
        double d;
        Var longitude = object->get(LONGITUDE);
        Object::Ptr subObject = longitude.extract<Object::Ptr>();
        if (subObject->has("$")&& !subObject->isNull("$")) {
            d = subObject->get("$").convert<double>();
        }else{
            d = longitude.convert<double>();
        }
        this->longitude = d;
    }
    if(object->has(LATITUDE) && !object->isNull(LATITUDE)){
        double d;
        Var LatRaw = object->get(LATITUDE);
        Var longitude = object->get(LATITUDE);
        Object::Ptr subObject = longitude.extract<Object::Ptr>();
        if (subObject->has("$")&& !subObject->isNull("$")) {
            d = subObject->get("$").convert<double>();
        }else{
            d = longitude.convert<double>();
        }
        this->latitude = d;
    }
}

