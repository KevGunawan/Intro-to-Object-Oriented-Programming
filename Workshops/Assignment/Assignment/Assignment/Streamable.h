/* Final Project Milestone 5
Module: Streamable
Filename: Streamable.h
Version 1.0
Author	Kevin Gunawan
Revision History
-----------------------------------------------------------
Date      Reason
2023/August/01  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.

-----------------------------------------------------------*/

#ifndef STREAMABLE_H
#define STREAMABLE_H
#include <iostream>
using namespace std;
namespace sdds {

	class Streamable {
	public:
		virtual ostream& write(ostream& os) const = 0;
		virtual istream& read(istream& is)  = 0;
		virtual bool conIO(ios& io) const = 0;
		virtual operator bool() const = 0;
		virtual ~Streamable() {};
	};
	ostream& operator << (ostream& os, const Streamable& stream);
	istream& operator >> (istream& is, Streamable& stream);
}
#endif // !STREAMABLE_H

