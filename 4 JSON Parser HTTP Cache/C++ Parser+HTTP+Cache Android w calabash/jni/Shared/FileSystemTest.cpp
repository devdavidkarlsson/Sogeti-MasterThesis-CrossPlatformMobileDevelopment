//FileSystemTest.cpp

#include "FileSystemTest.h"

bool FileSystemTest::test(string path){
    //Test file system and RW-permission
    
    cout << "File system test initiated..." << endl;
    string file(path+"/testfile.txt");
    TemporaryFile::registerForDeletion(file);
    FileOutputStream fos(file, ios::binary);
    fos << "sometestdata";
    fos.close();

    Poco::FileInputStream fis(file);
    cout << ( fis.good()? "A test file was successfully created" : "Error. No test file created" ) << endl;
    string read;
    fis >> read;
    cout << ( read=="sometestdata"? "Test file content sucseefully validated" : "Error. Wrong content in test file" ) << endl << endl;
    fis.close();
    
    File tmpFile(file);
    tmpFile.remove();
    return read=="sometestdata"? true : false;

}
