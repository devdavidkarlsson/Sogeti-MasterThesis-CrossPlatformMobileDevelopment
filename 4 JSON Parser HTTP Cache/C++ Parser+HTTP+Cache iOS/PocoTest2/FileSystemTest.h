//FileSystemTest.h

#ifndef __FileSystemTest__
#define __FileSystemTest__


#include <iostream>
#include <Poco/TemporaryFile.h>
#include <Poco/FileStream.h>
#include <assert.h>

using namespace Poco;
using namespace std;

class FileSystemTest{
public:
    static bool test(string path);
};
#endif /* defined(__FileSystemTest__) */
