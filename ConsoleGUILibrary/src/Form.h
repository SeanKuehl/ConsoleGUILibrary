#pragma once
#include <vector>
#include <iostream>


class Form
{
	//the whole thing is based around a large vector of chars
private:
	char formGrid[30][120];

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
		formGrid[1][5] = 'x';	//one is fathest left I can put it and I need to go four to the right
		formGrid[1][27] = 'x';
		formGrid[1][49] = 'x';
		formGrid[1][71] = 'x';
		formGrid[1][93] = 'x';
		formGrid[1][115] = 'x';
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

