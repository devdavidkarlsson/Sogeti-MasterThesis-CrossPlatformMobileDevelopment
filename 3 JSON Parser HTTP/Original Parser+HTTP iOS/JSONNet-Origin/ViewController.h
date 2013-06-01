//ViewController.h

#import <UIKit/UIKit.h>
#import "JSONType.h"
#import "MKNetworkEngine.h"

@interface ViewController : UIViewController<UITableViewDelegate,UITableViewDataSource>{

    JSONType *mJSON;
}
@property (strong, nonatomic) MKNetworkOperation *getOperation;
@property (weak, nonatomic) IBOutlet UITableView *tableView;


@end
