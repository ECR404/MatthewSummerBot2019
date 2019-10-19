#include "api.h"
#include "okapi/api.hpp"

#ifndef LIFT_H
#define LIFT_H

class LiftControl
{
    private:
        int liftState;
        int intakeState;
        void handleIntakeOuttake();
        pros::Task keepAtPos1Task;
        pros::Task keepAtPos2Task;

        void keepAtPosOne();
        void keepAtPosTwo();

    public:
        LiftControl();
        void setToSmallCup();
        void setToTallCup();
        void reset();

        void stepUp();
        void stepDown();

        int getState();

        void Loop();

};

#endif
