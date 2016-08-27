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

  void loadSDF(std::string const& file_in);

    // member
  unsigned int width; // canvas size 
  unsigned int height; 
  std::map<std::string, Material> materials_; 
  std::vector<std::shared_ptr<Shape>> shapes_;
  std::vector<std::shared_ptr<LightSource>> light_;
  std::shared_ptr<Camera> cam_;

};

#endif // BUW_SCENE_HPP