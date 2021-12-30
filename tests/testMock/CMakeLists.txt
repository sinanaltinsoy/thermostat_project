add_library(testMock testMock.cpp ${HEADER_LIST})

target_include_directories(testMock PUBLIC ../include/)

target_link_libraries(testMock PRIVATE Thermostat gtest_main gmock_main)

target_compile_features(testMock PUBLIC cxx_std_11)