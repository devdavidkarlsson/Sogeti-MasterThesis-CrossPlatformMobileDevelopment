//FirstView.js

//FirstView Component Constructor
Ti.include("/ui/common/transform.js");
function FirstView() {
	//create object instance, a parasitic subclass of Observable
	var self = Ti.UI.createView();
	
	//label using localization-ready strings from <app dir>/i18n/en/strings.xml
// Custom View
var view0 = Titanium.UI.createView({
    left: 0,
    top: 0,
    width: 320,
    height: 460,
    backgroundColor: '#ffffff'
});

var view1 = Titanium.UI.createView({
    width: 320,
    height: 460,
    backgroundColor: '#ffffff'
});

var imageView2 = Titanium.UI.createImageView({
	image: '/images/prototype1_bg.png',
    left: -2,
    top: -5,
    width: Ti.Platform.displayCaps.platformWidth,
    height: Ti.Platform.displayCaps.platformHeight,
    contentMode: 'aspectfill'
});
view1.add(imageView2);

var button3 = Titanium.UI.createButton({
    left: 101,
    top: 230,
    width: 117,
    height: 44,
    title: 'Go',
    color: '#000000',
    font: {fontFamily: 'Helvetica-Bold', fontSize: 15}
});
button3.addEventListener('click', function()
{
    ta6.value = String.prototype.transform(tf4.value);
});
view1.add(button3);

var tf4 = Titanium.UI.createTextField({
    borderStyle: Titanium.UI.INPUT_BORDERSTYLE_ROUNDED,
    left: 101,
    top: 108,
    width: 117,
    height: 30,
    value: '',
    color: '#000000',
    font: {fontFamily: 'Helvetica', fontSize: 14}
});
view1.add(tf4);

var l5 = Titanium.UI.createLabel({
    left: 26,
    top: 111,
    width: 73,
    height: 21,
    text: 'Input',
    font: {fontFamily: 'Helvetica-Bold', fontSize: 19}
});
view1.add(l5);

var ta6 = Titanium.UI.createTextArea({
    left: 98,
    top: 361,
    width: 117,
    height: 47,
    backgroundColor: '#ffffff',
    value: '#'
});
view1.add(ta6);

var l7 = Titanium.UI.createLabel({
    left: -2,
    top: 241,
    width: 101,
    height: 21,
    text: 'Transform'
});
view1.add(l7);

var l8 = Titanium.UI.createLabel({
    left: 20,
    top: 374,
    width: 73,
    height: 21,
    text: 'Output'
});
view1.add(l8);

var imageView9 = Titanium.UI.createImageView({
	image:'/images/arrow.png',
    left: 98,
    top: 139,
    width: 120,
    height: 88
});
view1.add(imageView9);

var imageView10 = Titanium.UI.createImageView({
	image: '/images/arrow.png',
    left: 100,
    top: 274,
    width: 120,
    height: 88
});
view1.add(imageView10);
view0.add(view1);
self.add(view0);
return self;
}

module.exports = FirstView;
