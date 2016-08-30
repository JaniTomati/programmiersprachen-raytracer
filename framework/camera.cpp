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

  // casts Ray from camera into certain direction
Ray Camera::castRay(glm::vec3 const& direction) {
  Ray camRay {origin_, direction};
  return camRay;
} 

Ray Camera::calc_eye_ray(int x, int y, int height, int width)
{
  // -------- das einfache Kameramodell -------- //
  // ----- Die Breite der Bildebene ist 1 ------ //
  // Blickrichtung ist die negative z-Richtung!
  // Die Position der Camera kann sich aber irgendwo befinden
    glm::vec3 direction{float(x)*1.0/float(width) -0.5,
                        float(y)*1.0/float(height) -0.5, 
                        -1.0*(0.5/tan(aovX_/2))}; // distance = 0.5 / tan(winkel/2)
    Ray ray{origin_, direction};
    //transf_ =  transformMatrix();

    //return transformRay(transf_ , ray);
    return ray;
}

  // print Camera
std::ostream& Camera::print(std::ostream& os) const {
  os << "Name: " << name_ << "\n"
  << "Angle of View: " << aovX_ << "° \n"
  << "Origin: " << "(" << origin_.x << ", "
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