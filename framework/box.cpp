// box.cpp (Programmiersprachen Aufgabe 5)

#include "box.hpp"

    // Default Constructor 
  Box::Box() : 
  Shape {"Box", {}},
  min_ {0.0f, 0.0f, 0.0f}, 
  max_ {0.0f, 0.0f, 0.0f} {}

    // Constructor takes min and max
  Box::Box(glm::vec3 const& min, glm::vec3 const& max) :
  Shape {"Box", {}}, 
  min_ {min}, 
  max_ {max} {
      // corrects user input
    min_.x = std::min(min.x, max.x);
    min_.y = std::min(min.y, max.y);
    min_.z = std::min(min.z, max.z);
    max_.x = std::max(min.x, max.x);
    max_.y = std::max(min.y, max.y);
    max_.z = std::max(min.z, max.z);
  }

    // Constructor takes name, color, min and max
  Box::Box(std::string const& name, Material const& mat, glm::vec3 const& min, glm::vec3 const& max) : 
  Shape {name, mat},
  min_ {min}, 
  max_ {max} {
      // corrects user input
    min_.x = std::min(min.x, max.x);
    min_.y = std::min(min.y, max.y);
    min_.z = std::min(min.z, max.z);
    max_.x = std::max(min.x, max.x);
    max_.y = std::max(min.y, max.y);
    max_.z = std::max(min.z, max.z);
  }

    // Destructor
  Box::~Box() {
    
  }

    // gets area of box object
  float Box::area() const {
    glm::vec3 difference = max_ - min_;
    return 2 * (std::abs(difference.x * difference.y) + std::abs(difference.x * difference.z) + std::abs(difference.y * difference.z));
  }
  
    // gets volume of box object
  float Box::volume() const {
    glm::vec3 difference = max_ - min_;
    return std::abs(difference.x * difference.y * difference.z);
  }

    // prints Box object
  std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum: (" << min_.x << ", " 
    << min_.y << ", " 
    << min_.z << ")" << "\n" 
    << "Maximum: (" << max_.x << ", " 
    << max_.y << ", " 
    << max_.z << ")" << std::endl;
    return os;
  }

    // get maximum
  glm::vec3 const& Box::maximum() const {
    return max_;
  }

    // get minimum
  glm::vec3 const& Box::minimum() const {
    return min_;
  }

    // set maximum
  void Box::maximum(glm::vec3 const& max) {
    max_ = max;
  }

    // set maximum
  void Box::minimum(glm::vec3 const& min) {
    min_ = min;
  }

 OptiHit Box::intersect(Ray const& ray) const{

  OptiHit hit{this};
  int z_1{0};
  int z_2{0};
  int z_3{0};
  float s_1{0};
  float s_2{0};
  float s_3{0};

  //Ebenen parallel zur y,z-Ebene
  if (ray.direction().x != 0){
    //für die Seiten beim Minimum
    glm::vec3 schnittpunkt_1{};
    float v_1 = (min_.x-ray.origin().x) / ray.direction().x;
    schnittpunkt_1.x = ray.origin().x + v_1*ray.direction().x;
    schnittpunkt_1.y = ray.origin().y + v_1*ray.direction().y;
    schnittpunkt_1.z = ray.origin().z + v_1*ray.direction().z;
    //für die Seiten beim Maximum
    glm::vec3 schnittpunkt_2{};
    float v_2 = (max_.x-ray.origin().x) / ray.direction().x;
    schnittpunkt_2.x = ray.origin().x + v_2*ray.direction().x;
    schnittpunkt_2.y = ray.origin().y + v_2*ray.direction().y;
    schnittpunkt_2.z = ray.origin().z + v_2*ray.direction().z;
    //Tests ob Schnittpunkte in der Box
    //beide in Box
    if (is_in_box(min_, max_, schnittpunkt_1) == true &&
      is_in_box(min_, max_, schnittpunkt_2) == true)
    {
      s_1 = std::min( distance_two_vecs(schnittpunkt_1,ray.origin()),
      distance_two_vecs(schnittpunkt_2,ray.origin()) );
      z_1 = 1;
    }
    //nur schnittpunkt_1 in box
    if (is_in_box(min_, max_, schnittpunkt_1) == true &&
      is_in_box(min_, max_, schnittpunkt_2) == false)
    {
      s_1 = distance_two_vecs(schnittpunkt_1,ray.origin());
      z_1 = 1;
    }
    //nur schnittpunkt_2 in box
    if (is_in_box(min_, max_, schnittpunkt_1) == false &&
      is_in_box(min_, max_, schnittpunkt_2) == true)
    {
      s_1 = distance_two_vecs(schnittpunkt_2,ray.origin());
      z_1 = 1;
    }
    //std::cout << "Erstens: distance = " << s_1 << " und " << z_1 << std::endl;
  }
  //Ebenen parallel zur x,z-Ebene
  if (ray.direction().y != 0){
    //für die Seiten beim Minimum
    glm::vec3 schnittpunkt_1{};
    float v_1 = (min_.y-ray.origin().y) / ray.direction().y;
    schnittpunkt_1.x = ray.origin().x + v_1*ray.direction().x;
    schnittpunkt_1.y = ray.origin().y + v_1*ray.direction().y;
    schnittpunkt_1.z = ray.origin().z + v_1*ray.direction().z;
    //für die Seiten beim Maximum
    glm::vec3 schnittpunkt_2{};
    float v_2 = (max_.y-ray.origin().y) / ray.direction().y;
    schnittpunkt_2.x = ray.origin().x + v_2*ray.direction().x;
    schnittpunkt_2.y = ray.origin().y + v_2*ray.direction().y;
    schnittpunkt_2.z = ray.origin().z + v_2*ray.direction().z;
    //Tests ob Schnittpunkte in der Box
    //beide in Box
    if (is_in_box(min_, max_, schnittpunkt_1) == true &&
      is_in_box(min_, max_, schnittpunkt_2) == true)
    {
      s_2 = std::min( distance_two_vecs(schnittpunkt_1,ray.origin()),
      distance_two_vecs(schnittpunkt_2,ray.origin()) );
      z_2 = 1;
    }
    //nur schnittpunkt_1 in box
    if (is_in_box(min_, max_, schnittpunkt_1) == true &&
      is_in_box(min_, max_, schnittpunkt_2) == false)
    {
      s_2 = distance_two_vecs(schnittpunkt_1,ray.origin());
      z_2 = 1;
    }
    //nur schnittpunkt_2 in box
    if (is_in_box(min_, max_, schnittpunkt_1) == false &&
      is_in_box(min_, max_, schnittpunkt_2) == true)
    {
      s_2 = distance_two_vecs(schnittpunkt_2,ray.origin());
      z_2 = 1;
    }
    //std::cout << "Zweitens: distance = " << s_2 << " und " << z_2 << std::endl;
  }
  //Ebenen parallel zur x,y-Ebene
  if (ray.direction().z != 0){
    //für die Seiten beim Minimum
    glm::vec3 schnittpunkt_1{};
    float v_1 = (min_.z-ray.origin().z) / ray.direction().z;
    schnittpunkt_1.x = ray.origin().x + v_1*ray.direction().x;
    schnittpunkt_1.y = ray.origin().y + v_1*ray.direction().y;
    schnittpunkt_1.z = ray.origin().z + v_1*ray.direction().z;
    //für die Seiten beim Maximum
    glm::vec3 schnittpunkt_2{};
    float v_2 = (max_.z-ray.origin().z) / ray.direction().z;
    schnittpunkt_2.x = ray.origin().x + v_2*ray.direction().x;
    schnittpunkt_2.y = ray.origin().y + v_2*ray.direction().y;
    schnittpunkt_2.z = ray.origin().z + v_2*ray.direction().z;
    //Tests ob Schnittpunkte in der Box
    //beide in Box
    if (is_in_box(min_, max_, schnittpunkt_1) == true &&
      is_in_box(min_, max_, schnittpunkt_2) == true)
    {
      s_3 = std::min( distance_two_vecs(schnittpunkt_1,ray.origin()),
      distance_two_vecs(schnittpunkt_2,ray.origin()) );
      z_3 = 1;
    }
    //nur schnittpunkt_1 in box
    if (is_in_box(min_, max_, schnittpunkt_1) == true &&
      is_in_box(min_, max_, schnittpunkt_2) == false)
    {
      s_3 = distance_two_vecs(schnittpunkt_1,ray.origin());
      z_3 = 1;
    }
    //nur schnittpunkt_2 in box
    if (is_in_box(min_, max_, schnittpunkt_1) == false &&
      is_in_box(min_, max_, schnittpunkt_2) == true)
    {
      s_3 = distance_two_vecs(schnittpunkt_2,ray.origin());
      z_3 = 1;
    }
    //std::cout << "Drittens: distance = " << s_3 << " und " << z_3 << std::endl;
  }

  //drei Schnittpunkte
  if (z_1 == 1 && z_2 == 1 && z_3 == 1){
    hit.distance_ = std::min(std::min(s_1,s_2),s_3);
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }

  //zwei Schnittpunkte
  if (z_1 == 1 && z_2 == 1 && z_3 == 0){
    hit.distance_ = std::min(s_1,s_2);
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }
  if (z_1 == 1 && z_3 == 1 && z_2 == 0){
    hit.distance_ = std::min(s_1,s_3);
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }
  if (z_2 == 1 && z_3 == 1 && z_1 == 0){
    hit.distance_ = std::min(s_2,s_3);
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }
  
  //ein Schnittpunkt
  if (z_1 == 0 && z_2 == 0 && z_3 == 1){
    hit.distance_ = s_3;
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }
  if (z_1 == 0 && z_3 == 0 && z_2 == 1){
    hit.distance_ = s_2;
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }
  if (z_2 == 0 && z_3 == 0 && z_1 == 1){
    hit.distance_ = s_1;
    hit.hit_ = true;
    hit.surface_pt_ = this->calc_surface_pt(ray, hit.distance_);
    hit.normalen_vec_ = this->calc_normalen_vec(hit);
  }

  //kein Schnittpunkt
  if (z_1 == 0 && z_2 == 0 && z_3 == 0){
    hit.hit_ = false;
  }

  return hit;
}

//Zusatz zu intersect
glm::vec3 Box::calc_normalen_vec(OptiHit const& hit) const {
  auto surface_pt = hit.surface_pt_; 
  if(surface_pt.x == Approx(min_.x)){
    return glm::vec3{-1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(min_.y)){
    return glm::vec3{0.0,-1.0,0.0};
  }
  if(surface_pt.z == Approx(min_.z)){
    return glm::vec3{0.0,0.0,-1.0};
  }
  if(surface_pt.x == Approx(max_.x)){
    return glm::vec3{1.0,0.0,0.0};
  }
  if(surface_pt.y == Approx(max_.y)){
    return glm::vec3{0.0,1.0,0.0};
  }
  if(surface_pt.z == Approx(max_.z)){
    return glm::vec3{0.0,0.0,1.0};
  }
}

// member function: checks whether a given point is in a box or not
bool Box::in_box(glm::vec3 const& test) const{
  bool result = false;
  if (test.x >= min_.x && test.x <= max_.x){
      if (test.y >= min_.y && test.y <= max_.y){
        if (test.z >= min_.z && test.z <= max_.z){
          result = true;
        }
      }
    }
    return result;
}

// free function: checks whether a given point is in a box or not 
bool is_in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point) {
  Box b {min, max};
    return b.in_box(point);
}

float distance_two_vecs(glm::vec3 const& p1, glm::vec3 const& p2) {
  return sqrt((p1.x-p2.x)*(p1.x-p2.x) +
    (p1.y-p2.y)*(p1.y-p2.y) +
    (p1.z-p2.z)*(p1.z-p2.z));
}