//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_GXNG_MATH_H
#define GXNG_GXNG_MATH_H

#include <cmath>

#include "Mat.h"
#include "Vec.h"

namespace gxng {

using Vec2f   = impl::Vec<float, 2>;
using Vec2i   = impl::Vec<int32_t, 2>;
using Vec3f   = impl::Vec<float, 3>;
using Vec4f   = impl::Vec<float, 4>;
using Mat4x4f = impl::Mat4x4<float>;

auto makeOrthographicMatrix(float left, float right, float bottom,
    float top, float near, float far) -> Mat4x4f;

auto makePerspectiveMatrix(
    float fov, float aspectRatio, float near, float far) noexcept -> Mat4x4f;

auto makeTranslationMatrix(const Vec3f& translationVec) noexcept
    -> Mat4x4f;

auto makeScaleMatrix(const Vec3f& scaleVec) noexcept -> Mat4x4f;

auto makeRotationMatrix(float angle, const Vec3f& axis) noexcept
    -> Mat4x4f;

}  // namespace gxng::math

#endif  // GXNG_GXNG_MATH_H
