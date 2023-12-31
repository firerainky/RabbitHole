#include <RabbitConfig.h>
#include <GLFW/glfw3.h>
#include <iostream>

#ifdef USE_ADDER
  #include <adder.h>
#endif

int main(int argc, char **argv) {
  #ifdef USE_ADDER
    zky::add(2, 3);
  #else
      std::cout << "No adder."
                << "\n";
  #endif
  std::cout << "Hello, rabbit hole."
            << "\n";

  std::cout << argv[0] << " Version " << RABBIT_VERSION_MAJOR << "."
            << RABBIT_VERSION_MINOR << "\n";

  GLFWwindow *window;

  if (!glfwInit()) {
    fprintf(stderr, "Failed to initialize GLFW\n");
    exit(EXIT_FAILURE);
  }

  window = glfwCreateWindow(300, 300, "Gears", NULL, NULL);
  if (!window) {
    fprintf(stderr, "Failed to open GLFW window\n");
    glfwTerminate();
    exit(EXIT_FAILURE);
  }

  // Main loop
  while (!glfwWindowShouldClose(window)) {
    // Swap buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  // Terminate GLFW
  glfwTerminate();

  return 0;
}