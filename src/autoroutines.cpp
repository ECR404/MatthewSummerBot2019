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
  //delay(200);
//  delay(3000);
/*  intakeMotorLeft.move(100);
  intakeMotorRight.move(100);
  drive.moveDistance(1.2_m);
  drive.turnAngle(90_deg);*/
  //insert autonomous code here
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
