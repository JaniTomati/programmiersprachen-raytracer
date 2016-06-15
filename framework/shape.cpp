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

  // Destructor 
Shape::~Shape() {
  std::cout << "Shape Destructor: " << name_ << std::endl;
}

  // get name 
std::string Shape::name() const {
  return name_;
}

  // set name
Color const& Shape::color() const {
  return color_; 
}

  // prints shape object
std::ostream& Shape::print(std::ostream& os) const {
  os << "Name: " << name_ << "\n" 
  << "Color RGB: (" << color_.r << ", " 
  << color_.g << ", " 
  << color_.b << ")" << std::endl;
  return os;
}

  // prints Shape object (overloading << operator)
std::ostream& operator << (std::ostream& os, Shape const& s) {
  return s.print(os);
}