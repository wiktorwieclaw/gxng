//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_TEXTURE_H
#define GXNG_TEXTURE_H

#include "glad.h"

#include <string_view>

namespace gxng {

class Texture {
 public:
  Texture();

  void bind() const noexcept;

  static void unbind() noexcept;

  void loadImage(std::string_view path);

 private:
  uint32_t width_;
  uint32_t height_;
  uint32_t id_;
  GLenum wrappingOption_  = GL_REPEAT;
  GLenum filteringOption_ = GL_NEAREST;
};

}  // namespace gxng::graphics
#endif  // GXNG_TEXTURE_H
