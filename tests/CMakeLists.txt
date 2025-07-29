if(MSVC)
  set(gtest_force_shared_crt on)
endif()


include(FetchContent)

FetchContent_Declare(googletest
        DOWNLOAD_EXTRACT_TIMESTAMP ON
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG main)
FetchContent_MakeAvailable(googletest)

find_package(GTest)

# Set up testing framework, then add tests
# define a function to add a gtest‐based nuts test
function(add_googletest_test TEST_NAME TEST_SOURCE)
  # create the executable
  add_executable(${TEST_NAME} ${TEST_SOURCE})

  # link in GoogleTest, Eigen, and your nuts lib
  target_link_libraries(${TEST_NAME}
    PRIVATE
      gtest_main
  )

  #  register it with CTest
  gtest_discover_tests(${TEST_NAME})
endfunction()

add_googletest_test(span_test span_test.cpp)
