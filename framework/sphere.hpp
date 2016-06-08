// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_SPHERE_HPP
#define BUW_SPHERE_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape {
public: 
  Sphere();
  Sphere(glm::vec3 const& ctr, float rad); 

	float area() const override;
	float volume() const override;
  glm::vec3 center() const;
  double radius() const;
  void center(glm::vec3 const& ctr);
  void radius(float const& rad);

private:
	glm::vec3 ctr_;
	float rad_;
};

#endif // BUW_SPHERE_HPP