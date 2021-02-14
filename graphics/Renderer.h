//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_RENDERER_H
#define GXNG_RENDERER_H

#include "ElementBuffer.h"
#include "Shader.h"
#include "Sprite.h"
#include "VertexArray.h"

namespace gxng {

class Renderer {
 public:
  explicit Renderer(Shader shader);

  void draw(Vec2f position, Vec2f size,
      float rotation, Vec3f color, Texture texture);

  void draw(Vec2f position, Vec2f size, float rotation,
      Vec3f color);

  void draw(const Sprite& sprite);

 private:
  static auto createModel(Vec2f position, Vec2f size, float rotation)
      -> Mat4x4f;

 private:
  Shader shader_;
  impl::VertexArray vao_;
  impl::ElementBuffer ebo_;
};

}  // namespace gxng::graphics

#endif  // GX2D_ENGINE_RENDERER_H
