#define _CRT_SECURE_NO_WARNINGS
#include "MotorVehicle.h"
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;
namespace sdds {
	MotorVehicle::MotorVehicle(const char* licenseplate, int year) {
		strncpy(m_licensePlate, licenseplate, 8);
		m_licensePlate[8] = '\0';
		m_year = year;
		strcpy(m_address, "Factory");
	}

	void MotorVehicle::moveTo(const char* address) {
		if (strcmp(m_address, address) != 0) {
			cout << "|" << right << setw(8) << m_licensePlate << "| |";
			cout << right << setw(20) << m_address << " ---> ";
			cout << left << setw(20) << address << "|" << endl;
			strcpy(m_address, address);
		}
	}

	ostream& MotorVehicle::write(ostream& os) const{
		return os << "| " << m_year << " | " << m_licensePlate << " | " << m_address;
	}

	istream& MotorVehicle::read(istream& in) {
		cout << "Built year: ";
		in >> m_year;

		cout << "License plate: ";
		in >> m_licensePlate;

		cout << "Current location: ";
		in.ignore();
		in.getline(m_address, 64);

		return in;
	}

	ostream& operator << (ostream& os, const MotorVehicle& other) {
		return other.write(os);
	}

	istream& operator >> (istream& in, MotorVehicle& other) {
		return other.read(in);
	}
}