#include "Thermostat.hpp"

//TODO DEL BELOW 
#include <iostream>
using namespace std;

Thermostat::Thermostat(Room *room,
                       float minThermostatWorkingTemp, 
                       float maxThermostatWorkingTemp, 
                       float minCoolerWorkingTemp, 
                       float maxCoolerWorkingTemp, 
                       float minHeaterWorkingTemp, 
                       float maxHeaterWorkingTemp) 
{
    _room = room;
    maxWorkingTemp = floatToFixedPoint(maxThermostatWorkingTemp);
    minWorkingTemp = floatToFixedPoint(minThermostatWorkingTemp);
    EnvironmentTemp = floatToFixedPoint(_room->getRoomTemp()); 

    float min = 0, max = 0;

    _room->getThermostatAdjustableTemp(&min, &max);

    setAdjustableTemp(floatToFixedPoint(min),
                      floatToFixedPoint(max));

    //TODO below
    targetTemp = 0xFFFF;

    Cooler* new_cooler = new Cooler(floatToFixedPoint(maxCoolerWorkingTemp), 
                                    floatToFixedPoint(minCoolerWorkingTemp),
                                    targetCoolerTemp);
    Heater* new_heater = new Heater(floatToFixedPoint(maxHeaterWorkingTemp),
                                    floatToFixedPoint(minHeaterWorkingTemp),
                                    targetHeaterTemp);
    _cooler = new_cooler;
    _heater = new_heater;

    setMode(_room->getThermostatMode());

    _room->thermostatConnect();

    getData();
}

Thermostat::~Thermostat()
{
    delete _cooler;
    delete _heater;
    _room->thermostatDisconnect();
}

Device::Status Thermostat::getSubStatus()
{
    Device::Status returnVal;

    if((_cooler->getStatus() == Device::Cooling) && (_heater->getStatus() == Device::Standby))
    {
        returnVal = Device::Cooling;
    }
    else if((_cooler->getStatus() == Device::Standby) && (_heater->getStatus() == Device::Heating))
    {
        returnVal = Device::Heating;
    }
    else if((_cooler->getStatus() == Device::Standby) && (_heater->getStatus() == Device::Standby))
    {
        returnVal = Device::Standby;
    }
    else
    {
        returnVal = Device::Error;
    }

    return returnVal;
}

int Thermostat::set(int target, Device::Status newStatus)
{
    targetTemp = target;
    setStatus(newStatus);
    _room->thermostatTargetTempChanged();
    return 0; 
}

void Thermostat::setCoolingMode()
{
    _cooler->set(targetCoolerTemp, Device::Cooling);
    _heater->set(targetHeaterTemp, Device::Standby);
    set(targetCoolerTemp, Device::Auto);
}

void Thermostat::setHeatingMode()
{
    _heater->set(targetHeaterTemp, Device::Heating);
    _cooler->set(targetCoolerTemp, Device::Standby);
    set(targetHeaterTemp, Device::Auto);
}

void Thermostat::setAutoMode()
{
    _heater->set(targetHeaterTemp, Device::Standby);
    _cooler->set(targetCoolerTemp, Device::Standby);
    set(targetTemp, Device::Auto);
}

Thermostat::SetModeState Thermostat::isSetNeeded()
{
    float min = 0; 
    float max = 0;
    Thermostat::SetModeState retVal = NoSet; 
    bool isAuto = false; 
    bool isAutoCurrent = false;
    Device::Status currentMode = getStatus();
    _room->getThermostatAdjustableTemp(&min, &max);
    isAuto = _room->getThermostatMode();
    
    if(currentMode == Device::Auto)
    {
        isAutoCurrent = true;
    }
    else
    {
        isAutoCurrent = false;
    }

    if(((targetLowTemp  != floatToFixedPoint(min))  ||
        (targetHighTemp != floatToFixedPoint(max))) &&
        (isAuto == isAutoCurrent)) 
    {
        retVal = AdjustableValuesSet;
    }
    else if((targetLowTemp  == floatToFixedPoint(min)) &&
            (targetHighTemp == floatToFixedPoint(max)) &&
            (isAuto != isAutoCurrent)) 
    {
        retVal = ModeSet;
    }    
    else if((targetLowTemp  != floatToFixedPoint(min)) ||
            (targetHighTemp != floatToFixedPoint(max)) ||
            (isAuto != isAutoCurrent)) 
    {
        retVal = AllValuesSet;
    }
    else
    {
        retVal = NoSet;
    }
    return retVal;
}

void Thermostat::setMode(bool isAutoMode)
{
    if(isAutoMode)
    {
        setAutoMode();
    }
    else
    {
        setStandbyMode();
    }
}

void Thermostat::setAdjustableTemp(int targetLow, int targetHigh)
{
    if(targetLow < minWorkingTemp)
    {
        //TODO RUNTIME ERROR
    }
    else if(targetHigh > maxWorkingTemp)
    {
        //TODO RUNTIME ERROR
    }
    else
    {
        targetLowTemp = targetLow;
        targetHighTemp = targetHigh;
        targetHeaterTemp = floatToFixedPoint(fixedPointToFloat(targetLowTemp) + 1);
        targetCoolerTemp = floatToFixedPoint(fixedPointToFloat(targetHighTemp) - 1); 
    }
}

void Thermostat::getData()
{
    Device::Status subStatus = getSubStatus();
    Device::Status status = getStatus();
    float readTempVal = fixedPointToFloat(EnvironmentTemp);
    float targetTempVal = fixedPointToFloat(targetTemp);
    float minTempVal = fixedPointToFloat(targetLowTemp);
    float maxTempVal = fixedPointToFloat(targetHighTemp);
    bool isThermostatWork = false;
    bool isThermostatHeat = false;
    bool isThermostatCool = false;

    if(status == Device::Auto)
    {
        isThermostatWork = true;
    }
    else
    {
        isThermostatWork = false;
    }

    if(subStatus == Device::Heating)
    {
        isThermostatHeat = true;
        isThermostatCool = false;
    }
    else if(subStatus == Device::Cooling)
    {
        isThermostatHeat = false;
        isThermostatCool = true;       
    }
    else
    {
        isThermostatHeat = false;
        isThermostatCool = false;
    }

    _room->setThermostatValues(readTempVal, targetTempVal, minTempVal, maxTempVal, isThermostatWork, isThermostatHeat, isThermostatCool);
}

void Thermostat::work()
{
    if(isSetNeeded() == Thermostat::AdjustableValuesSet)
    {
        float min = 0, max = 0;
        _room->getThermostatAdjustableTemp(&min, &max);
        setAdjustableTemp(floatToFixedPoint(min),
                          floatToFixedPoint(max));
        _room->thermostatAdjustableTempsChanged();
    }
    else if(isSetNeeded() == Thermostat::ModeSet)
    {
        setMode(_room->getThermostatMode());
        _room->thermostatModeChanged();
    }
    else if(isSetNeeded() == Thermostat::AllValuesSet)
    {
        //TODO
        float min = 0, max = 0;
        _room->getThermostatAdjustableTemp(&min, &max);
        setAdjustableTemp(floatToFixedPoint(min),
                          floatToFixedPoint(max));
        _room->thermostatAdjustableTempsChanged();
        setMode(_room->getThermostatMode());
        _room->thermostatModeChanged();
    }
    else
    {
        //DO NOTHING
    }

    Device::Status currentMode = getStatus();
    Device::Status currentSubMode = getSubStatus();
    EnvironmentTemp = floatToFixedPoint(_room->getRoomTemp()); 

    if((currentMode == Device::Auto) && (currentSubMode == Device::Standby) && (EnvironmentTemp < targetLowTemp))
    {
        setHeatingMode();
        _room->startHeating();
    }
    else if((currentMode == Device::Auto) && (currentSubMode == Device::Standby) && (EnvironmentTemp > targetHighTemp))
    {
        setCoolingMode();
        _room->startCooling();
    }
    else if((currentMode == Device::Auto) && (currentSubMode == Device::Heating) && (EnvironmentTemp == targetHeaterTemp))
    {
        setAutoMode();
        _room->startSteady();
    }
    else if((currentMode == Device::Auto) && (currentSubMode == Device::Cooling) && (EnvironmentTemp == targetCoolerTemp))
    {
        setAutoMode();
        _room->startSteady();
    }
    else if((currentMode == Device::Auto) && (currentSubMode == Device::Cooling))
    {
        _room->tempCooling();
    }
    else if((currentMode == Device::Auto) && (currentSubMode == Device::Heating))
    {
        _room->tempHeating();
    }
    else if((currentMode == Device::Auto) && (currentSubMode == Device::Standby))
    {
        _room->tempSteady();
    }
    else if((currentMode == Device::Standby) && (currentSubMode == Device::Standby))
    {
        _room->thermostatSleep();
    }
    else
    {
        //TODO RUN TIME ERROR
    }

    getData();
}

