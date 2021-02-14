//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_VERTEXARRAY_H
#define GXNG_VERTEXARRAY_H

#include <memory>
#include <vector>

#include "VertexBuffer.h"
#include "glad.h"

namespace gxng::impl {

class VertexArray {
 public:
  VertexArray() noexcept;

  void addBuffer(VertexBuffer&& buffer, uint32_t attributeIndex) noexcept;

  void bind() const noexcept;

  void unbind() const noexcept;

 private:
  GLuint id_;
  std::vector<VertexBuffer> buffers_;
};

}  // namespace gxng::impl

#endif  // GXNG_VERTEXARRAY_H
