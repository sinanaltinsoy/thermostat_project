//
//  testParameterized.cpp
//  testParameterized
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#include "testThermostat.hpp"

#define THERMOSTAT_ADJUSTABLE_MIN_TEMP 5.0
#define THERMOSTAT_ADJUSTABLE_MAX_TEMP 30.0
#define TEST_LOOP_NUMBER 1000

TEST_P(ThermostatTestFixture, TestParameterizedRoomTemp)
{
    float roomTemp = (float)GetParam();
    
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

INSTANTIATE_TEST_SUITE_P(TestRoomTempLowerLimits, ThermostatTestFixture, testing::Values(-40.0, -39.0, -38.0, -37.0, 0, 1.0, 2.0, 3.0, 4.0, 4.6, 4.7, 4.8, 4.9));
INSTANTIATE_TEST_SUITE_P(TestRoomTempSteadyLimits, ThermostatTestFixture, testing::Values(5.0, 5.1, 5.2, 5.3, 6.0, 7.0, 8.0, 9.0, 10.0, 29.7, 29.8, 29.9, 30.0));
INSTANTIATE_TEST_SUITE_P(TestRoomTempHigherLimits, ThermostatTestFixture, testing::Values(30.1, 30.2, 30.3, 30.4, 31.0, 32.0, 33.0, 37.0, 38.0, 39.0, 40.0));
INSTANTIATE_TEST_SUITE_P(TestRoomTempAllLimits, ThermostatTestFixture, testing::Range((double)THERMOSTAT_MIN_WORKING_TEMP, (double)THERMOSTAT_MAX_WORKING_TEMP, 0.5));
