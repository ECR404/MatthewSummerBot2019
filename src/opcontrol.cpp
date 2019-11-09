#include "main.h"
#include "lift.h"
/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
ControllerButton intakeButton(ControllerDigital::R1);
ControllerButton outtakeButton(ControllerDigital::R2);
ControllerButton drop(ControllerDigital::L2);
ControllerButton pickUp(ControllerDigital::L1);
ControllerButton lift(ControllerDigital::up);
ControllerButton lower(ControllerDigital::down);
ControllerButton armUp(ControllerDigital::X);
ControllerButton armDown(ControllerDigital::B);

double tribarMultiplier = 0.7;

void opcontrol() {
  // CLEAN LCD first
	pros::lcd::clear_line(1);
	pros::lcd::clear_line(2);
	pros::lcd::clear_line(3);
	pros::lcd::clear_line(4);
	pros::lcd::clear_line(5);
	pros::lcd::set_text(1, "");

//	LiftControl lc;
  double speed = -200;
	double slower = 0;


  while(true)
	{
		//liftMotor.move(127);
			//User Control code here
			userDrive();
			if(intakeButton.isPressed()){
				intakeMotorLeft.move(200);
				intakeMotorRight.move(200);
			}
			else if(outtakeButton.isPressed()){
				intakeMotorLeft.move(-100);
				intakeMotorRight.move(-100);
			}
			else{
				intakeMotorLeft.move(10);
				intakeMotorRight.move(10);
			}
			if(drop.isPressed()){
				triBar.move(50*tribarMultiplier);
			}
			else if(pickUp.isPressed())
			{
				if(triBar.getPosition() >= -300)
				{
					triBar.move(-200*tribarMultiplier);
				}
			else if(triBar.getPosition() < -300)
				{
					triBar.move(-60*tribarMultiplier);
				}

		/*		slower += 0.00000000001; //.05115
			  speed += slower;
				if(speed >= -80)
				{
					speed = -80;
				} */
				intakeMotorLeft.move(-5);
				intakeMotorRight.move(-5);
			}
			else{
				triBar.move(10*tribarMultiplier);
				speed = -130;
				slower = 0;
			}
/////////////////////////////Arm Controls///////////////////////////////////////////
			if(armUp.isPressed())
			{
				liftMotor.move(127);
			}
			else if(armDown.isPressed())
			{
				liftMotor.move(-127);
			}
			else
			{
				if(liftMotor.getPosition() > 10)
			 	{
					liftMotor.move(10);
				}
				else
				{
					liftMotor.move(-5);
				}
			}
////////////////////////////////////////////////////////////////////////////////////
/*			if(lift.changedToPressed()){
				// liftMotor.move(-127);
				lc.stepUp();
			}
			else if(lower.changedToPressed()){
				// liftMotor.move(127);
				lc.stepDown();
			}
			else{
				liftMotor.move(-8);
			}

			*/
		//	lc.Loop();
			  //pros::delay(20);
	}
}
