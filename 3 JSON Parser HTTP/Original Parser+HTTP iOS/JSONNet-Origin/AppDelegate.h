//AppDelegate.h

#import <UIKit/UIKit.h>
#import "NetEngine.h"
#define ApplicationDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)


@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) NetEngine *engine;
@end
