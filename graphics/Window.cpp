//
// Created by vixu on 1/2/21.
//

#include "Window.h"

#include <stdexcept>

namespace gxng {

Window::Window(uint32_t width, uint32_t height, std::string_view title)
    : width(width), height(height) {
  if (!glfwInit()) {
    throw std::runtime_error{"GLFW initialization error"};
  }

  glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
  glfwWindow_ = glfwCreateWindow(width, height, title.data(), nullptr, nullptr);
  glfwSetWindowSizeLimits(glfwWindow_, width, height, width, height);

  glfwMakeContextCurrent(glfwWindow_);
  glfwSetWindowUserPointer(glfwWindow_, this);

  if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
    throw std::runtime_error{"GLAD initialization error!"};
  }

  glfwSetFramebufferSizeCallback(glfwWindow_, Window::frameBufferCallback);
  glViewport(0, 0, width, height);
}

Window::~Window() { glfwTerminate(); }

void Window::update() const noexcept {
  glfwPollEvents();
  glfwSwapBuffers(glfwWindow_);
}

auto Window::getGLFWwindow() const noexcept -> GLFWwindow* {
  return glfwWindow_;
}

auto Window::shouldClose() const noexcept -> bool {
  return glfwWindowShouldClose(glfwWindow_);
}

void Window::frameBufferCallback(
    GLFWwindow* window, int width, int height) noexcept {
  glViewport(0, 0, width, height);
}

void Window::clear() const noexcept {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

auto Window::getWidth() const -> int { return width; }

auto Window::getHeight() const -> int { return height; }

}  // namespace gxng::graphics