// lightsource.hpp (Ray-Traycer 7.1)

#ifndef BUW_LIGHTSOURCE_HPP
#define BUW_LIGHTSOURCE_HPP
#include <string>
#include <glm/vec3.hpp>
#include "color.hpp"

struct LightSource {

    // constructors 
  LightSource();
  LightSource(std::string const& name, glm::vec3 const& pos, Color const& point, Color const& ambient);
    // destructor 
  ~LightSource();

  	// print 
  std::ostream& print(std::ostream& os) const; 

  	// member
  std::string name_;
  glm::vec3 pos_; // Position of the Point Lightsource 
  Color ip_; // Point Light Intensity 
  Color ia_; // Ambient Light Intensity

};

std::ostream& operator << (std::ostream& os, LightSource const& light);

#endif // BUW_LIGHTSOURCE_HPP