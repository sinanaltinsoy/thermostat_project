//
//  Room.hpp
//  Room
//
//  Created by Sinan Altinsoy on 23/12/21.
//  Copyright © 2021 Sinan Altinsoy. All rights reserved.
//

#ifndef RoomApp_hpp
#define RoomApp_hpp

#include "Room.hpp"
#include <iostream>

using namespace std;

class RoomApp : public Room
{
public:
	RoomApp(float initRealTemp, float initThermostatMinTemp, float initThermostatMaxTemp);
	~RoomApp();
	void thermostatConnect();
	void thermostatDisconnect();
	void tempHeating();
	void tempCooling();
	void tempSteady();
	void startHeating();
	void startCooling();
	void startSteady();
	void thermostatSleep();
	void thermostatModeChanged();
	void thermostatAdjustableTempsChanged();
	void thermostatTargetTempChanged();
};

#endif /* RoomApp_hpp */