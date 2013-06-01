//ViewController.h


#import <UIKit/UIKit.h>
#include "RefListType.h"
#include <String.h>
#include "NetPoco.h"

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>{
    RefListType* ref;
}
@end
