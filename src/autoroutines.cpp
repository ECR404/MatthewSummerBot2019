#include "main.h"
/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/

// auto profileController = AsyncControllerFactory::motionProfile(10.0,2.0,10.0,myChassis);

void skillRun()
{
  pros::lcd::print(2, "Auto:  skillRun");
  liftMotor.moveAbsolute(250,-100);
  pros::delay(300);
  liftMotor.move(-18);
  pros::delay(500);
  intakeMotorLeft.move(100);
  intakeMotorRight.move(100);
  drive.setMaxVelocity(40);
  drive.moveDistance(1.1_m);
  liftMotor.move(0);
  drive.moveDistance(-.5_m);
  drive.turnAngle(140_deg); //136
  drive.setMaxVelocity(150);
  drive.moveDistance(.5_m);
  intakeMotorLeft.move(-65);
  intakeMotorRight.move(-65);
  triBar.moveAbsolute(-630,40);
  pros::delay(2000);
  intakeMotorLeft.move(-100);
  intakeMotorRight.move(-100);
  drive.setMaxVelocity(200);
  drive.moveDistance(-.5_m);
}

void autoRedLeft()
{
  pros::lcd::print(2, "Auto:  autoRedLeft");

}

void autoBlueLeft()
{
  pros::lcd::print(2, "Auto:  autoBlueLeft");

}

void autoRedRight()
{
  pros::lcd::print(2, "Auto:  autoRedRight");

}

void autoBlueRight()
{
  pros::lcd::print(2, "Auto:  autoBlueRight");

}
