// material.hpp (Programmiersprachen Aufgabenblatt 6)

#include "material.hpp"

Material::Material() :
name_ {"Material"},
ka_ {0.0f, 0.0f, 0.0f}, 
kd_ {0.0f, 0.0f, 0.0f},
ks_ {0.0f, 0.0f, 0.0f},
m_ {0.0f} {}

Material::Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m) :
name_ {name},
ka_ {ka},
kd_ {kd},
ks_ {ks},
m_ {m} {}

  // print method
std::ostream& Material::print(std::ostream& os) const {
	os << "Name: " << name_ << "\n"
	<< "Ambient Refflection: " << ka_
	<< "Diffuse Refflection: " << kd_
	<< "Specular Refflection: " << ks_
	<< "Exponent: " << m_ << std::endl;
	return os;
}

  // get ambient reflection ka_
Color const& Material::ambient() const {
  return ka_;
}

  // get diffuse reflection kd_
Color const& Material::diffuse() const {
  return kd_;
}

  // get specular reflection ks_
Color const& Material::specular() const {
  return ks_;
}

  // get exponent m_
float Material::exponent() const {
  return m_;
}

  // << Operator 
std::ostream& operator << (std::ostream& os, Material const& mat) {
	return mat.print(os);
}