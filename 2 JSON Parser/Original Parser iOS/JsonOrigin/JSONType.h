//JSONType.h

#import <UIKit/UIKit.h>
#import <YAJLiOS/YAJL.h>
#import "RefListType.h"

@interface JSONType : NSObject <YAJLParserDelegate>

@property (nonatomic, assign) BOOL isParsingSubObject;
@property (nonatomic, retain) NSString *currentKey;
@property (nonatomic, readonly) NSInteger depth;
@property (nonatomic,retain) RefListType *refList;

//@property (nonatomic, assign) FROM_TYPE fromType;

-(void)parseTest:(NSData*)data;



@end
