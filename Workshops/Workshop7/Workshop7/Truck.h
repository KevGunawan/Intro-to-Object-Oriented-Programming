#ifndef TRUCK_H
#define TRUCK_H
#include "MotorVehicle.h"
#include <iostream>

using namespace std;

namespace sdds {
	class Truck : public MotorVehicle {
		double m_capacity;
		double m_cargo;

	public:
		Truck(const char* licensePlate, int year, double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		ostream& write(ostream& os) const;
		istream& read(istream& in);
		friend ostream& operator<<(ostream& os, const Truck& truck);
		friend istream& operator>>(istream& in, Truck& truck);
	};
	ostream& operator<<(ostream& os, const Truck& truck);
	istream& operator>>(istream& in, Truck& truck);
}
#endif // !TRUCK_H
