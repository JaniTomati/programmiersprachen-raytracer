// main.cpp (Programmiersprachen Aufgabenblatt 5)

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "sphere.hpp"
#include "box.hpp"

/* ------------------ Aufgabe 5.2 ------------------ */

TEST_CASE("Sphere: gets member ctr_ (center)", "[aufgabe5.2]") {
  Sphere s1 {}; // default constructor test
  REQUIRE(0.0f == s1.center().x);
  REQUIRE(0.0f == s1.center().y);
  REQUIRE(0.0f == s1.center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.center().x);
  REQUIRE(2.3f == s2.center().y);
  REQUIRE(1.2f == s2.center().z);

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  REQUIRE(6.9f == s3.center().x);
  REQUIRE(4.2f == s3.center().y);
  REQUIRE(-1.2f == s3.center().z);
}

TEST_CASE("Sphere: gets member rad_ (radius)", "[aufgabe5.2]") {
  Sphere s1 {}; // default constructor test
  REQUIRE(0.0f == s1.radius());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  REQUIRE(-4.3f == s2.radius());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  REQUIRE(4.3f == s3.radius());
}

TEST_CASE("Sphere: sets member ctr_ (center)", "[aufgabe5.2]") {
  Sphere s1 {}; 
  s1.center({1.0f, 1.0f, 1.0f});
  REQUIRE(1.0f == s1.center().x);
  REQUIRE(1.0f == s1.center().y);
  REQUIRE(1.0f == s1.center().z);

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  s2.center({3.4f, 4.2f, -1.0f});
  REQUIRE(3.4f == s2.center().x);
  REQUIRE(4.2f == s2.center().y);
  REQUIRE(-1.0f == s2.center().z);

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  s3.center({9.1f, -6.9f, -10.2f});
  REQUIRE(9.1f == s3.center().x);
  REQUIRE(-6.9f == s3.center().y);
  REQUIRE(-10.2f == s3.center().z);
}

TEST_CASE("Sphere: sets member rad_ (radius)", "[aufgabe5.2]") {
  Sphere s1 {}; 
  s1.radius(4.2f);
  REQUIRE(4.2f == s1.radius());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, -4.3f};
  s2.radius(-6.29f);
  REQUIRE(-6.29f == s2.radius());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, 4.3f};
  s3.radius(2.811f);
  REQUIRE(2.811f == s3.radius());
}

TEST_CASE("Sphere: gets area of sphere object", "[aufgabe5.2]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.area());
  
  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(Approx(232.3522f) == s2.area());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(Approx(598.2849f) == s3.area());

  Sphere s4 {{6.9f, 4.2f, -1.2f}, 1.25f};
  REQUIRE(Approx(19.635f) == s4.area());

  auto s5 = std::make_shared<Sphere>(Sphere{{6.9f, 4.2f, -1.2f}, 1.25f});
  std::shared_ptr<Shape> shape = s5;
  REQUIRE(Approx(19.635f) == shape -> area());
}

TEST_CASE("Sphere: gets volume of sphere object", "[aufgabe5.2]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.volume());

  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(Approx(333.0381f) == s2.volume());

  Sphere s3 {{6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(Approx(1376.0553f) == s3.volume());

  Sphere s4 {{6.9f, 4.2f, -1.2f}, 1.25f};
  REQUIRE(Approx(8.18123f) == s4.volume());

  auto s5 = std::make_shared<Sphere>(Sphere{{6.9f, 4.2f, -1.2f}, 1.25f});
  std::shared_ptr<Shape> shape = s5;
  REQUIRE(Approx(8.18123f) == shape -> volume());

}

TEST_CASE("Box: gets member min_ (minimum)", "[aufgabe5.2]") {
  Box b1 {}; // test default constructor 
  REQUIRE(0.0f == b1.minimum().x);
  REQUIRE(0.0f == b1.minimum().y);
  REQUIRE(0.0f == b1.minimum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(1.0f == b2.minimum().x);
  REQUIRE(2.3f == b2.minimum().y);
  REQUIRE(4.1f == b2.minimum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-1.0f == b3.minimum().x);
  REQUIRE(-4.3f == b3.minimum().y);
  REQUIRE(5.6f == b3.minimum().z);
}

TEST_CASE("Box: gets member max_ (maximum)", "[aufgabe5.2]") {
  Box b1 {}; // test default constructor 
  REQUIRE(0.0f == b1.maximum().x);
  REQUIRE(0.0f == b1.maximum().y);
  REQUIRE(0.0f == b1.maximum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(0.0f == b2.maximum().x);
  REQUIRE(2.5f == b2.maximum().y);
  REQUIRE(1.2f == b2.maximum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-9.0f == b3.maximum().x);
  REQUIRE(1.5f == b3.maximum().y);
  REQUIRE(-2.2f == b3.maximum().z);
}

TEST_CASE("Box: sets member min_ (minimum)", "[aufgabe5.2]"){
  Box b1 {};
  b1.minimum({1.0f, 1.0f, 1.0f});
  REQUIRE(1.0f == b1.minimum().x);
  REQUIRE(1.0f == b1.minimum().y);
  REQUIRE(1.0f == b1.minimum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  b2.minimum({-3.5f, 2.4f, -11.3f});
  REQUIRE(-3.5f == b2.minimum().x);
  REQUIRE(2.4f == b2.minimum().y);
  REQUIRE(-11.3f == b2.minimum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  b3.minimum({-2.2f, 12.3f, -0.9f});
  REQUIRE(-2.2f == b3.minimum().x);
  REQUIRE(12.3f == b3.minimum().y);
  REQUIRE(-0.9f == b3.minimum().z);
}

TEST_CASE("Box: sets member max_ (maximum)", "[aufgabe5.2]"){
  Box b1 {};
  b1.maximum({1.0f, 1.0f, 1.0f});
  REQUIRE(1.0f == b1.maximum().x);
  REQUIRE(1.0f == b1.maximum().y);
  REQUIRE(1.0f == b1.maximum().z);

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  b2.maximum({-3.5f, 2.4f, -11.3f});
  REQUIRE(-3.5f == b2.maximum().x);
  REQUIRE(2.4f == b2.maximum().y);
  REQUIRE(-11.3f == b2.maximum().z);

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  b3.maximum({-2.2f, 12.3f, -0.9f});
  REQUIRE(-2.2f == b3.maximum().x);
  REQUIRE(12.3f == b3.maximum().y);
  REQUIRE(-0.9f == b3.maximum().z);
}

TEST_CASE("Box: gets area of box object", "[aufgabe5.2]") {
  Box b1 {};
  REQUIRE(0.0f == b1.area());

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(Approx(7.36f) == b2.area());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(308.08f) == b3.area());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(34.78f) == b4.area());

  auto b5 = std::make_shared<Box>(Box{{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}});
  std::shared_ptr<Shape> box = b5;
  REQUIRE(Approx(34.78f) == box -> area());
  
}

TEST_CASE("Box: gets volume of box object", "[aufgabe5.2]") {
  Box b1 {};
  REQUIRE(0.0f == b1.volume());

  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(Approx(0.58f) == b2.volume());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(361.92f) == b3.volume());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(6.67f) == b4.volume());

  auto b5 = std::make_shared<Box>(Box{{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}});
  std::shared_ptr<Shape> box = b5;
  REQUIRE(Approx(6.67f) == box -> volume());
} 

/* ------------------ Aufgabe 5.3 ------------------ */

TEST_CASE("Box: constructor tests", "[aufgabe5.3]") {
  Box b1 {};
  REQUIRE(0.0f == b1.minimum().x);
  REQUIRE(0.0f == b1.minimum().y);
  REQUIRE(0.0f == b1.minimum().z);

  REQUIRE(0.0f == b1.maximum().x);
  REQUIRE(0.0f == b1.maximum().y);
  REQUIRE(0.0f == b1.maximum().z);

  REQUIRE("Box" == b1.name());

  REQUIRE("Material" == b1.material().name_);
  REQUIRE(0.0f == b1.material().ambient().r);
  REQUIRE(0.0f == b1.material().ambient().g);
  REQUIRE(0.0f == b1.material().ambient().b);
  REQUIRE(0.0f == b1.material().diffuse().r);
  REQUIRE(0.0f == b1.material().diffuse().g);
  REQUIRE(0.0f == b1.material().diffuse().b);
  REQUIRE(0.0f == b1.material().specular().r);
  REQUIRE(0.0f == b1.material().specular().g);
  REQUIRE(0.0f == b1.material().specular().b);
  REQUIRE(0.0f == b1.material().m_);


  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(1.0f == b2.minimum().x);
  REQUIRE(2.3f == b2.minimum().y);
  REQUIRE(4.1f == b2.minimum().z);

  REQUIRE(0.0f == b2.maximum().x);
  REQUIRE(2.5f == b2.maximum().y);
  REQUIRE(1.2f == b2.maximum().z);

  REQUIRE("Box" == b2.name());

  REQUIRE("Material" == b2.material().name_);
  REQUIRE(0.0f == b2.material().ambient().r);
  REQUIRE(0.0f == b2.material().ambient().g);
  REQUIRE(0.0f == b2.material().ambient().b);
  REQUIRE(0.0f == b2.material().diffuse().r);
  REQUIRE(0.0f == b2.material().diffuse().g);
  REQUIRE(0.0f == b2.material().diffuse().b);
  REQUIRE(0.0f == b2.material().specular().r);
  REQUIRE(0.0f == b2.material().specular().g);
  REQUIRE(0.0f == b2.material().specular().b);
  REQUIRE(0.0f == b2.material().m_);


  Box b3 {"Box 3", {"Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-1.0f == b3.minimum().x);
  REQUIRE(-4.3f == b3.minimum().y);
  REQUIRE(5.6f == b3.minimum().z);

  REQUIRE(-9.0f == b3.maximum().x);
  REQUIRE(1.5f == b3.maximum().y);
  REQUIRE(-2.2f == b3.maximum().z);

  REQUIRE("Box 3" == b3.name());

  REQUIRE("Eisen" == b3.material().name_);
  REQUIRE(1.0f == b3.material().ambient().r);
  REQUIRE(2.2f == b3.material().ambient().g);
  REQUIRE(4.2f == b3.material().ambient().b);
  REQUIRE(3.3f == b3.material().diffuse().r);
  REQUIRE(4.4f == b3.material().diffuse().g);
  REQUIRE(5.5f == b3.material().diffuse().b);
  REQUIRE(3.1f == b3.material().specular().r);
  REQUIRE(5.0f == b3.material().specular().g);
  REQUIRE(0.1f == b3.material().specular().b);
  REQUIRE(3.2f == b3.material().m_);

} 

TEST_CASE("Sphere: constructor tests", "[aufgabe5.3]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.center().x);
  REQUIRE(0.0f == s1.center().y);
  REQUIRE(0.0f == s1.center().z);

  REQUIRE(0.0f == s1.radius());

  REQUIRE("Sphere" == s1.name());

  REQUIRE("Material" == s1.material().name_);
  REQUIRE(0.0f == s1.material().ambient().r);
  REQUIRE(0.0f == s1.material().ambient().g);
  REQUIRE(0.0f == s1.material().ambient().b);
  REQUIRE(0.0f == s1.material().diffuse().r);
  REQUIRE(0.0f == s1.material().diffuse().g);
  REQUIRE(0.0f == s1.material().diffuse().b);
  REQUIRE(0.0f == s1.material().specular().r);
  REQUIRE(0.0f == s1.material().specular().g);
  REQUIRE(0.0f == s1.material().specular().b);
  REQUIRE(0.0f == s1.material().m_);
  
  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.center().x);
  REQUIRE(2.3f == s2.center().y);
  REQUIRE(1.2f == s2.center().z);
  
  REQUIRE(4.3f == s2.radius());

  REQUIRE("Sphere" == s2.name());

  REQUIRE("Material" == s2.material().name_);
  REQUIRE(0.0f == s2.material().ambient().r);
  REQUIRE(0.0f == s2.material().ambient().g);
  REQUIRE(0.0f == s2.material().ambient().b);
  REQUIRE(0.0f == s2.material().diffuse().r);
  REQUIRE(0.0f == s2.material().diffuse().g);
  REQUIRE(0.0f == s2.material().diffuse().b);
  REQUIRE(0.0f == s2.material().specular().r);
  REQUIRE(0.0f == s2.material().specular().g);
  REQUIRE(0.0f == s2.material().specular().b);
  REQUIRE(0.0f == s2.material().m_);


  Sphere s3 {"Sphere 3", {"Aluminium", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(6.9f == s3.center().x);
  REQUIRE(4.2f == s3.center().y);
  REQUIRE(-1.2f == s3.center().z);

  REQUIRE(-6.9f == s3.radius());

  REQUIRE("Sphere 3" == s3.name());

  REQUIRE("Aluminium" == s3.material().name_);
  REQUIRE(1.0f == s3.material().ambient().r);
  REQUIRE(2.2f == s3.material().ambient().g);
  REQUIRE(4.2f == s3.material().ambient().b);
  REQUIRE(3.3f == s3.material().diffuse().r);
  REQUIRE(4.4f == s3.material().diffuse().g);
  REQUIRE(5.5f == s3.material().diffuse().b);
  REQUIRE(3.1f == s3.material().specular().r);
  REQUIRE(5.0f == s3.material().specular().g);
  REQUIRE(0.1f == s3.material().specular().b);
  REQUIRE(3.2f == s3.material().m_);
} 

/* ------------------ Aufgabe 5.5 ------------------ */

TEST_CASE("Shape: print method", "[aufgabe5.5]") {
  Sphere s1 {{0.4f, 2.3f, 1.2f}, 4.3f};
  std::cout << s1 << std::endl;

  Sphere s2 {"Kugel", {"Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  std::cout << s2 << std::endl;

  Box b1 {};
  std::cout << b1 << std::endl;

  auto b2 = std::make_shared<Box>(Box{"Schachtel", {}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}});
  b2 -> print(std::cout);
  std::cout << std::endl;
} 

/* ------------------ Aufgabe 5.6 ------------------ */

TEST_CASE("intersectRaySphere", "[aufgabe5.6]") {
  // Ray
  glm::vec3 ray_origin{0.0f, 0.0f, 0.0f};
  // ray direction has to be normalized !
  // you can use : 
  // v = glm::normalize(some_vector)
  glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};

  // Sphere
  glm::vec3 sphere_center{0.0f, 0.0f, 5.0f};
  float sphere_radius{1.0f};

  float distance{0.0f};
  auto result = glm::intersectRaySphere(
    ray_origin, ray_direction,
    sphere_center,
    sphere_radius * sphere_radius, // squared radius !!!
    distance);

  REQUIRE(distance == Approx(4.0f));

} 

/* ------------------ Aufgabe 5.7 ------------------ */

TEST_CASE("static and dynamic variables", "[aufgabe5.7]") {
  /* Allgemein: 
  STATISCH: zur Uebersetzungszeit festgelegt oder gebunden, kann zur Lauftzeit nicht
  veraendert werden (Bsp: Java, C++). 
  - Variablen werden mit Typ versehen, typabhängige Fehlererkennung, schnellere Ausfuehrung als dynamisch typisierte Sprachen
  DYNAMISCH: nicht festgelegt bis zur Laufzeit des Programms. Erlaubt veraenderungen
  waehrend des Programmablaufs (Bsp: Scheme, Javascript).
  - Variablen sind nur Namen, Typen sind mit Weten verbunden, keine Deklarationen, deshalb groessere Flexibilitaet*/

  Color red(255, 0, 0); 
  Material mat("Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f);
  glm::vec3 position(0, 0, 0); 

  // Adresse eines Sphere-Objektes wird an eine Zeigervariable vom Typ Sphere zugewiesen
  std::shared_ptr<Sphere> s1 = // statische Klasse
    std::make_shared<Sphere>("sphere0", mat, position, 1.2); // dynamische Klasse 
    // statische und dynamische Klasse sind identisch

  // Adresse eines Sphere-Objektes wird an eine Zeigervariable vom Typ der Basisklasse Shape zugewiesen
  std::shared_ptr<Shape> s2 = // statische Klasse
    std::make_shared<Sphere>("sphere1", mat, position, 1.2); // dynamische Klasse
    // statische und dynamische Klasse unterscheiden sich
    

  /* Im Kontext der Vererbung erlauben statisch typisierte OO-Sprachen, dass die dynamische Klasse
   eine von der statischen Klasse abgeleitete Klasse sein kann. 
   Die dynamische Klasse bestimmt bei virtuellen Funktionen, welche Methode ausgefuehrt wird. */

  std::cout << std::endl;
  s1 -> print(std::cout); 
  std::cout << std::endl;
  s2 -> print(std::cout);
  std::cout << std::endl;
} 

/* ------------------ Aufgabe 5.8 ------------------ */

TEST_CASE("Destructor: virtual vs. non-virtual", "[aufgabe5.8]") {
  // Color red(255, 0, 0); 
  Material mat("Eisen", {1.0f, 2.2f, 4.2f}, {3.3f, 4.4f, 5.5f}, {3.1f, 5.0f, 0.1f}, 3.2f);
  glm::vec3 position(0, 0, 0);

  Sphere* s0 = new Sphere("sphere0", mat, position, 1.2); 
  Shape* s1 = new Sphere("sphere1", mat, position, 1.2); // s ist polymorph

  std::cout << std::endl;
  s0 -> print(std::cout); 
  std::cout << std::endl;
  s1 -> print(std::cout);
  std::cout << std::endl;

  delete s0; 
  delete s1; 

  /* virtual: ruft erst den Unterklassen-Destruktor (Sphere), dann den Basisklasse (Shape) für beide Beispiele
     non-virtual: Sphere0: ruft zuerst den Destruktor der Klasse Sphere, dann den der Klasse (Shape)
     Sphere1: Ruft nur den Destruktor der Klasse Shape 
     => kommt zu Resource Leak, bei dem die erworbenen Ressourcen nicht mehr vom Programm freigegeben werden

     Ist der Destruktor nicht als virtual deklariert kommt es zu "undefinied behaviour", was zu bugs fuehren kann. 
     Virtual Destructors sind immer dann nuetzlich, wenn eine Klasse polymorph verwendet wird (bzw. mindestens eine 
     virtuelle Funktion vorhanden ist)
     http://stackoverflow.com/questions/461203/when-to-use-virtual-destructors */
} 

/* ------------------ Main ------------------ */

int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}

/* ------------------------------------------ */
