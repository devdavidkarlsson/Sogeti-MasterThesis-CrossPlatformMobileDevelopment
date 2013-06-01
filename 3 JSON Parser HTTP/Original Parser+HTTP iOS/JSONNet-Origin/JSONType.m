//JSONType.m

#import "JSONType.h"
#import <YAJLiOS/YAJL.h>


#pragma mark Defined Keys

#define REF_LIST @"RefList"

#pragma mark -

@implementation JSONType


-(void)parseTest:(NSData*)data{

    YAJLParser *parser = [[YAJLParser alloc] initWithParserOptions:YAJLParserOptionsAllowComments];
    parser.delegate = self;
    [parser parse:data];
    if (parser.parserError)
        NSLog(@"Error:\n%@", parser.parserError);

    parser.delegate = nil;

}

- (void)parserDidStartDictionary:(YAJLParser *)parser {
    if( [self.currentKey isEqualToString:REF_LIST] ) {
        self.isParsingSubObject = YES;
        if( !_refList )
            _refList = [[RefListType alloc] initWithOwner:self];
            parser.delegate = _refList;
    }
}

- (void)parserDidEndDictionary:(YAJLParser *)parser { }

- (void)parserDidStartArray:(YAJLParser *)parser {
}
- (void)parserDidEndArray:(YAJLParser *)parser { }

- (void)parser:(YAJLParser *)parser didMapKey:(NSString *)key {
    if(![key isEqualToString:@"$"]){
        _currentKey = key;
    }
}
- (void)parser:(YAJLParser *)parser didAdd:(id)value { }

@end
