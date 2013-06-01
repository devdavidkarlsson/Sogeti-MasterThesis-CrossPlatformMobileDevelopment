//RefType.h

#import "ParseEntity.h"

@class LocationType;

@interface RefType : ParseEntity

@property (nonatomic, retain) NSString *mNo;
@property (nonatomic, retain) NSString *mName;
@property (nonatomic, retain) NSString *mUrl;
@property (nonatomic, retain) LocationType *mLocation;

@end
