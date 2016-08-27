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
#include "color.hpp"

struct OptiHit;

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
  //intersect
  virtual OptiHit intersect(Ray const& ray) const = 0;
  glm::vec3 calc_surface_pt(Ray const& ray, float distance) const;
  virtual glm::vec3 calc_normalen_vec(OptiHit const& hit) const = 0;

protected:
  std::string name_;
  Material mat_;
};

struct OptiHit {
  OptiHit():
    hit_{false},
    distance_{INFINITY},
    closest_shape_{nullptr},
    normalen_vec_{},
    surface_pt_{}
    {}

  OptiHit(const Shape* s):
    hit_{false},
    distance_{INFINITY},
    closest_shape_{s},
    normalen_vec_{},
    surface_pt_{}
    {}

  OptiHit(bool h, float d, const Shape* c, glm::vec3 const& n0, glm::vec3 const& s):
    hit_{h},
    distance_{d},
    closest_shape_{c},
    normalen_vec_{n0},
    surface_pt_{s}
    {}
  
  bool hit_;  //wird in intersect berechnet
  float distance_;  //wird in intersect berechnet
  const Shape* closest_shape_; //wird in intersect berechnet
  glm::vec3 normalen_vec_;
  glm::vec3 surface_pt_;
};

std::ostream& operator << (std::ostream& os, Shape const& s);

#endif // BUW_SHAPE_HPP