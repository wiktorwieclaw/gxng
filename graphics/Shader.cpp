//
// Created by vixu on 1/2/21.
//

#include "Shader.h"

#include <cstring>

namespace gxng {

Shader::Shader() noexcept
    : id_{glCreateProgram()} {

}

void Shader::load(std::string_view vertexPath, std::string_view fragmentPath) {
  const auto vertexShader = initShader(GL_VERTEX_SHADER, vertexPath.data());
  const auto fragmentShader =
      initShader(GL_FRAGMENT_SHADER, fragmentPath.data());

  glAttachShader(id_, vertexShader);
  glAttachShader(id_, fragmentShader);
  glLinkProgram(id_);
  checkShaderLinkErrors();

  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);
}


auto Shader::initShader(GLenum type, std::string_view path) -> uint32_t {
  std::string source    = readFile(path);
  const auto shader     = glCreateShader(type);
  const auto cStrSource = source.c_str();
  glShaderSource(shader, 1, &cStrSource, nullptr);
  glCompileShader(shader);
  checkShaderCompileErrors(shader, path.data());
  return shader;
}

void Shader::bind() const noexcept { glUseProgram(id_); }

void Shader::unbind() const noexcept { glUseProgram(0); }

void Shader::setUniform1f(std::string_view name, float value) const noexcept {
  glUniform1f(glGetUniformLocation(id_, name.data()), value);
}

void Shader::setUniform1i(std::string_view name, int value) const noexcept {
  glUniform1i(glGetUniformLocation(id_, name.data()), value);
}

void Shader::setUniform2f(
    std::string_view name, const Vec2f& vec) const noexcept {
  glUniform2f(glGetUniformLocation(id_, name.data()), vec[0], vec[1]);
}

void Shader::setUniform3f(
    std::string_view name, const Vec3f& vec) const noexcept {
  glUniform3f(glGetUniformLocation(id_, name.data()), vec[0], vec[1], vec[2]);
}

void Shader::setUniform4f(
    std::string_view name, const Vec4f& vec) const noexcept {
  glUniform4f(
      glGetUniformLocation(id_, name.data()), vec[0], vec[1], vec[2], vec[3]);
}

void Shader::setUniformMat4x4f(
    std::string_view name, const Mat4x4f& matrix) const noexcept {
  glUniformMatrix4fv(glGetUniformLocation(id_, name.data()), 1, GL_FALSE,
      matrix.array().data());
}

void Shader::checkShaderCompileErrors(uint32_t shader, std::string_view path) {
  auto success = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
  if (!success) {
    auto maxLength = 0;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);
    std::vector<char> errorLog(maxLength);
    glGetShaderInfoLog(shader, maxLength, &maxLength, errorLog.data());
    const std::string message =
        "Shader compile error: " + std::string{path} + "\n" + errorLog.data();
    throw std::runtime_error{message};
  }
}

void Shader::checkShaderLinkErrors() const {
  using namespace std::string_literals;
  auto success = 0;
  glGetProgramiv(id_, GL_LINK_STATUS, &success);
  if (!success) {
    auto maxLength = 0;
    glGetShaderiv(id_, GL_INFO_LOG_LENGTH, &maxLength);
    std::vector<char> errorLog(maxLength);
    glGetProgramInfoLog(id_, maxLength, &maxLength, errorLog.data());
    const std::string message = "Shader link error:\n"s + errorLog.data();
    throw std::runtime_error{message};
  }
}

auto Shader::readFile(std::string_view path) -> std::string {
  FILE* file = fopen(path.data(), "rt");
  if (file == nullptr) {
    throw std::runtime_error{"Cannot open shader: " + std::string{path}};
  }
  fseek(file, 0, SEEK_END);
  unsigned long length = ftell(file);

  char* data = new char[length + 1];
  memset(data, 0, length + 1);
  fseek(file, 0, SEEK_SET);
  fread(data, 1, length, file);
  fclose(file);
  std::string result{data};
  delete[] data;
  return result;
}

}  // namespace gxng::graphics
