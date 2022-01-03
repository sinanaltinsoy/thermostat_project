//
//  testRunTimeErrors.cpp
//  testRunTimeErrors
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#include "testThermostat.hpp"
#include <stdexcept>

TEST(TestRunTimeErrors, TestNoThrow)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    EXPECT_CALL(*_mockRoom, thermostatConnect());
    EXPECT_CALL(*_mockRoom, thermostatDisconnect());
    EXPECT_CALL(*_mockRoom, thermostatSleep());

    ASSERT_NO_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
        _thermostat->work();

        delete _thermostat;
    });

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinThermostatWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT -1,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMaxThermostatWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT + 1,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinCoolerWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT - 1,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMaxCoolerWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT + 1,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinHeaterWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT - 1,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMaxHeaterWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT + 1);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinMaxHeaterWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinHeaterLowerThanThermostatWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT - 1,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMaxHeaterGreaterThanThermostatWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT + 1);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinMaxCoolerWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinCoolerLowerThanThermostatWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT - 1,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMaxCoolerGreaterThanThermostatWorkingTempError)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    ASSERT_THROW(
    {
        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT + 1,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);
    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestMinMaxAdjustableTemperaturesLimit)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    EXPECT_CALL(*_mockRoom, thermostatConnect());

    ASSERT_THROW(
    {

        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);

        

        _mockRoom->setThermostatAdjustableTemp(30, 5);

        _thermostat->work();

    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestLowerAdjustableTemperaturesLimit)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    EXPECT_CALL(*_mockRoom, thermostatConnect());

    ASSERT_THROW(
    {

        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);

        

        _mockRoom->setThermostatAdjustableTemp(-41, 30);

        _thermostat->work();

    }, std::runtime_error);

    delete _mockRoom;
}

TEST(TestRunTimeErrors, TestHigherAdjustableTemperaturesLimit)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);

    EXPECT_CALL(*_mockRoom, thermostatConnect());

    ASSERT_THROW(
    {

        Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP_LIMIT,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MIN_WORKING_TEMP_LIMIT,
                                            (float)COOLER_MAX_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MIN_WORKING_TEMP_LIMIT,
                                            (float)HEATER_MAX_WORKING_TEMP_LIMIT);

        

        _mockRoom->setThermostatAdjustableTemp(5, 41);

        _thermostat->work();

    }, std::runtime_error);

    delete _mockRoom;
}