// WARNING
// This file has been generated automatically by MonoDevelop to
// mirror C# types. Changes in this file made by drag-connecting
// from the UI designer will be synchronized back to C#, but
// more complex manual changes may not transfer correctly.


#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>


@interface Prototype1ViewController : UIViewController {
	UITextField *_txtInput;
	UIButton *_btnGo;
	UITextView *_txtOutput;
}

@property (nonatomic, retain) IBOutlet UITextField *txtInput;

@property (nonatomic, retain) IBOutlet UIButton *btnGo;

@property (nonatomic, retain) IBOutlet UITextView *txtOutput;

- (IBAction)actionGo:(id)sender;
-(void) TellTime;
@end
