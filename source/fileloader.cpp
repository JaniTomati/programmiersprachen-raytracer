// fileloader.cpp (Programmiersprachen Aufgabe 6) (Test)

#include <iostream>      
#include <fstream>
#include <sstream> 
#include <string>
#include <map>
#include "material.hpp"

int main() {

  std::ifstream file;
  std::string line;
  file.open("../doc/fivepointsix.txt");

  while (!file.eof()) {
    std::getline(file, line);

    Material mat;
    std::map<std::string, Material> materialmap;
    std::stringstream ss;
    std::string keyword; 

    ss << line; 
    ss >> keyword; 

    if (keyword == "define") {

      ss >> keyword;

      if (keyword == "material") {

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

        std::cout << mat << std::endl;
      }
    }

  }

	return 0;
}