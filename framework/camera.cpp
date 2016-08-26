// camera.cpp (Ray-Traycer 7.1)

#include "camera.hpp"

  // default constructor 
Camera::Camera() : 
  name_ {"Default Camera"}, 
  aovX_ {45.0},
  origin_ {0.0f, 0.0f, 0.0f},
  direction_ {0.0f, 0.0f, -1.0f},
  upVector_ {0.0f, 1.0f, 0.0f} {}

Camera::Camera(std::string const& name, double aovX) :
  name_ {name}, 
  aovX_ {45.0},
  origin_ {0.0f, 0.0f, 0.0f},
  direction_ {0.0f, 0.0f, -1.0f},
  upVector_ {0.0f, 1.0f, 0.0f} {}

Camera::~Camera() {}

  // print Camera
std::ostream& Camera::print(std::ostream& os) const {
  os << "Name: " << name_ << "\n"
  << "Angle of View: " << aovX_ << "° \n"
  << "Origin: " << "(" <<origin_.x << ", "
  << origin_.y << ", "<< origin_.z << ") \n"
  << "Direction: " << "(" << direction_.x
  << ", " << direction_.y << ", " << direction_.z << ") \n"
  << "Up-Vector: " << "(" << upVector_.x << ", " << upVector_.y 
  << ", " << upVector_.z << ") \n" << std::endl;
  return os;
}

  // << Operator 
std::ostream& operator << (std::ostream& os, Camera const& cam) {
  return cam.print(os);
}