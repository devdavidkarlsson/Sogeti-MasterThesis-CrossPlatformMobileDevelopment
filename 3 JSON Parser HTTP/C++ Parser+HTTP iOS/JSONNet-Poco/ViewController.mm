//ViewController.mm


#import "ViewController.h"


@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    int iterations = 1;
    for (int i = 0; i < iterations; i++) {
        ref = NetPoco::getRefListType();
        if (i < iterations - 1) delete ref;
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}


# pragma tableView:

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return 1;//Returns the no of sections in the tableview
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return ref->refs.size();
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
    

    std::list<RefType>::iterator it = ref->refs.begin();
    std::advance(it, indexPath.row);
    cell.textLabel.text =[NSString stringWithUTF8String: it->getName().c_str()];
    return cell;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    std::list<RefType>::iterator it = ref->refs.begin();
    std::advance(it, indexPath.row);
    NSString *titleString = [NSString stringWithFormat:@"%@ %@",
                             [NSString stringWithUTF8String:it->getNo().c_str()],
                             [NSString stringWithUTF8String:it->getName().c_str()
                              ]];

    NSString *msgString = [NSString stringWithFormat:@"Latitude:%f Longitude:%f",
                           it->getLocation()->getLatitude(),
                           it->getLocation()->getLongitude()];
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:titleString message:msgString delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil, nil];
    [alert show];
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    
}


@end
