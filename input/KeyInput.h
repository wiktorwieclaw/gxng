//
// Created by vixu on 5/22/20.
//

#ifndef GXNG_KEYINPUT_H
#define GXNG_KEYINPUT_H

#include <functional>

#include "Action.h"
#include "Window.h"

namespace gxng {

class KeyInput {
 public:
  explicit KeyInput(Window& window);

  void setCallback(std::function<void(int, Action)> callback) noexcept;

  [[nodiscard]] auto isPressed(int glfwKeyCode) const noexcept -> bool;

 private:
  static void callbackCaller(
      GLFWwindow* window, int key, int scancode, int action, int mode) noexcept;

 private:
  Window& window_;
  std::function<void(int, Action)> callback_;
  static KeyInput* instance_;
};

}  // namespace gxng

#endif  // GXNG_KEYINPUT_H
