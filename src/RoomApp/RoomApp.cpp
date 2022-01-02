#include "RoomApp.hpp"

RoomApp::RoomApp(float initRealTemp, float initThermostatMinTemp, float initThermostatMaxTemp) : Room(initRealTemp, initThermostatMinTemp, initThermostatMaxTemp) 
{


}

RoomApp::~RoomApp()
{

}

void RoomApp::thermostatConnect()
{
    cout << "Thermostat is connected." << endl;
}

void RoomApp::thermostatDisconnect()
{
    cout << "Thermostat is disconnected." << endl;
}

void RoomApp::tempHeating()
{
    cout << "Heater is working." << endl;
}

void RoomApp::tempCooling()
{
    cout << "Cooler is working." << endl;
}

void RoomApp::tempSteady()
{
    cout << "Heater and Cooler is not working." << endl;
}

void RoomApp::startHeating()
{
    cout << "Heater start working." << endl;
}

void RoomApp::startCooling()
{
    cout << "Cooler start working." << endl;
}

void RoomApp::startSteady()
{
    cout << "Heater and Cooler stop working." << endl;
}

void RoomApp::thermostatSleep()
{
    cout << "Thermostat: StandBy Mode" << endl;
}

void RoomApp::thermostatModeChanged()
{
    cout << "Thermostat Mode Changed" << endl;
}

void RoomApp::thermostatAdjustableTempsChanged()
{
    cout << "New adjustable values are set." << endl;
}

void RoomApp::thermostatTargetTempChanged()
{
    cout << "Thermostat target temp is changed." << endl;
}
