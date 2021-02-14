//
// Created by vixu on 5/22/20.
//

#include "MouseInput.h"

#include <stdexcept>
#include <utility>

namespace gxng {

MouseInput* MouseInput::instance_;

MouseInput::MouseInput(Window& window) : window_{window} {
  if (instance_ == nullptr)
    instance_ = this;
  else
    throw std::runtime_error{"There can be only one MouseInput object"};

  glfwSetCursorPosCallback(
      window.getGLFWwindow(), MouseInput::positionCallback);

  glfwSetMouseButtonCallback(
      window.getGLFWwindow(), MouseInput::buttonCallback);
}

auto MouseInput::isPressed(int buttonCode) const noexcept -> bool {
  return glfwGetMouseButton(window_.getGLFWwindow(), buttonCode);
}

auto MouseInput::getPosX() const -> double { return posX_; }

auto MouseInput::getPosY() const -> double { return posY_; }

void MouseInput::positionCallback(
    GLFWwindow* window, double xpos, double ypos) {
  instance_->posX_ = xpos;
  instance_->posY_ = ypos;
}

void MouseInput::buttonCallback(
    GLFWwindow* window, int button, int action, int mods) {
  instance_->buttonCallback_(
      instance_->posX_, instance_->posY_, button, static_cast<Action>(action));
}

void MouseInput::setButtonCallback(
    std::function<void(double, double, int, Action)> callback) noexcept {
  buttonCallback_ = std::move(callback);
}

}  // namespace gxng