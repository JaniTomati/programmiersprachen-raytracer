// shape.cpp (Programmiersprachen Aufgabenblatt 5)

#include "shape.hpp"

  // default Constructor 
Shape::Shape() :
name_ {"Default Shape"}, 
mat_ {},
worldTransform_ {},
worldTransformInv_ {glm::inverse(worldTransform_)} {}

  // Constructor takes name and color 
Shape::Shape(std::string const& name, Material const& mat) : 
name_ {name},
mat_ {mat},
worldTransform_ {},
worldTransformInv_ {glm::inverse(worldTransform_)} {}

  // Constructor added with 7.6 (Transformations)
Shape::Shape(std::string const& name, Material const& mat, Matrix const& worldTransform) : 
name_ {name},
mat_ {mat},
worldTransform_ {worldTransform},
worldTransformInv_ {glm::inverse(worldTransform_)} {}

  // Destructor 
Shape::~Shape() {
  
}

  // get name 
std::string Shape::name() const {
  return name_;
}

  // get material
Material const& Shape::material() const {
  return mat_; 
}

  // get worldTransform_
Matrix Shape::world_transformation() const {
  return worldTransform_;
}

  // get worldTransformInv_
Matrix Shape::world_transformation_inv() const {
  return worldTransformInv_;
}

  // prints shape object
std::ostream& Shape::print(std::ostream& os) const {
  os << "Name: " << name_ << "\n" 
  << "Material: " << mat_;
  return os;
}

glm::vec3 Shape::calc_surface_pt(Ray const& ray, float distance) const {
  glm::vec3 surface_pt{ray.origin_ + ray.direction_*distance};
  return surface_pt;
}

  // Translation: shifitng one point around a vector (q = T p)
void Shape::translate(glm::vec3 const& v) {
  Matrix translateMat;
  translateMat[0] = glm::vec4 {1.0f, 0.0f, 0.0f, 0.0f};
  translateMat[1] = glm::vec4 {0.0f, 1.0f, 0.0f, 0.0f};
  translateMat[2] = glm::vec4 {0.0f, 0.0f, 1.0f, 0.0f};
  translateMat[3] = glm::vec4 {v, 1.0f};

  worldTransform_ = translateMat * worldTransform_;
  worldTransformInv_ = glm::inverse(worldTransform_);
}

  // Scaling: scaling a point relativ to the origin 
void Shape::scale(glm::vec3 const& s) {
  Matrix scaleMat;
  scaleMat[0] = glm::vec4 {s.x, 0.0f, 0.0f, 0.0f};
  scaleMat[1] = glm::vec4 {0.0f, s.y, 0.0f, 0.0f};
  scaleMat[2] = glm::vec4 {0.0f, 0.0f, s.x, 0.0f};
  scaleMat[3] = glm::vec4 {0.0f, 0.0f, 0.0f, 1.0f};

  worldTransform_ = scaleMat * worldTransform_;
  worldTransformInv_ = glm::inverse(worldTransform_);
}

  // Rotation: rotation relating x-axis
void Shape::rotateX(float phi) {
  Matrix rotationMat;
  rotationMat[0] = glm::vec4 {1.0f, 0.0f, 0.0f, 0.0f};
  rotationMat[1] = glm::vec4 {0.0f, cos(phi), sin(phi), 0.0f};
  rotationMat[2] = glm::vec4 {0.0f, -sin(phi), cos(phi), 0.0f};
  rotationMat[3] = glm::vec4 {0.0f, 0.0f, 0.0f, 1.0f};

  worldTransform_ = rotationMat * worldTransform_;
  worldTransformInv_ = glm::inverse(worldTransform_);
}

  // Rotation: rotation relating y-axis
void Shape::rotateY(float phi) {
  Matrix rotationMat;
  rotationMat[0] = glm::vec4 {cos(phi), 0.0f, -sin(phi), 0.0f};
  rotationMat[1] = glm::vec4 {0.0f, 1.0f, 0.0f, 0.0f};
  rotationMat[2] = glm::vec4 {sin(phi), 0.0f, cos(phi), 0.0f};
  rotationMat[3] = glm::vec4 {0.0f, 0.0f, 0.0f, 1.0f};

  worldTransform_ = rotationMat * worldTransform_;
  worldTransformInv_ = glm::inverse(worldTransform_);
}

  // Rotation: rotation relating z-axis
void Shape::rotateZ(float phi) {
  Matrix rotationMat;
  rotationMat[0] = glm::vec4 {cos(phi), sin(phi), 0.0f, 0.0f};
  rotationMat[1] = glm::vec4 {-sin(phi), cos(phi), 0.0f, 0.0f};
  rotationMat[2] = glm::vec4 {0.0f, 0.0f, 1.0f, 0.0f};
  rotationMat[3] = glm::vec4 {0.0f, 0.0f, 0.0f, 1.0f};

  worldTransform_ = rotationMat * worldTransform_;
  worldTransformInv_ = glm::inverse(worldTransform_);
}

  // prints Shape object (overloading << operator)
std::ostream& operator << (std::ostream& os, Shape const& s) {
  return s.print(os);
}
