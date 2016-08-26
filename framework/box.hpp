// shape.hpp (Programmiersprachen Aufgabe 5)

#ifndef BUW_BOX_HPP
#define BUW_BOX_HPP
#include "shape.hpp"
#include <algorithm>

class Box : public Shape {
public: 
  Box();
  Box(glm::vec3 const& min, glm::vec3 const& max);
  Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max);
  ~Box() override;

  float area() const override;
  float volume() const override;
  std::ostream& print(std::ostream& os) const override; 
  bool intersect(Ray const& ray, float& t) const override;
  glm::vec3 const& maximum() const;
  glm::vec3 const& minimum() const;
  void maximum(glm::vec3 const& max);
  void minimum(glm::vec3 const& min);
  bool in_box(glm::vec3 const& point) const;

private:
  glm::vec3 min_;
  glm::vec3 max_;
};

bool in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point);
bool is_in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point);
float distance_two_vecs(glm::vec3 const& p1, glm::vec3 const& p2);

#endif // BUW_BOX_HPP