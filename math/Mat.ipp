//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_MAT_IPP
#define GXNG_MAT_IPP

namespace gxng::impl {

template <Number T>
constexpr Mat4x4<T>::Mat4x4() noexcept {
  array_.fill(0);
}

template <Number T>
constexpr Mat4x4<T>::Mat4x4(T diagonal) noexcept : array_{} {
  array_.fill(0);
  for (size_t i = 0; i < 4; ++i) {
    array_[i + i * 4] = diagonal;
  }
}

template <Number T>
constexpr auto Mat4x4<T>::operator[](size_t index) noexcept -> T& {
  return const_cast<T&>(static_cast<const Mat4x4<T>&>(*this)[index]);
}

template <Number T>
constexpr auto Mat4x4<T>::operator[](size_t index) const noexcept -> const T& {
  return array_[index];
}

template <Number T>
constexpr auto Mat4x4<T>::multiply(const Mat4x4<T>& mat) noexcept
    -> Mat4x4<T>& {
  for (size_t x = 0; x < 4; ++x) {
    for (size_t y = 0; y < 4; ++y) {
      auto sum = 0.0f;
      for (size_t e = 0; e < 4; ++e) {
        sum += array_[x + e * 4] * mat.array_[e + y * 4];
      }
      array_[x + y * 4] = sum;
    }
  }
  return *this;
}

template <Number T>
constexpr auto Mat4x4<T>::operator*=(const Mat4x4<T>& mat) noexcept
    -> Mat4x4<T>& {
  return multiply(mat);
}

template <Number T>
constexpr auto Mat4x4<T>::array() const noexcept
    -> const std::array<T, 4 * 4>& {
  return array_;
}

template <Number T>
constexpr auto operator*(Mat4x4<T> lhs, const Mat4x4<T>& rhs) noexcept
    -> Mat4x4<T> {
  return lhs.multiply(rhs);
}

}  // namespace gxng::math::impl

#endif  // GXNG_MAT_IPP
