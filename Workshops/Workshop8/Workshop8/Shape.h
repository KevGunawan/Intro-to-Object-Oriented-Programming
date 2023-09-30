#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

namespace sdds {
	class Shape {
	public:
		virtual void draw(std::ostream& os) const = 0;
		virtual void getSpecs(std::istream& is) = 0;
		virtual ~Shape() {}
		friend std::ostream& operator<<(std::ostream& os, const Shape& shape);
		friend std::istream& operator>>(std::istream& is, Shape& shape);
	};
	std::ostream& operator<<(std::ostream& os, const Shape& shape);
	std::istream& operator>>(std::istream& is, Shape& shape);
}


#endif // !SHAPE_H
