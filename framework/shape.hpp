// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP

class Shape {
public:
	virtual double area() const = 0;
	virtual double volume() const = 0;
private:

};

#endif // BUW_SHAPE_HPP