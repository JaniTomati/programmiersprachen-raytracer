#include <thread>
#include <renderer.hpp>
#include <fensterchen.hpp>
#include <sdfloader.hpp>

int main(int argc, char* argv[]) {
  Scene scene = loadSDF("../doc/rendertest.txt");
  // unsigned const width = 600;
  // unsigned const height = 600;
  // std::string const filename = "./checkerboard.ppm";

  Renderer app(scene);

  std::thread thr([&app]() { app.render(); });

  Window win(glm::ivec2(scene.width_, scene.height_));

  while (!win.shouldClose()) {
    if (win.isKeyPressed(GLFW_KEY_ESCAPE)) {
      win.stop();
    }

    glDrawPixels(scene.width_, scene.height_, GL_RGB, GL_FLOAT
                , app.colorbuffer().data());

    win.update();
  }

  thr.join();

  return 0;
}
