//
//  testThermostat.hpp
//  testThermostat
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef testThermostat_hpp
#define testThermostat_hpp

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Thermostat.hpp"

/* THERMOSTAT CONFIG */
#define INITIAL_THERMOSTAT_TARGET_LOW_TEMP  (18.0)
#define INITIAL_THERMOSTAT_TARGET_HIGH_TEMP (24.0)

#define THERMOSTAT_MIN_WORKING_TEMP  (-40)
#define THERMOSTAT_MAX_WORKING_TEMP  40

/* HEATER CONFIG */
#define HEATER_MIN_WORKING_TEMP      (-40)
#define HEATER_MAX_WORKING_TEMP      40

/* COOLER CONFIG */
#define COOLER_MIN_WORKING_TEMP      (-18)
#define COOLER_MAX_WORKING_TEMP      40

#define INITIAL_REAL_TEMP            18

class MockRoom : public Room
{
public:
    MockRoom(float initRealTemp, float initThermostatMinTemp, float initThermostatMaxTemp) : Room(initRealTemp, initThermostatMinTemp, initThermostatMaxTemp) 
    {

    }

    ~MockRoom()
    {

    }

    MOCK_METHOD(void, thermostatConnect, ());
    MOCK_METHOD(void, thermostatDisconnect, ());
    MOCK_METHOD(void, tempHeating, ());
    MOCK_METHOD(void, tempCooling, ());
    MOCK_METHOD(void, tempSteady, ());
    MOCK_METHOD(void, startHeating, ());
    MOCK_METHOD(void, startCooling, ());
    MOCK_METHOD(void, startSteady, ());
    MOCK_METHOD(void, thermostatSleep, ());
    MOCK_METHOD(void, thermostatModeChanged, ());
    MOCK_METHOD(void, thermostatAdjustableTempsChanged, ());
    MOCK_METHOD(void, thermostatTargetTempChanged, ());
};

class ThermostatTestFixture : public testing::Test,
                              public testing::WithParamInterface<float> 
{
public:
    void SetUp() override;
    void TearDown() override;
    void ThermostatOn();
    void ReadThermostat();
protected:
    MockRoom *_mockRoom;
    Thermostat *_thermostat;
    float tempParam;
    bool isThermostatAutoMode;
    bool isThermostatHeating;
    bool isThermostatCooling;
    float thermostatTemp;
    float thermostatTargetTemp;
    float thermostatMinTemp;
    float thermostatMaxTemp;
};
 
void ThermostatTestFixture::SetUp()
{    
    _mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);
    
    EXPECT_CALL(*_mockRoom, thermostatConnect());

    _thermostat = new Thermostat(_mockRoom,
                                 (float)THERMOSTAT_MIN_WORKING_TEMP,
                                 (float)THERMOSTAT_MAX_WORKING_TEMP,
                                 (float)COOLER_MIN_WORKING_TEMP,
                                 (float)COOLER_MAX_WORKING_TEMP,
                                 (float)HEATER_MIN_WORKING_TEMP,
                                 (float)HEATER_MAX_WORKING_TEMP);

}

void ThermostatTestFixture::TearDown()
{
    EXPECT_CALL(*_mockRoom, thermostatDisconnect());

    delete _thermostat;
    delete _mockRoom;
}

void ThermostatTestFixture::ThermostatOn()
{
    //TODO
    // Thermostat ON
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, tempSteady());
    
    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(5, 30);

    _thermostat->work();
}

void ThermostatTestFixture::ReadThermostat()
{
    _mockRoom->getThermostatValues(&thermostatTemp, 
                                   &thermostatTargetTemp,
                                   &thermostatMinTemp,
                                   &thermostatMaxTemp,
                                   &isThermostatAutoMode,
                                   &isThermostatHeating,
                                   &isThermostatCooling);
}

#endif /* testThermostat_hpp */