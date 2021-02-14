//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_SHADER_H
#define GXNG_SHADER_H

#include <string_view>

#include "glad.h"
#include "gxng_math.h"

namespace gxng {

class Shader {
 public:
  Shader() noexcept;

  void load(std::string_view vertexPath, std::string_view fragmentPath);

  void bind() const noexcept;

  void unbind() const noexcept;

  void setUniform1f(std::string_view name, float value) const noexcept;

  void setUniform1i(std::string_view name, int32_t value) const noexcept;

  void setUniform2f(std::string_view name, const Vec2f& matrix) const noexcept;

  void setUniform3f(std::string_view name, const Vec3f& matrix) const noexcept;

  void setUniform4f(std::string_view name, const Vec4f& matrix) const noexcept;

  void setUniformMat4x4f(
      std::string_view name, const Mat4x4f& matrix) const noexcept;

 private:
  static auto readFile(std::string_view path) -> std::string;

  [[nodiscard]] static auto initShader(GLenum type, std::string_view path)
      -> uint32_t;

  static void checkShaderCompileErrors(uint32_t shader, std::string_view path);

  void checkShaderLinkErrors() const;

 private:
  uint32_t id_;
};

}  // namespace gxng

#endif  // GXNG_SHADER_H
