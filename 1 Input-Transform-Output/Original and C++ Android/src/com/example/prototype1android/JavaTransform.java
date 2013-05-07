//JavaTransform.java
package com.example.prototype1android;


public class JavaTransform {
	public static String transform (String input)
	{
		StringBuilder output= new StringBuilder();
		char[] tmp = input.toCharArray();
		
		for (int i = input.length() - 1; i >= 0; i--)
		{
			output = output.append(tmp[i]);
		}
		return output.toString();
	}
}
