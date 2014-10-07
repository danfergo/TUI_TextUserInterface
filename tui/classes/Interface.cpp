/*
 * TUInterface.cpp
 *
 *  Created on: 04/10/2014
 *      Author: Daniel
 */

#include "Interface.h"
#include <iostream>

tui::Interface::Interface(std::string title,unsigned cols, unsigned rows):root(new Page(title)), running(false), title(title), cols(cols), rows(rows){


}

tui::Interface::~Interface() {

}

void tui::Interface::setCols(unsigned cols){
	this->cols = cols;
}
void tui::Interface::setRows(unsigned rows){
	this->rows = rows;
}

tui::Page * tui::Interface::setRoot(Page * root){
	Page * current = this->root;
	this->root = root;
	return current;
}


void tui::Interface::run(){
	running = true;
	std::string input;
	while(running){
		display();
		getline(std::cin, input);
		root->preInputHandler(input,this,NULL);
	}
}

void tui::Interface::pause(){
	running = 0;
}




void tui::Interface::display(){
	std::deque<Page *> activeChain = root->getActiveChain();
	std::vector<std::string> activePageContent = activeChain.front()->display();
	unsigned i = 0;
	std::string screen;
	try{
		std::cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << std::endl;
	}catch(...){}

	for(std::deque<Page *>::iterator it = activeChain.begin();
			it!=activeChain.end(); it++){
		if((*it)->getTitle() != ""){
			if(it == activeChain.begin()){
				std::cout << (*it)->getTitle() ;
			}else
				std::cout << " -> " << (*it)->getTitle() ;

		}

	}
	std::cout << "\n";



	for(std::vector<std::string>::iterator it = activePageContent.begin();
			it!=activePageContent.end(); it++){
		screen += "|" + (*it) + "                                        |\n";
		if(i == 49) break;
		i++;
	}
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << screen;
	std::cout << "+----------------------------------------------+" << std::endl;
	std::cout << "TO do bla bla, press X" << std::endl;
	std::cout << "prompt~>";
}
