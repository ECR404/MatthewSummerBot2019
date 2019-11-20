#include "main.h"
/**
 * This is where all the various autonomous routines are located
 * and subsequently called by the autonomous() selector based on LCD input
 **/

// auto profileController = AsyncControllerFactory::motionProfile(10.0,2.0,10.0,myChassis);

void skillRun()
{
  pros::lcd::print(2, "Auto:  skillRun");

/*
drive.setMaxVelocity(70);
drive.moveDistance(-.3_m);
drive.moveDistance(.8_m);
drive.moveDistance(-.5_m);
*/


  intakeMotorLeft.move(-100);
  intakeMotorRight.move(-100);
  drive.setMaxVelocity(80);
  drive.moveDistance(1.5_m);
  drive.turnAngle(180_deg);
  drive.moveDistance(1_m);
  drive.turnAngle(45_deg);
  drive.moveDistance(.65_m);
  triBar.moveAbsolute(180,-180);
  intakeMotorLeft.move(20);
  intakeMotorRight.move(20);
  pros::delay(2.5);
  drive.moveDistance(-.5_m);



  /*
  intakeMotorLeft.move(65);
  intakeMotorRight.move(65);
  drive.moveDistance(.25_m);
  liftMotor.move(65);
  pros::delay(3000);
  drive.moveDistance(.1_m);
  drive.moveDistance(-.5_m);




/*

  liftMotor.moveAbsolute(350,-180);
  pros::delay(300);
  liftMotor.move(-18);
  pros::delay(500);
  intakeMotorLeft.move(100);
  intakeMotorRight.move(100);
  drive.setMaxVelocity(40);
  drive.moveDistance(1.1_m);
  liftMotor.move(0);
  drive.moveDistance(-.5_m);
  drive.turnAngle(140_deg); //-137 blue 140 red
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




/*  liftMotor.moveAbsolute(350,-180);
  pros::delay(300);
  liftMotor.move(-10);
  pros::delay(500);
  triBar.move(10);
  intakeMotorLeft.move(100);
  intakeMotorRight.move(100);
  drive.setMaxVelocity(130);
  drive.moveDistance(1.1_m); // first move forward
  liftMotor.move(-5);
  drive.moveDistance(-.5_m);
  drive.setMaxVelocity(200);
  drive.turnAngle(58_deg); //first turn to adjust for next line
  //drive.setMaxVelocity(200);
  drive.moveDistance(-.8_m);
  drive.turnAngle(-47_deg); //turn to second line
  drive.moveDistance(1_m);//move forward to pick up
  drive.setMaxVelocity(150);
  drive.moveDistance(-.5_m);
  drive.setMaxVelocity(200);
  drive.turnAngle(-130_deg); //-136  blue 140 red  turn to aim
  drive.moveDistance(.5_m);
  intakeMotorLeft.move(-65);
  intakeMotorRight.move(-65);
  triBar.move(0);
  triBar.moveAbsolute(-630,50);
  pros::delay(1800);
  intakeMotorLeft.move(-100);
  intakeMotorRight.move(-100);
  drive.setMaxVelocity(200);
  drive.moveDistance(-.5_m);
  */
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
