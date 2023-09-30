/* Final Project Milestone 4
Module: Publication
Filename: Publication.cpp
Version 1.0
Author	Kevin Gunawan
Revision History
-----------------------------------------------------------
Date      Reason
2023/July/25  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include "Publication.h"
#include <iostream>
#include <string.h>
#include <cstring>
#include <iomanip>

using namespace std;

namespace sdds {

	Publication::Publication() {
        m_title = nullptr;
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();
	}

    Publication::Publication(const Publication& other) {
        if (other.m_title != nullptr) {
            m_title = new char[strlen(other.m_title) + 1];
            strcpy(m_title, other.m_title);
        }
        else {
            m_title = nullptr;
        }
        strcpy(m_shelfId, other.m_shelfId);
        m_membership = other.m_membership;
        m_libRef = other.m_libRef;
        m_date = other.m_date;
    }

    Publication& Publication::operator=(const Publication& other) {
        if (this != &other) {
            delete[] m_title;

            if (other.m_title != nullptr) {
                m_title = new char[strlen(other.m_title) + 1];
                strcpy(m_title, other.m_title);
            }
            else {
                m_title = nullptr;
            }
            strcpy(m_shelfId, other.m_shelfId);
            m_membership = other.m_membership;
            m_libRef = other.m_libRef;
            m_date = other.m_date;
        }
        return *this;
    }

    Publication::~Publication() {
        delete[] m_title;
        m_title = nullptr;
    }

    void Publication::set(int member_id) {
        m_membership = member_id;
    }

    void Publication::setRef(int value) {
        m_libRef = value;
    }

    void Publication::resetDate() {
        m_date = Date();
    }

    char Publication::type() const {
        return 'P';
    }

    bool Publication::onLoan() const {
        if (m_membership != 0) {
            return true;
        }
        return false;
    }

    Date Publication::checkoutDate() const {
        return m_date;
    }

    bool Publication::operator==(const char* title) const {
        if (strstr(m_title, title) != nullptr) {
            return true;
        }
        return false;
    }

    Publication::operator const char* () const {
        return m_title;
    }

    int Publication::getRef() const {
        return m_libRef;
    }

    bool Publication::conIO(ios& io) const {
        if (&io == &cin || &io == &cout) {
            return true;
        }
        return false;
    }

    ostream& Publication::write(ostream& os) const {
        char title[SDDS_TITLE_WIDTH + 1] = { 0 };
        strncpy(title, m_title, SDDS_TITLE_WIDTH);

        if (conIO(os)) {
            os << "| ";
            os << m_shelfId << " | ";
            os << setw(SDDS_TITLE_WIDTH) << left << setfill('.');
            os << title << " | ";
            if (m_membership != 0) {
                os << m_membership;
            }
            else {
                os << " N/A ";
            }  
            os << " | " << m_date << " |";
        }
        else {
            os << type() << "\t";
            os << "\t";
            os << m_libRef << "\t";
            os << m_shelfId << "\t";
            os << m_title << "\t";
            if (m_membership != 0) {
                os << m_membership;
            }
            else {
                os << " N/A ";
            }
            os << "\t" << m_date;
        }

        return os;
    }

    istream& Publication::read(istream& is) {

        char tempTitle[300]{};
        char tempShelf[SDDS_SHELF_ID_LEN + 1]{};
        int tempRef = -1;
        int tempMem = 0;
        Date tempDate;

        if (m_title != nullptr) {
            delete[] m_title;
            m_title = nullptr;
        }
        m_shelfId[0] = '\0';
        m_membership = 0;
        m_libRef = -1;
        resetDate();

        if (conIO(is)) {
            cout << "Shelf No: ";
            is.getline(tempShelf, SDDS_SHELF_ID_LEN + 1);
            if ((int)strlen(tempShelf) != SDDS_SHELF_ID_LEN) {
                is.setstate(ios::failbit);
            }
            cout << "Title: ";
            is.getline(tempTitle, 300);
            cout << "Date: ";
            is >> tempDate;
        }
        else {
            is >> tempRef;
            is.ignore();
            is.getline(tempShelf, SDDS_TITLE_WIDTH + 1, '\t');
            is.getline(tempTitle, 300, '\t');
            is >> tempMem;
            is.ignore();
            is >> tempDate;
        }
        if (!tempDate) {
            is.setstate(ios::failbit);
        }
        if (is) {
            m_title = new char[strlen(tempTitle) + 1];
            strcpy(m_title, tempTitle);
            strcpy(m_shelfId, tempShelf);
            m_membership = tempMem;
            m_date = tempDate;
            m_libRef = tempRef;
        }
        return is;
    }

    Publication::operator bool() const {
        if (m_title != nullptr && m_shelfId[0] != '\0') {
            return true;
        }
        return false;
    }
}