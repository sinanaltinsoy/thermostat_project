#include "testMock/testMock.cpp"
#include "testParameterized/testParameterized.cpp"
#include "testRunTimeErrors/testRunTimeErrors.cpp"

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}