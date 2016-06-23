// material.hpp (Programmiersprachen Aufgabenblatt 6)


#ifndef BUW_MATERIAL_HPP
#define BUW_MATERIAL_HPP
#include "color.hpp"
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include <string>

struct Material {
		// constructors
	Material();
	Material(std::string const& name, Color const& ka, Color const& kd, Color const& ks, float m);

		// functions
	std::ostream& print(std::ostream& os) const;
	Color const& ambient() const;
	Color const& diffuse() const;
	Color const& specular() const;
	float exponent() const;

		// member
	std::string name_;
	Color ka_; // ambient reflection
	Color kd_; // diffuse reflection
	Color ks_; // specular reflection
	float m_;
};

std::ostream& operator << (std::ostream& os, Material const& mat);

#endif //BUW_MATERIAL_HPP