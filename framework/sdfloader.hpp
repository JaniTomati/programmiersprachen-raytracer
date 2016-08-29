// // SDFloader.hpp (Ray-Tracer 7.1)

#ifndef BUW_SDFLOADER_HPP
#define BUW_SDFLOADER_HPP
#include "scene.hpp"

struct SDFloader {

  Scene loadSDF(std::string const& fileIn);

};

#endif // BUW_SDFLOADER_HPP