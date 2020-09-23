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
	/*Form f = Form();
	
	f.SetCell(1);
	

	f.ShowGrid();*/
	BaseComponent b = BaseComponent(5, 1);
	b.CenteredText("hello there");
	b.FillBorder('x');
	b.ShowComponent();

	return 0;
}