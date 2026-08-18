// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <beman/bounds_test/bounds_test.hpp>
// Alternatively: import beman.bounds_test;

#include <limits>

namespace bt = beman::bounds_test;

int main(int argc, char** /* argv */) {
  static_assert(bt::can_convert_modular<unsigned>(1));
  static_assert(bt::can_convert_modular<unsigned>(0));
  static_assert(bt::can_convert_modular<unsigned>(-1));
  static_assert(bt::can_convert_modular<unsigned>(std::numeric_limits<int>::min()));
  static_assert(bt::can_convert_modular<unsigned>(std::numeric_limits<int>::max()));

  const bool valid = bt::can_convert<unsigned>(argc);
  return valid ? 0 : 1;
}
