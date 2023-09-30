#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Food.h"
namespace sdds {
    class CalorieList {
        Food * f_Items;
        int m_noOfItems;
        int m_itemsAdded;
        int totalCalorie()const;
        void Title()const;
        void footer()const;
        void setEmpty();
        bool isValid()const;
    public:
        void init(int noOfItems);
        bool add(const char* name, int cal, int time);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
