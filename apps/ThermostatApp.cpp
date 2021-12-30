#include <iostream>
#include "Thermostat.hpp"

using namespace std;

//TODO ROOM APP FILE
class RoomApp : public Room
{
public:
    RoomApp(float initRealTemp, float initThermostatMinTemp, float initThermostatMaxTemp) : Room(initRealTemp, initThermostatMinTemp, initThermostatMaxTemp) 
    {


    }

    void thermostatConnect()
    {
        cout << "Thermostat is connected." << endl;
    }

    void thermostatDisconnect()
    {
        cout << "Thermostat is disconnected." << endl;
    }

    void tempHeating()
    {
        cout << "Heater is working." << endl;
    }

    void tempCooling()
    {
        cout << "Cooler is working." << endl;
    }

    void tempSteady()
    {
        cout << "Heater and Cooler is not working." << endl;
    }

    void startHeating()
    {
        cout << "Heater start working." << endl;
    }

    void startCooling()
    {
        cout << "Cooler start working." << endl;
    }

    void startSteady()
    {
        cout << "Heater and Cooler stop working." << endl;
    }

    void thermostatSleep()
    {
        cout << "Thermostat: StandBy Mode" << endl;
    }

    void thermostatModeChanged()
    {
        cout << "Thermostat Mode Changed" << endl;
    }

    void thermostatAdjustableTempsChanged()
    {
        cout << "New adjustable values are set." << endl;
    }

    void thermostatTargetTempChanged()
    {
        cout << "Thermostat target temp is changed." << endl;
    }
};

using namespace std;

int main()
{
    cout << "START" << endl;

    float initRealTemp = 18;
    float initThermostatMinTemp = 5;
    float initThermostatMaxTemp = 30;
    float thermostatMinWorkingTemp = -40;
    float thermostatMaxWorkingTemp = 40;
    float coolerMinWorkingTemp = -18;
    float coolerMaxWorkingTemp = 40;
    float heaterMinWorkingTemp = -40;
    float heaterMaxWorkingTemp = 40;

    RoomApp *_room = new RoomApp(initRealTemp, initThermostatMinTemp, initThermostatMaxTemp);

    Thermostat *_thermostat = new Thermostat(_room,
                                             thermostatMinWorkingTemp,
                                             thermostatMaxWorkingTemp,
                                             coolerMinWorkingTemp,
                                             coolerMaxWorkingTemp,
                                             heaterMinWorkingTemp,
                                             heaterMaxWorkingTemp);


    _room->setThermostatMode(true);
    _room->setThermostatAdjustableTemp(5, 30);
    //while(1)
    {
        _thermostat->work();
    }    

    _room->setRoomTemp(24);

    float checkRoomTemp;
    checkRoomTemp = _room->getRoomTemp();

    cout << "Room Temp: " << checkRoomTemp << endl;
    
    delete _thermostat;
    delete _room;
    return 0;
}