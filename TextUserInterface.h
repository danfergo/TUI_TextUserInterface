/*
 * TextUserInterface.h
 *
 *  Created on: 04/11/2013
 *      author: Daniel Gomes
 *      e-mail: up201306839@fe.up.pt
 *
 */

#ifndef TEXTUSERINTERFACE_H_
#define TEXTUSERINTERFACE_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

class TextUserInterface {
public:
	const enum Alignment {LEFT, CENTER, RIGHT};
private:
	unsigned int width;
	unsigned int height;
	std::string title;
	void clearScreen();
public:
	TextUserInterface(std::string title, unsigned int width, unsigned int height);
	int getWidth() {
		return width;
	}
	static std::vector<std::string> strsplit(std::string str, std::string sep);
	static std::string printLine(int size, char c);
	static std::string printTextLine(std::string text, Alignment align, unsigned size);

	std::string print(std::string output, Alignment align = LEFT, std::string msg = "", bool menu = false);
	int printInt(std::string output, std::string msg, int min, int max, Alignment align = LEFT);
	float printFloat(std::string output, std::string msg, float min, float max, Alignment align = LEFT);
	void printEnd(std::string output, Alignment align = LEFT);
	int printMenu(std::string menu, bool err = false);
};


#endif /* TEXTUSERINTERFACE_H_ */
