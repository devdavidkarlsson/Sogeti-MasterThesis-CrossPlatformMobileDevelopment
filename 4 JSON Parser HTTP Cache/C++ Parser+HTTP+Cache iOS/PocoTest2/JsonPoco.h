//JsonPoco.h


#import <Foundation/Foundation.h>

@interface JsonPoco : NSObject

+(void) jsonCreate:(NSString*) path;
+(BOOL) jsonParse:(id) mainView;
+(void) jsonFlush;
+(void) jsonStore;
+(void) jsonDestroy;

@end
