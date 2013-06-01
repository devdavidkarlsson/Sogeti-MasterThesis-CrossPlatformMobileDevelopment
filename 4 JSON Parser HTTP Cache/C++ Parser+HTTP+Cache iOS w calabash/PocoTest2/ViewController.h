//ViewController.h


#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>
#include "RefListType.h"
#include <String.h>
#include "JsonPoco.h"
#include "RefWrapper.h"

@interface ViewController : UIViewController <UITableViewDelegate, UITableViewDataSource>
    

@property (weak, nonatomic) IBOutlet UILabel *cacheStatusLabel;
@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (retain, nonatomic) NSMutableArray *refs;
@property (weak, nonatomic) IBOutlet UIBarButtonItem *trashButton;


- (IBAction)flushAction:(id)sender;
- (IBAction)refreshAction:(id)sender;
- (IBAction)saveAction:(id)sender;
- (void) getData;
- (void) alert:(NSString*) alert;
-(void) addData:(RefWrapper*)data;
@end
