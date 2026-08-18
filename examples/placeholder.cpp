// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include <beman/bounds_test/bounds_test.hpp>
// Alternatively: import beman.bounds_test;

namespace bt = beman::bounds_test;

int main(int argc, char** /* argv */) {
  const volatile int runtime_value{argc};

  const bool valid =
      bt::can_convert_modular<unsigned>(runtime_value) &&
      bt::can_convert<unsigned>(runtime_value);

  return valid ? 0 : 1;
}
