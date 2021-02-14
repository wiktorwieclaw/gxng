//
// Created by vixu on 1/2/21.
//

#include "Sprite.h"

namespace gxng {

Sprite::Sprite() noexcept
    : position_{}, size_{}, color_{}, texture_{}, rotationAngle_{} {}

Sprite::Sprite(const Vec2f& position, const Vec2f& size, const Vec3f& color,
    const Texture& texture, float rotationAngle) noexcept
    : position_{position},
      size_{size},
      color_{color},
      texture_{texture},
      rotationAngle_{rotationAngle} {}

auto Sprite::getPosition() const noexcept -> const Vec2f& { return position_; }

auto Sprite::getSize() const noexcept -> const Vec2f& { return size_; }

auto Sprite::getColor() const noexcept -> const Vec3f& { return color_; }

auto Sprite::getTexture() const noexcept -> const Texture& { return texture_; }

auto Sprite::getRotationAngle() const noexcept -> float {
  return rotationAngle_;
}

void Sprite::setPosition(const Vec2f& position) noexcept {
  position_ = position;
}

void Sprite::setSize(const Vec2f& size) noexcept { size_ = size; }

void Sprite::setColor(const Vec3f& color) noexcept { color_ = color; }

void Sprite::setTexture(const Texture& texture) noexcept { texture_ = texture; }

void Sprite::setRotationAngle(float rotationAngle) noexcept {
  rotationAngle_ = rotationAngle;
}

}  // namespace gxng