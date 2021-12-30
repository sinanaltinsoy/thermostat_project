add_subdirectory(testParameterized)
add_subdirectory(testMock)

add_executable(testThermostat testThermostat.cpp)

target_compile_features(testThermostat PRIVATE cxx_std_11)

target_link_libraries(testThermostat Thermostat Room Cooler Heater Device testMock testParameterized gtest_main gmock_main)