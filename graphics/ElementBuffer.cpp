//
// Created by vixu on 1/2/21.
//

#include "ElementBuffer.h"

namespace gxng::impl {

void ElementBuffer::bind() const noexcept {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
}

void ElementBuffer::unbind() const noexcept {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

}  // namespace gxng::impl