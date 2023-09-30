#ifndef LBLSHAPE_H
#define LBLSHAPE_H
#include "Shape.h"

namespace sdds {
	class LblShape :public Shape {
	private:
		char* m_label;
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		virtual ~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&) = delete;
		void getSpecs(std::istream& is);
	};
}


#endif // !LBLSHAPE_H
