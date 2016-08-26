// camera.cpp (Ray-Traycer 7.1)

#include "camera.hpp"

  // default constructor 
Camera::Camera() : 
  name_ {"Default Camera"}, 
  aovX_ {45.0},
  origin_ {0.0f, 0.0f, 0.0f},
  direction_ {0.0f, 0.0f, -1.0f},
  upVector_ {0.0f, 1.0f, 0.0f} {}

Camera::Camera(std::string const& name, double aof, glm::vec3 const& upVector) :
  name_ {name}, 
  aovX_ {45.0},
  origin_ {0.0f, 0.0f, 0.0f},
  direction_ {0.0f, 0.0f, -1.0f},
  upVector_ {upVector} {} 