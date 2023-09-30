/* Final Project Milestone 5
Module: LibApp.h
Filename: LibApp.h
Version 1.0
Author	Kevin Gunawan
Revision History
-----------------------------------------------------------
Date      Reason
2023/August/1  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/


#ifndef LIBAPP_H
#define LIBAPP_H
#include <iostream>
#include "Menu.h"
#include "Lib.h"
#include "Streamable.h"
#include "Publication.h"
#include "Book.h"

namespace sdds {
	class LibApp {
		bool m_changed;
		Menu m_mainMenu;
		Menu m_exitMenu;
		char m_filename[SDDS_MAX_FILENAME + 1];
		Publication* m_PPA[SDDS_LIBRARY_CAPACITY];
		int m_NOLP;
		int m_LLRN;
		Menu m_publicationType;

		bool confirm(const char* message);
		void load();
		void save();
		int search(int search);
		void returnPub();

	public:
		LibApp(const char* fileName);
		~LibApp();

		void newPublication();
		void removePublication();
		void checkOutPub();
		void run();
		Publication* getPub(int libref);
	};
}
#endif // !LIBAPP_H
