// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "color.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <cmath>
#include <string>

class Shape {
public:
	Shape();
	Shape(std::string const& name, Color const& color);
	virtual float area() const = 0;
	virtual float volume() const = 0;
	std::string name() const;
	Color const& color() const; 
private:
	std::string name_;
	Color color_;
};

#endif // BUW_SHAPE_HPP