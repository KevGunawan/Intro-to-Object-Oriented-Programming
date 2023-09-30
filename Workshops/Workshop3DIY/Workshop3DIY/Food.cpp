#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds {

	void Food::setName(const char* name) {
		strnCpy(f_foodName, name, 30);
	}

	void Food::setEmpty() {
		f_Cal = 0;
		f_foodName[0] = '\0';
		f_time = 0;
	}

	void Food::set(const char* name, int cal, int time) {
		if ( cal < 0 || name == nullptr || time < 0) {
			setEmpty();
		}
		else {
			setName(name);
			f_Cal = cal;
			f_time = time;
		}
	}

	int Food::calorie()const {
		return f_Cal;
	}

	bool Food::isValid()const {
		if (f_Cal > 0 && f_foodName[0] != '\0' && f_time > 0) {
			return true;
		}
		else {
			return false;
		}
	}

	void Food::display()const {
		
		if (isValid() == true) {
			cout << "| ";
			cout.width(30);
			cout.fill('.');
			cout << left << f_foodName;
			cout << " | ";
			cout.width(4);
			cout.fill(' ');
			cout << right << f_Cal;
			cout << " | ";
			cout.width(10);
			cout.fill(' ');
			if (f_time == 1) {
				cout << left << "Breakfast";
			}
			if (f_time == 2) {
				cout << left << "Lunch";
			}
			if (f_time == 3) {
				cout << left << "Dinner";
			}
			if (f_time == 4) {
				cout << left << "Snack";
			}
			cout << " |" << endl;
		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}
