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
  REQUIRE(Approx(4.24f) == b2.area());

  Box b3 {{-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(Approx(58.48f) == b3.area());

  Box b4 {{-2.8f, 1.1f, -1.9f}, {-3.3f, 6.9f, -4.2f}};
  REQUIRE(Approx(30.18f) == b4.area());
  
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

  REQUIRE("Shape" == b1.name());

  REQUIRE(0.0f == b1.color().r);
  REQUIRE(0.0f == b1.color().g);
  REQUIRE(0.0f == b1.color().b);


  Box b2 {{1.0f, 2.3f, 4.1f}, {0.0f, 2.5f, 1.2f}};
  REQUIRE(1.0f == b2.minimum().x);
  REQUIRE(2.3f == b2.minimum().y);
  REQUIRE(4.1f == b2.minimum().z);

  REQUIRE(0.0f == b2.maximum().x);
  REQUIRE(2.5f == b2.maximum().y);
  REQUIRE(1.2f == b2.maximum().z);

  REQUIRE("Shape" == b2.name());

  REQUIRE(0.0f == b2.color().r);
  REQUIRE(0.0f == b2.color().g);
  REQUIRE(0.0f == b2.color().b);


  Box b3 {"Box 3", {1.0f, 0.3f, 0.5f}, {-1.0f, -4.3f, 5.6f}, {-9.0f, 1.5f, -2.2f}};
  REQUIRE(-1.0f == b3.minimum().x);
  REQUIRE(-4.3f == b3.minimum().y);
  REQUIRE(5.6f == b3.minimum().z);

  REQUIRE(-9.0f == b3.maximum().x);
  REQUIRE(1.5f == b3.maximum().y);
  REQUIRE(-2.2f == b3.maximum().z);

  REQUIRE("Box 3" == b3.name());

  REQUIRE(1.0f == b3.color().r);
  REQUIRE(0.3f == b3.color().g);
  REQUIRE(0.5f == b3.color().b);

}

TEST_CASE("Sphere: constructor tests", "[aufgabe5.3]") {
  Sphere s1 {};
  REQUIRE(0.0f == s1.center().x);
  REQUIRE(0.0f == s1.center().y);
  REQUIRE(0.0f == s1.center().z);

  REQUIRE(0.0f == s1.radius());

  REQUIRE("Shape" == s1.name());

  REQUIRE(0.0f == s1.color().r);
  REQUIRE(0.0f == s1.color().g);
  REQUIRE(0.0f == s1.color().b);
  
  Sphere s2 {{0.4f, 2.3f, 1.2f}, 4.3f};
  REQUIRE(0.4f == s2.center().x);
  REQUIRE(2.3f == s2.center().y);
  REQUIRE(1.2f == s2.center().z);

  REQUIRE(4.3f == s2.radius());

  REQUIRE("Shape" == s2.name());

  REQUIRE(0.0f == s2.color().r);
  REQUIRE(0.0f == s2.color().g);
  REQUIRE(0.0f == s2.color().b);

  Sphere s3 {"Sphere 3", {0.9f, 0.35f, 0.2f}, {6.9f, 4.2f, -1.2f}, -6.9f};
  REQUIRE(6.9f == s3.center().x);
  REQUIRE(4.2f == s3.center().y);
  REQUIRE(-1.2f == s3.center().z);

  REQUIRE(-6.9f == s3.radius());

  REQUIRE("Sphere 3" == s3.name());

  REQUIRE(0.9f == s3.color().r);
  REQUIRE(0.35f == s3.color().g);
  REQUIRE(0.2f == s3.color().b);

}

/* ------------------ Main ------------------ */

int main(int argc, char *argv[]) {
  return Catch::Session().run(argc, argv);
}

/* ------------------------------------------ */
