//LRUPersistentCache.h
//Added storage capabilities to the LRUCache of POCO C++

#ifndef __LRUPersistentCache__
#define __LRUPersistentCache__

#include <Poco/AbstractCache.h>
#include "LRUPersistentStrategy.h"
#include <iostream>
#include <fstream>
#include "FileSystemTest.h"
#include <string>


namespace Poco {
    
    template <
	class TKey,
	class TValue,
	class TMutex = FastMutex,
	class TEventMutex = FastMutex
    >
    class LRUPersistentCache: public AbstractCache<TKey, TValue, LRUPersistentStrategy<TKey, TValue>, TMutex, TEventMutex>
	/// An LRUCache implements Least Recently Used caching. The default size for a cache is 1024 entries.
    {
    public:
        LRUPersistentCache(long size = 1024, string cachePath="/"):
		AbstractCache<TKey, TValue, LRUPersistentStrategy<TKey, TValue>, TMutex, TEventMutex>(LRUPersistentStrategy<TKey, TValue>(size))
        {
            cout << "Cache created, will be stored at: " << cachePath << endl;
            this->cachePath = cachePath;
            this->cacheFile = cachePath+"/persistentCache.tmp";

            loadCache();
        }
        
        ~LRUPersistentCache()
        {
            cout << "Cache released" << endl;
        }
        
        void loadCache(){
            // verify filesystem access:
            if(FileSystemTest::test(this->cachePath)){
                try{
                    
                    // create stream
                    ifstream ifs(this->cacheFile.c_str(), ios::binary);
                    
                    // read file to cache if stream is good
                    if(ifs.good()){
                        while (! ifs.eof() ){
                            map<string,string> headerPairs;
                            string tmp;
                            string key;
                            string data;
                        
                            //Discard any empty lines between data:
                            getline(ifs, tmp);
                            while(tmp.empty()){
                                getline(ifs, tmp);
                                cout << "Empty line..." << "\n";
                                //If file ended return from the load method.
                                if(ifs.eof()){
                                    cout << "End of File.."<< "\n";
                                    return;
                                }
                            }
                        
                            //After empty lines get "Key"
                            key = tmp;
                            getline(ifs, tmp);
                        
                            //Get segment of header pairs
                            while(tmp != key){
                                StringTokenizer headerPair(tmp, "✰", StringTokenizer::TOK_TRIM);
                                //StringTokenizer::Iterator it = headerPair.begin();
                                std::cout << *(headerPair.begin()) <<"✰" << *(headerPair.end()-1)<< std::endl;
                                string headerKey = *(headerPair.begin());
                                string headerValue = *(headerPair.end()-1);
                                
                                headerPairs.insert(make_pair(headerKey, headerValue));
                                getline(ifs, tmp);
                            }
                        
                            cout << "Added " << headerPairs.size() << " header pairs from cache" << "\n";
            
                            while(tmp!=key){
                                getline(ifs, tmp);
                                cout << "Searching for header->data delimiter" << "\n";
                            
                            }
                            cout << "Found header->data delimiter" << "\n";
                        
                            //Get segment of data!
                            getline(ifs, tmp);
                            while(tmp != key){
                                
                                data+=tmp;
                                getline(ifs, tmp);
                            } //done
                            cout << "DATA: " << data << "\n";
                            cout << "Ending delimiter:" << tmp << "\n";
                         
                            this->add(key,make_pair(headerPairs, data));
                            cout << "Added: " << key << " to memory-cache" << endl;
                        }
                        ifs.close();
                    }
                    
                }
                catch (Exception &ex){
                    cerr << ex.displayText() << endl;
                }
            }
        }
        
        void saveCache(){
            //Store cached data in persistent file.
            try{
                ofstream ofs(this->cacheFile.c_str(), ios::binary | ios::trunc );
                if(ofs.good()){
                    //Store all key, value pairs in file using \t as delimiter.
                    std::set<string> allKeys =  this->getAllKeys();
                    for(set<string>::iterator iterator = allKeys.begin(); iterator != allKeys.end(); iterator++) {
                        
                        // iterator iterates the keys of the cache.
                        //The cache consist of a key-value pair with value: < <map<string, string>, string  >.
                        // get("myString") => <pair<map<string, string>, string >
                        
                        // First add key:
                        ofs << *iterator << "\n";// << *this->get(*iterator) << "\n";
                        cout << *iterator << "\n";

                        //Add headers:
                        map<string, string> headers = this->get(*iterator)->first;
                        std::map<string,string>::iterator headersIt = headers.begin();
                        for (headersIt=headers.begin(); headersIt!=headers.end(); ++headersIt){
                            ofs << headersIt->first << "✰" << headersIt->second << "\n";
                            cout  << headersIt->first << "✰" << headersIt->second << "\n";
                        }
                        
                        //key line and then data:
                        ofs << *iterator << "\n";
                        cout << *iterator << "\n";
                        ofs << this->get(*iterator)->second << "\n";
                        cout << this->get(*iterator)->second << "\n";
                        //Finish with key:
                        ofs << *iterator << "\n";
                        cout << *iterator << "\n";
                        
                    }
                }
                ofs.close();
                
                
            }
            catch (Exception &ex){
                cerr << ex.displayText() << endl;
            }
        }
        
        

        
        
    private:
        LRUPersistentCache(const LRUPersistentCache& aCache);
        LRUPersistentCache& operator = (const LRUPersistentCache& aCache);
        string cachePath;
        string cacheFile;

    };
    
    
}

#endif /* defined(__LRUPersistentCache__) */
