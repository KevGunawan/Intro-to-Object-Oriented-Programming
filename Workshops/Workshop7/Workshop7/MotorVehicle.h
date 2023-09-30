#ifndef MOTORVEHICLE_H
#define MOTORVEHICLE_H
#include <iostream>

using namespace std;

namespace sdds {
	class MotorVehicle {
		char m_licensePlate[9];
		char m_address[64];
		int m_year;

	public:
		MotorVehicle(const char* licenseplate, int year);
		void moveTo(const char* address);
		ostream& write(ostream& os) const;
		istream& read(istream& in);
		friend ostream& operator<< (ostream& os, const MotorVehicle& other);
		friend istream& operator>> (istream& in, MotorVehicle& other);
	};
	ostream& operator<< (ostream& os, const MotorVehicle& other);
	istream& operator>> (istream& in, MotorVehicle& other);
}
#endif // !MOTORVEHICLE_H
