//
//  Room.cpp
//  Room
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#include "Room.hpp"

Room::Room(float initRealTemp, float initThermostatMinTemp, float initThermostatMaxTemp)
{
    realTemp =  initRealTemp;
    thermostatMinTempSet = initThermostatMinTemp;
    thermostatMaxTempSet = initThermostatMaxTemp;
    isThermostatAutoModeSet = false;
}

Room::~Room()
{

}

void Room::setRoomTemp(float Temp)
{
    realTemp = Temp;
}

float Room::getRoomTemp()
{
    return realTemp;
}

void Room::setThermostatAdjustableTemp(float min, float max)
{
    thermostatMinTempSet = min;
    thermostatMaxTempSet = max;  
}

void Room::getThermostatAdjustableTemp(float *min, float *max)
{
    *min = thermostatMinTempSet;
    *max = thermostatMaxTempSet;
}

void Room::setThermostatMode(bool isAutoMode)
{
    isThermostatAutoModeSet = isAutoMode;
}

bool Room::getThermostatMode()
{
    return isThermostatAutoModeSet;
}

void Room::setThermostatValues(float readTempVal, float targetTempVal, float minTempVal, float maxTempVal, bool isThermostatWork, bool isThermostatHeat, bool isThermostatCool)
{
    thermostatTemp = readTempVal;
    thermostatTargetTemp = targetTempVal;
    thermostatMinTemp = minTempVal;
    thermostatMaxTemp = maxTempVal;
    isThermostatAutoMode = isThermostatWork;
    isThermostatHeating = isThermostatHeat;
    isThermostatCooling = isThermostatCool;
}

void Room::getThermostatValues(float *readTempVal, float *targetTempVal, float *minTempVal, float *maxTempVal, bool *isThermostatWork, bool *isThermostatHeat, bool *isThermostatCool)
{
    *readTempVal = thermostatTemp;
    *targetTempVal = thermostatTargetTemp;
    *minTempVal = thermostatMinTemp;
    *maxTempVal = thermostatMaxTemp;
    *isThermostatWork = isThermostatAutoMode;
    *isThermostatHeat = isThermostatHeating;
    *isThermostatCool = isThermostatCooling;
}
