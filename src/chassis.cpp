#include "main.h"

//CHASSIS VARIABLES

//drive controller using built in PID to use in userControl
okapi::ChassisControllerIntegrated drive = ChassisControllerFactory::create(
  {1,2}, {-3,-4}, //leftMotors, rightMotors (negative = reversed)
  AbstractMotor::gearset::green, //200rpm internal gearing
  {4_in, 13_in}); //chassis specs (wheel size, chassis width)

//drive controller using tuned PID to use in auton
//to tune PID: start values near 0 (such as .0001) and increase until performs as desired (if only using kp)
//final value will end up near .005
okapi::ChassisControllerPID myChassis = ChassisControllerFactory::create(
  {1,2}, {-3,-4}, //leftMotors, rightMotors (negative = reversed)
  IterativePosPIDController::Gains{0, 0, 0}, //distance PID values (kp, ki, kd)
  IterativePosPIDController::Gains{0, 0, 0}, //angle PID values (to drive straight)
  IterativePosPIDController::Gains{0, 0, 0}, //turning PID values
  AbstractMotor::gearset::green, //internal gearing
  ChassisScales {4_in, 13_in} //chassis specs (wheel size, chassis width)
);

void userDrive()
{
  //normal tank drive controls
  drive.tank(controller.getAnalog(ControllerAnalog::leftY),
  controller.getAnalog(ControllerAnalog::rightY));
}
