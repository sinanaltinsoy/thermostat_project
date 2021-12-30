set(HEADER_LIST "${ThermostatProject_SOURCE_DIR}/include/Cooler/Cooler.hpp")

add_library(Cooler Cooler.cpp ${HEADER_LIST})

target_include_directories(Cooler PUBLIC ../../include/Device)
target_include_directories(Cooler PUBLIC ../../include/Cooler)

target_link_libraries(Cooler PRIVATE)

target_compile_features(Cooler PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/Cooler"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})