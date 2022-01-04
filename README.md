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
