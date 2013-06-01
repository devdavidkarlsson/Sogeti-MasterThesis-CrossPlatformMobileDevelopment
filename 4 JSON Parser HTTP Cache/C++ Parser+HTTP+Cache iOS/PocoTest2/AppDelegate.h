//AppDelegate.h

#import <UIKit/UIKit.h>
#include "NetPoco.h"


#define ApplicationDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)

@interface AppDelegate : UIResponder <UIApplicationDelegate>{
    NetPoco* netHelper;

}
@property (nonatomic) NetPoco* netHelper;
@property (strong, nonatomic) UIWindow *window;

@end
