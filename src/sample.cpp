#include "main.h"

//here we will implement the code that was outlined in sample.h

//externed variables must be declared and initialized
//like normal variables, then they will become public
bool sampleVar = true;

//these are button objects, they can be used to detect when buttons on the
//controller are pressed
//NOTE: these are not externed in sample.h because it is not required to be global
//since it is only referenced in this file
ControllerButton sampleButton1(ControllerDigital::R1);
ControllerButton sampleButton2(ControllerDigital::R2);

void sampleFunction(int sampleParameter)
{
  //insert code here
}

void sampleTaskFn(void* params)
{
  //some code that will run once
  while(true)
  {
    //code that will be repeated while the task runs
    //the while(true) and delay MUST be used for the task to work as intended
    //see initialize.cpp to see how to start tasks

    //while this button is pressed, it will be true and continue to occur
    if(sampleButton1.isPressed())
    {
      sampleFunction(10);
    }

    //this will only run once when the button is pressed, the button must be
    //released and pressed again for this to run again
    if(sampleButton2.changedToPressed())
    {
      sampleFunction(SAMPLE_MACRO);
    }
    pros::delay(10);
  }
}
