//CppTransform.cpp
#include "CppTransform.h"
#include <cstring>

char* NativeCpp::transformRec(char buf[], int len)
{
    int i;
    char *tmp=new char[len];
    std::strcpy(tmp, buf);
    for(i=len-1; i>=0;i--){
        buf[(len-1)-i]=tmp[i];
    }
    return buf;
}

char* NativeCpp::transform(const char *input)
{
    char* str= new char[strlen(input)];
    std::strcpy(str,input);
    return NativeCpp::transformRec(str, std::strlen(str));
}

