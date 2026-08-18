// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <cassert> // Add this for runtime assert
#include <limits>

#include <beman/bounds_test/bounds_test.hpp>
// Alternatively: import beman.bounds_test;

namespace bt = beman::bounds_test;

int main(int argc, char** /* argv */) {
  [[maybe_unused]] constexpr int cnt{std::numeric_limits<int>::max()};

  // TODO(CK): Change static_assert to standard runtime assert
  static_assert(bt::can_convert_modular<unsigned>(cnt));
  static_assert(bt::can_convert<unsigned>(cnt));
}
