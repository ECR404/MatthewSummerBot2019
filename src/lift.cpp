#include "main.h"
#include "lift.h"

enum IntakeState
{
  intaking = 0,
  outtaking = 1,
};

LiftControl::LiftControl()
{
  liftState = 0;
  intakeState = IntakeState::intaking;
}

void LiftControl::Loop()
{
  // handleIntakeOuttake();
  pros::lcd::set_text(2, std::to_string(liftState));
  switch(liftState)
  {
    case 1:
      liftMotor.move_absolute(300, 10000);
      break;
    case 2:
      liftMotor.move_absolute(550, 10000);
      break;
    case 0:
      liftMotor.move_voltage(0);
      break;
  }

  if(liftState > 0)
  {
    // if(intakeState == IntakeState::intaking)
    // {
    //   intakeMotorLeft.move(-127);
    //   intakeMotorRight.move(-127);
    // }
    // if(intakeState == IntakeState::outtaking)
    // {
    //   intakeMotorLeft.move(127);
    //   intakeMotorRight.move(127);
    // }
    // triBar.move_voltage(-12000);
  }

}

void LiftControl::handleIntakeOuttake()
{
  if(ControllerButton(ControllerDigital::R1).changedToPressed())
    intakeState = IntakeState::outtaking;
  if(ControllerButton(ControllerDigital::R2).changedToPressed())
    intakeState = IntakeState::intaking;
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
  liftState = 1;
}

void LiftControl::setToTallCup()
{
  // liftMotor.move(-120);
  // pros::delay(500);
  liftState = 2;
}

void LiftControl::reset()
{
  // liftMotor.move(-120);
  triBar.move_voltage(0);
  // liftMotor.move_voltage(0);
  liftState = 0;
}
