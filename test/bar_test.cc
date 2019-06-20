#include <iostream>
#include "gtest/gtest.h"

#include "autograd/foo.hh"

TEST(AutogradBar, GetStringSize) {
  EXPECT_EQ(size_t{5}, autograd::bar(std::string{"Kyoto"}));
  EXPECT_EQ(size_t{9}, autograd::bar(std::string{"Stockholm"}));
  EXPECT_EQ(size_t{10}, autograd::bar(std::string{"Montreal  "}));
  EXPECT_EQ(size_t{3}, autograd::bar(std::string{"   "}));
}

TEST(AutogradBar, EmptyStringHaveZeroSize) {
  EXPECT_EQ(size_t{0}, autograd::bar(std::string{""}));
}
