#pragma once
#include <string>
#include <iostream>

#define cellHieght 7	//this includes the borders
#define cellWidth 22	//this includes the borders
#define formWidth 120
#define formHieght 30

class BaseComponent
{
	//this will take in the component's cell and set up some basic
	//functionality that most component's will use like text centering etc.

public:
	int topLeftX = 0;

	int topLeftY = 0;

	

	char charList[cellHieght][cellWidth];

	BaseComponent(int x, int y) {
		//think about what I'll need when adding charList contents to main form
		InitializeList();
		topLeftX = x;
		topLeftY = y;
	}

	void InitializeList() {
		for (int y = 0; y < cellHieght; y++) {
			for (int x = 0; x < cellWidth; x++) {
				charList[y][x] = ' ';
			}
		}
	}

	void FillBorder(char c) {
		//works
		for (int y = 0; y < cellHieght; y++) {
			for (int x = 0; x < cellWidth; x++) {
				if (y == 0) {
					//this is the top border
					charList[y][x] = c;
				}
				else if (y == (cellHieght - 1)) {
					//this is the bottom border
					charList[y][x] = c;
				}
				else if (x == 0 || x == (cellWidth - 1)) {
					//this is the side border
					charList[y][x] = c;
				}
			}
		}
	}

	void CenteredText(std::string str) {
		//works
		

		//working with 20 functional chars
		//find the functional center of the string and put it on the charList's middle line
		int centerX = 11;	//keep in mind the border is the first character
		int centerY = 3;
		int stringSize = str.size();
		int startPoint = centerX - (stringSize / 2);
		int counter = 0;



		for (int i = startPoint; i < (startPoint + (stringSize)); i++) {
			charList[centerY][i] = str[counter];
			std::cout << charList[centerY][i] << i << "\n";
			counter++;
		}

	}

	void ShowComponent() {
		for (int y = 0; y < cellHieght; y++) {
			std::cout << "\n";
			for (int x = 0; x < cellWidth; x++) {
				std::cout << charList[y][x];
			}
		}
	}
	
private:
	
	
	

	

};

