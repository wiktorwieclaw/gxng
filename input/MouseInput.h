//
// Created by vixu on 5/22/20.
//

#ifndef GXNG_MOUSEINPUT_H
#define GXNG_MOUSEINPUT_H

#include <functional>

#include "Action.h"
#include "Window.h"

namespace gxng {

class MouseInput {
 public:
  explicit MouseInput(Window& window);

  [[nodiscard]] auto isPressed(int buttonCode) const noexcept -> bool;

  [[nodiscard]] auto getPosX() const -> double;

  [[nodiscard]] auto getPosY() const -> double;

  void setButtonCallback(
      std::function<void(double, double, int, Action)> callback) noexcept;

 private:
  static void positionCallback(GLFWwindow* window, double xpos, double ypos);

  static void buttonCallback(
      GLFWwindow* window, int button, int action, int mods);

 private:
  Window& window_;
  double posX_ = 0.0;
  double posY_ = 0.0;
  std::function<void(double, double, int, Action)> buttonCallback_;
  static MouseInput* instance_;
};

}  // namespace gxng

#endif  // GXNG_MOUSEINPUT_H
