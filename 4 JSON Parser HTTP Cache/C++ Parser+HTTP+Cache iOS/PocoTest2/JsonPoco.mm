//  JsonPoco.mm


//Create a global C++ function for doing NSLOG:
int printf(const char * __restrict format, ...)
{
    va_list args;
    va_start(args,format);
    NSLogv([NSString stringWithUTF8String:format], args) ;
    va_end(args);
    return 1;
}



#import "JsonPoco.h"
#import "AppDelegate.h"
#import "RefWrapper.h"
#import "ViewController.h"
#define AppDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)

@implementation JsonPoco


+(void) jsonCreate:(NSString*) path{
    
    
    
        AppDelegate.netHelper = new NetPoco([path cStringUsingEncoding:NSUTF8StringEncoding]);

    

}
+(BOOL) jsonParse:(id) mainView{

    RefListType *ref = AppDelegate.netHelper->getRefListType();
    
    //Wrap C++ objects to Obj-C
    std::list<RefType>::iterator it;
    for(it = ref->refs.begin(); it != ref->refs.end(); it++){
        RefWrapper *tmp = [[RefWrapper alloc] init];
        tmp.mNo = [NSString stringWithUTF8String:it->getNo().c_str()];
        tmp.mName = [NSString stringWithUTF8String:it->getName().c_str()];
        tmp.mUrl = [NSString stringWithUTF8String:it->getUrl().c_str()];
        tmp.longitude = it->getLocation()->getLongitude();
        tmp.latitude = it ->getLocation()->getLatitude();
        [((ViewController*)mainView) addData:tmp];
    }
    return AppDelegate.netHelper->usingCached;
    
}
+(void) jsonStore{
    AppDelegate.netHelper->storeCache();
}

+(void) jsonFlush{
    AppDelegate.netHelper->clearCache();

    
}
+(void) jsonDestroy{
    delete AppDelegate.netHelper;
    
}
@end
