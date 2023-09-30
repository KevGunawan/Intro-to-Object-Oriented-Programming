/* Final Project Milestone 5
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
namespace sdds {
	class Menu;

	class MenuItem {
		friend class Menu;
		char* m_content;

		MenuItem(const char* content);
		MenuItem(const MenuItem& other) = delete;
		MenuItem& operator = (const MenuItem& other) = delete;
		~MenuItem();
		operator bool() const;
		operator const char* () const;
		void displayContent(std::ostream& os) const;
	};

	class Menu {
		static const unsigned int MAX_MENU_ITEMS = 20;
		char* title;
		MenuItem* items[MAX_MENU_ITEMS];
		unsigned int itemCount;

	public:
		Menu(const Menu& other) = delete;
		Menu& operator =(const Menu& other) = delete;
		Menu();
		Menu(const char* menuTitle);
		~Menu();
		
		void displayTitle() const;
		void displayMenu() const;
		unsigned int run();
		unsigned int operator~() const;
		Menu& operator<<(const char* menuItemContent);
		operator int() const;
		operator unsigned int() const;
		operator bool() const;
		const char* operator[](unsigned int index) const;
		friend std::ostream& operator<<(std::ostream& os, Menu& menu);		
	};
	std::ostream& operator<<(std::ostream& os, Menu& menu);
}


#endif
