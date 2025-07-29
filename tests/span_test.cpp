

#include <gtest/gtest.h>

template <typename T> class TrueFalse : public ::testing::Test {};

using Both = ::testing::Types<std::false_type, std::true_type>;
TYPED_TEST_SUITE(TrueFalse, Both);

TYPED_TEST(TrueFalse, Dummy) {
  if constexpr (TypeParam::value) {
    std::cout << "True" << std::endl;
  } else {
    std::cout << "False" << std::endl;
  }
}
