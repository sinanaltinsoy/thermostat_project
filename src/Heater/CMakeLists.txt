set(HEADER_LIST "${ThermostatProject_SOURCE_DIR}/include/Heater/Heater.hpp")

add_library(Heater Heater.cpp ${HEADER_LIST})

target_include_directories(Heater PUBLIC ../../include/Device)
target_include_directories(Heater PUBLIC ../../include/Heater)

target_link_libraries(Heater PRIVATE)

target_compile_features(Heater PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/Heater"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})