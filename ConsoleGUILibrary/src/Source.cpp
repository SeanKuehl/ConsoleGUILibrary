#include <iostream>
#include "Form.h"
#include "BaseComponent.h"

int main() {
	//max width is 120 '-'
	//max hieght before needing scrolling is 28 (including top and bottom things)
	//every letter is a symbol in length
	
	//divide each 'screen' into slots that can be used by single elements
	//or larger elements can be strung across multiple, a borderline idea
	//a 'button' is surrounded like a box, a text box doesn't have that etc
	int x;
	Form f = Form();
	
	//f.AddBorderedText("scott lee kuehl", 'w', 8);
	/*f.AddMultiText("hello");
	f.AddMultiText("hello");
	f.AddMultiText("hello");
	f.AddMultiText("hello");
	f.AddMultiText("hello");
	f.AddMultiText("hello");
	f.AddMultiText("hello");
	f.CreateMultiText(10);*/

	/*f.AddFormTitle("sup buddy");
	f.AddFormText("I am here and I might just exist in this ethereal plane");
	f.AddFormText("this is where I live I think");
	f.AddFormText("hey buday");
	f.CreateTextForm();*/

	//addformtext, addformtitle, createtextform
	

	f.ShowForm();
	std::cin >> x;
	

	return 0;
}