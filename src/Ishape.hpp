#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include <string>

class Ishape {
public:
	virtual ~Ishape() {};

	std::string virtual type() const = 0;
	void virtual zoom(const double) = 0;
	void virtual draw() = 0;
};

#endif // ISHAPE_HPP
