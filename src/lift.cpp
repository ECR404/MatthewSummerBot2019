#include "main.h"
#include "lift.h"
#include "treelarlib.h"

LiftControl::LiftControl()
{
  liftState = 0;

  pros::Task keepAtPos1Task(keepAtPosOne);
  pros::Task keepAtPos2Task(keepAtPosTwo);

  keepAtPos1Task.suspend();
  keepAtPos2Task.suspend();
}

void LiftControl::Loop()
{
  // handleIntakeOuttake();
  pros::lcd::set_text(2, std::to_string(liftState));


  switch(liftState)
  {
    case 1:
      
      break;
    case 2:
      
      break;
      
    case 0:
      liftMotor.move_voltage(0);
      break;
  }

  if(liftState > 0)
  {
    triBar.move_absolute(500, 200);
  }

}

void LiftControl::stepUp()
{
  switch(liftState)
  {
    case 0:
      setToSmallCup();
      break;
    case 1:
      setToTallCup();
      break;
    case 2:
      break;
  }
}

int LiftControl::getState()
{
  return liftState;
}

void LiftControl::stepDown()
{
  switch(liftState)
  {
    case 2:
      setToSmallCup();
      break;
    case 1:
      reset();
      break;
    case 0:
      break;
  }
}

void LiftControl::setToSmallCup()
{
  // liftMotor.move_relative(120, 10);
  // pros::delay(500);
  keepAtPos2Task.suspend();
  keepAtPos1Task.resume();
  liftState = 1;
}

void LiftControl::keepAtPosOne(void* params)
{
  liftMotor.move_absolute(400, 1000);
  while(liftMotor.get_position() < 400-5 && liftMotor.get_position() > 400+5)
  {
    pros::delay(2);
  }
}

void LiftControl::setToTallCup()
{
  // liftMotor.move(-120);
  // pros::delay(500);
  keepAtPos1Task.suspend();
  keepAtPos2Task.resume();
  liftState = 2;
}

void LiftControl::keepAtPosTwo(void* params)
{
  liftMotor.move_absolute(650, 1000);
  while(liftMotor.get_position() < 650-5 && liftMotor.get_position() > 650+5)
  {
    pros::delay(2);
  }
}

void LiftControl::reset()
{
  // liftMotor.move(-120);
  triBar.move_voltage(0);

  keepAtPos1Task.suspend();
  keepAtPos2Task.suspend();
  // liftMotor.move_voltage(0);
  liftState = 0;
}
