//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_ELEMENTBUFFER_H
#define GXNG_ELEMENTBUFFER_H

#include <array>
#include <cstdint>

#include "glad.h"

namespace gxng::impl {

class ElementBuffer {
 public:
  template <size_t size>
  explicit ElementBuffer(const std::array<uint16_t, size>& elements) noexcept;

  void bind() const noexcept;

  void unbind() const noexcept;

 private:
  uint32_t id_;
};

}  // namespace gxng::impl

#include "ElementBuffer.ipp"

#endif  // GXNG_ELEMENTBUFFER_H
