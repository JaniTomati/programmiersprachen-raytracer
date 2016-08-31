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

Camera::Camera(std::string const& name, double aovX, glm::vec3 const& ori, glm::vec3 const& dir, glm::vec3 const& up) :
  name_ {name},
  aovX_ {aovX},
  origin_ {ori},
  direction_ {dir},
  upVector_ {up} {}

Camera::~Camera() {}

Ray Camera::calc_eye_ray(int x, int y, int height, int width) const {

    glm::vec3 direction{float(x) * 1.0 / float(width) - 0.5,
                        float(y) * 1.0 / float(height) - 0.5, 
                        -1.0 * (0.5 / tan(aovX_/2))}; // distance to canvas = 0.5 / tan(angle / 2)
  
    Ray camRay{origin_, direction};
    auto transformedCam = transformCam();

    return camRay.transformRay(transformedCam);
}

/* * Kameratansformation (Abbildungen):
  - Urpsrung => e (eye)
  - negative z-Achse => n
  - y-Achse => up (falls n senkrecht auf n)
  - u = n x up (u steht senkrecht auf n und up)
  - v = u x n (sicherstellen, dass up senkrecht zu u und n) 
  - u, v und n sind zu normieren (neue Achsen des Systems) 
  - glm::cross(x, y) => Kreuzprodukt */

  // rays are generated in the simple coordinate system and transformed by the matrix
  // to fit the new system
glm::mat4 Camera::transformCam() const {
  glm::vec3 e = origin_;
  glm::vec3 n = glm::normalize(direction_);
  glm::vec3 up = upVector_;

  glm::vec3 u = glm::normalize(glm::cross(n, up));
  glm::vec3 v = glm::normalize(glm::cross(u, n));

  glm::mat4 transformCam;
  transformCam[0] = glm::vec4 {u, 0.0f};
  transformCam[1] = glm::vec4 {v, 0.0f};
  transformCam[2] = glm::vec4 {n * -1.0f, 0.0f};
  transformCam[3] = glm::vec4 {e, 1.0f};

  return transformCam;
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