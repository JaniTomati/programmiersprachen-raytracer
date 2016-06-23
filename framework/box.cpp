// box.cpp (Programmiersprachen Aufgabe 5)

#include "box.hpp"

    // Default Constructor 
  Box::Box() : 
  Shape {"Box", {}},
  min_ {0.0f, 0.0f, 0.0f}, 
  max_ {0.0f, 0.0f, 0.0f} {}

    // Constructor takes min and max
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  Shape {"Box", {}}, 
  min_ {min}, 
  max_ {max} {}

    // Constructor takes name, color, min and max
  Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) : 
  Shape {name, mat},
  min_ {min}, 
  max_ {max} {}

    // Destructor
  Box::~Box() {
    
  }

    // gets area of box object
  float Box::area() const {
    glm::vec3 difference = max_ - min_;
    return 2 * (std::abs(difference.x * difference.y) + std::abs(difference.x * difference.z) + std::abs(difference.y * difference.z));
  }
  
    // gets volume of box object
  float Box::volume() const {
    glm::vec3 difference = max_ - min_;
    return std::abs(difference.x * difference.y * difference.z);
  }

    // prints Box object
  std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum: (" << min_.x << ", " 
    << min_.y << ", " 
    << min_.z << ")" << "\n" 
    << "Maximum: (" << max_.x << ", " 
    << max_.y << ", " 
    << max_.z << ")" << std::endl;
    return os;
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