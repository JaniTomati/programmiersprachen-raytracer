// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include "ray.hpp"

  /* * Leaf */ 
class Sphere : public Shape {
public: 
  Sphere();
  Sphere(glm::vec3 const& ctr, float rad);
  Sphere(std::string const& name, Material const& mat, glm::vec3 const& ctr, float rad); 
  ~Sphere() override; // Aufgabe 5.8

  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override;
  glm::vec3 const& center() const;
  float radius() const;
  void center(glm::vec3 const& ctr);
  void radius(float rad);
    //intersect
  OptiHit intersect(Ray const& ray) const override;
  glm::vec3 calc_normalen_vec(OptiHit const& hit) const override;

private:
	glm::vec3 ctr_;
	float rad_;
};

#endif // BUW_SPHERE_HPP