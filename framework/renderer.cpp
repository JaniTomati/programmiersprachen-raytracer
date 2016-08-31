// -----------------------------------------------------------------------------
// Copyright  : (C) 2014 Andreas-C. Bernstein
// License    : MIT (see the file LICENSE)
// Maintainer : Andreas-C. Bernstein <andreas.bernstein@uni-weimar.de>
// Stability  : experimental
//
// Renderer
// -----------------------------------------------------------------------------

#include "renderer.hpp"

Renderer::Renderer(Scene const& scene) : 
  scene_ (scene),
  colorbuffer_(scene_.width_ * scene_.height_, Color(0.0, 0.0, 0.0)),
  ppm_(scene_.width_, scene_.height_)
  {}

// Renderer::Renderer(Scene const& scene, unsigned w, unsigned h, std::string const& file):
  //   scene_(scene)
  // , width_(w)
  // , height_(h)
  // , colorbuffer_(w*h, Color(0.0, 0.0, 0.0))
  // , ppm_(width_, height_)
  // {}

void Renderer::render() {
  //const std::size_t checkersize = 20;

  for (unsigned y = 0; y < scene_.height_; ++y) {
    for (unsigned x = 0; x < scene_.width_; ++x) {
      //glm::vec3 origin(float(x)/float(width_)*2.0f -1.0f, float(y)/float(height_)*2.0f-1.0f,0.0f);
      //glm::vec3 direction(0,0,-1.0);
      //Ray ray(origin, direction);
      Ray ray = scene_.cam_.calc_eye_ray(x,y,scene_.height_,scene_.width_);
  //for (unsigned y = 0; y < scene_.height_; ++y) {
    //for (unsigned x = 0; x < scene_.width_; ++x) {
      Pixel p(x,y);
      // glm::vec3 origin(float(x)/float(scene_.width_)*2.0f-1.0f, float(y)/float(scene_.height_)*2.0f-1.0f, 0.0f);
      // glm::vec3 direction(0, 0, -1.0);
      // Ray ray(origin, direction);

      p.color = raytrace(ray, 2);

      write(p);
    }
  }

  //ppm_.save(scene_.fileOut_);
  ppm_.save(scene_.fileOut_);
}

Color Renderer::raytrace(Ray const& ray, unsigned int depth) {
  // OptiHit closest;
  // for (auto const& shape : scene.shape_) 
  // geschweifteKlammerauf
  //   auto current = shape -> intersect
  //   falls was getroffen, ist current.distance näher???

  // closest shape that has been hit 
  // OptiHit closest = scene_.root->intersect(ray);

  //unsigned int x = 200;
  //unsigned int y = 200;
  //Pixel p(x,y);

  // Beispielszene mit einer Sphere und einem Licht
  // Material m1{"Plüschpelzpummel", {0.1f,0.2f,0.3f},
  // {0.3f,0.4f,0.5f}, {0.6f,0.7f,0.8f}, 0.9f};
  // Sphere debugSphere("Testsphäre",
  // m1, glm::vec3(0, 0, -3.0), 1.0);
  // LightSource heiligenschein{};
  OptiHit closest = scene_.composite_ -> intersect(ray); // = debugSphere.intersect(ray);
  Color color;

  if (closest.hit_){

    float c = 0.001;
    
    //Lichtberechnung

    for (auto const& lightsource : scene_.lights_){

      // Ray, das vom Oberflächenpunkt der Shape
      // aus zur Lightsource verläuft
      Ray lightray{closest.surface_pt_,
      lightsource.pos_-closest.surface_pt_};
      // Verschieben des Ursprungs weg von der Shape
      lightray.origin_ += lightray.direction_ * c;

      // Erstellen der Parameter für diffuse Beleuchtung
      glm::vec3 l = lightray.direction_;
      float nl = glm::dot(closest.normalen_vec_,l);

      //diffuse Lichtberechnung
      color = color + lightsource.ip_ *
      (closest.closest_shape_->material().diffuse()) *
      std::max(nl,0.0f) +
      lightsource.ia_ *
      (closest.closest_shape_->material().ambient());
      
    }
  }
  
  else {
    color = Color(0,0,0); // black (background)
  }

  return color;



  /*for (auto const& shape : scene_.shapes_) { 
    auto current = shape -> intersect; 

    if (current.distance_ < closest.distance_) {
      closest = current;
    }
  }*/

    //BÖRNS
  // Sphere debugSphere(glm::vec3(0, 0, -3.0), 1.0);
  // auto optihit = debugSphere.intersect(ray);

  // unsigned int x = 200;
  // unsigned int y = 200;
  // Pixel p(x,y);
  // if (optihit.hit_) {
  //   return Color(1,1,1); // white 
  // } else {
  //   return Color(0,0,0); // black (background)
  //   }
    
    // nDotL = std::max(0.0, glm::dot(n,l))
}

void Renderer::write(Pixel const& p) {
  // flip pixels, because of opengl glDrawPixels
  size_t buf_pos = (scene_.width_*p.y + p.x);
  if (buf_pos >= colorbuffer_.size() || (int)buf_pos < 0) {
    std::cerr << "Fatal Error Renderer::write(Pixel p) : "
      << "pixel out of ppm_ : "
      << (int)p.x << "," << (int)p.y
      << std::endl;
  } else {
    colorbuffer_[buf_pos] = p.color;
  }

  ppm_.write(p);
}