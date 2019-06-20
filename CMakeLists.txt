cmake_minimum_required(VERSION 3.1)
project(autograd)

# Set build type to RELEASE by default:
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "No build type provided, default to RELEASE.")
  set(CMAKE_BUILD_TYPE "RELEASE")
endif()

# Options can be turned on and off by providing cmake with a -DOPTIONNAME=ON (or OFF) argument.
# For example, to turn off benchmarks, build a shared library, and use sanitize flags in a DEBUG build:
#    cmake .. -DCMAKE_BUILD_TYPE=DEBUG -DAUTOGRAD_BENCH=OFF -DBENCH_STATIC=OFF -DAUTOGRAD_SANITIZE=ON
option(AUTOGRAD_TEST      "Build tests" ON)
option(AUTOGRAD_BENCH     "Build benchmarks" ON)
option(AUTOGRAD_STATIC    "Builds a static library instead of a shared one" OFF)
option(AUTOGRAD_SANITIZE  "Adds sanitive flags" OFF)

if(AUTOGRAD_STATIC)
  set(AUTOGRAD_LIB_NAME "autograd_static")
  set(AUTOGRAD_LIB_TYPE STATIC)
else()
  set(AUTOGRAD_LIB_NAME "autograd")
  set(AUTOGRAD_LIB_TYPE SHARED)
endif()

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

include_directories(. include)

set(CMAKE_CXX_STANDARD 14) # cmake 3.1 supports '98', '11' or '14'. cmake 3.8 or later support '17'.
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(AUTOGRAD_SANITIZE)
  set(CMAKE_CXX_FLAGS "-fsanitize=address -fsanitize=undefined ${CMAKE_CXX_FLAGS}")
endif()

add_subdirectory(src)

if(AUTOGRAD_TEST)
  enable_testing()
  add_subdirectory(test)
endif()

if(AUTOGRAD_BENCH)
  add_subdirectory(bench)
endif()

message(STATUS "")
message(STATUS "BUILD SUMMARY")
message(STATUS "  CMAKE_GENERATOR      : ${CMAKE_GENERATOR}")
message(STATUS "  Compiler ID          : ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "  Build type           : ${CMAKE_BUILD_TYPE}")
message(STATUS "  Library name         : ${AUTOGRAD_LIB_NAME}")
message(STATUS "  Library type         : ${AUTOGRAD_LIB_TYPE}")
message(STATUS "  Build tests          : ${AUTOGRAD_TEST}")
message(STATUS "  Build benchmarks     : ${AUTOGRAD_BENCH}")
message(STATUS "  Sanitize flags       : ${AUTOGRAD_SANITIZE}")
message(STATUS "")
