// sphere.cpp (Programmiersprachen Aufgabe 5)

#include "sphere.hpp"
  
    // default constructor
  Sphere::Sphere() :
  Shape {"Sphere", {}},
  ctr_ {0.0f, 0.0f, 0.0f}, 
  rad_ {0.0f} {}

    // Constructor takes center and radius
  Sphere::Sphere(glm::vec3 const& ctr, float rad) :
  Shape {"Sphere", {}}, 
  ctr_ {ctr},
  rad_ {rad} {}

    // Constructor takes name, color, center and radius
  Sphere::Sphere(std::string const& name, Material const& mat, glm::vec3 const& ctr, float rad) :
  Shape {name, mat},
  ctr_ {ctr}, 
  rad_ {rad} {}

    // Destructor 
  Sphere::~Sphere() {
    
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
    os << "Center: (" << ctr_.x << ", "  //glm::to_string(glm::vec3)
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
  void Sphere::radius(float rad) {
    rad_ = rad;
  }

  bool Sphere::intersect(Ray const& ray, float& distance) const {
    // ray.direction_ = glm::normalize(ray.direction_);
    return glm::intersectRaySphere(ray.origin_, ray.direction_, ctr_, rad_ * rad_, distance);
  }