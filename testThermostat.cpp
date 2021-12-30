#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Thermostat.hpp"
#include <iostream>

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

using namespace std;

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


TEST(TestThermostat, TestMockClass)
{
    MockRoom *_mockRoom = new MockRoom((float)INITIAL_REAL_TEMP, (float)INITIAL_THERMOSTAT_TARGET_LOW_TEMP, (float)INITIAL_THERMOSTAT_TARGET_HIGH_TEMP);
    
    EXPECT_CALL(*_mockRoom, thermostatConnect());
    EXPECT_CALL(*_mockRoom, thermostatDisconnect());
    EXPECT_CALL(*_mockRoom, thermostatSleep());

    Thermostat *_thermostat = new Thermostat(_mockRoom,
                                            (float)THERMOSTAT_MIN_WORKING_TEMP,
                                            (float)THERMOSTAT_MAX_WORKING_TEMP,
                                            (float)COOLER_MIN_WORKING_TEMP,
                                            (float)COOLER_MAX_WORKING_TEMP,
                                            (float)HEATER_MIN_WORKING_TEMP,
                                            (float)HEATER_MAX_WORKING_TEMP);

    _thermostat->work();

    delete _thermostat;
    delete _mockRoom;
}

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



TEST_F(ThermostatTestFixture, TestInit)
{
    //EMPTY TEST TO TEST INITIALIZATION
}

TEST_F(ThermostatTestFixture, TestFirstWorkAfterInit)
{
    EXPECT_CALL(*_mockRoom, thermostatSleep());

    _thermostat->work();
}

TEST_F(ThermostatTestFixture, TestInitValuesTest)
{
    EXPECT_CALL(*_mockRoom, thermostatSleep());

    _thermostat->work();

    ReadThermostat();

    ASSERT_FALSE(isThermostatAutoMode);
    ASSERT_FALSE(isThermostatHeating);
    ASSERT_FALSE(isThermostatCooling);
    ASSERT_EQ(INITIAL_REAL_TEMP, thermostatTemp);
    //ASSERT_EQ(0xFFFF, thermostatTargetTemp); //TODO
    ASSERT_EQ(INITIAL_THERMOSTAT_TARGET_LOW_TEMP, thermostatMinTemp);
    ASSERT_EQ(INITIAL_THERMOSTAT_TARGET_HIGH_TEMP, thermostatMaxTemp);
}

TEST_F(ThermostatTestFixture, TestNewModeSet)
{
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, tempSteady());
    
    _mockRoom->setThermostatMode(true);

    _thermostat->work();

    ReadThermostat();

    ASSERT_TRUE(isThermostatAutoMode);
    ASSERT_FALSE(isThermostatHeating);
    ASSERT_FALSE(isThermostatCooling);
    ASSERT_EQ(INITIAL_REAL_TEMP, thermostatTemp);
    //ASSERT_EQ(0xFFFF, thermostatTargetTemp); //TODO
    ASSERT_EQ(INITIAL_THERMOSTAT_TARGET_LOW_TEMP, thermostatMinTemp);
    ASSERT_EQ(INITIAL_THERMOSTAT_TARGET_HIGH_TEMP, thermostatMaxTemp);
}

TEST_F(ThermostatTestFixture, TestSameModeSetTwice)
{
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, tempSteady());
    
    _mockRoom->setThermostatMode(true);

    _thermostat->work();

    EXPECT_CALL(*_mockRoom, tempSteady());
    _mockRoom->setThermostatMode(true);
    _thermostat->work();
}

TEST_F(ThermostatTestFixture, TestNewAdjustableTempsSet)
{
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatSleep());
    
    _mockRoom->setThermostatAdjustableTemp(5, 30);

    _thermostat->work();

    ReadThermostat();

    ASSERT_FALSE(isThermostatAutoMode);
    ASSERT_FALSE(isThermostatHeating);
    ASSERT_FALSE(isThermostatCooling);
    ASSERT_EQ(INITIAL_REAL_TEMP, thermostatTemp);
    //ASSERT_EQ(0xFFFF, thermostatTargetTemp); //TODO
    ASSERT_EQ(5, thermostatMinTemp);
    ASSERT_EQ(30, thermostatMaxTemp);
}

TEST_F(ThermostatTestFixture, TestSameAdjustableTempsSetTwice)
{
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatSleep());
    
    _mockRoom->setThermostatAdjustableTemp(5, 30);

    _thermostat->work();

    EXPECT_CALL(*_mockRoom, thermostatSleep());
    _mockRoom->setThermostatAdjustableTemp(5, 30);

    _thermostat->work();

}

TEST_F(ThermostatTestFixture, TestThermostatOnOff)
{
    // Thermostat ON
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, tempSteady());
    
    _mockRoom->setThermostatMode(true);

    _thermostat->work();

    // Thermostat OFF
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, thermostatSleep());
    _mockRoom->setThermostatMode(false);

    _thermostat->work();
}

TEST_F(ThermostatTestFixture, TestStartHeating)
{
    // Thermostat ON
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, tempSteady());
    
    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(5, 30);

    _thermostat->work();

    _mockRoom->setRoomTemp(1);

    float checkRoomTemp;
    checkRoomTemp = _mockRoom->getRoomTemp();
    
    ASSERT_EQ(1, checkRoomTemp);

    EXPECT_CALL(*_mockRoom, startHeating());
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());

    _thermostat->work();

    ReadThermostat();

    ASSERT_TRUE(isThermostatAutoMode);
    ASSERT_TRUE(isThermostatHeating);
    ASSERT_FALSE(isThermostatCooling);
    ASSERT_EQ(1, thermostatTemp);
    ASSERT_EQ(6, thermostatTargetTemp);
    ASSERT_EQ(5, thermostatMinTemp);
    ASSERT_EQ(30, thermostatMaxTemp);

    EXPECT_CALL(*_mockRoom, tempHeating());

    _thermostat->work();    
}

TEST_F(ThermostatTestFixture, TestStartCooling)
{
    // Thermostat ON
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    EXPECT_CALL(*_mockRoom, tempSteady());
    
    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(10, 20);

    _thermostat->work();

    _mockRoom->setRoomTemp(24);

    float checkRoomTemp;
    checkRoomTemp = _mockRoom->getRoomTemp();
    
    ASSERT_EQ(24, checkRoomTemp);

    EXPECT_CALL(*_mockRoom, startCooling());
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged());

    _thermostat->work();

    ReadThermostat();

    ASSERT_TRUE(isThermostatAutoMode);
    ASSERT_FALSE(isThermostatHeating);
    ASSERT_TRUE(isThermostatCooling);
    ASSERT_EQ(24, thermostatTemp);
    ASSERT_EQ(19, thermostatTargetTemp);
    ASSERT_EQ(10, thermostatMinTemp);
    ASSERT_EQ(20, thermostatMaxTemp);

    EXPECT_CALL(*_mockRoom, tempCooling());

    _thermostat->work();  
}

TEST_F(ThermostatTestFixture, TestHeatUntilToTarget)
{  
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    // BELOW SHOULD BE 5000 TOTALLY
    EXPECT_CALL(*_mockRoom, startHeating());
    EXPECT_CALL(*_mockRoom, startSteady());
    EXPECT_CALL(*_mockRoom, tempHeating()).Times(testing::Exactly(1000));
    EXPECT_CALL(*_mockRoom, tempSteady()).Times(testing::Exactly(3998));
    // BELOW SHOULD BE 3 TIMES 
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged()).Times(testing::Exactly(3));

    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(5, 30);
    _mockRoom->setRoomTemp(1);

    for(int i = 0; i < 5000; i++)
    {
        _thermostat->work();

        if(i == 500)
        {
            _mockRoom->setRoomTemp(5); // STILL HEATING
        }
        else if(i == 1000)
        {
            _mockRoom->setRoomTemp(6); // HEATING STOP
        }
        else if(i == 2000)
        {
            _mockRoom->setRoomTemp(7); // STEADY STATE
        }
        else if(i == 3000)
        {
            _mockRoom->setRoomTemp(5); // STEADY STATE
        }
        else
        {

        }
    }
}

TEST_F(ThermostatTestFixture, TestCoolUntilToTarget)
{
    EXPECT_CALL(*_mockRoom, thermostatAdjustableTempsChanged());
    EXPECT_CALL(*_mockRoom, thermostatModeChanged());
    // BELOW SHOULD BE 5000 TOTALLY
    EXPECT_CALL(*_mockRoom, startCooling());
    EXPECT_CALL(*_mockRoom, startSteady());
    EXPECT_CALL(*_mockRoom, tempCooling()).Times(testing::Exactly(1000));
    EXPECT_CALL(*_mockRoom, tempSteady()).Times(testing::Exactly(3998));
    // BELOW SHOULD BE 3 TIMES 
    EXPECT_CALL(*_mockRoom, thermostatTargetTempChanged()).Times(testing::Exactly(3));

    _mockRoom->setThermostatMode(true);
    _mockRoom->setThermostatAdjustableTemp(5, 30);
    _mockRoom->setRoomTemp(35);

    for(int i = 0; i < 5000; i++)
    {
        _thermostat->work();

        if(i == 500)
        {
            _mockRoom->setRoomTemp(30); // STILL COOLING
        }
        else if(i == 1000)
        {
            _mockRoom->setRoomTemp(29); // COOLING STOP
        }
        else if(i == 2000)
        {
            _mockRoom->setRoomTemp(28); // STEADY STATE
        }
        else if(i == 3000)
        {
            _mockRoom->setRoomTemp(30); // STEADY STATE
        }
        else
        {

        }
    }
}

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

int main(int argc, char **argv)
{
    ::testing::InitGoogleMock(&argc, argv);
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}