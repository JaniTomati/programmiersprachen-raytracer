// box.cpp (Programmiersprachen Aufgabe 5)

#include "box.hpp"

    // Default Constructor 
  Box::Box() : 
  Shape {},
  min_ {0.0f, 0.0f, 0.0f}, 
  max_ {0.0f, 0.0f, 0.0f} {}

    // Constructor takes min and max
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  Shape {}, // name and color default 
  min_ {min}, 
  max_ {max} {}

    // Constructor takes name, color, min and max
  Box::Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max) : 
  Shape {name, color},
  min_ {min}, 
  max_ {max} {}

    // gets area of box object
  float Box::area() const {
    glm::vec3 difference = max_ - min_;
    float result = 2 * (difference.x * difference.y + difference.x * difference.z + difference.y * difference.z);

    if (result < 0) {
      result = result * (-1); // only positive solutions
    }

    return result;
  }
  
    // gets volume of box object
  float Box::volume() const {
    glm::vec3 difference = max_ - min_;
    float result = difference.x * difference.y * difference.z;

    if (result < 0) {
      result = result * (-1);
    }

    return result;
  }

    // get maximum
  glm::vec3 const& Box::maximum() const {
    return max_;
  }

    // get minimum
  glm::vec3 const& Box::minimum() const {
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