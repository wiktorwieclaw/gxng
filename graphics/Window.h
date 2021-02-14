//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_WINDOW_H
#define GXNG_WINDOW_H

#include <string_view>

// clang-format off
// reversing order leads to compilation error
#include "glad.h"
#include <GLFW/glfw3.h>
// clang-format on

namespace gxng {

class Window {
 public:
  Window(uint32_t width, uint32_t height, std::string_view title);

  ~Window();

  void update() const noexcept;

  [[nodiscard]] auto getGLFWwindow() const noexcept -> GLFWwindow*;

  [[nodiscard]] auto getWidth() const -> int;

  [[nodiscard]] auto getHeight() const -> int;

  [[nodiscard]] auto shouldClose() const noexcept -> bool;

  void clear() const noexcept;

  static void frameBufferCallback(
      GLFWwindow* window, int width, int height) noexcept;

 private:
  GLFWwindow* glfwWindow_;
  uint32_t width, height;
};

}  // namespace gxng::graphics

#endif  // GXNG_WINDOW_H