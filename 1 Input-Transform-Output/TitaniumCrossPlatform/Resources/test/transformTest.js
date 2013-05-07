//transformTest.js
Ti.include("../ui/common/transform.js");

// Override the junity log function:
Ti.include("jsunity-0.6.js");
jsUnity.log = function(message){
	Ti.API.info(message);
}

// Test suite
var transformTestSuite = {
	suiteName: "Transform Test Suite",
	setUp: function(){
		jsUnity.log("set up");
	},
	
	tearDown: function(){
		jsUnity.log("tear down");
	},
	
	testQuery: function() {
		jsUnity.log("Transformation Test:");
		var input = "sirap";
		var output = String.prototype.transform(input);
		jsUnity.assertions.assertTrue(output=="paris");
   },
   	
   	testQueryPerformance: function() {
	jsUnity.log("Transformation Performance Test:");
	var input = "sirap";
	var start,stop, executionTime;
	for(var j = 0; j<100; j++ ){
		start = +new Date().getTime();
		for(var i = 0; i < 10000; i++){
			var output = String.prototype.transform(input);
			
		}
		stop = +new Date().getTime();
    	executionTime = (stop - start);
    	jsUnity.log("Execution time: "  + executionTime+ " Milliseconds");
  }	
	jsUnity.assertions.assertNotNaN(executionTime);
   }
   
   
	
};

Titanium.UI.currentWindow.addEventListener(
    'focus',
    function(e) {
        jsUnity.run(transformTestSuite);
});
