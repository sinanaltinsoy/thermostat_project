//
//  Config.hpp
//  Config
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef Config_hpp
#define Config_hpp

#include <math.h>
#include <iostream>
#include <stdbool.h>
#include <stdexcept>

#define THERMOSTAT_MIN_WORKING_TEMP_LIMIT -40.0
#define THERMOSTAT_MAX_WORKING_TEMP_LIMIT  40.0
#define COOLER_MIN_WORKING_TEMP_LIMIT  -18.0
#define COOLER_MAX_WORKING_TEMP_LIMIT   40.0
#define HEATER_MIN_WORKING_TEMP_LIMIT  -40.0
#define HEATER_MAX_WORKING_TEMP_LIMIT   30.0

inline int floatToFixedPoint(float temp, float fixedPointOffset, float fixedPointIndex)
{
    return (int)roundf(fixedPointIndex * (temp + fixedPointOffset));
}  

inline float fixedPointToFloat(int tempFixed, float fixedPointOffset, float fixedPointIndex)
{
    return ((float)tempFixed / fixedPointIndex - fixedPointOffset);
}

#endif /* Config_hpp */