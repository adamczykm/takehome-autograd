#include <iostream>
#include "gtest/gtest.h"

#include "autograd/count_primes.hh"

TEST(AutogradPrimes, CountPrimes) {
  EXPECT_EQ(size_t{0}, autograd::count_primes(0));
  EXPECT_EQ(size_t{0}, autograd::count_primes(1));
  EXPECT_EQ(size_t{1}, autograd::count_primes(2));
  EXPECT_EQ(size_t{2}, autograd::count_primes(3));
  EXPECT_EQ(size_t{2}, autograd::count_primes(4));
  EXPECT_EQ(size_t{3}, autograd::count_primes(5));
  EXPECT_EQ(size_t{4}, autograd::count_primes(10));
  EXPECT_EQ(size_t{25}, autograd::count_primes(100));
  EXPECT_EQ(size_t{168}, autograd::count_primes(1000));
}
