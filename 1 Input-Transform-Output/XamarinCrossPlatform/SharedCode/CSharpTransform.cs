//CSharpTransform.cs
using System;

namespace Prototype1
{
	public static class CSharpTransform
	{
		public static String transform (String input)
		{
			String output= null;
			for (int i = input.Length - 1; i >= 0; i--)
			{
				
				output = output + input[i];
			}
			return output;
		}


	}
}

