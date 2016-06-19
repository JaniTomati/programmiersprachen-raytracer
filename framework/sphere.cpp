// sphere.cpp (Programmiersprachen Aufgabe 5)

#include "sphere.hpp"
  
    // default constructor
  Sphere::Sphere() :
  Shape {"Sphere", {0.0f, 0.0f, 0.0f}},
  ctr_ {0.0f, 0.0f, 0.0f}, 
  rad_ {0.0f} {}

    // Constructor takes center and radius
  Sphere::Sphere(glm::vec3 const& ctr, float rad) :
  Shape {"Sphere", {0.0f, 0.0f, 0.0f}}, 
  ctr_ {ctr},
  rad_ {rad} {}

    // Constructor takes name, color, center and radius
  Sphere::Sphere(std::string const& name, Color const& color, glm::vec3 const& ctr, float rad) :
  Shape {name, color},
  ctr_ {ctr}, 
  rad_ {rad} {}

  Sphere::~Sphere() {
    std::cout << "Sphere Destructor: " << name_ << std::endl;
  }

    // get area A = 4 * pi * r^2
  float Sphere::area() const {
    return 4.0f * M_PI * rad_ * rad_;
  }

    // get volume V = 4/3 * pi * r^3
  float Sphere::volume() const {
    return std::abs((4.0f / 3.0f) * M_PI * rad_ * rad_ * rad_);
  }

    // prints Sphere object
  std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << "Center: (" << ctr_.x << ", " 
    << ctr_.y << ", " 
    << ctr_.z << ")" << "\n" 
    << "Radius: " << rad_ 
    << std::endl;
    return os;
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

  bool Sphere::intersect(Ray const& ray, float& distance) {
    return glm::intersectRaySphere(ray.origin_, ray.direction_, ctr_, rad_ * rad_, distance);
  }