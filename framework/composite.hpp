// composite.hpp (Ray-Tracer 7.2)

#ifndef BUW_COMPOSITE_HPP
#define BUW_COMPOSITE_HPP
#include <string>
#include <vector>
#include <map>
#include "shape.hpp"
#include "ray.hpp"

  /* * Composite */ 
class Composite : public Shape {

public: 
    // constructors 
  Composite();
  Composite(std::string const& name);
    // destructor 
  ~Composite() override;

    // member functions 
  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
  void addShape(std::shared_ptr<Shape> const& shape);
  void removeShape(std::shared_ptr<Shape> const& shape);
  void get_children() const; // ??? 
  OptiHit intersect(Ray const& ray) const override;
  glm::vec3 calc_normalen_vec(OptiHit const& hit) const override;

private: 
  // Shape: name_
  // Shape: material_ 
  std::vector<std::shared_ptr<Shape>> shapes_;

};

#endif // BUW_COMPOSITE_HPP

/* * Composite-Pattern: Tree Structure 
e.g. Component: Base Class
     Composite: Directory Class
     Leaf: File Class */ 