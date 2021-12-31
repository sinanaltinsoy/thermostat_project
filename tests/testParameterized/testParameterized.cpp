#include "testThermostat.hpp"

#define THERMOSTAT_ADJUSTABLE_MIN_TEMP 5
#define THERMOSTAT_ADJUSTABLE_MAX_TEMP 30
#define TEST_LOOP_NUMBER 1000

TEST_P(ThermostatTestFixture, TestParameterizedRoomTemp)
{
    float roomTemp = GetParam();
    int testLoopNumber = TEST_LOOP_NUMBER;
    float thermostatAdjustableMinTemp = THERMOSTAT_ADJUSTABLE_MIN_TEMP;
    float thermostatAdjustableMaxTemp = THERMOSTAT_ADJUSTABLE_MAX_TEMP;

    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());

    if(roomTemp < thermostatAdjustableMinTemp) 
    {
        EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged()).Times(testing::Exactly(2));
        EXPECT_CALL(*_mockRoom, startHeating()); 
        EXPECT_CALL(*_mockRoom, tempHeating()).Times(testing::Exactly(testLoopNumber-1));   
    }   
    else if(roomTemp > thermostatAdjustableMaxTemp) 
    {
        EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged()).Times(testing::Exactly(2));
        EXPECT_CALL(*_mockRoom, startCooling()); 
        EXPECT_CALL(*_mockRoom, tempCooling()).Times(testing::Exactly(testLoopNumber-1));   
    }
    else // (roomTemp >= thermostatAdjustableMinTemp) && (roomTemp <= thermostatAdjustableMaxTemp)
    {
        EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
        EXPECT_CALL(*_mockRoom, tempSteady()).Times(testing::Exactly(testLoopNumber));  
    }   

    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(thermostatAdjustableMinTemp, thermostatAdjustableMaxTemp);
    _mockRoom->setRoomTemp(roomTemp);

    for(int i = 0; i < testLoopNumber; i++)
    {
        _thermostat->work();
    }
}

INSTANTIATE_TEST_SUITE_P(TestRoomTempSteadyLimits, ThermostatTestFixture, testing::Values(5.0, 5.1, 5.2, 5.3, 29.7, 29.8, 29.9, 30.0));
//TODO //Range(1, 9 [, 2]));
INSTANTIATE_TEST_SUITE_P(TestRoomTempLowerLimits, ThermostatTestFixture, testing::Values(-40, -39, -38, -37, -36, -35, -34, -33));
//INSTANTIATE_TEST_SUITE_P(TestRoomTempHigherLimits, ThermostatTestFixture, testing::Values(-40, -39, 5.2, 5.3, 29.7, 38, 39, 40.0));
//INSTANTIATE_TEST_SUITE_P(TestRoomTempAll, ThermostatTestFixture, testing::Values(-40, -39, 5.2, 5.3, 29.7, 38, 39, 40.0));

//TODO: Add Runtime error Tests
//TODO: Add Wrong Init Tests