set(HEADER_LIST "${ThermostatProject_SOURCE_DIR}/include/Room/Room.hpp")

add_library(Room Room.cpp ${HEADER_LIST})

target_include_directories(Room PUBLIC ../../include/Room)

target_link_libraries(Room PRIVATE)

target_compile_features(Room PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/Room"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})