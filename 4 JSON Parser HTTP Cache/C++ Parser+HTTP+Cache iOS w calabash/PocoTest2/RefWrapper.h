//RefWrapper.h


#import <Foundation/Foundation.h>

@interface RefWrapper : NSObject

@property (nonatomic, retain) NSString *mNo;
@property (nonatomic, retain) NSString *mName;
@property (nonatomic, retain) NSString *mUrl;
@property (nonatomic) double longitude;
@property (nonatomic) double latitude;

@end
