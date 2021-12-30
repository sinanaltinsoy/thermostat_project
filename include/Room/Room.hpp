//
//  Room.hpp
//  Room
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef Room_hpp
#define Room_hpp

class Room
{
private:
	float realTemp;
	/* Set Values */
    float thermostatMinTempSet;
    float thermostatMaxTempSet;
    bool isThermostatAutoModeSet;
	/* Read Values */
    float thermostatTemp;
    float thermostatTargetTemp;
    float thermostatMinTemp;
    float thermostatMaxTemp;
    bool isThermostatAutoMode;
    bool isThermostatHeating;
    bool isThermostatCooling;
public:
	Room(float initRealTemp, float initThermostatMinTemp, float initThermostatMaxTemp);
	~Room();
	virtual void thermostatConnect() = 0;
	virtual void thermostatDisconnect() = 0;
	virtual void tempHeating() = 0;
	virtual void tempCooling() = 0;
	virtual void tempSteady() = 0;
	virtual void startHeating() = 0;
	virtual void startCooling() = 0;
	virtual void startSteady() = 0;
	virtual void thermostatSleep() = 0;
	virtual void thermostatModeChanged() = 0;
	virtual void thermostatAdjustableTempsChanged() = 0;
	virtual void thermostatTargetTempChanged() = 0;

	void setRoomTemp(float Temp);
	float getRoomTemp();	
	void setThermostatValues(float readTempVal, float targetTempVal, float minTempVal, float maxTempVal, bool isThermostatWork, bool isThermostatHeat, bool isThermostatCool);
	void getThermostatValues(float *readTempVal, float *targetTempVal, float *minTempVal, float *maxTempVal, bool *isThermostatWork, bool *isThermostatHeat, bool *isThermostatCool);
	void setThermostatAdjustableTemp(float min, float max);
	void getThermostatAdjustableTemp(float *min, float *max);
	void setThermostatMode(bool isAutoMode);
	bool getThermostatMode();
};

#endif /* Room_hpp */