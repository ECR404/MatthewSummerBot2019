#include "main.h"

//DEVICE DEFINITIONS
Controller controller;

Motor intakeMotorRight(4, //motorPort
	true, //reversed or not
	AbstractMotor::gearset::red, //internal gearing
	AbstractMotor::encoderUnits::degrees); //measurement type

	Motor intakeMotorLeft(9, //motorPort
		false, //reversed or not
		AbstractMotor::gearset::red, //internal gearing
		AbstractMotor::encoderUnits::degrees); //measurement type

		Motor liftMotor(7, //motorPort
			true, //reversed or not
			AbstractMotor::gearset::red, //internal gearing
			AbstractMotor::encoderUnits::degrees); //measurement type

			Motor triBar(8, //motorPort
				false, //reversed or not
				AbstractMotor::gearset::red, //internal gearing
				AbstractMotor::encoderUnits::degrees); //measurement type
				//add other motors and sensors here

				//END DEVICE DEFINITIONS

				//IMPORTANT FOR AUTON SELECT, DO NOT MODIFY
				// array for scripts descriptions/names displayed in selection menu
				const char* titles[] = {"Skills", "autoRedLeft", "AutoBlueLeft", "autoRedRight", "autoBlueRight"};

				int selection;													// Select script to run
				unsigned int scriptNumber = 0;					// scriptNumber which will be passed
				// to autonomous() and run matching function
				// via the glabal selection

				static bool selectionMade = false;

				void on_left_button()
				{
					static bool pressed = false;
					if(!selectionMade)
					{
						pros::lcd::clear_line(4);
						if (scriptNumber != 0)
						{
							scriptNumber--;
							pros::lcd::print(2, "Script#: %d\n", scriptNumber);
							pros::lcd::print(3, titles[scriptNumber]);
						}
						else
						{
							pros::lcd::print(2, "Script#: %d Can't decrement\n", scriptNumber);
							pros::lcd::print(3, titles[scriptNumber]);
						}
					}
				}

				void on_center_button()
				{
					static bool pressed = false;
					pressed = !pressed;
					if (pressed)
					{
						selection = scriptNumber;
						pros::lcd::set_text(4, "<< SELECTED >>");
						selectionMade = true;
					}
					else
					{
						pros::lcd::set_text(4, "<< DE-SELECTED >>");
						selection = 0;					// Reset selection
						selectionMade = false;
					}
				}

				void on_right_button()
				{
					static bool pressed = false;
					if(!selectionMade)
					{
						pros::lcd::clear_line(4);
						if (scriptNumber < (NUM_SCRIPTS - 1))
						{
							scriptNumber++;
							pros::lcd::print(2, "Script#: %d\n", scriptNumber);
							pros::lcd::print(3, titles[scriptNumber]);
						} else
						{
							pros::lcd::print(2, "Script#: %d Can't increment\n", scriptNumber);
							pros::lcd::print(3, titles[scriptNumber]);
						}
					}
				}
				//END AUTON SELECT FUNCTIONS

				//Initialize global variables here, unless initialized in a seperate cpp file



				/**
				* Runs initialization code. This occurs as soon as the program is started.
				*
				* All other competition modes are blocked by initialize; it is recommended
				* to keep execution time for this mode under a few seconds.
				*/
				void initialize()
				{
					pros::lcd::initialize();

					//this will start a task using the sampleTaskFn we declared in sample.h and
					//defined in sample.cpp, tasks run in parallel to other tasks, and the
					//userControl loop
					pros::Task sampleTask(sampleTaskFn);
				}

				/**
				* Runs while the robot is in the disabled state of Field Management System or
				* the VEX Competition Switch, following either autonomous or opcontrol. When
				* the robot is enabled, this task will exit.
				*/
				void disabled() {}

				/**
				* Runs after initialize(), and before autonomous when connected to the Field
				* Management System or the VEX Competition Switch. This is intended for
				* competition-specific initialization routines, such as an autonomous selector
				* on the LCD.
				*
				* This task will exit when the robot is enabled and autonomous or opcontrol
				* starts.
				*/
				void competition_initialize()
				{
					//AUTON SELECT
					pros::lcd::set_text(1, "Autonomous Mode Select");

					// Write script 0 selection as first choice to screen
					if (scriptNumber == 0) {
						pros::lcd::print(2, "Script#: %d\n", scriptNumber);
						pros::lcd::print(3, titles[scriptNumber]);
					}

					pros::lcd::register_btn0_cb(on_left_button);
					pros::lcd::register_btn1_cb(on_center_button);
					pros::lcd::register_btn2_cb(on_right_button);
					//END AUTON SELECT

				}
