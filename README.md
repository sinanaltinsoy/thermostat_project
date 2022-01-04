# Thermostat Project

This project aims to create a thermostat library that keeps the temperature value in a room between the adjustable minimum and maximum temperature values. 

This library, 

- Starts the heater if the room temperature is less than the adjustable minimum temperature value and continues to work the heater until the room temperature reaches the adjustable minimum temperature value. 

- When the temperature is higher than the adjustable maximum temperature value, the library starts the cooler with the same working principle and continues to work the cooler until the room is below the adjustable maximum temperature value. 

- Likewise, the library keeps the cooler and heater in standby mode if the room temperature is between the adjustable minimum and maximum temperature values.

Operations such as turning on and off the thermostat or setting the thermostat adjustable minimum and maximum temperature values are done through the Room library which contains Room class. 

After the Thermostat library was designed, a Demo application named ThermostatApp was created using this library. The class diagram of this demo application is given below.

![alt text](https://github.com/sinanaltinsoy/thermostatproject/blob/main/docs/ThermostatAppClassDiagram.png?raw=true)

The test cases to test the Thermostat library were created by mocking the Room class. In these test cases, 4 different test suites were used. Test cases are given below.

As a result of these test cases, 226 tests were performed and no errors were found.

The application was built with cmake and this build created two executable files which are apps/ThermostatApp.cpp and tests/testThermostat.cpp.

The Demo App named Thermostatapp can be run with the executable file in apps/ThermostatApp.cpp.

The tests can be run via tests/testThermostat.cpp executable file and test results can be seen.

To run the project via terminal, the following commands must be entered respectively from the application folder.

`% cmake -S . -B build`

`% cd build`

`% make`

`% cd apps`

`% ./ThermostatApp`

`% cd tests`

`% ./testThermostat`



Output of the test file:

> [==========] Running 226 tests from 7 test suites.
[----------] Global test environment set-up.
[----------] 1 test from TestThermostat
[ RUN      ] TestThermostat.TestMockClass
[       OK ] TestThermostat.TestMockClass (0 ms)
[----------] 1 test from TestThermostat (0 ms total)
[----------] 12 tests from ThermostatTestFixture
[ RUN      ] ThermostatTestFixture.TestInit
[       OK ] ThermostatTestFixture.TestInit (0 ms)
[ RUN      ] ThermostatTestFixture.TestFirstWorkAfterInit
[       OK ] ThermostatTestFixture.TestFirstWorkAfterInit (0 ms)
[ RUN      ] ThermostatTestFixture.TestInitValuesTest
[       OK ] ThermostatTestFixture.TestInitValuesTest (0 ms)
[ RUN      ] ThermostatTestFixture.TestNewModeSet
[       OK ] ThermostatTestFixture.TestNewModeSet (0 ms)
[ RUN      ] ThermostatTestFixture.TestSameModeSetTwice
[       OK ] ThermostatTestFixture.TestSameModeSetTwice (0 ms)
[ RUN      ] ThermostatTestFixture.TestNewAdjustableTempsSet
[       OK ] ThermostatTestFixture.TestNewAdjustableTempsSet (0 ms)
[ RUN      ] ThermostatTestFixture.TestSameAdjustableTempsSetTwice
[       OK ] ThermostatTestFixture.TestSameAdjustableTempsSetTwice (0 ms)
[ RUN      ] ThermostatTestFixture.TestThermostatOnOff
[       OK ] ThermostatTestFixture.TestThermostatOnOff (0 ms)
[ RUN      ] ThermostatTestFixture.TestStartHeating
[       OK ] ThermostatTestFixture.TestStartHeating (0 ms)
[ RUN      ] ThermostatTestFixture.TestStartCooling
[       OK ] ThermostatTestFixture.TestStartCooling (0 ms)
[ RUN      ] ThermostatTestFixture.TestHeatUntilToTarget
[       OK ] ThermostatTestFixture.TestHeatUntilToTarget (20 ms)
[ RUN      ] ThermostatTestFixture.TestCoolUntilToTarget
[       OK ] ThermostatTestFixture.TestCoolUntilToTarget (13 ms)
[----------] 12 tests from ThermostatTestFixture (35 ms total)
[----------] 16 tests from TestRunTimeErrors
[ RUN      ] TestRunTimeErrors.TestNoThrow
[       OK ] TestRunTimeErrors.TestNoThrow (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinThermostatWorkingTempError
[       OK ] TestRunTimeErrors.TestMinThermostatWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMaxThermostatWorkingTempError
[       OK ] TestRunTimeErrors.TestMaxThermostatWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinCoolerWorkingTempError
[       OK ] TestRunTimeErrors.TestMinCoolerWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMaxCoolerWorkingTempError
[       OK ] TestRunTimeErrors.TestMaxCoolerWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinHeaterWorkingTempError
[       OK ] TestRunTimeErrors.TestMinHeaterWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMaxHeaterWorkingTempError
[       OK ] TestRunTimeErrors.TestMaxHeaterWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinMaxHeaterWorkingTempError
[       OK ] TestRunTimeErrors.TestMinMaxHeaterWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinHeaterLowerThanThermostatWorkingTempError
[       OK ] TestRunTimeErrors.TestMinHeaterLowerThanThermostatWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMaxHeaterGreaterThanThermostatWorkingTempError
[       OK ] TestRunTimeErrors.TestMaxHeaterGreaterThanThermostatWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinMaxCoolerWorkingTempError
[       OK ] TestRunTimeErrors.TestMinMaxCoolerWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinCoolerLowerThanThermostatWorkingTempError
[       OK ] TestRunTimeErrors.TestMinCoolerLowerThanThermostatWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMaxCoolerGreaterThanThermostatWorkingTempError
[       OK ] TestRunTimeErrors.TestMaxCoolerGreaterThanThermostatWorkingTempError (0 ms)
[ RUN      ] TestRunTimeErrors.TestMinMaxAdjustableTemperaturesLimit
[       OK ] TestRunTimeErrors.TestMinMaxAdjustableTemperaturesLimit (0 ms)
[ RUN      ] TestRunTimeErrors.TestLowerAdjustableTemperaturesLimit
[       OK ] TestRunTimeErrors.TestLowerAdjustableTemperaturesLimit (0 ms)
[ RUN      ] TestRunTimeErrors.TestHigherAdjustableTemperaturesLimit
[       OK ] TestRunTimeErrors.TestHigherAdjustableTemperaturesLimit (0 ms)
[----------] 16 tests from TestRunTimeErrors (0 ms total)
[----------] 13 tests from TestRoomTempLowerLimits/ThermostatTestFixture
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2 (3 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4 (3 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7 (3 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/11
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/11 (2 ms)
[ RUN      ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/12
[       OK ] TestRoomTempLowerLimits/ThermostatTestFixture.TestParameterizedRoomTemp/12 (2 ms)
[----------] 13 tests from TestRoomTempLowerLimits/ThermostatTestFixture (38 ms total)
[----------] 13 tests from TestRoomTempSteadyLimits/ThermostatTestFixture
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1 (3 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2 (3 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5 (3 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6 (3 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10 (2 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/11
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/11 (3 ms)
[ RUN      ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/12
[       OK ] TestRoomTempSteadyLimits/ThermostatTestFixture.TestParameterizedRoomTemp/12 (2 ms)
[----------] 13 tests from TestRoomTempSteadyLimits/ThermostatTestFixture (39 ms total)
[----------] 11 tests from TestRoomTempHigherLimits/ThermostatTestFixture
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0 (2 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1 (2 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9 (3 ms)
[ RUN      ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10
[       OK ] TestRoomTempHigherLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10 (3 ms)
[----------] 11 tests from TestRoomTempHigherLimits/ThermostatTestFixture (34 ms total)
[----------] 160 tests from TestRoomTempAllLimits/ThermostatTestFixture
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/0 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/1 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/2 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/3 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/4 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/5 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/6 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/7 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/8 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/9 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/10 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/11
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/11 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/12
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/12 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/13
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/13 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/14
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/14 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/15
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/15 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/16
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/16 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/17
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/17 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/18
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/18 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/19
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/19 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/20
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/20 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/21
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/21 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/22
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/22 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/23
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/23 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/24
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/24 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/25
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/25 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/26
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/26 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/27
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/27 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/28
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/28 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/29
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/29 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/30
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/30 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/31
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/31 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/32
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/32 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/33
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/33 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/34
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/34 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/35
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/35 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/36
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/36 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/37
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/37 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/38
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/38 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/39
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/39 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/40
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/40 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/41
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/41 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/42
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/42 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/43
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/43 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/44
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/44 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/45
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/45 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/46
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/46 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/47
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/47 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/48
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/48 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/49
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/49 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/50
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/50 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/51
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/51 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/52
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/52 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/53
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/53 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/54
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/54 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/55
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/55 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/56
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/56 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/57
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/57 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/58
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/58 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/59
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/59 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/60
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/60 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/61
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/61 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/62
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/62 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/63
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/63 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/64
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/64 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/65
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/65 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/66
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/66 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/67
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/67 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/68
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/68 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/69
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/69 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/70
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/70 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/71
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/71 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/72
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/72 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/73
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/73 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/74
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/74 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/75
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/75 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/76
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/76 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/77
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/77 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/78
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/78 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/79
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/79 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/80
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/80 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/81
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/81 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/82
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/82 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/83
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/83 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/84
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/84 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/85
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/85 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/86
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/86 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/87
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/87 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/88
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/88 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/89
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/89 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/90
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/90 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/91
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/91 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/92
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/92 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/93
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/93 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/94
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/94 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/95
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/95 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/96
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/96 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/97
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/97 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/98
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/98 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/99
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/99 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/100
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/100 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/101
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/101 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/102
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/102 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/103
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/103 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/104
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/104 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/105
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/105 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/106
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/106 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/107
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/107 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/108
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/108 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/109
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/109 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/110
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/110 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/111
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/111 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/112
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/112 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/113
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/113 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/114
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/114 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/115
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/115 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/116
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/116 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/117
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/117 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/118
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/118 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/119
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/119 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/120
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/120 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/121
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/121 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/122
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/122 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/123
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/123 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/124
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/124 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/125
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/125 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/126
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/126 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/127
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/127 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/128
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/128 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/129
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/129 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/130
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/130 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/131
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/131 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/132
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/132 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/133
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/133 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/134
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/134 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/135
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/135 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/136
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/136 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/137
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/137 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/138
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/138 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/139
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/139 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/140
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/140 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/141
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/141 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/142
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/142 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/143
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/143 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/144
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/144 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/145
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/145 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/146
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/146 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/147
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/147 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/148
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/148 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/149
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/149 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/150
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/150 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/151
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/151 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/152
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/152 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/153
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/153 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/154
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/154 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/155
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/155 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/156
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/156 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/157
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/157 (2 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/158
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/158 (3 ms)
[ RUN      ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/159
[       OK ] TestRoomTempAllLimits/ThermostatTestFixture.TestParameterizedRoomTemp/159 (2 ms)
[----------] 160 tests from TestRoomTempAllLimits/ThermostatTestFixture (466 ms total)
[----------] Global test environment tear-down
[==========] 226 tests from 7 test suites ran. (615 ms total)
[  PASSED  ] 226 tests.
