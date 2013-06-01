//NetEngine.m


#import "NetEngine.h"
#define JSON_URL(__C1__, __C2__) [NSString stringWithFormat:@"et08dc0/exjobbjail/%@_%@_capitals.json", __C1__, __C2__]
@implementation NetEngine


-(MKNetworkOperation*) getRefListType:(GetResponseBlock) completionBlock{
    MKNetworkOperation *op = [self operationWithPath:JSON_URL(@"se",@"sv") params:nil httpMethod:@"GET"];
        
    //NSMutableDictionary *headerFields = [NSMutableDictionary dictionary];
    //[op addHeaders:headerFields];
    
    [op addCompletionHandler:^(MKNetworkOperation *completedOperation)
     {
         // Cache is not to be used in this implementation:
         //[self emptyCache];
         
         JSONType *json = [[JSONType alloc] init];
         
         if([completedOperation isCachedResponse]) {
             //DLog(@"Data from cache %@", [completedOperation responseString]);
         }
         else {
             //DLog(@"Data from server %@", [completedOperation responseString]);
             [json parseTest:[completedOperation responseData]];
         }
         completionBlock(json);
         
     }errorHandler:^(MKNetworkOperation *errorOp, NSError* error) {
         NSLog(@"An error occured");
         //errorBlock(error);
     }];
    
    [self enqueueOperation:op];
    
    return op;
}


@end
