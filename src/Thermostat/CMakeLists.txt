set(HEADER_LIST "${ThermostatProject_SOURCE_DIR}/include/Thermostat/Thermostat.hpp")

add_library(Thermostat Thermostat.cpp ${HEADER_LIST})

target_include_directories(Thermostat PUBLIC ../../include/)
target_include_directories(Thermostat PUBLIC ../../include/Device)
target_include_directories(Thermostat PUBLIC ../../include/Cooler)
target_include_directories(Thermostat PUBLIC ../../include/Heater)
target_include_directories(Thermostat PUBLIC ../../include/Room)
target_include_directories(Thermostat PUBLIC ../../include/Thermostat)

target_link_libraries(Thermostat PRIVATE)

target_compile_features(Thermostat PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/Thermostat"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})