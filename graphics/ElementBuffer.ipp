//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_ELEMENTBUFFER_IPP
#define GXNG_ELEMENTBUFFER_IPP

namespace gxng::impl {

template <size_t size>
ElementBuffer::ElementBuffer(
    const std::array<uint16_t, size>& elements) noexcept
    : id_{} {
  glGenBuffers(1, &id_);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id_);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size * sizeof(decltype(elements)),
      elements.data(), GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

}  // namespace gxng::impl

#endif  // GXNG_ELEMENTBUFFER_IPP
