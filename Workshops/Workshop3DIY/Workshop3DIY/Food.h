#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Food {
        char f_foodName[30];
        int f_Cal;
        int f_time;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int cal, int time);
        void display()const;
        bool isValid()const;
        int calorie()const;
    };
}

#endif // !SDDS_SUBJECT_H
