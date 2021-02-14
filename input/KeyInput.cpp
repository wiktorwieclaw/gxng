//
// Created by vixu on 5/22/20.
//

#include "KeyInput.h"
#include <stdexcept>

namespace gxng {

KeyInput* KeyInput::instance_;

KeyInput::KeyInput(Window& window) : window_{window} {
  if (instance_ == nullptr) {
    instance_ = this;
  } else {
    throw std::runtime_error{"There can be only one KeyInput object"};
  }

  glfwSetKeyCallback(window.getGLFWwindow(), KeyInput::callbackCaller);
}

auto KeyInput::isPressed(int glfwKeyCode) const noexcept -> bool {
  return glfwGetKey(window_.getGLFWwindow(), glfwKeyCode);
}

void KeyInput::callbackCaller(
    GLFWwindow* window, int key, int scancode, int action, int mode) noexcept {
  instance_->callback_(key, static_cast<Action>(action));
}

void KeyInput::setCallback(std::function<void(int, Action)> callback) noexcept {
  callback_ = std::move(callback);
}

}  // namespace gxng
