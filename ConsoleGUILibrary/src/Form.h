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

class Form
{
	//the whole thing is based around a large vector of chars
private:
	char formGrid[formHieght][formWidth];
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

public:

	Form() {
		InitializeGrid();
		BasicGrid();
	}

	Form(std::string title, std::string text) {
		//this is for a text form. It will use centered text for the title
		//and will put down the text as it is
		int firstLineMiddle = functionalFormWidth / 2;
		//see centered text in vase component
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
			xPos = cell - ((yPos * 5)) -1;
			if (xPos == 5) {
				xPos -= 1;	//this is for those like 10, 15 and 20
			}
		}
		else {
			xPos = cell - 1;
		}

		return xPos;
	}

	void AddComponents() {
		//go through list of comps, add them to formGrid based on coords
		for (BaseComponent bc : componentList) {

		}
	}

	void AddBorderedText(std::string text, char border, int cell) {
		//componentList.push_back(BaseComponent())
	}

	void SetCell(int cell) {
		//this will be a part of putting objects on the screen
		int yPos = firstComponentYCoord + (cellHieght *GetYPosition(cell));
		int xPos = firstComponentXCoord + (cellWidth *GetXPosition(cell, GetYPosition(cell)));
		/*int yPos =  GetYPosition(cell);
		int xPos = GetXPosition(cell, yPos);*/
		BaseComponent b = BaseComponent(xPos, yPos);
		b.CenteredText("hello there");

		//this is the x and y pos of the top left of the cell
		//std::cout << xPos << "  " << yPos << "  " << cell << "\n";
		formGrid[yPos][xPos] = 'x';
		formGrid[yPos + 5][xPos] = 'x';
		formGrid[yPos][xPos + 20] = 'x';
		formGrid[yPos + 5][xPos + 20] = 'x';
		
			
		/*int topLeftX = 27;
		int topLeftY = 1;
		formGrid[topLeftY][topLeftX] = 'x';
		formGrid[topLeftY+5][topLeftX] = 'x';
		formGrid[topLeftY][topLeftX+20] = 'x';
		formGrid[topLeftY + 5][topLeftX+20] = 'x';

		topLeftX = 5;
		topLeftY = 1;
		formGrid[topLeftY][topLeftX] = 'x';
		formGrid[topLeftY + 5][topLeftX] = 'x';
		formGrid[topLeftY][topLeftX + 20] = 'x';
		formGrid[topLeftY + 5][topLeftX + 20] = 'x';*/
	}

	void ShowGrid() {
		for (int y = 0; y < 30; y++) {
			
			for (int x = 0; x < 120; x++) {
				std::cout << formGrid[y][x];	//print the item in the list
				//no need for a \n because it gets to the end of the line and automaticaaly wraps
			}
			
		}
	}

	void AddButton() {

	}

	void AddText() {

	}

	void AddList() {
		//stretches across cells vertically with text only
	}

};

