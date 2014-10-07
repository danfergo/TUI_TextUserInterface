#include "tui/TextUserInterface.h"

using namespace tui;

int main(){
	Interface tuix("Hello World!", 75,30);
	PageMenu * m = new PageMenu("Main Menu");
	Page * page = new Page("My Page");
	m->addOption(page);
	tuix.setRoot(m);
	tuix.run();

	return 0;
}


