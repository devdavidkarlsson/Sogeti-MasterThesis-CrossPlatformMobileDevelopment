//LocationType.m

#import "LocationType.h"

#pragma mark Defined Keys

#define Latitude @"Latitude"
#define Longitude @"Longitude"

#pragma mark -

@implementation LocationType

- (void)parser:(YAJLParser *)parser didAdd:(id)value {
    if( [self.currentKey isEqualToString:Latitude] )
        _latitude = value;
    else if( [self.currentKey isEqualToString:Longitude] )
        _longitude = value;
}

@end
