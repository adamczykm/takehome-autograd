#include "autograd/foo.hh"

namespace autograd {

auto bar(std::string const& x) -> size_t {
  return x.size();
}

} /* end namespace autograd */
