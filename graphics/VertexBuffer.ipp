//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_VERTEXBUFFER_IPP
#define GXNG_VERTEXBUFFER_IPP

#include "AutoBinder.h"

namespace gxng::impl {

template <std::size_t size>
VertexBuffer::VertexBuffer(
    const std::array<float, size>& vertices, size_t vecComponentCount) noexcept
    : vecComponentCount_(vecComponentCount), id_{} {
  glGenBuffers(1, &id_);
  AutoBinder bufferBinder{*this};
  glBufferData(
      GL_ARRAY_BUFFER, size * sizeof(float), vertices.data(), GL_STATIC_DRAW);
}

}  // namespace gxng::impl

#endif  // GXNG_VERTEXBUFFER_IPP
