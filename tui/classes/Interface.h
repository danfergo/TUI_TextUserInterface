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

#include "Page.h"

namespace tui{
	class Page;

	/**
	 * Main class, interface.
	 */
	class Interface {
	public:

	private:
		Page * root;
		bool running;
		std::string title;
		unsigned cols, rows;
	public:
		Interface(std::string title,unsigned cols, unsigned rows);
		virtual ~Interface();

		void setCols(unsigned cols);
		void setRows(unsigned rows);
		Page * setRoot(Page * root);
		void run();
		void pause();
		virtual void display();
	};
}
#endif /* TUINTERFACE_H_ */
