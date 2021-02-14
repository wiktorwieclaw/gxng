//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_VEC_IPP
#define GXNG_VEC_IPP

#include "Vec.h"

namespace gxng::impl {

template <Number T, size_t size_>
constexpr Vec<T, size_>::Vec() noexcept {
  array_.fill(0);
}

template <Number T, size_t size_>
template <Number... Params>
constexpr Vec<T, size_>::Vec(Params... params) noexcept : array_{params...} {}

template <Number T, size_t size_>
template <Number DifferentT>
constexpr Vec<T, size_>::Vec(const Vec<DifferentT, size_>& vec) noexcept {
  for(size_t i = 0; i < size_; ++i) {
    array_[i] = vec[i];
  }
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator==(
    const Vec<T, size_>& rhs) const noexcept -> bool {
  return std::ranges::equal(array_, rhs.array_);
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator=(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  array_ = vec.array_;
  return *this;
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator[](size_t index) noexcept -> T& {
  return const_cast<T&>(static_cast<const Vec<T, size_>&>(*this)[index]);
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator[](size_t index) const noexcept
    -> const T& {
  return array_[index];
}

template <Number T, size_t size_>
[[nodiscard]] constexpr auto Vec<T, size_>::size() const noexcept -> size_t {
  return size_;
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::add(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  std::ranges::transform(array_, vec.array_, array_.begin(), std::plus{});
  return *this;
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::subtract(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  std::ranges::transform(array_, vec.array_, array_.begin(), std::minus{});
  return *this;
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::multiply(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  std::ranges::transform(array_, vec.array_, array_.begin(), std::multiplies{});
  return *this;
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::divide(const Vec<T, size_>& vec)
    -> Vec<T, size_>& {
  for (auto x : vec.bitset_) {
    if (x == static_cast<T>(0)) {
      throw std::runtime_error("Cannot divide by 0.");
    }
  }
  std::ranges::transform(array_, vec.array_, array_.begin(), std::divides{});
  return *this;
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator+=(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  return add(vec);
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator-=(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  return subtract(vec);
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator*=(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  return multiply(vec);
}

template <Number T, size_t size_>
constexpr auto Vec<T, size_>::operator/=(const Vec<T, size_>& vec) noexcept
    -> Vec<T, size_>& {
  return divide(vec);
}

template <Number T, size_t size>
constexpr auto operator+(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept {
  return lhs.add(rhs);
}

template <Number T, size_t size>
constexpr auto operator-(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept {
  return lhs.subtract(rhs);
}

template <Number T, size_t size>
constexpr auto operator*(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept {
  return lhs.multiply(rhs);
}

template <Number T, size_t size>
constexpr auto operator/(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept {
  return lhs.divide(rhs);
}

}  // namespace gxng::impl

#endif  // GX2D_ENGINE_VEC_IPP
