#include <iostream>
#include "gtest/gtest.h"

#include "autograd/foo.hh"

TEST(AutogradAnswer, WrongWrongWRONNNNG) {
  EXPECT_FALSE(autograd::answer(8129));
  EXPECT_FALSE(autograd::answer(-4));
  EXPECT_FALSE(autograd::answer(47));
  EXPECT_FALSE(autograd::answer(41));
  EXPECT_FALSE(autograd::answer(2));
}

TEST(AutogradAnswer, GoodAnswer) {
  ASSERT_TRUE(autograd::answer(42));
}
