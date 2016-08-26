// camera.hpp (Ray-Traycer 7.1)

#ifndef BUW_CAMERA_HPP
#define BUW_CAMERA_HPP
#include <string>
#include <glm/vec3.hpp>

class Camera {

public:

  // Constructors 
  Camera();
  Camera(std::string const& name, double aof, glm::vec3 const& upVector);
  // Destructor
  ~Camera();

private:
  //member 
  std::string name_;
  // double focalLength_; //distance to canvas 
  double aovX_; // horizontal angle of view (x-axis)
  glm::vec3 origin_; // (0.0f, 0.0f, 0.0f)
  glm::vec3 direction_; // negative z-axis 
  glm::vec3 upVector_; // camera orientation (which way is up?)


};

#endif // BUW_CAMERA_HPP