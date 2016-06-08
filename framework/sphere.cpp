// sphere.cpp (Programmiersprachen Aufgabe 5)

#include "sphere.hpp"
#include <cmath>
  
  Sphere::Sphere() : ctr_ {0.0, 0.0, 0.0}, rad_ {0.0} {}
  Sphere::Sphere(glm::vec3 const& ctr, float rad) : ctr_ {ctr}, rad_ {rad} {}

    // get area A = 4 * pi * r^2
  float area() const override {
    return 4.0f * M_PI * rad_ * rad_;
  }

    // get volume V = 4/3 * pi * r^3
  float volume() const override {
    return (4.0f / 3.0f) * M_PI * rad_ * rad_ * rad_;
  }

    // get center
  glm::vec3 Sphere::center() const {
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