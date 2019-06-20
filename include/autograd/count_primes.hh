#ifndef AUTOGRAD_FOO_H_
#define AUTOGRAD_FOO_H_

#include <iostream>

namespace autograd {

auto est_n_primes(size_t n) -> double;

auto count_primes(size_t n) -> size_t;

auto count_primes_no_goto(size_t n) -> size_t;

} /* end namespace autograd */

#endif
