// SDFloader.cpp (Ray-Tracer 7.1)

#include "scene.hpp"

Scene loadSDF(std::string const& file_in) {

  std::ifstream file;
  std::string line;
  file.open(file_in); // opens input file 
  Scene scene;

  if(file.is_open()) {

    while(!file.eof()) { // end of file 
      std::getline(file, line);

      // keyword 
      std::stringstream ss;
      std::string keyword; 

      if(keyword == "define") {
        ss >> keyword;

          // Loads Material # materials
        if(keyword == "material") {
          Material mat;
          std::map<std::string, Material> materialmap;

          ss >> mat.name_;
          ss >> mat.ka_.r;
          ss >> mat.ka_.g;
          ss >> mat.ka_.b;
          ss >> mat.kd_.r;
          ss >> mat.kd_.g;
          ss >> mat.kd_.b;
          ss >> mat.ks_.r;
          ss >> mat.ks_.g;
          ss >> mat.ks_.b;
          ss >> mat.m_;

          materialmap[mat.name_] = mat;

          std::cout << "Added Material: " << mat << std::endl;
        }

          // Loads Shapes # geometry
        else if(keyword == "shape") {
          ss << keyword;

          if(keyword == "sphere") {
            // ... do
          }

          else if(keyword == "box") {
            // ... do
          }
        }

          // Loads Light # light - from right above 
        else if(keyword == "light") {
          // ... do
        }

          // Loads Camera # camera
        else if(keyword == "camera") {
          Camera cam;

          ss >> cam.name_;
          ss >> came.aovX_;

          std::cout << "Added Camera: " << cam << std::endl;
        }
      }

        // Renders Scene 
      else if (keyword == "render") {
        // ... do
      }

    }
  }

}