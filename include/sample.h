//#ifndef _FILENAME_H_     -MUST BE IN ALL HEADER FILES
//#define _FILENAME_H_     -MUST BE IN ALL HEADER FILES
#ifndef _SAMPLE_H_
#define _SAMPLE_H_

#include "api.h" //standard PROS api
#include "okapi/api.hpp" //special okapi API, includes motion profiling

//macros can be used instead of parameters or normal numbers or other values
//to allow ease of editing, in this example wherever SAMPLE_MACRO appears, it
//will be read by the code as the integer 500
#define SAMPLE_MACRO 500

//extern keyword means that the following variable or function is defined in a
//cpp file somewhere in the code, and makes that variable or function global, or
//visible to all cpp files in the project
extern bool sampleVar;

//FUNCTION EXAMPLES
//function that takes an integer as a parameter and returns nothing, used to
//perform actions or modify variables
void sampleFunction(int sampleParameter);
//can be done with different return types or parameters

//this is the format for a function that will be used to create a task
//tasks are used for multitasking, useful for launchers, lifts, etc
void sampleTaskFn(void* params);

#endif
//#endif                   -MUST BE IN ALL HEADER FILES
