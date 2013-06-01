//RefType.m

#import "RefType.h"
#import "LocationType.h"

#pragma mark Defined Keys

#define No @"No"
#define Name @"Name"
#define Url @"Url"
#define Location @"Location"

#pragma mark -

@implementation RefType

- (void)parserDidStartDictionary:(YAJLParser *)parser {
    [super parserDidStartDictionary:parser];
    
    if([self.currentKey isEqualToString:Location]){
        self.isParsingSubObject = YES;
        self.mLocation = [[LocationType alloc] initWithOwner:self];
        parser.delegate = self.mLocation;
    }
}

- (void)parser:(YAJLParser *)parser didAdd:(id)value {
    if([self.currentKey isEqualToString:No])
        self.mNo = [NSString stringWithFormat:@"%@", value];
    else if([self.currentKey isEqualToString:Name])
        self.mName = value;
    else if([self.currentKey isEqualToString:Url])
        self.mUrl = value;
}

@end
