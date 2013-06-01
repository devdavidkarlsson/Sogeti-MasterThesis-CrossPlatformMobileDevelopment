//RefListType.cpp
#include "RefListType.h"


RefListType::RefListType(string jsonString){
    this->jsonString = jsonString;

}

RefListType::~RefListType(){}


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
        Var refList = object->get(REF_LIST);
        object = refList.extract<Object::Ptr>();
    }if (object->has(REF)) {
        Var ref = object->get(REF);
        if (object->isArray(REF)) {
            Array::Ptr rawArr = ref.extract<Array::Ptr>();
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
    std::stringstream ss;
    ss << millis;
    return ss.str();
 
}





