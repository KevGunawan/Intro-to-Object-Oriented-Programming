#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Account {
        int m_number;
        double m_balance;
        void setEmpty();
    public:
        Account();
        Account(int number, double balance);
        std::ostream& display()const;
        operator bool()const;
        operator int()const;
        operator double()const;
        bool operator ~()const;
        Account& operator = (int num);
        Account& operator = (Account& Rop);
        Account& operator += (double deposit);
        Account& operator -= (double withdraw);
        Account& operator << (Account& Rop);
        Account& operator >> (Account& Rop);
        friend double operator +(const Account& left, const Account& right);
        friend double operator += (double& left, const Account& right);

    };
    double operator +(const Account& left, const Account& right);
    double operator += (double& left, const Account& right);
}
#endif // SDDS_ACCOUNT_H_