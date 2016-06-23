// shape.cpp (Programmiersprachen Aufgabenblatt 5)

#include "shape.hpp"

  // default Constructor 
Shape::Shape() :
name_ {"Shape"}, 
mat_ {} {}

  // Constructor takes name and color 
Shape::Shape(std::string const& name, Material const& mat) : 
name_ {name},
mat_ {mat} {}

  // Destructor 
Shape::~Shape() {
  
}

  // get name 
std::string Shape::name() const {
  return name_;
}

  // set name
Material const& Shape::material() const {
  return mat_; 
}

  // prints shape object
std::ostream& Shape::print(std::ostream& os) const {
  os << "Name: " << name_ << "\n" 
  << "Material: " << mat_
  << std::endl;
  return os;
}

  // prints Shape object (overloading << operator)
std::ostream& operator << (std::ostream& os, Shape const& s) {
  return s.print(os);
}