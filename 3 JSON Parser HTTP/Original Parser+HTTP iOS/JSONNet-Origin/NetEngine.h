//NetEngine.h


#import "MKNetworkEngine.h"
#import "JSONType.h"

typedef void (^GetResponseBlock)(JSONType *getJsonComplex);

@interface NetEngine : MKNetworkEngine
-(MKNetworkOperation*) getRefListType:(GetResponseBlock) completionBlock;
@end
