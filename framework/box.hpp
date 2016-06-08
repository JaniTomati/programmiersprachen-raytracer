// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <glm/vec3.hpp>

class Box : public Shape {
public: 
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);

	float area() const override;
	float volume() const override;
  glm::vec3 maximum() const;
  glm::vec3 minimum() const;
  void maximum(glm::vec3 const& max);
  void minimum(glm::vec3 const& min);

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif // BUW_BOX_HPP