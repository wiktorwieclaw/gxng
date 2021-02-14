//
// Created by vixu on 1/2/21.
//

#include "VertexBuffer.h"

namespace gxng::impl {

void VertexBuffer::bind() const noexcept { glBindBuffer(GL_ARRAY_BUFFER, id_); }

void VertexBuffer::unbind() const noexcept { glBindBuffer(GL_ARRAY_BUFFER, 0); }

auto VertexBuffer::getComponentCount() const -> size_t {
  return vecComponentCount_;
}

}  // namespace gxng::impl
