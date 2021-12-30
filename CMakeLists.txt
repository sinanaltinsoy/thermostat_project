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

add_library(Device Device.cpp Device.hpp)
add_library(Cooler Cooler.cpp Cooler.hpp)
add_library(Heater Heater.cpp Heater.hpp)
add_library(Thermostat Thermostat.cpp Thermostat.hpp)
add_library(Room Room.cpp Room.hpp)

add_executable(Main main.cpp)
target_link_libraries(Main PRIVATE Device)
target_link_libraries(Main PRIVATE Cooler)
target_link_libraries(Main PRIVATE Heater)
target_link_libraries(Main PRIVATE Thermostat)
target_link_libraries(Main PRIVATE Room)

add_executable(testThermostat testThermostat.cpp)
target_link_libraries(testThermostat Device Cooler Heater Thermostat Room gtest_main gmock_main)

