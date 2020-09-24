#pragma once
#include <vector>
#include <string>
#include <iostream>
#include "BaseComponent.h"
#define firstComponentYCoord 1
#define firstComponentXCoord 5
#define formHieght 30
#define formWidth 120
#define cellHieght 7
#define cellWidth 22
#define functionalFormWidth 118
#define formMiddle 60
#define firstYCoordAfterTitle 2

class Form
{
	//the whole thing is based around a large vector of chars
private:
	char formGrid[formHieght][formWidth];
	std::vector<std::string> bodyText;	//this is if the user wants a mainly text form
	std::vector<std::string> multiTextComponent;
	std::string title;	//this is if the user wants a mainly text form
	std::vector<BaseComponent> componentList;
	//I'll have a list of components and I'll add them all from their attributes
	//when the form is loaded

	void BasicGrid() {
		for (int i = 0; i < 120; i++) {
			formGrid[0][i] = '-';	//create the roof of the form
			formGrid[29][i] = '-';	//create the bottom of the form
		}

		
		for (int i = 1; i < 29; i++) {
			formGrid[i][0] = '|';	//create the sides of the form keeping in mind the top and bottom
			formGrid[i][119] = '|';
		}

		//horizontally it starts at five an increases by 22
		//vertically it starts at one and increses by 5
		//formGrid[1][5] = 'x';	//one is fathest left I can put it and I need to go four to the right
		//formGrid[1][27] = 'x';
		//formGrid[1][49] = 'x';
		//formGrid[1][71] = 'x';
		//formGrid[1][93] = 'x';
		//formGrid[1][115] = 'x';
		/*formGrid[6][5] = 'x';
		formGrid[6][27] = 'x';*/

		/*formGrid[7][5] = 'x';
		formGrid[7][27] = 'x';
		formGrid[12][5] = 'x';
		formGrid[12][27] = 'x';*/
		//the cell size is 7 vertically, but the edge is a part of that so the
		//functional size is 5


	}

	void InitializeGrid() {
		for (int y = 0; y < 30; y++) {
			std::cout << "\n";	//go to the next row
			for (int x = 0; x < 120; x++) {
				formGrid[y][x] = ' ';	//initialize the values in the grids
			}
		}
	}

	int GetYPosition(int cell) {
		int yPos = 0;

		while (cell > 5) {
			cell -= 5;	//the more 5s you can take away, the lower the row it's in
			yPos++;
		}

		return yPos;
	}

	int GetXPosition(int cell, int yPos) {
		int xPos = 0;

		//to get xpos on first row, take one away from all, on next row it's five, on third it's ten, on fourth it's 15
		if (cell > 5) {
			xPos = cell - ((yPos * 5)) - 1;
			if (xPos == 5) {
				xPos -= 1;	//this is for those like 10, 15 and 20
			}
		}
		else {
			xPos = cell - 1;
		}

		return xPos;
	}

public:

	Form() {
		InitializeGrid();
		BasicGrid();
	}

	

	

	void AddFormTitle(std::string text) {
		title = text;
	}

	void AddFormText(std::string text) {
		bodyText.push_back(text);
	}

	void CreateTextForm() {
		//takes stuff done in addtitle and addformtext and puts them on the screen
		//formMiddle is a precompiler var already
		
		//first align the title
		AlignFormTitle(title);
		//then keep aligning text lines until you run out of them

		//bodyText
		int centerX = formMiddle;	//keep in mind the border is the first character
		int centerY = firstComponentYCoord;	//because title already occupies the top
		int stringSize = 0;
		int startPoint = 0;
		int counter = 0;
		int numberOfLines = bodyText.size();
		std::string str;

		

		for (int i = firstYCoordAfterTitle; i < numberOfLines+ firstYCoordAfterTitle; i++) {
			//i starts at one because the title occupies the top spot, that being one
			
			str = bodyText[i- firstYCoordAfterTitle];	//offset i so it's the same if i started at 0
			stringSize = str.size();
			startPoint = centerX - (stringSize / 2);
			centerY = i;
			counter = 0;

			for (int i = startPoint; i < (startPoint + (stringSize)); i++) {
				formGrid[centerY][i] = str[counter];
				//std::cout << charList[centerY][i] << i << "\n";
				counter++;
			}


		}

		
	}

	void AlignFormTitle(std::string title) {
		//works


		
		//find the functional center of the string and put it on the charList's middle line
		int centerX = formMiddle;	//keep in mind the border is the first character
		int centerY = firstComponentYCoord;
		int stringSize = title.size();
		int startPoint = centerX - (stringSize / 2);
		int counter = 0;



		for (int i = startPoint; i < (startPoint + (stringSize)); i++) {
			formGrid[centerY][i] = title[counter];
			//std::cout << charList[centerY][i] << i << "\n";
			counter++;
		}
	}

	

	void AddComponents() {
		//go through list of comps, add them to formGrid based on coords
		int startingX = 0;
		int startingY = 0;
		for (BaseComponent bc : componentList) {
			startingX = bc.topLeftX;
			startingY = bc.topLeftY;
			//bc.charList, formGrid
			//another for loop that adds to both nums in both places in both lists
			for (int y = 0; y < cellHieght; y++) {
				for (int x = 0; x < cellWidth; x++) {
					formGrid[startingY+y][startingX+x] = bc.charList[0+y][0+x];
				}
			}
			
		}
	}

	void AddBorderedText(std::string text, char border, int cell) {
		//this will be a part of putting objects on the screen
		int yPos = firstComponentYCoord + (cellHieght * GetYPosition(cell));
		int xPos = firstComponentXCoord + (cellWidth * GetXPosition(cell, GetYPosition(cell)));
		BaseComponent b = BaseComponent(xPos, yPos);
		b.CenteredText(text);
		b.FillBorder(border);
		componentList.push_back(b);
		AddComponents();
		
	}

	void AddText(std::string text, int cell) {
		//this will be a part of putting objects on the screen
		int yPos = firstComponentYCoord + (cellHieght * GetYPosition(cell));
		int xPos = firstComponentXCoord + (cellWidth * GetXPosition(cell, GetYPosition(cell)));
		BaseComponent b = BaseComponent(xPos, yPos);
		b.CenteredText(text);
		
		componentList.push_back(b);
		AddComponents();
	}

	void AddMultiText(std::string text) {
		multiTextComponent.push_back(text);

	}

	void CreateMultiText(int cell) {
		//this will be a part of putting objects on the screen
		std::vector<std::string> setter;
		int yPos = firstComponentYCoord + (cellHieght * GetYPosition(cell));
		int xPos = firstComponentXCoord + (cellWidth * GetXPosition(cell, GetYPosition(cell)));
		BaseComponent b = BaseComponent(xPos, yPos);
		b.FillWithText(multiTextComponent[0], multiTextComponent[1], multiTextComponent[2], multiTextComponent[3], multiTextComponent[4], multiTextComponent[5], multiTextComponent[6]);

		componentList.push_back(b);
		AddComponents();
		multiTextComponent = setter;	//clear it for the next component
	}

	

	void ShowForm() {
		for (int y = 0; y < 30; y++) {
			
			for (int x = 0; x < 120; x++) {
				std::cout << formGrid[y][x];	//print the item in the list
				//no need for a \n because it gets to the end of the line and automaticaaly wraps
			}
			
		}
	}

	

};

