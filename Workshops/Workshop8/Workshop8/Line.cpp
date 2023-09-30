#include "Line.h"
#include <iostream>

using namespace std;

namespace sdds {

	Line::Line() :LblShape() {
		m_length = 0;
	}

	Line::Line(const char* label, int length) : LblShape(label) {
		m_length = length;
	}

	void Line::draw(std::ostream& os) const {
		if (m_length > 0 && label() != nullptr) {
			os << label() << '\n';
			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
		}
	}

	void Line::getSpecs(std::istream& is) {
		LblShape::getSpecs(is);
		is >> m_length;
		is.ignore(100, '\n');
	}
}