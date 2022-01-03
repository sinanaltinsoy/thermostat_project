#include "testThermostat.hpp"

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
    ASSERT_EQ(0xFFFF, thermostatTargetTemp); 
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
    ASSERT_EQ(0xFFFF, thermostatTargetTemp);
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
    ASSERT_EQ(0xFFFF, thermostatTargetTemp);
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
            _mockRoom->setRoomTemp(5.1); // STEADY STATE
        }
        else if(i == 4000)
        {
            _mockRoom->setRoomTemp(5); // STEADY STATE
        }
        else
        {
            //DO NOTHING
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
            _mockRoom->setRoomTemp(29.9); // STEADY STATE
        }
        else if(i == 4000)
        {
            _mockRoom->setRoomTemp(30); // STEADY STATE
        }
        else
        {
            //DO NOTHING
        }
    }
}