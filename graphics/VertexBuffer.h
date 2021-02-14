//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_VERTEXBUFFER_H
#define GXNG_VERTEXBUFFER_H

#include <array>
#include <cstdint>

#include "glad.h"

namespace gxng::impl {

class VertexBuffer {
 public:
  template <std::size_t size>
  VertexBuffer(const std::array<float, size>& vertices,
      size_t vecComponentCount) noexcept;

  void bind() const noexcept;

  void unbind() const noexcept;

  [[nodiscard]] auto getComponentCount() const -> size_t;

 private:
  uint32_t id_;
  const size_t vecComponentCount_;
};

}  // namespace gxng::impl

#include "VertexBuffer.ipp"

#endif  // GXNG_VERTEXBUFFER_H
