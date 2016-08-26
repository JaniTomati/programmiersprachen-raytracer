// scene.hpp (Programmiersprachen Aufgabenblatt 6)

#include "material.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "camera.hpp"
#include "lightsource.hpp"
#include <iostream>      
#include <fstream>
#include <sstream> 
#include <string>
#include <map>
#include <vector>

struct Scene {
		
	 // member
  unsigned int width; 
  unsigned int height; 
	std::vector<std::shared_ptr<Shape>> shapes_;
	std::map<std::string, Material> materials_; 
	std::shared_ptr<Camera> cam_;
	// std::vector<shared_ptr<LightSource>> light_; 
    // Light Object still has to be added to the framework 

};

Scene loadSDF(std::string const& file_in);