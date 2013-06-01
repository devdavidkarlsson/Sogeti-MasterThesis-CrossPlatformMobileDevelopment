//ViewController.h


#import <UIKit/UIKit.h>
#include "RefListType.h"
#include <String.h>

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>{
    RefListType* ref;
}
@end
