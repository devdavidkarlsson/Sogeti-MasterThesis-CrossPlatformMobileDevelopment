//NativeTransform.h
#import <Foundation/Foundation.h>

@interface NativeTransform : NSObject
//@property (nonatomic, retain) NSString *preTransform, *postTransform;

+(NSString*) transform:(NSString*)input;

@end
