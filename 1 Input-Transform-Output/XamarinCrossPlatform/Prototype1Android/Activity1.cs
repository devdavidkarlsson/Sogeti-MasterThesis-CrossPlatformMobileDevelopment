//Activity1.cs
using System;

using Android.App;
using Android.Content;
using Android.Runtime;
using Android.Views;
using Android.Widget;
using Android.OS;
using Java.Interop;

namespace Prototype1
{
	[Activity (Label = "Prototype1Android", MainLauncher=true)]
	public class Activity1 : Activity
	{

		protected override void OnCreate (Bundle bundle)
		{
			base.OnCreate (bundle);

			// Set our view from the "main" layout resource
			base.RequestWindowFeature(WindowFeatures.NoTitle);
			SetContentView (Resource.Layout.Main);

			// Get our button from the layout resource,
			// and attach an event to it if not defined
			// in Main.axml:
			//
			//Button btnGo= FindViewById<Button>(Resource.Id.btnGo);
			//btnGo.Click += actionGo;
		}

		[Export]
		public void actionGo (View v) //(object sender, EventArgs e)
		{
			TextView txtInput = FindViewById<TextView>(Resource.Id.txtInput);
			TextView txtOutput = FindViewById<TextView>(Resource.Id.txtOutput);
			txtInput.ClearFocus();
			txtOutput.Text =(CSharpTransform.transform(txtInput.Text.ToString()));
			//TEST:
			for (var j=0; j<100; j++) {
				var start = DateTime.Now;
				for (var i =0; i< 10000; i++) {
					String output = CSharpTransform.transform ("sirap");
				}
				var stop = DateTime.Now;
				var executionTime = stop - start;
				Console.WriteLine (executionTime.TotalMilliseconds);
			}
		}

	}
}


