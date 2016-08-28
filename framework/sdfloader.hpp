// // SDFloader.hpp (Ray-Tracer 7.1)

#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP
#include "scene.hpp"
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

struct SDFloader {

  Scene loadSDF(std::string const& fileIn);

};

#endif // BUW_SDFLOADER_HPP