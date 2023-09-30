#include "Rectangle.h"
#include <string.h>
#include <iostream>

using namespace std;

namespace sdds {
	Rectangle::Rectangle() : LblShape() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* lbl,unsigned int width, unsigned int height) : LblShape(lbl) {
		m_width = width;
		m_height = height;
		if (height < 3 || width < (strlen(label()) + 2)) {
			m_width = 0;
			m_height = 0;
		}
	}

	void Rectangle::getSpecs(istream& is) {
		LblShape::getSpecs(is);
		is >> m_width;
		is.ignore(1);
		is >> m_height;
		is.ignore(100, '\n');
	}

	void Rectangle::draw(ostream& os) const {
		unsigned int i;
		unsigned int j;
		if (m_width > 0 && m_height > 0) {
			os << '+';
			for (i = 0; i < (m_width - 2); i++) {
				os << '-';
			}
			os << '+' << '\n';

			os << '|' << label();
			for (i = strlen(label()); i < (m_width - 2); i++) {
				os << ' ';
			}
			os << '|' << '\n';

			for (i = 0; i < m_height - 3; i++) {
				os << '|';
				for (j = 0; j < m_width - 2; j++) {
					os << ' ';
				}
				os << '|' << '\n';
			}

			os << '+';
			for (i = 0; i < (m_width - 2); i++) {
				os << '-';
			}
			os << '+';
		}
	}
}
