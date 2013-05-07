// WARNING
//
// This file has been generated automatically by MonoDevelop to store outlets and
// actions made in the Xcode designer. If it is removed, they will be lost.
// Manual changes to this file may not be handled correctly.
//
using MonoTouch.Foundation;

namespace Prototype1
{
	[Register ("Prototype1ViewController")]
	partial class Prototype1ViewController
	{
		[Outlet]
		MonoTouch.UIKit.UITextField txtInput { get; set; }

		[Outlet]
		MonoTouch.UIKit.UIButton btnGo { get; set; }

		[Outlet]
		MonoTouch.UIKit.UITextView txtOutput { get; set; }

		[Action ("actionGo:")]
		partial void actionGo (MonoTouch.Foundation.NSObject sender);
		
		void ReleaseDesignerOutlets ()
		{
			if (txtInput != null) {
				txtInput.Dispose ();
				txtInput = null;
			}

			if (btnGo != null) {
				btnGo.Dispose ();
				btnGo = null;
			}

			if (txtOutput != null) {
				txtOutput.Dispose ();
				txtOutput = null;
			}
		}
	}
}
