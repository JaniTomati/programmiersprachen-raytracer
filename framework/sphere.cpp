// sphere.cpp (Programmiersprachen Aufgabe 5)

#include "sphere.hpp"
  
    // default constructor
  Sphere::Sphere() :
  Shape {},
  ctr_ {0.0f, 0.0f, 0.0f}, 
  rad_ {0.0f} {}

    // Constructor takes center and radius
  Sphere::Sphere(glm::vec3 const& ctr, float rad) :
  Shape {}, // name and color default 
  ctr_ {ctr},
  rad_ {rad} {}

    // Constructor takes name, color, center and radius
  Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& ctr, float rad) :
  Shape {name, color},
  ctr_ {ctr}, 
  rad_ {rad} {}

    // get area A = 4 * pi * r^2
  float Sphere::area() const {
    return 4.0f * M_PI * rad_ * rad_;
  }

    // get volume V = 4/3 * pi * r^3
  float Sphere::volume() const {
    float result = (4.0f / 3.0f) * M_PI * rad_ * rad_ * rad_;

    if (result < 0) {
      result = result * (-1); // only positive solutions
    }

    return result;
  }

    // get center
  glm::vec3 const& Sphere::center() const {
    return ctr_;
  }

    // get radius
  float Sphere::radius() const {
    return rad_;
  }

    // set center
  void Sphere::center(glm::vec3 const& ctr) {
    ctr_ = ctr;
  }

    // set radius 
  void Sphere::radius(float const& rad) {
    rad_ = rad;
  }