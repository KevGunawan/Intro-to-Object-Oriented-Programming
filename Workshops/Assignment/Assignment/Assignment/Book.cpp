/* Final Project Milestone 4
Module: Book
Filename: Book.cpp
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
#include "Book.h"
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;
namespace sdds {

	Book::Book() : Publication() {
		m_authorName = nullptr;
	}

	Book::Book(const Book& book) : Publication(book) {
		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}
		m_authorName = new char[strlen(book.m_authorName) + 1];
		strcpy(m_authorName, book.m_authorName);
	}

	Book& Book::operator = (const Book& book) {
		Publication::operator =(book);

		if (this != &book) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}

		if (book.m_authorName != nullptr)
		{
			m_authorName = new char[strlen(book.m_authorName) + 1];
			strcpy(m_authorName, book.m_authorName);
		}
		return *this;
	}

	Book::~Book() {
		delete[] m_authorName;
	}

	char Book::type()const {
		return 'B';
	}

	ostream& Book::write(ostream& os) const {
		Publication::write(os);

		if (conIO(os)) {
			char author[SDDS_AUTHOR_WIDTH + 1] = { 0 };
			strncpy(author, m_authorName, SDDS_AUTHOR_WIDTH);
			os << " ";
			os << setw(SDDS_AUTHOR_WIDTH) << left << setfill(' ') << author << " |";

		}
		else {
			os << "\t" << m_authorName;
		}

		return os;
	}

	istream& Book::read(istream& is) {
		char name[256];

		Publication::read(is);

		if (m_authorName) {
			delete[] m_authorName;
			m_authorName = nullptr;
		}

		if (conIO(is)) {

			is.ignore();
			cout << "Author: ";
			
		}
		else {
			is.ignore(1, '\t');			
		}
		
		is.get(name, 256);

		if (!is.fail()) {

			m_authorName = new char[strlen(name) + 1];
			strcpy(m_authorName, name);
		}

		return is;
	}

	void Book::set(int member_id) {
		Publication::set(member_id);
		Publication::resetDate();

	}

	Book::operator bool()const {
		if ((m_authorName && m_authorName[0] != '\0') && Publication::operator bool()) {
			return true;
		}
		return false;
	}
}