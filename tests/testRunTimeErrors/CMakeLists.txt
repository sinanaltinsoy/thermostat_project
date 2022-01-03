add_library(testRunTimeErrors testRunTimeErrors.cpp ${HEADER_LIST})

target_include_directories(testRunTimeErrors PUBLIC ../include/)

target_link_libraries(testRunTimeErrors PRIVATE Thermostat gtest_main gmock_main)

target_compile_features(testRunTimeErrors PUBLIC cxx_std_11)