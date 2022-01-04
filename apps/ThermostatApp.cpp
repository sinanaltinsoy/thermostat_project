//
//  ThermostatApp.cpp
//  ThermostatApp
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#include <iostream>
#include "RoomApp.hpp"
#include "Thermostat.hpp"

using namespace std;

class ThermostatApp
{
private:
    RoomApp *_room;
    Thermostat *_thermostat;
public:
    ThermostatApp()
    {
        float initRealTemp = 18;
        float initThermostatMinTemp = 5;
        float initThermostatMaxTemp = 30;
        float thermostatMinWorkingTemp = -40;
        float thermostatMaxWorkingTemp = 40;
        float coolerMinWorkingTemp = -18;
        float coolerMaxWorkingTemp = 40;
        float heaterMinWorkingTemp = -40;
        float heaterMaxWorkingTemp = 30;

        _room = new RoomApp(initRealTemp, initThermostatMinTemp, initThermostatMaxTemp);

        _thermostat = new Thermostat(_room,
                                     thermostatMinWorkingTemp,
                                     thermostatMaxWorkingTemp,
                                     coolerMinWorkingTemp,
                                     coolerMaxWorkingTemp,
                                     heaterMinWorkingTemp,
                                     heaterMaxWorkingTemp);
    }

    ~ThermostatApp()
    {
        delete _room;
        delete _thermostat;
    }

    void setMode(bool isAutoMode)
    {
        _room->setThermostatMode(isAutoMode);
    }

    void setAdjustableTemp(float ThermostatMinTemp, float ThermostatMaxTemp)
    {
        _room->setThermostatAdjustableTemp(ThermostatMinTemp, ThermostatMaxTemp);
    }

    float getRoomTemp()
    {
        return _room->getRoomTemp();
    }

    void simulation(float newRoomTemp)
    {
        _room->setRoomTemp(newRoomTemp);
        _thermostat->work();
    }
};

int main()
{
    cout << "--- Thermostat Init ---" << endl;

    ThermostatApp *_thermostatapp = new ThermostatApp();

    _thermostatapp->setMode(true);
    _thermostatapp->setAdjustableTemp(5, 30);

    float newRoomTemp = -10;

    cout << "--- Room Simulation Start ---" << endl;

    int cycle = 0;

    while(1)
    { 
        _thermostatapp->simulation(newRoomTemp);

        cout << "Cycle " << cycle;
        cout << " - Room Temp: " << _thermostatapp->getRoomTemp() << endl; 

        newRoomTemp++;
        cycle++;

        if(newRoomTemp == 45)
        {
            break;
        }
    } 

    cout << "--- Room Simulation End ---" << endl;   

    return 0;
}