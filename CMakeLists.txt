cmake_minimum_required(VERSION 3.14)
project(windows-gtest-example
  VERSION 0.1.0
  DESCRIPTION "tests fail to run"
  LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
if (CMAKE_BUILD_TYPE MATCHES DEBUG)
  set(CMAKE_VERBOSE_MAKEFILE YES)
endif()


##########################
##       Tests         ##
##########################
enable_testing()
add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/tests")

