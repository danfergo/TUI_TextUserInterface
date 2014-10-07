#include "Page.h"

unsigned tui::Page::pageIdCounter = 0;

 tui::Page::Page(std::string title): id(++pageIdCounter),
		 activeChild(NULL), title(title){
}

tui::Page::~Page(){

}

void tui::Page::setTitle(std::string title){
	this->title = title;
}
std::string tui::Page::getTitle() const{
	return this->title;
}


bool tui::Page::preInputHandler(std::string input, Interface * interface,Page * parent){
	if(!inputHandler(input,interface,parent) && activeChild){
		return activeChild->preInputHandler(input,interface,this);
	}
	return false;
}


bool tui::Page::inputHandler(std::string input, Interface * interface,Page * parent){
	if(input == "\\quit"){
		interface->pause();
		return true;
	}

	return false;
}

std::deque <tui::Page *> tui::Page::getActiveChain(){
	std::deque<Page *> activeChain;
	if(activeChild){
		activeChain = activeChild->getActiveChain();
	}
	activeChain.push_front(this);
	return activeChain;
}


std::vector<std::string> tui::Page::display(){
	std::vector<std::string> show;
	show.push_back(" ");
	show.push_back("             Text User Interface");
	show.push_back("                             by Danfergo");
	show.push_back("source code and wiki at:");
	show.push_back("github /danfergo/TextUserInterface");
	return show;
}

void tui::Page::addChild(tui::Page * page){
	this->children.push_back(page);
}
void tui::Page::addActiveChild(tui::Page * page){
	this->children.push_back(page);
	activeChild = page;
}



