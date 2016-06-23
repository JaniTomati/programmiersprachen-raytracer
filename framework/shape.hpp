// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_SHAPE_HPP
#define BUW_SHAPE_HPP
#include "material.hpp"
#include "ray.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>
#include <cmath>
#include <string>
#include <iostream>

class Shape {
public:
  Shape();
  Shape(std::string const& name, Material const& mat);
  virtual ~Shape(); // Aufgabe 5.8
  virtual float area() const = 0; // not implemented on this level --> children classes are able to override the function
  virtual float volume() const = 0;
  virtual std::ostream& print(std::ostream& os) const; 
  std::string name() const;
  Material const& material() const;

protected: 
  std::string name_;
  Material mat_;
};

std::ostream& operator << (std::ostream& os, Shape const& s);

#endif // BUW_SHAPE_HPP