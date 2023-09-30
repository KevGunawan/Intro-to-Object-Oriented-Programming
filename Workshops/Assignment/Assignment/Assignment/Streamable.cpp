/* Final Project Milestone 4
Module: Streamable
Filename: Streamable.cpp
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

#include <iostream>
#include "Streamable.h"

using namespace std;
namespace sdds {

	ostream& operator << (ostream& os, const Streamable& stream) {
		if (stream) {
			stream.write(os);
		}
		return os;
	}

	istream& operator >> (istream& is, Streamable& stream) {
		return stream.read(is);
	}

}
