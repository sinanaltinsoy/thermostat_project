#include "Heater.hpp"

Heater::Heater(int maxTemp, int minTemp, int initialTarget)
{
    targetTemp = initialTarget;
    maxWorkingTemp = maxTemp;
    minWorkingTemp = minTemp;

    setStandbyMode();
}

Heater::~Heater()
{
    //DO NOTHING
}

void Heater::setHeatingMode()
{
    setStatus(Heating);
}

int Heater::set(int target, Device::Status newStatus)
{
    targetTemp = target;
    if(newStatus == Heating)
    {
        setHeatingMode();
    }
    else
    {
        setStandbyMode();
    }  
}
