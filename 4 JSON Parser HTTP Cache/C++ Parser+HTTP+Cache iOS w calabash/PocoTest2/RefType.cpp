//RefType.cpp
#include "RefType.h"

RefType::RefType(){
    this->mLocation = 0;
}

RefType::RefType(Object::Ptr object)
{
    this->mLocation = 0;
    deserialize(object);
}

RefType::~RefType(){
    //delete this->mLocation; //Using smart pointer instead is an alternative..
    //this->mLocation = 0;
}


string RefType::getNo(){
    return this->mNo;
}

void RefType::setNo(string no){
    this->mNo = no;
}

string RefType::getName(){
    return this->mName;
}

void RefType::setName(string name){
    this->mName = name;
}

string RefType::getUrl(){
    return this->mUrl;
}

void RefType::setUrl(string url){
    this->mUrl = url;
}

LocationType* RefType::getLocation(){
    return this->mLocation;
}

void RefType::setLocation(LocationType *location){
    this->mLocation = location;
}

void RefType::deserialize(Object::Ptr object){
    if(object->has(NUMBER) && !object->isNull(NUMBER)){
        string str;
        Var no = object->get(NUMBER);
        Object::Ptr subObject = no.extract<Object::Ptr>();
        if (subObject->has("$")&& !subObject->isNull("$")) {
            str = subObject->get("$").convert<string>();
        }else{
            str = no.convert<string>();
        }
        this->mNo = str;
    }
    if(object->has(NAME) && !object->isNull(NAME)){
        string str;
        Var name = object->get(NAME);
        Object::Ptr subObject = name.extract<Object::Ptr>();
        if (subObject->has("$")&& !subObject->isNull("$")) {
            str = subObject->get("$").convert<string>();
        }else{
            str = name.convert<string>();
        }
        this->mName = str;
    }
    if(object->has(URL) && !object->isNull(URL)){
        string str;
        Var url = object->get(URL);
        Object::Ptr subObject = url.extract<Object::Ptr>();
        if (subObject->has("$")&& !object->isNull("$")) {
            str = subObject->get("$").convert<string>();
        }else{
            str = url.convert<string>();
        }
        this->mUrl = str;
    }
    if(object->has(LOCATION) && !object->isNull(LOCATION)){
        Var locationRaw = object->get(LOCATION);
        Object::Ptr locationObject = locationRaw.extract<Object::Ptr>();
        this->mLocation = new LocationType(locationObject);
    }
    else {
        printf("NO! Location");

    }
    
}


