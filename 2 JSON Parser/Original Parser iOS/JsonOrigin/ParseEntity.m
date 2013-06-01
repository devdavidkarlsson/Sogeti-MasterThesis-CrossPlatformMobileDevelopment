//ParseEntity.m
#import "ParseEntity.h"
#import <libkern/OSAtomic.h>

@implementation ParseEntity {
    NSInteger _depth;
}

- (NSInteger)depth {
    return _depth;
}

- (id) init {
    @throw [[NSException alloc] initWithName:@"Wrong usage" reason:[NSString stringWithFormat:@"Entity based classes should use [initWithOwner:] (%@)", self.class] userInfo:nil];
}

- (id) initWithOwner:(ParseEntity *)owner {
    self = [super init];
    
    if( self ) {
        _owner = owner;
        _depth = 0;
        _isParsingSubObject = NO;
        
        if([self.owner isKindOfClass:ParseEntity.class] && [self.owner isParsingSubObject])
            [self parserDidStartDictionary:nil];
    }
    
    return self;
}

- (void)parserDidStartDictionary:(YAJLParser *)parser {
    OSAtomicIncrement32(&_depth);
}

- (void)parserDidEndDictionary:(YAJLParser *)parser {
    OSAtomicDecrement32(&_depth);
    
    if(!_depth){
        parser.delegate = self.owner;
        
        if([self.owner isKindOfClass:ParseEntity.class] && [self.owner isParsingSubObject])
            [self.owner parserDidEndDictionary:parser];
    }
}

- (void)parserDidStartArray:(YAJLParser *)parser {
    OSAtomicIncrement32(&_depth);
    _isParsingSubObject = YES;
}

- (void)parserDidEndArray:(YAJLParser *)parser {
    OSAtomicDecrement32(&_depth);
    _isParsingSubObject = NO;
    
    if(!_depth)
        parser.delegate = self.owner;
}

- (void)parser:(YAJLParser *)parser didMapKey:(NSString *)key {
    if(![key isEqualToString:@"$"])
        _currentKey = key;
}

- (void)parser:(YAJLParser *)parser didAdd:(id)value {
}

@end
