//CSharpTransformTest.cs
using System;
using NUnit.Framework;
using Prototype1;

namespace Prototype1Test
{
	[TestFixture]
	public class CSharpTransformTest
	{
		[Test]
		public void Pass ()
		{
			String output=CSharpTransform.transform("Abc123");
			Assert.True (output.Equals(output));
		}

		[Test]
		public void Fail ()
		{
			String output=CSharpTransform.transform("Abc123");
			Assert.False (output.Equals("321bA"));
		}

		[Test]
		public void QueryPerformance ()
		{
			for (var j=0; j<100; j++) {
				var start = DateTime.Now;
				for (var i =0; i< 10000; i++) {
					String output = CSharpTransform.transform ("sirap");
				}
				var stop = DateTime.Now;
				var executionTime = stop - start;
				Console.WriteLine (executionTime.TotalMilliseconds);
			}
			Assert.True (true);
		}

	}
}
