#include "api.h"
#include "okapi/api.hpp"

#ifndef CHASSIS_H
#define CHASSIS_H

//CHASSIS RELATED VARIABLES AND FUNCTIONS
extern okapi::ChassisControllerPID myChassis; //for auton
extern okapi::ChassisControllerIntegrated drive; //for user control

void userDrive();

//Add more functions here
//format: returnType functionName(parameterType parameterName);


#endif
