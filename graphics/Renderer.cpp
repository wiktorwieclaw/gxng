//
// Created by vixu on 1/2/21.
//

#include "Renderer.h"

#include "AutoBinder.h"

namespace gxng {

// clang-format off
Renderer::Renderer(Shader shader)
    : shader_{shader},
      vao_{},
      ebo_{std::array<uint16_t, 2 * 3> {
            0, 1, 2,
            0, 3, 1
          }} {
  constexpr std::array vertices{
      // pos      // tex
      0.0f, 1.0f, 0.0f, 1.0f,
      1.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 0.0f,
      1.0f, 1.0f, 1.0f, 1.0f,
  };

  vao_.addBuffer(impl::VertexBuffer{vertices, 4}, 0);
}
// clang-format on

void Renderer::draw(Vec2f position, Vec2f size, float rotation,
    Vec3f color, Texture texture) {
  AutoBinder textureBinder{texture};
  draw(position, size, rotation, color);
}

void Renderer::draw(
    Vec2f position, Vec2f size, float rotation, Vec3f color) {
  AutoBinder shaderBinder{shader_};
  auto model = createModel(position, size, rotation);
  shader_.setUniformMat4x4f("model", model);
  shader_.setUniform3f("spriteColor", color);

  AutoBinder vaoBinder{vao_};
  AutoBinder eboBinder{ebo_};
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, nullptr);
}

void Renderer::draw(const Sprite& sprite) {
  draw(sprite.getPosition(), sprite.getSize(), sprite.getRotationAngle(),
      sprite.getColor(), sprite.getTexture());
}

auto Renderer::createModel(
    Vec2f position, Vec2f size, float rotation) -> Mat4x4f {
  auto model = makeTranslationMatrix(Vec3f{position[0], position[1], 0.0f});
  model *= makeTranslationMatrix(Vec3f{0.5f * size[0], 0.5f * size[1], 0.0f});
  model *= makeRotationMatrix(rotation, Vec3f{0.0f, 0.0f, 1.0f});
  model *= makeTranslationMatrix(Vec3f{-0.5f * size[0], -0.5f * size[1], 0.0f});
  model *= makeScaleMatrix(Vec3f{size[0], size[1], 1.0f});
  return model;
}

}  // namespace gxng::graphics