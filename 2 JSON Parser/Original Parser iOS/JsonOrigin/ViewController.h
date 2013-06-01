//ViewController.h

#import <UIKit/UIKit.h>
#import "JSONType.h"

@interface ViewController : UIViewController<UITableViewDelegate,UITableViewDataSource>{
    JSONType *jsonComplex;
}

@end
