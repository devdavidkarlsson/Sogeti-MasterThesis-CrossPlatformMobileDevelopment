//ViewController.mm
#import "ViewController.h"
#import "NativeTransform.h"
#import "CppTransform.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    self.txtInput.delegate=self;
}

- (BOOL)textFieldShouldReturn:(UITextField *)textField {
    [textField resignFirstResponder];
    return NO;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (IBAction)actionGo:(id)sender {
    [self.txtInput resignFirstResponder];
    //self.txtOutput.text = [NativeTransform transform:self.txtInput.text];
    self.txtOutput.text = [NSString stringWithUTF8String:NativeCpp::transform([self.txtInput.text UTF8String])];

}
@end
