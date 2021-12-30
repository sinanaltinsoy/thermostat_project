//
//  Cooler.hpp
//  Cooler
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef Cooler_hpp
#define Cooler_hpp

#include "Device.hpp"

class Cooler : public Device
{
private:  
    void setCoolingMode();
public:   
    Cooler(int maxTemp, int minTemp, int initialTarget);
    ~Cooler();
    int set(int target, Status newStatus);
};

#endif /* Cooler_hpp */
