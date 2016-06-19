// ray.hpp (Programmiersprachen Aufgabenblatt 5)

#ifndef BUW_RAY_HPP
#define BUW_RAY_HPP
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <glm/gtx/intersect.hpp>

struct Ray {
    // default-constructor
  Ray() : 
  origin_ {0.0f, 0.0f, 0.0f},
  direction_ {0.0f, 0.0f, 0.0f} {}

    // constructor takes origin_ and direction_ 
  Ray(glm::vec3 const& origin, glm::vec3 const& direction) :
  origin_ {origin},
  direction_ {glm::normalize(direction)} {}

    // member
  glm::vec3 origin_;
  glm::vec3 direction_;

};

#endif // BUW_RAY_HPP