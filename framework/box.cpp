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

  bool Box::intersect(Ray const& ray, float& t) const {
    bool result = true;
    int z_1 = 0;
    int z_2 = 0;
    int z_3 = 0;

    if (ray.direction().x != 0) {
    //für die Seiten beim Minimum
      glm::vec3 schnittpunkt_1{};
      float v_1 = (min_.x - ray.origin().x) / ray.direction().x;
      schnittpunkt_1.x = ray.origin().x + v_1 * ray.direction().x;
      schnittpunkt_1.y = ray.origin().y + v_1 * ray.direction().y;
      schnittpunkt_1.z = ray.origin().z + v_1 * ray.direction().z;

    //für die Seiten beim Maximum
      glm::vec3 schnittpunkt_2{};
      float v_2 = (max_.x - ray.origin().x) / ray.direction().x;
      schnittpunkt_2.x = ray.origin().x + v_2 * ray.direction().x;
      schnittpunkt_2.y = ray.origin().y + v_2 * ray.direction().y;
      schnittpunkt_2.z = ray.origin().z + v_2 * ray.direction().z;

    //Test ob einer der Schnittpunkte in der Box ist
      if (in_box(schnittpunkt_1) == true || in_box(schnittpunkt_2) == true) {
        z_1 = 1;
      }
    }

  //Ebenen parallel zur x,z-Ebene
    if (ray.direction().y != 0) {

    //für die Seiten beim Minimum
      glm::vec3 schnittpunkt_1{};
      float v_1 = (min_.y - ray.origin().y) / ray.direction().y;
      schnittpunkt_1.x = ray.origin().x + v_1 * ray.direction().x;
      schnittpunkt_1.y = ray.origin().y + v_1 * ray.direction().y;
      schnittpunkt_1.z = ray.origin().z + v_1 * ray.direction().z;

    //für die Seiten beim Maximum
      glm::vec3 schnittpunkt_2{};
      float v_2 = (max_.y - ray.origin().y) / ray.direction().y;
      schnittpunkt_2.x = ray.origin().x + v_2 * ray.direction().x;
      schnittpunkt_2.y = ray.origin().y + v_2 * ray.direction().y;
      schnittpunkt_2.z = ray.origin().z + v_2 * ray.direction().z;

    //Test ob einer der Schnittpunkte in der Box ist
      if (in_box(schnittpunkt_1) == true || in_box(schnittpunkt_2) == true) {
        z_2 = 1;
      }
    }

  //Ebenen parallel zur x,y-Ebene
    if (ray.direction().z != 0){
    //für die Seiten beim Minimum
      glm::vec3 schnittpunkt_1{};
      float v_1 = (min_.z - ray.origin().z) / ray.direction().z;
      schnittpunkt_1.x = ray.origin().x + v_1 * ray.direction().x;
      schnittpunkt_1.y = ray.origin().y + v_1 * ray.direction().y;
      schnittpunkt_1.z = ray.origin().z + v_1 * ray.direction().z;
    //für die Seiten beim Maximum
      glm::vec3 schnittpunkt_2{};
      float v_2 = (max_.z - ray.origin().z) / ray.direction().z;
      schnittpunkt_2.x = ray.origin().x + v_2 * ray.direction().x;
      schnittpunkt_2.y = ray.origin().y + v_2 * ray.direction().y;
      schnittpunkt_2.z = ray.origin().z + v_2 * ray.direction().z;
    //Test ob einer der Schnittpunkte in der Box ist
      if (in_box(schnittpunkt_1) == true || in_box(schnittpunkt_2) == true) {
        z_3 = 1;
      }
    }
 
    t = 0; //Distanz ist 0, da Schnittpunkt

  //kein Schnittpunkt
    if (z_1 == 0 && z_2 == 0 && z_3 == 0){
      result = false;
    //Distanz muss noch berechnet werden!!!
    }

    return result;
  }

    // member function: checks whether a given point is in a box or not
  bool Box::in_box(glm::vec3 const& point) const {
    bool result = false;
    if (point.x >= min_.x && point.x <= max_.x) {
      if (point.y >= min_.y && point.y <= max_.y) {
        if (point.z >= min_.z && point.z <= max_.z) {
          result = true;
        }
      }
    }
    return result;
  }

    // free function: checks whether a given point is in a box or not 
  bool in_box(glm::vec3 const& min, glm::vec3 const& max, glm::vec3 const& point) {
    Box b {min, max};
    return b.in_box(point);
  }