//RefType.m

#import "RefType.h"
#import "LocationType.h"

#pragma mark Defined Keys

#define NUMBER @"No"
#define NAME @"Name"
#define URL @"Url"
#define LOCATION @"Location"

#pragma mark -

@implementation RefType

- (void)parserDidStartDictionary:(YAJLParser *)parser {
    [super parserDidStartDictionary:parser];
    
    if([self.currentKey isEqualToString:LOCATION]){
        self.isParsingSubObject = YES;
        self.mLocation = [[LocationType alloc] initWithOwner:self];
        parser.delegate = self.mLocation;
    }
}

- (void)parser:(YAJLParser *)parser didAdd:(id)value {
    if([self.currentKey isEqualToString:NUMBER])
        self.mNo = [NSString stringWithFormat:@"%@", value];
    else if([self.currentKey isEqualToString:NAME])
        self.mName = value;
    else if([self.currentKey isEqualToString:URL])
        self.mUrl = value;
}

@end
