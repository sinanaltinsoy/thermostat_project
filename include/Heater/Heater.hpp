//
//  Heater.hpp
//  Heater
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef Heater_hpp
#define Heater_hpp

#include "Device.hpp"

class Heater : public Device
{
private:
    void setHeatingMode();
public:
    Heater(int maxTemp, int minTemp, int initialTarget);
    ~Heater();
    int set(int target, Status newStatus);
};

#endif /* Heater_hpp */
