//RefListType.m

#import "RefListType.h"
#import "RefType.h"

#pragma mark Defined Keys

#define REF @"Ref"

#pragma mark -

@implementation RefListType {
    RefType *_ref;
}

- (void)parserDidStartDictionary:(YAJLParser *)parser {
    [super parserDidStartDictionary:parser];
    
    if( [self.currentKey isEqualToString:REF] ) {
        self.isParsingSubObject = YES;
        if( !_refs )
            _refs = [[NSMutableArray alloc] init];
        
        _ref = [[RefType alloc] initWithOwner:self];
        parser.delegate = _ref;
        
        [_refs addObject:_ref];
    }
}

@end
