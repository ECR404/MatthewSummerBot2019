//#ifndef _FILENAME_H_     -MUST BE IN ALL HEADER FILES
//#define _FILENAME_H_     -MUST BE IN ALL HEADER FILES
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "api.h" //standard PROS api
#include "okapi/api.hpp" //special okapi API, includes motion profiling

#define NUM_SCRIPTS 5										// Number of autonomous scripts

// function stubs for auton select
void on_left_button();
void on_center_button();
void on_right_button();

//Device setup
//EXTERN MOTORS, CONTROLLER, AND SENSORS HERE
//extern keyword means that the following variable or function is defined in a
//cpp file somewhere in the code, and makes that variable or function global, or
//visible to all cpp files in the project
//define devices in initialize.cpp

//chassis will be externed in chassis.h
extern okapi::Motor intakeMotorRight;
extern okapi::Motor intakeMotorLeft;
extern okapi::Motor liftMotor;
extern okapi::Motor triBar;
//format: extern okapi::Motor motorName;

extern okapi::Controller controller; //Always extern the controller

//Other global variables

#endif
//#endif                   -MUST BE IN ALL HEADER FILES
