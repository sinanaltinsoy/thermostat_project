#include <iostream>
#include "RoomApp.hpp"
#include "Thermostat.hpp"

using namespace std;

int main()
{
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
    _room->setThermostatAdjustableTemp(initThermostatMinTemp, initThermostatMaxTemp);

    _thermostat->work();

    float newRoomTemp = -10;

    cout << "--- Room Simulation Start ---" << endl;

    while(1)
    { 
        _room->setRoomTemp(newRoomTemp);
        cout << "Room Temp: " << _room->getRoomTemp() << endl;   

        _thermostat->work();

        newRoomTemp++;

        if(newRoomTemp == 45)
        {
            break;
        }
    } 

    cout << "--- Room Simulation End ---" << endl;   

    delete _thermostat;
    delete _room;
    return 0;
}