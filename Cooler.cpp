#include "Cooler.hpp"

Cooler::Cooler(int maxTemp, int minTemp, int initialTarget)
{
    targetTemp = initialTarget;
    maxWorkingTemp = maxTemp;
    minWorkingTemp = minTemp;

    setStandbyMode();
}

Cooler::~Cooler()
{
    //DO NOTHING
}

void Cooler::setCoolingMode()
{
    setStatus(Cooling);
}


int Cooler::set(int target, Device::Status newStatus)
{
    targetTemp = target;

    if(newStatus == Cooling)
    {
        setCoolingMode();
    }
    else
    {
        setStandbyMode();
    }  
}
