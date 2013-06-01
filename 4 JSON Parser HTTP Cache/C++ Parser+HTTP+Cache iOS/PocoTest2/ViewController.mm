//ViewController.mm


#import "ViewController.h"



@implementation ViewController
@synthesize refs;


- (void)viewDidLoad
{
    [super viewDidLoad];
    self.navigationController.toolbarHidden=NO;
    
    NSString *imagePath = [[NSBundle mainBundle] pathForResource:@"Sogeti_heart" ofType:@"jpg"];
    UIImage *logo = [UIImage imageWithData:[NSData dataWithContentsOfFile:imagePath]];
    UIImageView *logoView = [[UIImageView alloc] initWithImage:logo];
    [logoView setFrame:CGRectMake(self.view.center.x-97, self.view.center.y-22, 194, 44)];
    logoView.alpha = 0.1;
    [self.tableView setBackgroundView:logoView];
    
    NSString *tempPath = NSTemporaryDirectory();
    [JsonPoco jsonCreate:tempPath];
    [self getData];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


# pragma tableView:

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return refs.count;
    NSLog(@"should add: %d rows", refs.count);
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"SimpleTableItem";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
    }
    
    RefWrapper* wrapper = [refs objectAtIndex:indexPath.row];
    cell.textLabel.text = wrapper.mName;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    RefWrapper* wrapper = [refs objectAtIndex:indexPath.row];
    NSString *titleString = [NSString stringWithFormat:@"%@ %@", wrapper.mNo, wrapper.mName];
    
    NSString *msgString = [NSString stringWithFormat:@"Latitude:%f Longitude:%f", wrapper.latitude, wrapper.longitude];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:titleString message:msgString delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];

    [alert show];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    
}


- (IBAction)flushAction:(id)sender {
    NSLog(@"Flush pressed");
    [self alert:@"Flushed cache!"];
    [JsonPoco jsonFlush];
    [self.refs removeAllObjects];
    self.refs = nil;
    [self.tableView reloadData];
    [self.view setBackgroundColor:[UIColor grayColor]];
    self.cacheStatusLabel.text= @"Empty";
    
    
}

- (IBAction)refreshAction:(id)sender {
    NSLog(@"Refresh pressed");
    [self alert:@"Refreshed!"];
    [self getData];
    [self.tableView reloadData];
    
    

}

- (IBAction)saveAction:(id)sender {
    [self alert:@"Saved"];
    [JsonPoco jsonStore];

}


-(void) getData{
    if ([JsonPoco jsonParse:self]) {
        [self.view setBackgroundColor:[UIColor redColor]];
        self.cacheStatusLabel.text= @"Using Cached";
        
    }else{
        [self.view setBackgroundColor:[UIColor greenColor]];
        self.cacheStatusLabel.text= @"Using HTTP";
        
    }
}


-(void) addData:(RefWrapper*)data{
    if (!self.refs) {
        self.refs = [[NSMutableArray alloc] init]; 
    }
    
    [self.refs addObject:data];
    [self.tableView reloadData];
}

-(void) alert:(NSString*)alert{
    
    //Clear all previous unfininshed alerts
    for(UILabel* oldAnim in [self.view subviews]){
        if (oldAnim.tag==100) {
            [oldAnim removeFromSuperview];
        }
    }
    
    CGRect alertFrame = CGRectMake(25, 25, 140, 22);
    UILabel *alertLabel = [[UILabel alloc] initWithFrame:alertFrame];
    alertLabel.text=alert;
    alertLabel.tag= 100;
    alertLabel.alpha = 0.0f;
    [alertLabel setBackgroundColor:[UIColor greenColor]];
    [alertLabel sizeToFit];
    alertLabel.textAlignment= NSTextAlignmentCenter;
    
    [self.view addSubview:alertLabel];
    

    [UIView animateWithDuration:2.0
                     animations:^{
                         [alertLabel setAlpha:1.0f];
                         [alertLabel setCenter:CGPointMake(self.view.center.x,
                                                           self.view.center.y)];
                     }
                     completion:^(BOOL finished) {
                         [UIView animateWithDuration:2.0
                                          animations:^{
                                              [alertLabel setAlpha:0.0f];
                                              
                                          }
                                          completion:^(BOOL finished) {
                                              [alertLabel removeFromSuperview];
                                          }];

                     }];
    

    
    
    
}


@end
