/*
 * TUInterface.cpp
 *
 *  Created on: 04/10/2014
 *      Author: Daniel
 */

#include "TUInterface.h"
#include <stdlib.h>
#include <iostream>
#include <deque>

TUInterface::TUInterface(std::string title,unsigned cols, unsigned rows):root(new Page()), running(false), title(title), cols(cols), rows(rows){


}

/*
TUInterface::TUInterface(std::string,unsigned cols, unsigned rows): root(new Page()),running(false) {

}
*/
TUInterface::~TUInterface() {

}

void TUInterface::setCols(unsigned cols){
	this->cols = cols;
}
void TUInterface::setRows(unsigned rows){
	this->rows = rows;
}


void TUInterface::run(){
	running = true;
	std::string input;
	while(running){
		display();
		getline(std::cin, input);
		root->preInputHandler(input,this,NULL);
	}
}

void TUInterface::pause(){
	running = 0;
}




void TUInterface::display(){
	std::deque<Page *> activeChain = root->getActiveChain();
	std::vector<std::string> activePageContent = activeChain.front()->display();
	unsigned i = 0;
	std::string screen;



	for(std::vector<std::string>::iterator it = activePageContent.begin();
			it!=activePageContent.end(); it++){
		screen += "|" + (*it) + "                                        |\n";
		if(i == 49) break;
		i++;
	}
	std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << screen;
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << "TO do bla bla, press X" << std::endl;
	std::cout << "prompt~>";
}
