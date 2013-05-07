//Application Window Component Constructor
var test=1;

function ApplicationWindow() {
	//load component dependencies
	var FirstView = require('ui/common/FirstView');
		
	//create component instance
	if(test=0){
		var self = Ti.UI.createWindow({
			backgroundColor:'#ffffff'
		});
	}else{
		var self = Ti.UI.createWindow({
			url: "test/transformTest.js",
			title: "Transform Unit Test"
		});
	}	
	//construct UI
	var firstView = new FirstView();
	self.add(firstView);
	
	return self;
}

//make constructor function the public component interface
module.exports = ApplicationWindow;
