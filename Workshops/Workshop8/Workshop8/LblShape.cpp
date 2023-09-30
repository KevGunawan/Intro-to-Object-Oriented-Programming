#define _CRT_SECURE_NO_WARNINGS 
#include "LblShape.h"
#include <iostream>
#include <string.h>

using namespace std;

namespace sdds {

	const char* LblShape::label() const {
		return m_label;
	}

	LblShape::LblShape() {
		m_label = nullptr;
	}

	LblShape::LblShape(const char* label) {
		m_label = nullptr;
		if (label != nullptr) {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	LblShape::~LblShape() {
		delete[] m_label;
		m_label = nullptr;
	}

	void LblShape::getSpecs(std::istream& is) {
		char input[1000];
		//gets input up until the coma
		is.getline(input, 1000, ',');
		if (m_label != nullptr) {
			delete[] m_label;
			m_label = nullptr;
		}
		m_label = new char[strlen(input) + 1];
		strcpy(m_label, input);
	}
}