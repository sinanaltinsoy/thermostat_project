cmake_minimum_required(VERSION 3.14)

project(ThermostatProject VERSION 1.0)

#enable_testing()

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)

#get GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG release-1.11.0
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

# The compiled library code is here
add_subdirectory(src)

# The executable code is here
add_subdirectory(apps)

add_subdirectory(tests)