// lightsource.hpp (Ray-Traycer 7.1)

#ifndef BUW_LIGHTSOURCE_HPP
#define BUW_LIGHTSOURCE_HPP
#include <string>
#include <glm/vec3.hpp>
#include "color.hpp"

class LightSource {

public:
    // constructors 
  Light();
  Light(std::string const& name, glm::vec3 const& pos, Color const& clr);
    // destructor 
  ~Light();

private:
  // member
  std::string name_;
  glm::vec3 pos_; // Point Lightsource 
  Color clr_; 

};

#endif // BUW_LIGHTSOURCE_HPP