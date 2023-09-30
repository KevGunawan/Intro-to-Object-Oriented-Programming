#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
    class Mark {
        int m_Mark;
        bool m_Valid;
    public:
        Mark();
        Mark(int Grade);
        operator int();
        Mark& operator+= (int Grade);
        Mark& operator = (int Grade);
        operator double();
        operator char();
        friend int operator += (int& left, const Mark& right);

    };
    int operator += (int& left, const Mark& right);
}
#endif // SDDS_ACCOUNT_H_