#include <iostream>
#include "cstring.h"
#include "Item.h"
using namespace std;
namespace sdds {

	void Item::setName(const char* name) {

		strnCpy(m_itemName, name, 20);
	}

	void Item::setEmpty() {
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed){
		if (price < 0 || name == nullptr) {
			setEmpty();
		}
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const {
		return m_price;
	}

	double Item::tax()const {
		if (m_taxed == false) {
			return 0.0;
		}
		else {
			return m_price * 0.13;
		}
	}

	bool Item::isValid()const {
		if (m_price > 0 && m_itemName[0] != '\0') {
			return true;
		}
		else {
			return false;
		}
	}

	void Item::display()const {
		if (isValid() == true) {
			cout << "| ";
			cout.width(20);
			cout.fill('.');
			cout << left << m_itemName;
			cout << " | ";
			cout.fill(' ');
			cout.width(7);
			cout << fixed;
			cout.precision(2);
			cout << right << m_price;
			cout << " | ";
			if (m_taxed == true) {
				cout << "Yes";
			}
			else {
				cout << "No ";
			}
			cout << " |" << endl;		 
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}


}