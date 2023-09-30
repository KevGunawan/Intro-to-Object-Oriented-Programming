#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "LblShape.h"

namespace sdds {
    class Rectangle : public LblShape {
    private:
       unsigned int m_width = 0 ;
        unsigned int m_height = 0;

    public:
        Rectangle();
        Rectangle(const char* lbl, unsigned int width, unsigned int height);

        void draw(std::ostream& os) const override;
        void getSpecs(std::istream& is) override;
    };
}


#endif // !RECTANGLE_H