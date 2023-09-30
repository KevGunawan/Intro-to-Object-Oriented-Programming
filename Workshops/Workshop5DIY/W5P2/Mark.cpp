#include <iostream>
#include "Mark.h"

using namespace std;
namespace sdds {
    
    Mark::Mark() {
        m_Mark = 0;
        m_Valid = true;
    }
    Mark::Mark(int mark) {
        if (mark >= 0 && mark <= 100) {
            m_Mark = mark;
            m_Valid = true;
        }
        else {
            m_Mark = 0;
            m_Valid = false;
        }
    }
    Mark::operator int() {
        return m_Mark;
    }
    Mark& Mark::operator += (int mark) {
        if (m_Valid) {
            m_Mark = m_Mark + mark;
            if (m_Mark < 0 || m_Mark > 100) {
                m_Mark = 0;
                m_Valid = false;
            }
        }
        return *this;
    }
    Mark& Mark::operator = (int mark) {
        m_Mark = mark;
        if (m_Mark < 0 || m_Mark > 100){
            m_Mark = 0;
            m_Valid = false;
        }
        else {
            m_Valid = true;
        }
        return *this;
    }

    Mark::operator double() {
        double result = 0.0;
        if (m_Valid) {
            if (m_Mark >= 0 && m_Mark < 50) {
                result = 0.0;
            }
            else if (m_Mark >= 50 && m_Mark < 60) {
                result = 1.0;
            }
            else if (m_Mark >= 60 && m_Mark < 70) {
                result = 2.0;
            }
            else if (m_Mark >= 70 && m_Mark < 80) {
                result = 3.0;
            }
            else if (m_Mark >= 80 && m_Mark < 100) {
                result = 4.0;
            }
        }
        else {
            result = 0;
        }
        return result;
    }
    
    Mark::operator char() {
        char result = 'X';
        if (m_Valid) {
            if (m_Mark >= 0 && m_Mark < 50) {
                result = 'F';
            }
            else if (m_Mark >= 50 && m_Mark < 60) {
                result = 'D';
            }
            else if (m_Mark >= 60 && m_Mark < 70) {
                result = 'C';
            }
            else if (m_Mark >= 70 && m_Mark < 80) {
                result = 'B';
            }
            else if (m_Mark >= 80 && m_Mark < 100) {
                result = 'A';
            }
        }
        return result;
    }

    int operator += (int& left, const Mark& right) {
        if (right.m_Valid) {
            left = left + right.m_Mark;
        }
        return left;
    }
}