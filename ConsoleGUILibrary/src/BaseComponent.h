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

	void FillWithText(std::string firstLine, std::string secondLine, std::string thirdLine, std::string fourthLine, std::string fifthLine, std::string sixthLine, std::string seventhLine) {
		std::string lineList[] = { firstLine, secondLine, thirdLine, fourthLine, fifthLine, sixthLine, seventhLine };
		int centerX = cellWidth / 2;	//keep in mind the border is the first character
		int centerY = 0;	//increment at end
		int stringSize = 0;
		int startPoint = 0;
		int counter = 0;
		int numberOfLines = cellHieght;
		std::string str;

		//before we begin, check that all the lengths of the texts will fit, 22 chars or less
		for (int i = 0; i < numberOfLines; i++) {
			try {
				if (lineList[i].size() > 22) {
					throw lineList[i];
				}
			}
			catch (std::string str) {
				std::cout << "an exception occured: " << str << " is longer than 22 chars.\n";
			}
		}



		for (int i = 0; i < numberOfLines; i++) {
			str = lineList[i];
			stringSize = str.size();
			startPoint = centerX - (stringSize / 2);
			centerY = i;
			counter = 0;
			
			for (int i = startPoint; i < (startPoint + (stringSize)); i++) {
				charList[centerY][i] = str[counter];
				//std::cout << charList[centerY][i] << i << "\n";
				counter++;
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
			//std::cout << charList[centerY][i] << i << "\n";
			counter++;
		}

	}

	
	

private:
	void InitializeList() {
		for (int y = 0; y < cellHieght; y++) {
			for (int x = 0; x < cellWidth; x++) {
				charList[y][x] = ' ';
			}
		}
	}
	
	

	

};

