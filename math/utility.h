//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_UTILITY_H
#define GXNG_UTILITY_H

#include <concepts>
#include <numbers>

namespace gxng::impl {

template <typename T>
concept Number = std::floating_point<T> || std::integral<T>;

template <std::floating_point T>
constexpr auto toRadians(T degrees) noexcept -> T;

}  // namespace gxng::math::impl

#include "utility.ipp"

#endif  // GXNG_UTILITY_H
