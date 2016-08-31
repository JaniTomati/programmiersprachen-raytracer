#include <thread>
#include <renderer.hpp>
#include <fensterchen.hpp>
//#include <sdfloader.hpp>

int main(int argc, char* argv[]) {
  Scene scene = loadSDF("../doc/BeispielSzene1.txt");
  unsigned const width = scene.width_;
  unsigned const height = scene.height_;
  std::string const filename = scene.fileOut_;
  // unsigned const width = 600;
  // unsigned const height = 600;
  // std::string const filename = "./checkerboard.ppm";

  Renderer app(scene);
  // Renderer app(width, height, filename);
  // Renderer app(scene, width, height, filename);

  std::thread thr([&app]() { app.render(); });

  //Window win(glm::ivec2(scene.width_, scene.height_));
  Window win(glm::ivec2(width,height));

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }

    //glDrawPixels(scene.width_, scene.height_, GL_RGB, GL_FLOAT
    glDrawPixels( width, height, GL_RGB, GL_FLOAT
                , app.colorbuffer().data());

    win.update();
  }

  thr.join();

  return 0;
}
