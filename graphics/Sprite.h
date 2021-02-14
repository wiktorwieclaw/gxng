//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_SPRITE_H
#define GXNG_SPRITE_H

#include "gxng_math.h"
#include "Texture.h"

namespace gxng {

class Sprite {
 public:
  Sprite() noexcept;

  Sprite(const Vec2f& position, const Vec2f& size, const Vec3f& color,
      const Texture& texture, float rotationAngle) noexcept;

  [[nodiscard]] auto getPosition() const noexcept -> const Vec2f&;

  [[nodiscard]] auto getSize() const noexcept -> const Vec2f&;

  [[nodiscard]] auto getColor() const noexcept -> const Vec3f&;

  [[nodiscard]] auto getTexture() const noexcept -> const Texture&;

  [[nodiscard]] auto getRotationAngle() const noexcept -> float;

  void setPosition(const Vec2f& position) noexcept;

  void setSize(const Vec2f& size) noexcept;

  void setColor(const Vec3f& color) noexcept;

  void setTexture(const Texture& texture) noexcept;

  void setRotationAngle(float rotationAngle) noexcept;

 private:
  Vec2f position_;
  Vec2f size_;
  Vec3f color_;
  Texture texture_;
  float rotationAngle_;
};

}  // namespace gxng

#endif  // GXNG_SPRITE_H
