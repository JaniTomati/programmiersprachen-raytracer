// scene.hpp (Programmiersprachen Aufgabenblatt 6)

#ifndef BUW_SCENE_HPP
#define BUW_SCENE_HPP
#include "material.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"
#include "camera.hpp"
#include "lightsource.hpp"
#include "color.hpp"
#include <iostream>      
#include <fstream>
#include <sstream> 
#include <string>
#include <map>
#include <vector>

struct Scene {

    // member
  unsigned int width_; // canvas size (x * y)
  unsigned int height_; 
  std::map<std::string, Material> materials_; 
  std::vector<std::shared_ptr<Shape>> shapes_;
  std::vector<LightSource> lights_;
  Camera cam_; // std::shared_ptr<Camera>
  std::string fileOut_;

};

#endif // BUW_SCENE_HPP