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

void opcontrol() {
  // CLEAN LCD first
	pros::lcd::clear_line(1);
	pros::lcd::clear_line(2);
	pros::lcd::clear_line(3);
	pros::lcd::clear_line(4);
	pros::lcd::clear_line(5);

	pros::lcd::set_text(1, "Running in Operator Control Mode");

	LiftControl lc;
  double speed = -101;
	double slower = 0;
  while(true)
	{
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
				intakeMotorLeft.move(15);
				intakeMotorRight.move(15);
			}
			if(drop.isPressed()){
				triBar.move(110);
			}
			else if(pickUp.isPressed()){
				triBar.move((int)speed);
				slower += 0.0215; //.05115
			  speed += slower;
				if(speed >= -92)
				{
					speed = -92;
				}
				intakeMotorLeft.move(-20);
				intakeMotorRight.move(-20);
			}
			else{
				triBar.move(10);
				speed = -110;
				slower = 0;
			}
			if(lift.changedToPressed()){
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
			lc.Loop();
			  pros::delay(20);
	}
}
