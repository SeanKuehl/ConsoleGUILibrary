#include "Form.h"

create a new form: Form f = Form();

form is organized into cells from 1-20

add bordered text: f.AddBorderedText(std::string, char, cellNumber);

to add a cell where every line has text on it:
f.AddMultiText("hello");
f.AddMultiText("hello");
f.AddMultiText("hello");
f.AddMultiText("hello");
f.AddMultiText("hello");
f.AddMultiText("hello");
f.AddMultiText("hello");

there are seven spaces for text in each cell

f.CreateMultiText(cellNumber); create the text at the given cell


how to create a form with just plain text on it:
f.AddFormTitle("sup buddy");	this will be the first line of text
f.AddFormText("I am here and I might just exist in this ethereal plane");
f.AddFormText("this is where I live I think");
f.AddFormText("hey buday");
you can add up to 28 lines of text to the form including the title
f.CreateTextForm(); put the text on the form

how to add just a single line of text without border:
f.AddText(std::string, cellNumber);


how to show form to the screen:
f.ShowForm();