#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}
	bool Bill::isValid()const {
		int i = 0;
		if ((m_title[0] != '\0') &&  m_items != nullptr) {
			for (i = 0; i < m_noOfItems; i++) {
				if (!m_items[i].isValid()) {
					return false;
				}
			}
		}
		return true;
		
	}

	double Bill::totalTax()const {
		int i = 0;
		double taxtotal = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			taxtotal += m_items[i].tax();
		}
		return taxtotal;
	}

	double Bill::totalPrice()const {
		int i = 0;
		double totalprice = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			totalprice += m_items[i].price();
		}
		return totalprice;
	}

	void Bill::Title()const {
		cout << "+--------------------------------------+" << endl;

		if (isValid()) {
			cout << "| ";
			cout.width(36);
			cout << left << m_title;
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const {
		cout << "+----------------------+---------+-----+" << endl;

		if (isValid()) {
			cout << "|                Total Tax: ";
			cout.width(10);
			cout << fixed;
			cout.precision(2);
			cout << right << totalTax();
			cout << " |" << endl;
			cout << "|              Total Price: ";
			cout.width(10);
			cout << fixed;
			cout.precision(2);
			cout << right << totalPrice();
			cout << " |" << endl;
			cout << "|          Total After Tax: ";
			cout.width(10);
			cout << fixed;
			cout.precision(2);
			cout << right << totalTax() + totalPrice();
			cout << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;

	}

	void Bill::init(const char* title, int noOfItems) {
		if (title == nullptr || noOfItems <= 0) {
			setEmpty();
		}
		else {
			int i = 0;
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}
	bool Bill::add(const char* item_name, double price, bool taxed) {
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			return true;
		}
		else return false;
	}

	void Bill::display()const {
		Title();
		int i = 0;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}
	
	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}
	
}