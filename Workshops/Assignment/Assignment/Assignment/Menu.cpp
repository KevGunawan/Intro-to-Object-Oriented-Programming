/* Final Project Milestone 5
Module: Menu
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string.h>
#include "Menu.h"
using namespace std;
namespace sdds {

    MenuItem::MenuItem(const char* content) {
        if (content != nullptr) {
            m_content = new char[strlen(content) + 1];
            strcpy(m_content, content);
        }
        else {
            m_content = nullptr;
        }
    }

    MenuItem::~MenuItem() {
        delete[] m_content;
    }

    MenuItem::operator bool() const {
        if (m_content == nullptr) {
            return false;
        }
        return true;
    }

    MenuItem::operator const char* () const {
        return m_content;
    }

    void MenuItem::displayContent(std::ostream& os) const {
        if (m_content != nullptr) {
            os << m_content;
        }
    }

    Menu::Menu() {
        unsigned int i;
        title = nullptr;
        itemCount = 0;
        for (i = 0; i < MAX_MENU_ITEMS; ++i) {
            items[i] = nullptr;
        }
    }

    Menu::Menu(const char* menuTitle) {
        unsigned int i;
        itemCount = 0;
        if (menuTitle != nullptr) {
            title = new char[strlen(menuTitle)+1];
            strcpy(title, menuTitle);
        }
        else {
            title = nullptr;
        }
        for (i = 0; i < MAX_MENU_ITEMS; ++i) {
            items[i] = nullptr;
        }
    }

    Menu::~Menu() {
        delete [] title;
         unsigned int i;
        for (i = 0; i < itemCount; ++i) {
            delete items[i];
        }
    }

    void Menu::displayTitle() const {
        if (title != nullptr) {
            cout << title << endl;
        }
    }

    void Menu::displayMenu() const {
        displayTitle();
        unsigned int i;
        for (i = 0; i < itemCount; ++i) {
            cout << setw(2) << i + 1 << "- ";
            items[i]->displayContent(cout);
            cout << '\n';
        }
        cout << " 0- Exit\n";
        cout << "> ";
    }

    unsigned int Menu::run() {
        displayMenu();
        unsigned int choice;
        cin >> choice;
        while (choice < 0 || choice > itemCount || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> choice;
        }
        return choice;
    }

    unsigned int Menu::operator~() const {
        displayMenu();
        unsigned int choice;
        cin >> choice;
        while (choice < 0 || choice > itemCount || cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Selection, try again: ";
            cin >> choice;
        }
        return choice;
    }
    Menu& Menu::operator<<(const char* menuItemContent) {
        if (itemCount < MAX_MENU_ITEMS) {
            items[itemCount] = new MenuItem(menuItemContent);
            ++itemCount;
        }
        return *this;
    }

    Menu::operator int() const {
        return itemCount;
    }

    Menu::operator unsigned int() const {
        return itemCount;
    }
    Menu::operator bool() const
    {
        if (itemCount > 0) {
            return true;
        }
        return false;
    }
    const char* Menu::operator[](unsigned int index) const {
        if (itemCount > 0) {
            return items[index % itemCount]->m_content;
        }
        return nullptr;
    }
    std::ostream& operator<<(std::ostream& os, Menu& menu) {
        if (menu.title != nullptr) {
            os << menu.title;
        }
        return os;
    }

}