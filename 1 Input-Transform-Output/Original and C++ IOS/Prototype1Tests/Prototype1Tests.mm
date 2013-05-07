//Prototype1Tests.mm
#import "Prototype1Tests.h"
#import "CppTransform.h"
#import "NativeTransform.h"

@implementation Prototype1Tests
@synthesize controller = _controller;
- (void)setUp
{
    [super setUp];
    
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"MainStoryboard_iPhone" bundle:nil];
    self.controller = [storyboard instantiateViewControllerWithIdentifier:@"test"];
    [self.controller performSelectorOnMainThread:@selector(loadView) withObject:nil waitUntilDone:YES];
}

- (void)tearDown
{
    // Tear-down code here.
    
    [super tearDown];
}

- (void)testCpp
{
    //STFail(@"Unit tests are not implemented yet in Prototype1Tests");
    NSString* inputString =[[NSString alloc] initWithFormat: @"paris"];
    //NSString* answerString =[[NSString alloc] initWithFormat: @"siraP"];
    NSString* response;
    NSDate *start= [NSDate date];
    for (int i=0; i<10000; i++) {
        response = [NSString stringWithUTF8String:NativeCpp::transform([inputString UTF8String])];
    }
    NSDate *stop= [NSDate date];
    NSTimeInterval executionTime= [stop timeIntervalSinceDate:start]*1000;
    NSLog(@"Execution Time: %f Milliseconds", executionTime);
    STAssertEqualObjects(response, @"sirap", @"Strings did not match using C++", nil);

    
}

- (void)testObjC
{
    //STFail(@"Unit tests are not implemented yet in Prototype1Tests");
    NSString* inputString =[[NSString alloc] initWithFormat: @"paris"];
    //NSString* answerString =[[NSString alloc] initWithFormat: @"siraP"];
    NSString* response;
    NSDate *start= [NSDate date];    
    for (int i=0; i<10000; i++) {
        response = [NativeTransform transform: inputString];
    }
    NSDate *stop= [NSDate date];
    NSTimeInterval executionTime= [stop timeIntervalSinceDate:start]*1000;
    NSLog(@"Execution Time: %f Milliseconds", executionTime);
    STAssertEqualObjects(response, @"sirap", @"Strings did not match using Objective-C", nil);
    
    
}

-(void)testUI{
    [self.controller.txtInput setText:@"Abc123"];
    [self.controller.btnGo sendActionsForControlEvents: UIControlEventTouchUpInside];
    NSLog(@"%@", self.controller.txtOutput.text);
    STAssertEqualObjects(@"321cbA", self.controller.txtOutput.text, @"Strings did not match using the UI", nil);

}

-(void)testPerformance{
    for (int j=0; j<100; j++) {
        [self testCpp];
    }
    NSLog(@"________________");
    for (int j=0; j<100; j++) {
        [self testObjC];
    }
    
}

@end
