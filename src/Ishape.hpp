#ifndef ISHAPE_HPP
#define ISHAPE_HPP

class Ishape {
public:
	virtual ~shape() {};
	
	void virtual draw() = 0;
};

#endif // ISHAPE_HPP
