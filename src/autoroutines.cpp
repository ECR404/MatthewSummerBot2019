#include "main.h"
/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/

// auto profileController = AsyncControllerFactory::motionProfile(10.0,2.0,10.0,myChassis);

void skillRun()
{
  pros::lcd::print(2, "Auto:  skillRun");
  liftMotor.moveAbsolute(100,-100);
  pros::delay(300);
  liftMotor.move(-18);
  pros::delay(500);
  intakeMotorLeft.move(100);
  intakeMotorRight.move(100);
  drive.setMaxVelocity(45);
  drive.moveDistance(1.27_m);
  liftMotor.move(0);
  drive.turnAngle(140_deg);
  drive.setMaxVelocity(150);
  drive.moveDistance(1.22_m);
  intakeMotorLeft.move(-55);
  intakeMotorRight.move(-55);
  triBar.moveAbsolute(-630,45);
  pros::delay(2000);
  intakeMotorLeft.move(-100);
  intakeMotorRight.move(-100);
  drive.setMaxVelocity(200);
  drive.moveDistance(-1_m);
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
