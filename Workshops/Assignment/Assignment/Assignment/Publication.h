/* Final Project Milestone 5
Module: Publication
Filename: Publication.h
Version 1.0
Author	Kevin Gunawan
Revision History
-----------------------------------------------------------
Date      Reason
2023/August/01 Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/

#ifndef PUBLICATION_H
#define PUBLICATION_H

#include "Date.h"
#include"Streamable.h"
#include "Lib.h"
#include <iostream>

using namespace std;

namespace sdds {

	class Publication : public Streamable {
        char* m_title;
        char m_shelfId[SDDS_SHELF_ID_LEN + 1];
        int m_membership;
        int m_libRef;
        Date m_date;

    public:
        Publication();
        ~Publication();
        Publication(const Publication& other);
        Publication& operator=(const Publication& other);
        void set(int member_id);
        void setRef(int value);
        void resetDate();
        virtual char type() const;
        bool onLoan() const;
        Date checkoutDate() const;
        bool operator==(const char* title) const;
        operator const char* () const;
        int getRef() const;
        bool conIO(ios& io) const;
        ostream& write(ostream& os) const;
        istream& read(istream& istr);
        operator bool() const;
	};
}
#endif // PUBLICATION_H
