#ifndef AUTOGRAD_FOO_H_
#define AUTOGRAD_FOO_H_

#include <iostream>

namespace autograd {

auto answer(int n) -> bool;

auto foo(int n) -> int;

auto bar(std::string const&) -> size_t;

} /* end namespace autograd */

#endif
