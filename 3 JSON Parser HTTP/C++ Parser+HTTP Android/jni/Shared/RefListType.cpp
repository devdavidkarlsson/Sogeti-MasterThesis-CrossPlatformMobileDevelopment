//RefListType.cpp
#include "RefListType.h"

RefListType::RefListType(istream &stream){
    
    this->deserialize(stream);
}
 
RefListType::RefListType(string jsonstring){
    read(jsonstring);
    deserialize();
}

RefListType::~RefListType(){}

void RefListType::read( string jsonString){
    this->jsonString=jsonString;
}



string RefListType::deserialize(){
    timeval start, end;
    gettimeofday(&start, NULL);

    Parser parser;
    DefaultHandler handler;
    parser.setHandler(&handler);
    parser.parse(this->jsonString);
    Var result = handler.result();
    
    
    Object::Ptr object = result.extract<Object::Ptr>();
    if (object->has(REF_LIST) && !object->isNull(REF_LIST)) {
        Var RefList = object->get(REF_LIST);
        object = RefList.extract<Object::Ptr>();
    }if (object->has(REF)) {
        Var Ref = object->get(REF);
        if (object->isArray(REF)) {
            Array::Ptr rawArr = Ref.extract<Array::Ptr>();
            int i=0;
            while (rawArr->isObject(i)) {
                Object::Ptr object = rawArr->getObject(i);
                
                refs.push_back(RefType(object));
                i++;
            }
            
        }
    }
    
    
    gettimeofday(&end, NULL);
    long millis = ((end.tv_sec * 1000) + (end.tv_usec / 1000))-((start.tv_sec * 1000) + (start.tv_usec / 1000));
    stringstream ss;
    ss << millis;
    cout << ss << endl;
    
    return ss.str();
  
}

string RefListType::deserialize(istream& stream){
    
    timeval start, end;
    gettimeofday(&start, NULL);
    
    Parser parser;
    DefaultHandler handler;
    parser.setHandler(&handler);
    parser.parse(stream);
    Var result = handler.result();
    
    Object::Ptr object = result.extract<Object::Ptr>();
    if (object->has(REF_LIST) && !object->isNull(REF_LIST)) {
        Var RefList = object->get(REF_LIST);
        object = RefList.extract<Object::Ptr>();
    }if (object->has(REF)) {
        Var Ref = object->get(REF);
        if (object->isArray(REF)) {
            Array::Ptr rawArr = Ref.extract<Array::Ptr>();
            int i=0;
            while (rawArr->isObject(i)) {
                Object::Ptr object = rawArr->getObject(i);
                
                refs.push_back(RefType(object));
                i++;
            }
            
        }
    }
    
    
    gettimeofday(&end, NULL);
    long millis = ((end.tv_sec * 1000) + (end.tv_usec / 1000))-((start.tv_sec * 1000) + (start.tv_usec / 1000));
    stringstream ss;
    ss << millis;
    printf(ss.str().c_str());
    printf("\n");
    return ss.str();

}





