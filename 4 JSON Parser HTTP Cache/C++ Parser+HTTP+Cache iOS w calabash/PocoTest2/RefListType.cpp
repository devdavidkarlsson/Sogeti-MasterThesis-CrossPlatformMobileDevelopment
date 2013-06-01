//RefListType.cpp
#include "RefListType.h"

RefListType::RefListType(istream &stream){ 
    this->deserialize(stream);
}
 
RefListType::RefListType(string jsonString){
    deserialize(jsonString);
}

RefListType::~RefListType(){}


void RefListType::deserialize(string jsonString){

    Parser parser;
    DefaultHandler handler;
    parser.setHandler(&handler);
    parser.parse(jsonString);
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
}

void RefListType::deserialize(istream& stream){

    
    Parser parser;
    DefaultHandler handler;
    parser.setHandler(&handler);
    parser.parse(stream);
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
}





