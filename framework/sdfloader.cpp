// SDFloader.cpp (Ray-Tracer 7.1)

#include "scene.hpp"
#include "renderer.hpp"

void Scene::loadSDF(std::string const& file_in) {

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

          materials_[mat.name_] = mat;

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
            Material sphereMat = materials_.find(sphereClrName) -> second;

              // new entry in shapes_ (ptr)
            shapes_.push_back(std::make_shared<Sphere>(sphereName, sphereMat, sphereCtr, sphereRad));
            ++vectorSizeShapes;

            std::cout << "Added Sphere: " << *shapes_[vectorSizeShapes - 1] << std::endl; 
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

            Material boxMat = materials_.find(boxClrName) -> second;

              // new entry in shapes_ (ptr)
            shapes_.push_back(std::make_shared<Box>(boxName, boxMat, boxMin, boxMax));
            ++vectorSizeShapes;

            std::cout << "Added Box: " << *shapes_[vectorSizeShapes - 1] << std::endl; 
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
          light_.push_back(std::make_shared<LightSource>(lightName, lightPos, diffuseLight, ambientLight));
          ++vectorSizeLight;

          std::cout << "Added Light: " << *light_[vectorSizeLight - 1] << std::endl;
        }

          // Loads Camera # camera
        else if(keyword == "camera") {
          std::string cameraName;
          double cameraAoV;

          ss >> cameraName;
          ss >> cameraAoV;

          cam_ = std::make_shared<Camera>(cameraName, cameraAoV);

          std::cout << "Added Camera: " << cam_ << std::endl;
        }
      }

        // Renders Scene 
      else if (keyword == "render") {
        // ... do
      }

    }
  }

  file.close();
  
}