/*
 * TUInterface.h
 *
 *  Created on: 04/10/2014
 *      Author: Daniel
 */

#ifndef TUINTERFACE_H_
#define TUINTERFACE_H_

#include <vector>
#include <string>
#include <deque>
#include <map>

class TUInterface {
public:
	class Page{
	private:
		std::map<std::string,Page *> children;
		Page * activeChild;
		std::vector<std::string> content;
	public:
		Page();
		virtual bool preInputHandler(std::string input, TUInterface * interface,Page * parent);
		virtual bool inputHandler(std::string input, TUInterface * interface,Page * parent);
		virtual std::vector<std::string> display();
		std::deque <Page *> getActiveChain();
	};
private:
	Page * root;
	bool running;
	std::string title;
	unsigned cols, rows;
public:
	TUInterface(std::string title,unsigned cols, unsigned rows);
	virtual ~TUInterface();

	void setCols(unsigned cols);
	void setRows(unsigned rows);

	void run();
	void pause();
	virtual void display();
};

#endif /* TUINTERFACE_H_ */
