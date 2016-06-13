// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"

class Box : public Shape {
public: 
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  Box(std::string const& name, Color const& color, glm::vec3 const& min, glm::vec3 const& max);

	float area() const override;
	float volume() const override;
  glm::vec3 const& maximum() const;
  glm::vec3 const& minimum() const;
  void maximum(glm::vec3 const& max);
  void minimum(glm::vec3 const& min);

private:
	glm::vec3 min_;
	glm::vec3 max_;
};

#endif // BUW_BOX_HPP