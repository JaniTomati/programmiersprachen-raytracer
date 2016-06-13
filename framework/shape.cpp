// shape.cpp (Programmiersprachen Aufgabenblatt 5)

#include "shape.hpp"

	// default Constructor 
Shape::Shape() :
	name_ {"Shape"}, 
	color_ {0.0f, 0.0f, 0.0f} {}

  // Constructor takes name and color 
Shape::Shape(std::string const& name, Color const& color) : 
	name_ {name},
	color_ {color} {}

  // get name 
std::string Shape::name() const {
  return name_;
}

  // set name
Color const& Shape::color() const {
  return color_; 
}