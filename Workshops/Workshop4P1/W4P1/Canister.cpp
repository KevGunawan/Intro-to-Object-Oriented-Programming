#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265
using namespace std;
namespace sdds {

	void Canister::setToDefault() {
		m_contentName = nullptr;
		m_diameter = 10.0;
		m_height = 13.0;
		m_contentVolume = 0.0;
		m_usable = true;
	}

	bool Canister::isEmpty()const {
		if (m_contentVolume < 0.00001) {
			return true;
		}
		return false;
	}

	bool Canister::hasSameContent(const Canister& C)const {
		return (strCmp(m_contentName, C.m_contentName) == 0);

	}

	void Canister::setName(const char* Cstr) {
		if (Cstr != nullptr && m_usable == true) {
			delete[] m_contentName;
			m_contentName = nullptr;
			int len = strLen(Cstr);
			m_contentName = new char[len + 1];
			strCpy(m_contentName, Cstr);
		}
	}

	Canister::Canister() {
		setToDefault();
	}

	Canister::Canister(const char* contentName) {
		setToDefault();
		setName(contentName);
	}

	Canister::Canister(double height, double diameter, const char* contentName) {
		setToDefault();
		if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30.0) {
			m_height = height;
			m_diameter = diameter;
			m_contentVolume = 0.0;
			setName(contentName);
		}
		else {
			m_usable = false;
		}
	}
	Canister::~Canister() {
		delete[] m_contentName;
		m_contentName = nullptr;
	}

	void Canister::clear() {
		if (m_usable == false) {
			delete[] m_contentName;
			m_contentName = nullptr;
			m_contentVolume = 0.0;
			m_usable = true;
		}
	}

	double Canister::capacity()const {
		return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
	}

	double Canister::volume()const {
		return m_contentVolume;
	}

	Canister& Canister::setContent(const char* contentName) {
		if (contentName == nullptr) {
			m_usable = false;
		}
		else if (isEmpty()) {
			setName(contentName);
		}
		else if (strCmp(m_contentName, contentName) != 0) {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(double quantity) {
		if (m_usable == true && quantity > 0 &&
			quantity + volume() <= capacity()) {
				m_contentVolume += quantity;
		}
		
		else {
			m_usable = false;
		}
		return *this;
	}

	Canister& Canister::pour(Canister& C) {
		if (C.m_usable == true && volume() < capacity()) {
			if (isEmpty()) {
				if (C.m_contentVolume > capacity()) {
					m_contentVolume = capacity();
					C.m_contentVolume -= capacity();
					setName(C.m_contentName);
				}
				else {
					pour(C.volume());
					C.m_contentVolume = 0.0;
					setName(C.m_contentName);
				}
			}
			else {
				if (capacity() - volume() < C.m_contentVolume) {
					C.m_contentVolume -= (capacity() - volume());
					m_contentVolume = capacity();
				}
				else {
					pour(C.volume());
					C.m_contentVolume = 0.0;
				}
				if (strCmp(m_contentName, C.m_contentName) != 0) {
					m_usable = false;
					delete[] m_contentName;
					m_contentName = nullptr;
				}
			}
		}
		return *this;
	}

	std::ostream& Canister::display()const {
		cout.setf(ios::fixed);
		cout.width(7);
		cout.precision(1);
		cout << capacity() << "cc (";
		cout << m_height << "x" << m_diameter << ") Canister";

		if (m_usable == false) {
			cout << " of Unusable content, discard!";
		}
		else if (m_contentName != nullptr) {
			cout << " of ";
			cout.width(7);
			cout.precision(1);
			cout << volume() << "cc   " << m_contentName;
		}

		return cout;
	}


}