// SDFloader.cpp (Ray-Tracer 7.1)

#include "sdfloader.hpp"
#include "renderer.hpp"

Scene SDFloader::loadSDF(std::string const& fileIn) {

  std::ifstream file;
  std::string line;
  file.open(fileIn); // opens input file 
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

          scene.materials_[mat.name_] = mat;

          std::cout << "Added Material: " << mat << std::endl;
        }

          // Loads Shapes # geometry
        else if(keyword == "shape") {
          ss << keyword;
          unsigned int vectorSizeShapes = 0;

          if(keyword == "sphere") {
            std::string sphereName;
            glm::vec3 sphereCtr; 
            float sphereRad;
            std::string sphereClrName;

            ss >> sphereName;
            ss >> sphereCtr.x;
            ss >> sphereCtr.y;
            ss >> sphereCtr.z;
            ss >> sphereRad;
            ss >> sphereClrName;

              // find() points from Name to Material (http://en.cppreference.com/w/cpp/container/map/find)
            Material sphereMat = scene.materials_.find(sphereClrName) -> second;

              // new entry in shapes_ (ptr)
            scene.shapes_.push_back(std::make_shared<Sphere>(sphereName, sphereMat, sphereCtr, sphereRad));
            ++vectorSizeShapes;

            std::cout << "Added Sphere: " << *scene.shapes_[vectorSizeShapes - 1] << std::endl; 
          }

          else if(keyword == "box") {
            std::string boxName;
            glm::vec3 boxMin;
            glm::vec3 boxMax;
            std::string boxClrName;

            ss >> boxName;
            ss >> boxMin.x;
            ss >> boxMin.y;
            ss >> boxMin.z;
            ss >> boxMax.x;
            ss >> boxMax.y;
            ss >> boxMax.z;
            ss >> boxClrName;

            Material boxMat = scene.materials_.find(boxClrName) -> second;

              // new entry in shapes_ (ptr)
            scene.shapes_.push_back(std::make_shared<Box>(boxName, boxMat, boxMin, boxMax));
            ++vectorSizeShapes;

            std::cout << "Added Box: " << *scene.shapes_[vectorSizeShapes - 1] << std::endl; 
          }
        }

          // Loads Light # light - from right above 
        else if(keyword == "light") {
          unsigned int vectorSizeLight = 0;
          std::string lightName; 
          glm::vec3 lightPos;
          Color diffuseLight;
          Color ambientLight;

          ss >> lightName;
          ss >> lightPos.x;
          ss >> lightPos.y;
          ss >> lightPos.z;
          ss >> diffuseLight.r;
          ss >> diffuseLight.g;
          ss >> diffuseLight.b;
          ss >> ambientLight.r;
          ss >> ambientLight.g;
          ss >> ambientLight.b;

            // new entry in light_ (ptr)
          scene.light_.push_back(std::make_shared<LightSource>(lightName, lightPos, diffuseLight, ambientLight));
          ++vectorSizeLight;

          std::cout << "Added Light: " << *scene.light_[vectorSizeLight - 1] << std::endl;
        }

          // Loads Camera # camera
        else if(keyword == "camera") {
          std::string cameraName;
          double cameraAoV;

          ss >> cameraName;
          ss >> cameraAoV;

          auto cam_ = std::make_shared<Camera>(cameraName, cameraAoV);

          std::cout << "Added Camera: " << scene.cam_ << std::endl;
        }
      }

        // Renders Scene 
      else if (keyword == "render") {
        std::string camName;
        ss >> camName;

          // checks whether camera exists so the frame can be rendered 
        if (camName == scene.cam_.name_) {
          ss >> scene.fileOut_;
          ss >> scene.width_;
          ss >> scene.height_;

          std::cout << "Camera: " << scene.cam_ << "\n Output File: " << scene.fileOut_
          << "\n Resolution: " << scene.width_ << " x " << scene.height_ << std::endl;

        }

        else {
            // else camera object doesn't exist yet 
          std::cerr << "Camera " << camName << " does not exist." << std::endl;

        }

      }

        // Prints Comment Line 
      else if (keyword == "#") {
        std::cout << line << std::endl;
      }

    }
  }

  file.close();
 return scene;

}