//
// Created by vixu on 1/2/21.
//

#include "Texture.h"

#include <stdexcept>

#include "../lib/lodepng/lodepng.h"
#include "AutoBinder.h"

namespace gxng {

Texture::Texture() : width_{}, height_{}, id_{} { glGenTextures(1, &id_); }

void Texture::bind() const noexcept { glBindTexture(GL_TEXTURE_2D, id_); }

void Texture::unbind() noexcept { glBindTexture(GL_TEXTURE_2D, 0); }

void Texture::loadImage(std::string_view path) {
  AutoBinder bufferBinder{*this};
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrappingOption_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrappingOption_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filteringOption_);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filteringOption_);

  std::vector<uint8_t> out;
  if (auto error = lodepng::decode(out, width_, height_, path.data());
      error != 0) {
    throw std::runtime_error(
        "Can't load image: " + std::string(path) +
        "\n make sure to set your working directory in IDE");
  }

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA,
      GL_UNSIGNED_BYTE, out.data());
  glGenerateMipmap(GL_TEXTURE_2D);
}

}  // namespace gxng
