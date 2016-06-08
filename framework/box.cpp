// box.cpp (Programmiersprachen Aufgabe 5)

#include "box.hpp"
#include <cmath>
    // constructors
  Box::Box() : min_ {0.0f, 0.0f, 0.0f}, max_ {0.0f, 0.0f, 0.0f} {}
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) : min_ {min}, max_ {max} {}

  float Box::area() const override;
  
  float Box::volume() const override;

    // get maximum
  glm::vec3 Box::maximum() const {
    return max_;
  }

    // get minimum
  glm::vec3 Box::minimum() const {
    return min_;
  }

    // set maximum
  void Box::maximum(glm::vec3 const& max) {
    max_ = max;
  }

    // set maximum
  void Box::minimum(glm::vec3 const& min) {
    min_ = min;
  }