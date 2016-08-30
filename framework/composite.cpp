// composite.cpp (Ray-Tracer 7.2)

#include "composite.hpp"

    // Constructors 
Composite::Composite() :
  Shape {"Default Composite", {}}, 
  shapes_ {} {}

Composite::Composite(std::string const& name) : 
  Shape {name, {}},
  shapes_ {} {}

    // Destructor 
Composite::~Composite() {

}

float Composite::area() const {
  float result = 0;
  for (auto const& shape : shapes_) {
    result = shape -> area();
    std::cout << shape -> name() << ": " << result << " (Area) \n" << std::endl;
  }
  return result;
}

float Composite::volume() const {
  float result = 0;
  for (auto const& shape : shapes_) {
    result = shape -> volume();
    std::cout << shape -> name() << ": " << result << " (Volume) \n"<< std::endl;
  }
  return result;
}

  // prints composite
std::ostream& Composite::print(std::ostream& os) const {
  for (auto const& shape : shapes_) {
    shape -> print(os); 
    os << "\n";
  }
  return os;
}

  // adds a shape to the composite 
void Composite::addShape(std::shared_ptr<Shape> const& shape) {
  shapes_.push_back(shape);
}

  // removes a shape from the composite => erase-remove idiom
void Composite::removeShape(std::shared_ptr<Shape> const& shape) {
  shapes_.erase(std::remove(shapes_.begin(), shapes_.end(), shape), shapes_.end()); 
}

  // returns closestHit: hit point of a certain ray that is closest to the ray origin
OptiHit Composite::intersect(Ray const& ray) const {

  OptiHit currentHit;
  OptiHit closestHit;

  for (auto const& shape : shapes_) {
    currentHit = shape -> intersect(ray);
    if (currentHit.distance_ < closestHit.distance_) {
      closestHit = currentHit;
    }
  }
  return closestHit;
}

glm::vec3 Composite::calc_normalen_vec(OptiHit const& hit) const {
  glm::vec3 result;
  for (auto const& shape : shapes_) {
    result = shape -> calc_normalen_vec(hit);
    std::cout << shape -> name() << ": (" << result.x << ", " << result.y <<
    ", " << result.z << ")" << std::endl;
  }
  return result;
}
