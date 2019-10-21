#include "main.h"
#include "treelarlib.h"

void stickMotor(okapi::Motor motor, int pos, int vel)
{
    auto controller = AsyncControllerFactory::posIntegrated(motor, vel);
    controller.setTarget(pos);
    controller.waitUntilSettled();
}