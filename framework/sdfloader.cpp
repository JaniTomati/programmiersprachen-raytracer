// SDFloader.cpp (Ray-Tracer 7.1)

#include "sdfloader.hpp"
#include <map>

Scene loadSDF(std::string const& fileIn) {

  std::ifstream file;
  std::string line;
  file.open(fileIn); // opens input file 
  std::map<std::string, std::shared_ptr<Shape>> findeShape; // added with 7.2 composite
  Scene loadedScene; 

  if(file.is_open()) {
    // std::cout << "The file is open." << std::endl;

    while(std::getline(file, line)) {
     // std::cout << line << std::endl;

        // keyword 
      std::stringstream ss;
      std::string keyword; 

      ss << line;
      ss >> keyword;

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

          loadedScene.materials_[mat.name_] = mat;

          std::cout << "Added Material: " << mat << std::endl;
        }

          // Loads Shapes # geometry
        else if(keyword == "shape") {
          ss >> keyword;
          unsigned int vectorSizeShapes = 0;

          if(keyword == "box") {
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

            Material boxMat = loadedScene.materials_.find(boxClrName) -> second;

              // new entry in shapes_ (ptr)
            // loadedScene.shapes_.push_back(std::make_shared<Box>(boxName, boxMat, boxMin, boxMax));
            // ++vectorSizeShapes;

            auto box = std::make_shared<Box>(boxName, boxMat, boxMin, boxMax);
            findeShape[boxName] = box;

            // std::cout << "Added Box: " << *loadedScene.shapes_[vectorSizeShapes - 1] << std::endl;
            std::cout << "Added Box: " << *box << std::endl;
          }

          else if(keyword == "sphere") {
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
            Material sphereMat = loadedScene.materials_.find(sphereClrName) -> second;

              // new entry in shapes_ (ptr)
            // loadedScene.shapes_.push_back(std::make_shared<Sphere>(sphereName, sphereMat, sphereCtr, sphereRad));
            // ++vectorSizeShapes;

            auto sphere = std::make_shared<Sphere>(sphereName, sphereMat, sphereCtr, sphereRad);
            findeShape[sphereName] = sphere;
            // std::cout << "Added Sphere: " << *loadedScene.shapes_[vectorSizeShapes - 1] << std::endl;
            std::cout << "Added Sphere: " << *sphere << std::endl;
          }

            // loads composites # composites 
          else if(keyword == "composite") {
            std::string compositeName;
            std::string shapeName;

            ss >> compositeName;
            loadedScene.composite_ = std::make_shared<Composite>(compositeName);

            while(!ss.eof()) {
              ss >> shapeName;
              auto foundShape = findeShape.find(shapeName);

              if(foundShape != findeShape.end()) {
                loadedScene.composite_ -> addShape(foundShape -> second);
              } 

              else {
                std::cerr << "ERROR! Shape " << shapeName << " could not be found!" << "\n" << std::endl;
              }
            }
            std::cout << "Added Composite: \n" << *loadedScene.composite_ << std::endl;
          }
        }

          // Loads Light # light 
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
          loadedScene.lights_.push_back(LightSource {lightName, lightPos, diffuseLight, ambientLight});
          ++vectorSizeLight;

          std::cout << "Added Light: " << loadedScene.lights_[vectorSizeLight - 1] << std::endl;
        }

          // Loads Camera # camera
        else if(keyword == "camera") {
          std::string cameraName;
          double cameraAoV;
          glm::vec3 cameraPos;
          glm::vec3 cameraDir;
          glm::vec3 cameraUp;

          ss >> cameraName;
          ss >> cameraAoV;
          ss >> cameraPos.x;
          ss >> cameraPos.y;
          ss >> cameraPos.z;
          ss >> cameraDir.x;
          ss >> cameraDir.y;
          ss >> cameraDir.z;
          ss >> cameraUp.x;
          ss >> cameraUp.y;
          ss >> cameraUp.z;

          loadedScene.cam_ = Camera {cameraName, cameraAoV, cameraPos, cameraDir, cameraUp};

          std::cout << "Added Camera: " << loadedScene.cam_ << std::endl;
        }
      }

        // renders Scene # render 
      else if (keyword == "render") {
        std::string camName;
        ss >> camName;

          // checks whether camera exists so the frame can be rendered 
        if (camName == loadedScene.cam_.name_) {
          ss >> loadedScene.fileOut_;
          ss >> loadedScene.width_;
          ss >> loadedScene.height_;

          std::cout << "Camera: " << loadedScene.cam_.name_ << "\n" << "Output File: " << loadedScene.fileOut_
          << "\n" << "Resolution: " << loadedScene.width_ << " x " << loadedScene.height_ << "\n" <<std::endl;

        }

        else {
            // else camera object doesn't exist yet 
          std::cerr << "ERROR! Camera " << camName << " could not be found! \n" << std::endl;

        } 
      }

        // Prints Comment Line #
      else if (keyword == "#") {
        std::cout << line << std::endl;
      }

        // in case of wrong syntax 
      else {
        std::cerr << "ERROR! The following line: '" << line << "' could not be parsed! \n" << std::endl;
      }
    }

    file.close();
  }

  else {
    std:: cerr << "ERROR! The document " << fileIn << "could not be opened! \n" << std::endl;
  }

  return loadedScene;

}