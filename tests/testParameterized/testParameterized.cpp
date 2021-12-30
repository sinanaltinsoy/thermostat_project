#include "testThermostat.hpp"

TEST_P(ThermostatTestFixture, TestParameterizedRoomTemp)
{
    float newTemp = GetParam();

    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    // BELOW SHOULD BE 1000 TOTALLY
    EXPECT_CALL(*_mockRoom, tempSteady()).Times(testing::Exactly(1000));
    

    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(5, 30);
    _mockRoom->setRoomTemp(newTemp);

    for(int i = 0; i < 1000; i++)
    {
        _thermostat->work();
    }
}

INSTANTIATE_TEST_SUITE_P(TestRoomTempSteadyLimits, ThermostatTestFixture, testing::Values(5.0, 5.1, 5.2, 5.3, 29.7, 29.8, 29.9, 30.0));

/*

TODO

TEST_P(ThermostatTestFixture, TestParameterizedRoomTempLower)
{
    float newTemp = GetParam();

    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    // BELOW SHOULD BE 1000 TOTALLY
    EXPECT_CALL(*_mockRoom, tempSteady()).Times(testing::Exactly(1000));
    

    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(5, 30);
    _mockRoom->setRoomTemp(newTemp);

    for(int i = 0; i < 1000; i++)
    {
        _thermostat->work();
    }
}

INSTANTIATE_TEST_SUITE_P(TestPL, ThermostatTestFixture, testing::Range(1, 9 [, 2]));
*/

//TODO: Add Runtime error Tests
//TODO: Add Wrong Init Tests