//ViewController.m

#import "ViewController.h"
#import <YAJLiOS/YAJL.h>
#import "RefType.h"
#import "LocationType.h"
#include <sys/time.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    //Get parsing data:
    NSString *filePath = [[NSBundle mainBundle] pathForResource:@"se_sv_capitals" ofType:@"json"];

    NSData* data = [NSData dataWithContentsOfFile:filePath];
    jsonComplex = [[JSONType alloc] init];
    
    NSDate *start, *end;
    start = [NSDate date];
    for (int i = 0; i<100; i++) {
        start = [NSDate date];
        [jsonComplex parseTest:data];
        end = [NSDate date];
        NSTimeInterval executionTime = ([end timeIntervalSinceDate:start]*1000) ;
        NSLog(@"Execution Time: %f", executionTime);
    }

    NSLog(@"%d", jsonComplex.refList.refs.count);

    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}



# pragma tableView:

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;//Returns the no of sections in the tableview
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return jsonComplex.refList.refs.count/100;
    //Returns the no of rows in the tableview, parsing has been performed 100 times!
}

//This method is called everytime when a row is created.
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *simpleTableIdentifier = @"SimpleTableItem";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:simpleTableIdentifier];
    
    if (cell == nil) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:simpleTableIdentifier];
    }
    RefType *ref= [jsonComplex.refList.refs objectAtIndex:indexPath.row];
    cell.textLabel.text =ref.mName;
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    RefType *ref = [jsonComplex.refList.refs objectAtIndex:indexPath.row];
    NSString *titleString = [NSString stringWithFormat:@"%@ %@", ref.mNo, ref.mName];
    NSString *msgString = [NSString stringWithFormat:@"Latitude:%@ Longitude:%@",
                          ref.mLocation.latitude, ref.mLocation.longitude];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:titleString message:msgString delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alert show];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}



@end
