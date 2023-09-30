#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
#include <string.h>
#include "Text.h"

using namespace std;
namespace sdds {
    int Text::getFileLength() const {
        int len = 0;
        ifstream fin(m_filename);
        while (fin) {
            fin.get();
            len += !!fin;
        }
        return len;
    }

    Text::Text(const char* filename) {
        m_content = nullptr;
        m_filename = nullptr;

        if (filename != nullptr) {
            m_filename = new char[strlen(filename) + 1];
            strcpy(m_filename, filename);
            read();
        }
    }

    Text::Text(const Text& other) {
        m_content = nullptr;
        m_filename = nullptr;
        *this = other;
    }

    Text& Text::operator=(const Text& other) {
        if (this != &other) {
            delete[] m_filename;
            delete[] m_content;

            if (other.m_filename != nullptr) {
                m_filename = new char[strlen(other.m_filename) + 1];
                strcpy(m_filename, other.m_filename);
                read();
            }
            else {
                m_filename = nullptr;
                m_content = nullptr;
            }
        }
        return *this;
    }

    Text::~Text() {
        delete[] m_filename;
        delete[] m_content;
    }

    void Text::read() {
        int length = getFileLength();
        ifstream file(m_filename);

        m_content = new char[length + 1];

        for (int i = 0; i < length; i++) {
            m_content[i] = file.get();
        }
        m_content[length] = '\0';
    }

    const char& Text::operator[](int index) const {
        return m_content[index];
    }

    void Text::write(ostream& os) const {
        if (m_content != nullptr)
            os << m_content;
    }

    ostream& operator<<(ostream& os, const Text& text) {
        text.write(os);
        return os;
    }


}