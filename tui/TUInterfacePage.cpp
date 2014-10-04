#include "TUInterface.h"

#include <iostream>


TUInterface::Page::Page():activeChild(NULL){


}

bool TUInterface::Page::preInputHandler(std::string input, TUInterface * interface,Page * parent){
	if(!inputHandler(input,interface,parent) && activeChild){
		return activeChild->preInputHandler(input,interface,this);
	}
	return false;
}


bool TUInterface::Page::inputHandler(std::string input, TUInterface * interface,Page * parent){
	if(input == "\\quit"){
		interface->pause();
		return true;
	}

	return false;
}

std::deque <TUInterface::Page *> TUInterface::Page::getActiveChain(){
	std::deque<Page *> activeChain;
	if(activeChild){
		activeChain = activeChild->getActiveChain();
	}
	activeChain.push_front(this);
	return activeChain;
}


std::vector<std::string> TUInterface::Page::display(){
	std::vector<std::string> show;
	show.push_back("Line 1");
	show.push_back("Line 2");
	return show;
}



