add_library(testParameterized testParameterized.cpp ${HEADER_LIST})

target_include_directories(testParameterized PUBLIC ../include/)

target_link_libraries(testParameterized PRIVATE Thermostat gtest_main gmock_main)

target_compile_features(testParameterized PUBLIC cxx_std_11)