set(HEADER_LIST "${ThermostatProject_SOURCE_DIR}/include/RoomApp/RoomApp.hpp")

add_library(RoomApp RoomApp.cpp ${HEADER_LIST})

target_include_directories(RoomApp PUBLIC ../../include/Room)
target_include_directories(RoomApp PUBLIC ../../include/RoomApp)

target_link_libraries(RoomApp PRIVATE)

target_compile_features(RoomApp PUBLIC cxx_std_11)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/include/RoomApp"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})