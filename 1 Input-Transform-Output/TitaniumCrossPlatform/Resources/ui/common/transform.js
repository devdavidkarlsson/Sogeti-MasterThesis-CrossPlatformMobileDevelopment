//transform.js

//Override string prototype reverse:
String.prototype.transform = function(input) {
    var output = "";
    for (var i = input.length - 1; i >= 0; i--)
	{		
		output = output + input[i];
	}
	return output;
}
       


