//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_MAT_H
#define GXNG_MAT_H

#include <array>
#include <cstddef>

#include "utility.h"

namespace gxng::impl {

template <Number T>
class Mat4x4 {
 public:
  constexpr Mat4x4() noexcept;

  constexpr explicit Mat4x4(T diagonal) noexcept;

  constexpr auto operator[](size_t index) noexcept -> T&;

  constexpr auto operator[](size_t index) const noexcept -> const T&;

  constexpr auto multiply(const Mat4x4<T>& mat) noexcept -> Mat4x4<T>&;

  constexpr auto operator*=(const Mat4x4<T>& mat) noexcept -> Mat4x4<T>&;

  [[nodiscard]] constexpr auto array() const noexcept
      -> const std::array<T, 4 * 4>&;

 private:
  std::array<T, 4 * 4> array_;
};

template <Number T>
constexpr auto operator*(Mat4x4<T> lhs, const Mat4x4<T>& rhs) noexcept
    -> Mat4x4<T>;

}  // namespace gxng::math::impl

#include "Mat.ipp"

#endif  // GXNG_GXNG_MAT_H
