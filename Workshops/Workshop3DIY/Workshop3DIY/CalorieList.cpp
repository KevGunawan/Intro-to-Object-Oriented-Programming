#include <iostream>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;
namespace sdds {

	void CalorieList::setEmpty() {
		f_Items = nullptr;
	}

	bool CalorieList::isValid()const {
		int i = 0;
		if (f_Items != nullptr) {
			for (i = 0; i < m_noOfItems; i++) {
				if (!f_Items[i].isValid()) {
					return false;
				}
			}
		}
		return true;
	}
	int CalorieList::totalCalorie()const {
		int i = 0;
		int totalCalorie = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			totalCalorie += f_Items[i].calorie();
		}
		return totalCalorie;
	}

	void CalorieList::Title()const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "|    Total Calories for today:   ";
			cout.width(6);
			cout << right << totalCalorie();
			cout << " |            |" << endl;
		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int noOfItems) {
		if (noOfItems < 0) {
			setEmpty();
		}
		else {
			int i = 0;
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			f_Items = new Food[m_noOfItems];
			for (i = 0; i < m_noOfItems; i++) {
				f_Items[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* name, int cal, int time) {
		if (m_itemsAdded < m_noOfItems) {
			f_Items[m_itemsAdded].set(name, cal, time);
			m_itemsAdded++;
			return true;
		}
		else return false;
	}

	void CalorieList::display()const {
		Title();
		int i = 0;
		for (i = 0; i < m_noOfItems; i++) {
			f_Items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] f_Items;
		f_Items = nullptr;
	}
}