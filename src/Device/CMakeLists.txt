set(HEADER_LIST "${ThermostatProject_SOURCE_DIR}/include/Device/Device.hpp")

add_library(Device Device.cpp ${HEADER_LIST})

target_include_directories(Device PUBLIC ../../include/Device)

target_link_libraries(Device PRIVATE)

target_compile_features(Device PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/Device"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})