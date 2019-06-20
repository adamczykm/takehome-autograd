#include "autograd/foo.hh"

namespace autograd {

auto foo(int n) -> int {
  return 42 + n;
}

} /* end namespace autograd */
