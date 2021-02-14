//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_VEC_H
#define GXNG_VEC_H

#include <algorithm>
#include <array>
#include <cstddef>
#include <functional>
#include <numeric>
#include <ranges>
#include <stdexcept>

#include "utility.h"

namespace gxng::impl {

template <Number T, size_t size_>
class Vec {
 public:
  constexpr Vec() noexcept;

  template <Number... Params>
  constexpr explicit Vec(Params... params) noexcept;

  template <Number DifferentT>
  constexpr explicit Vec(const Vec<DifferentT, size_>& vec) noexcept;

  constexpr auto operator=(const Vec<T, size_>& vec) noexcept -> Vec<T, size_>&;

  constexpr auto operator[](size_t index) noexcept -> T&;

  constexpr auto operator[](size_t index) const noexcept -> const T&;

  [[nodiscard]] constexpr auto size() const noexcept -> size_t;

  constexpr auto add(const Vec<T, size_>& vec) noexcept -> Vec<T, size_>&;

  constexpr auto subtract(const Vec<T, size_>& vec) noexcept -> Vec<T, size_>&;

  constexpr auto multiply(const Vec<T, size_>& vec) noexcept -> Vec<T, size_>&;

  constexpr auto divide(const Vec<T, size_>& vec) -> Vec<T, size_>&;

  constexpr auto operator+=(const Vec<T, size_>& vec) noexcept
      -> Vec<T, size_>&;

  constexpr auto operator-=(const Vec<T, size_>& vec) noexcept
      -> Vec<T, size_>&;

  constexpr auto operator*=(const Vec<T, size_>& vec) noexcept
      -> Vec<T, size_>&;

  constexpr auto operator/=(const Vec<T, size_>& vec) noexcept
      -> Vec<T, size_>&;

  constexpr auto operator==(const Vec<T, size_>& rhs) const noexcept -> bool;

 private:
  std::array<T, size_> array_;
};

template <Number T, size_t size>
constexpr auto operator+(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept;

template <Number T, size_t size>
constexpr auto operator-(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept;

template <Number T, size_t size>
constexpr auto operator*(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept;

template <Number T, size_t size>
constexpr auto operator/(Vec<T, size> lhs, const Vec<T, size>& rhs) noexcept;

}  // namespace gxng::math::impl

#include "Vec.ipp"

#endif  // GXNG_VEC_H
