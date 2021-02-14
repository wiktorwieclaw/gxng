//
// Created by vixu on 1/2/21.
//

#include "VertexArray.h"

#include "AutoBinder.h"

namespace gxng::impl {

VertexArray::VertexArray() noexcept : id_{} { glGenVertexArrays(1, &id_); }

void VertexArray::addBuffer(
    VertexBuffer&& buffer, uint32_t attributeIndex) noexcept {
  AutoBinder arrayBinder{*this};
  AutoBinder bufferBinder{buffer};

  glEnableVertexAttribArray(attributeIndex);
  glVertexAttribPointer(attributeIndex, buffer.getComponentCount(), GL_FLOAT,
      GL_FALSE, 0, nullptr);

  buffers_.push_back(buffer);
}

void VertexArray::bind() const noexcept { glBindVertexArray(id_); }

void VertexArray::unbind() const noexcept { glBindVertexArray(0); }

}  // namespace gxng::impl