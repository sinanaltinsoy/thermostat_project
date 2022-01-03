//
//  Thermostat.hpp
//  Thermostat
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef Thermostat_hpp
#define Thermostat_hpp

#include "Config.hpp"
#include "Device.hpp"
#include "Cooler.hpp"
#include "Heater.hpp"
#include "Room.hpp"
#include <iostream>

using namespace std;

class Thermostat : public Device
{
public:
    enum SetModeState
    {
        NoSet,
        AdjustableValuesSet,
        ModeSet,
        AllValuesSet,
        Error
    };
private:
    Room *_room;
    Cooler *_cooler;
    Heater *_heater;
    float fixedPointOffset;
    float fixedPointIndex;
    int EnvironmentTemp;
    int targetLowTemp;
    int targetHighTemp;
    int targetHeaterTemp;
    int targetCoolerTemp;
    Device::Status getSubStatus();
    int set(int target, Status newStatus);
    void setCoolingMode();
    void setHeatingMode();
    void setAutoMode(); 
    SetModeState isSetNeeded();
    void setMode(bool isAutoMode);
    void setAdjustableTemp(int targetLow, int targetHigh);
    void getData();
public:
    Thermostat(Room *room,
               float minThermostatWorkingTemp, 
               float maxThermostatWorkingTemp, 
               float minCoolerWorkingTemp, 
               float maxCoolerWorkingTemp, 
               float minHeaterWorkingTemp, 
               float maxHeaterWorkingTemp);
    ~Thermostat();
    void work();
};

#endif /* Thermostat_hpp */
