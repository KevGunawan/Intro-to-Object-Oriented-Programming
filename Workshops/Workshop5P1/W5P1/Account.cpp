#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
    void Account::setEmpty() {
        m_number = -1;
        m_balance = 0.0;
    }
    // New account
    Account::Account() {
        m_number = 0;
        m_balance = 0.0;
    }
    Account::Account(int number, double balance) {
        setEmpty();
        if (number >= 10000 && number <= 99999
            && balance > 0) {
            m_number = number;
            m_balance = balance;
        }
    }
    std::ostream& Account::display() const {
        if (*this) {
            cout << " ";
            cout << m_number;
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << m_balance;
            cout.unsetf(ios::right);
            cout << " ";
        }
        else if (~*this) {
            cout << "  NEW  |         0.00 ";
        }
        else {
            cout << "  BAD  |    ACCOUNT   ";
        }
        return cout;
    }
    Account::operator bool()const {
        if (m_number >= 10000 && m_number <= 99999) {
            return true;
        }
        return false;
    }
    Account::operator int()const {
        return m_number;
    }
    Account::operator double()const {
        return m_balance;
    }
    bool Account::operator ~()const{
        if (m_number == 0) {
            return true;
        }
        return false;

    }
    Account& Account::operator = (int num) {
        if (m_number == 0 && (num >= 10000 && num <= 99999)) {
            m_number = num;
        }
        if (num < 10000) {
            setEmpty();
        }
        return *this;
    }
    Account& Account::operator = (Account& Rop) {
        if (this->m_number == 0) {
            this->m_balance = Rop.m_balance;
            this->m_number = Rop.m_number;
            Rop.m_balance = 0;
            Rop.m_number = 0;
        }
        return *this;
    }
    Account& Account::operator += (double deposit) {
        if ((*this) && deposit > 0) {
            m_balance += deposit;
        }
        return *this;
    }
    Account& Account::operator -= (double withdraw) {
        if ((*this) && withdraw > 0 && withdraw < m_balance) {
            m_balance -= withdraw;
        }
        return *this;
    }
    Account& Account::operator << (Account& Rop) {
        if ((*this) && m_number != Rop.m_number) {
            this->m_balance += Rop.m_balance;
            Rop.m_balance = 0;
        }
        return *this;
    }
    Account& Account::operator >> (Account& Rop) {
        if ((*this) && m_number != Rop.m_number) {
            Rop.m_balance += this->m_balance;
            this->m_balance = 0;
        }
        return *this;
    }
    double operator +(const Account& left, const Account& right) {
        double result = 0;
        if (left && right) {
            result = left.m_balance + right.m_balance;
        }
        return result;
    }

    double operator += (double& left, const Account& right) {
        if (right) {
            left = left + right.m_balance;
        }
        return left;
    }
}