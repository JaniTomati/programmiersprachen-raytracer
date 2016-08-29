// camera.hpp (Ray-Traycer 7.1)

#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP
#include <string>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <iostream>
#include "ray.hpp"

struct Camera {

   // Constructors 
  Camera();
  Camera(std::string const& name, double aovX);
   // Destructor
  ~Camera();

  Ray castRay(glm::vec3 const& direction);  
   // print camera
  std::ostream& print(std::ostream& os) const;

   //member 
  std::string name_;
  double aovX_; // horizontal angle of view (x-axis)
  // double focalLength_; (distance to canvas) 
  glm::vec3 origin_; // (0.0f, 0.0f, 0.0f)
  glm::vec3 direction_; // negative z-axis 
  glm::vec3 upVector_; // camera orientation (which way is up?)

};

std::ostream& operator << (std::ostream& os, Camera const& cam);

#endif // BUW_CAMERA_HPP