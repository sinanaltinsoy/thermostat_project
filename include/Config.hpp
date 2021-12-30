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

#define FIXED_POINT_OFFSET           40//TODO (0 - THERMOSTAT_MIN_WORKING_TEMP)
#define FIXED_POINT_INDEX            10

inline int floatToFixedPoint(float Temp)
{
    return (int)roundf((float)FIXED_POINT_INDEX * (Temp + (float)FIXED_POINT_OFFSET));
}  

inline float fixedPointToFloat(int TempFixed)
{
    return ((float)TempFixed / (float)FIXED_POINT_INDEX) - (float)FIXED_POINT_OFFSET;
}

#endif /* Config_hpp */