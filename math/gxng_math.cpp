//
// Created by vixu on 12/31/20.
//

#include "gxng_math.h"

namespace gxng {

auto makeOrthographicMatrix(float left, float right, float bottom,
    float top, float near, float far) -> Mat4x4f {
  const auto a = right - left;
  const auto b = top - bottom;
  const auto c = near - far;
  if (a == 0.0f || b == 0.0f || c == 0.0f) {
    throw std::runtime_error("Cannot divide by 0.");
  }

  Mat4x4f newMat;
  newMat[0 + 0 * 4] = 2.0f / a;
  newMat[1 + 1 * 4] = 2.0f / b;
  newMat[2 + 2 * 4] = 2.0f / c;
  newMat[0 + 3 * 4] = (left + right) / (-a);
  newMat[1 + 3 * 4] = (bottom + top) / (-b);
  newMat[2 + 3 * 4] = (far + near) / (-a);
  newMat[3 + 3 * 4] = 1.0f;
  return newMat;
}

auto makePerspectiveMatrix(
    float fov, float aspectRatio, float near, float far) noexcept -> Mat4x4f {
  // TODO: division by 0 exception
  Mat4x4f result;
  const float q = 1.0f / std::tan(impl::toRadians(0.5f * fov));
  const float a = q / aspectRatio;
  const float b = (near + far) / (near - far);
  const float c = (2.0f * near * far) / (near - far);

  result[0 + 0 * 4] = a;
  result[1 + 1 * 4] = q;
  result[2 + 2 * 4] = b;
  result[3 + 3 * 4] = -1.0f;
  result[3 + 2 * 4] = c;
  return result;
}

auto makeTranslationMatrix(const Vec3f& translationVec) noexcept
    -> Mat4x4f {
  Mat4x4f result{1.0f};
  result[0 + 3 * 4] = translationVec[0];
  result[1 + 3 * 4] = translationVec[1];
  result[2 + 3 * 4] = translationVec[2];
  return result;
}

auto makeScaleMatrix(const Vec3f& scaleVec) noexcept -> Mat4x4f {
  Mat4x4f result;
  result[0 + 0 * 4] = scaleVec[0];
  result[1 + 1 * 4] = scaleVec[1];
  result[2 + 2 * 4] = scaleVec[2];
  result[3 + 3 * 4] = 1.0f;
  return result;
}

auto makeRotationMatrix(float angle, const Vec3f& axis) noexcept
    -> Mat4x4f {
  Mat4x4f result;
  const float r   = impl::toRadians(angle);
  const float c   = std::cos(r);
  const float s   = std::sin(r);
  const float omc = 1.0f - c;

  const float& x = axis[0];
  const float& y = axis[1];
  const float& z = axis[2];

  result[0 + 0 * 4] = x * x * omc + c;
  result[1 + 0 * 4] = y * x * omc + z * s;
  result[2 + 0 * 4] = x * z * omc - y * s;

  result[0 + 1 * 4] = x * y * omc - z * s;
  result[1 + 1 * 4] = y * y * omc + c;
  result[2 + 1 * 4] = y * z * omc + x * s;

  result[0 + 2 * 4] = x * z * omc + y * s;
  result[1 + 2 * 4] = y * z * omc - x * s;
  result[2 + 2 * 4] = z * z * omc + c;

  result[3 + 3 * 4] = 1.0f;

  return result;
}

}  // namespace gxng::math