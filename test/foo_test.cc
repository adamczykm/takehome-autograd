#include <iostream>
#include "gtest/gtest.h"

#include "autograd/foo.hh"

TEST(AutogradFoo, Positives) {
  EXPECT_EQ(38, autograd::foo(-4));
  EXPECT_EQ(42, autograd::foo(0));
}

TEST(AutogradFoo, Negatives) {
  EXPECT_NE(-1, autograd::foo(99));
  EXPECT_NE(0, autograd::foo(-41));
  EXPECT_NE(42, autograd::foo(42));
}
