#include "Device.hpp"

Device::Device()
{
    //DO NOTHING
}

Device::~Device()
{
    //DO NOTHING
}

Device::Status Device::getStatus()
{
    return _status;
}

void Device::setStatus(const Status status)
{
    _status = status;
}

void Device::setStandbyMode()
{
    setStatus(Standby);
}
