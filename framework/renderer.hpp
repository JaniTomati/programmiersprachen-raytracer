// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#ifndef BUW_RENDERER_HPP
#define BUW_RENDERER_HPP
#include "scene.hpp"
#include "color.hpp"
#include "ray.hpp"
#include "shape.hpp"
#include "sphere.hpp"
#include "pixel.hpp"
#include "ppmwriter.hpp"
#include <string>
#include <glm/glm.hpp>

class Renderer {

public:
  Renderer(unsigned w, unsigned h, std::string const& file);

  void render();
  void write(Pixel const& p);
  Color raytrace(Ray const& ray, unsigned int depth);

  // Color shade(OptiHit const&, Ray const& ray, unsigned int depth);

  inline std::vector<Color> const& colorbuffer() const {
    return colorbuffer_;
  }

private:
  Scene scene_;
  unsigned width_;
  unsigned height_;
  std::vector<Color> colorbuffer_;
  std::string filename_;
  PpmWriter ppm_;
};

#endif // #ifndef BUW_RENDERER_HPP
