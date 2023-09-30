/* Final Project Milestone 4
Module: Book
Filename: Book.h
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


#ifndef BOOK_H
#define BOOK_H
#include "Publication.h"
using namespace std;
namespace sdds {
	class Book : public Publication {
	private:
		char* m_authorName;
	public:
		Book();
		Book(const Book& book);
		Book& operator = (const Book& book);
		~Book();
		char type() const;
		ostream& write(ostream& os) const;
		istream& read(istream& is);
		virtual void set(int member_id);
		operator bool()const;
	};
}

#endif // 

