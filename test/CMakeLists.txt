add_subdirectory(gtest)

include_directories(./gtest/googletest/include)

set(test_src
  run_all.cc
  foo_test.cc
  bar_test.cc
  answer_test.cc
  primes_test.cc
)

add_executable(test_autograd ${test_src})

target_link_libraries(test_autograd
  gtest
  ${AUTOGRAD_LIB_NAME}
  ${CMAKE_THREAD_LIBS_INIT}
  ${MATH_LIBS}
)

add_test(
  NAME tests
  COMMAND test_autograd
)
