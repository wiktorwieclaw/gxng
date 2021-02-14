//
// Created by vixu on 1/2/21.
//

#ifndef GXNG_AUTOBINDER_H
#define GXNG_AUTOBINDER_H

namespace gxng {

template <typename T>
concept Bindable = requires(T t) {
  t.bind();
  t.unbind();
};

template <Bindable T>
class AutoBinder {
 public:
  explicit AutoBinder(T& object) : object_{object} { object_.bind(); }

  ~AutoBinder() { object_.unbind(); }

 private:
  T& object_;
};

}  // namespace gxng::graphics

#endif  // GXNG_AUTOBINDER_H
