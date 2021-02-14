//
// Created by vixu on 12/31/20.
//

#ifndef GXNG_UTILITY_IPP
#define GXNG_UTILITY_IPP

namespace gxng::impl {

template <std::floating_point T>
constexpr auto toRadians(T degrees) noexcept -> T {
  return degrees * static_cast<T>(std::numbers::pi / 180.0);
}

}  // namespace gxng::math::impl

#endif  // GXNG_UTILITY_IPP
