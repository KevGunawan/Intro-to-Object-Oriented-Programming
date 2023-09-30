#include <iostream>
#include <iomanip>
#include "Label.h"
#include "cstring.h"

using namespace std;

namespace sdds {

	Label::Label() {
		strCpy(m_labelFrame, "+-+|+-+|");
		m_labelContent = nullptr;
	}

	Label::Label(const char* frameArg) {
		if (frameArg != nullptr) {
			strCpy(m_labelFrame, frameArg);
		}
		m_labelContent = nullptr;
	}

	Label::Label(const char* frameArg, const char* content) {
		if (frameArg != nullptr && content != nullptr) {
			strCpy(m_labelFrame, frameArg);
			int len = strLen(content);
			m_labelContent = new char[len + 1];
			strCpy(m_labelContent, content);
		}
	}

	Label::~Label() {
		delete[] m_labelContent;
		m_labelContent = nullptr;
	}

	void Label::readLabel() {
		char contentcpy[71];
		cout << "> ";
		cin.getline(contentcpy, 71);
		int len = strLen(contentcpy);
		m_labelContent = new char[len + 1];
		strCpy(m_labelContent, contentcpy);
	}

	std::ostream& Label::printLabel()const {
		if (m_labelContent != nullptr) {
			int len = strLen(m_labelContent) + 3;
			cout << m_labelFrame[0] << setw(len) << setfill(m_labelFrame[1]) << m_labelFrame[2] << endl;
			cout << m_labelFrame[7] << setw(len) << setfill(' ') << m_labelFrame[3] << endl;
			cout << m_labelFrame[7] << ' ' << m_labelContent << ' ' << m_labelFrame[3] << endl;
			cout << m_labelFrame[7] << setw(len) << setfill(' ') << m_labelFrame[3] << endl;
			cout << m_labelFrame[6] << setw(len) << setfill(m_labelFrame[5]) << m_labelFrame[4];
		}
		return cout;
	}
}