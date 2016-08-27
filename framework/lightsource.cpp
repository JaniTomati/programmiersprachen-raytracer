// lightsource.cpp (Ray-Traycer 7.1)

#include "lightsource.hpp"

LightSource::LightSource() :
  name_ {"Default Light"},
  pos_ {0.0f, 0.0f, -1.0f}, // default position (test value)
  ip_ {1.0f, 1.0f, 1.0f}, // white Light 
  ia_ {0.35f, 0.35f, 0.35f} {} // default ambient Light (test value)
  // ambient memeber only works for one Lightsource => there can only be one ambient value in one scene 
  // => idea: <<abstract>> Lightsource with children (diffuse and ambient light)

LightSource::LightSource(std::string const& name, glm::vec3 const& pos, Color const& point, Color const& ambient) : 
  name_ {name},
  pos_ {pos},
  ip_ {point},
  ia_ {ambient} {}

    // destructor 
LightSource::~LightSource() {}

std::ostream& LightSource::print(std::ostream& os) const {
  os << "Name: " << name_ << "\n"
  << "Position: " << "(" << pos_.x << ", "
  << pos_.y << ", "<< pos_.z << ") \n"
  << "Diffuse Light (Point Light): " << ip_ 
  << "Ambient Light: " << ia_ << std::endl;
  return os;
}

// << Operator 
std::ostream& operator << (std::ostream& os, LightSource const& light) {
  return light.print(os);
}
