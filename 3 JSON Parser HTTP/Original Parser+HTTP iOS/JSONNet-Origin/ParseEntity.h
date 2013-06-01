//ParseEntity.h
#import <YAJLiOS/YAJL.h>

typedef enum {
    NONE,
    OBJECT,
    ARRAY
} FROM_TYPE;

@interface ParseEntity : NSObject <YAJLParserDelegate>

@property (nonatomic, assign) id owner;
@property (nonatomic, assign) BOOL isParsingSubObject;
@property (nonatomic, retain) NSString *currentKey;
@property (nonatomic, readonly) NSInteger depth;
@property (nonatomic, assign) FROM_TYPE fromType;

- (id) initWithOwner:(id)owner;

@end
