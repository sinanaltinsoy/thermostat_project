//
//  Device.hpp
//  Device
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef Device_hpp
#define Device_hpp

class Device
{
public:    
    enum Status
    {
        Standby,
        Heating,
        Cooling,
        Auto,
        Error
    };
    Device();
    ~Device();
    Status getStatus();
private:
    Status _status; 
protected:
    int targetTemp;
    int maxWorkingTemp;
    int minWorkingTemp;
    void setStatus(const Status status);      
    void setStandbyMode();
    virtual int set(int target, Status newStatus) = 0;
};

#endif /* Device_hpp */
