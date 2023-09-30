#define _CRT_SECURE_NO_WARNINGS
#include "Truck.h"
#include<string.h>
#include<iostream>
#include <iomanip>

using namespace std;

namespace sdds {

    Truck::Truck(const char* licensePlate, int year, double capacity, const char* address)
        : MotorVehicle(licensePlate, year) {
        m_capacity = capacity;
        m_cargo = 0.0;
        moveTo(address);
    }
    bool Truck::addCargo(double cargo) {
        if (m_cargo < m_capacity) {
            m_cargo += cargo;
            if (m_cargo > m_capacity) {
                m_cargo = m_capacity;
            }
            return true;
        }
        return false;
    }

    bool Truck::unloadCargo() {
        if (m_cargo > 0) {
            m_cargo = 0.0;
            return true;
        }
        return false;
    }

    ostream& Truck::write(ostream& os) const {
        MotorVehicle::write(os);
        os << " | " << fixed << setprecision(0) << m_cargo << "/" << m_capacity;
        return os;
    }

    istream& Truck::read(istream& in) {
        MotorVehicle::read(in);
        std::cout << "Capacity: ";
        in >> m_capacity;
        std::cout << "Cargo: ";
        in >> m_cargo;

        return in;
    }

    std::ostream& operator<<(std::ostream& os, const Truck& truck) {
        return truck.write(os);
    }

    std::istream& operator>>(std::istream& in, Truck& truck) {
        return truck.read(in);
    }
}
