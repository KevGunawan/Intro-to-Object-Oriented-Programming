#define _CRT_SECURE_NO_WARNINGS
#include "HtmlText.h"
#include <iostream>
#include <string.h>
#include <cstring>

namespace sdds {

	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		m_title = nullptr;
		if (title != nullptr) {
			m_title = new char[strlen(title) + 1];
			strcpy(m_title, title);
		}
	}

	HtmlText::HtmlText(const HtmlText& other) : Text(other) {
		m_title = nullptr;
		*this = other;
	}

    HtmlText::~HtmlText() {
        delete[] m_title;
    }

	HtmlText& HtmlText::operator=(const HtmlText& other) {
		if (this != &other) {
			delete[] m_title;

			if (other.m_title != nullptr) {
				m_title = new char[strlen(other.m_title) + 1];
				strcpy(m_title, other.m_title);
                Text::operator=(other);
			}
			else {
				m_title = nullptr;
			}
		}
		return *this;
	}

    void HtmlText::write(std::ostream& os) const {
        int i;
        bool MS = false;
        os << "<html><head><title>";
        if (m_title != nullptr) {
            os << m_title;
        }
        else {
            os << "No Title";
        }

        os << "</title></head>\n<body>\n";

        if (m_title != nullptr)
            os << "<h1>" << m_title << "</h1>\n";

        for (i = 0; (*this)[i] != '\0'; i++) {
            char ch = (*this)[i];

            switch (ch) {
            case ' ':
                if (MS)
                    os << "&nbsp;";
                else {
                    MS = true;
                    os << ' ';
                }
                break;
            case '<':
                os << "&lt;";
                MS = false;
                break;
            case '>':
                os << "&gt;";
                MS = false;
                break;
            case '\n':
                os << "<br />\n";
                MS = false;
                break;
            default:
                os << ch;
                MS = false;
                break;
            }
        }

        os << "</body>\n</html>";
    }
}
