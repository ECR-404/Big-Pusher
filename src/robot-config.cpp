#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftChassisMotorA = motor(PORT7, ratio18_1, false);
motor LeftChassisMotorB = motor(PORT8, ratio18_1, true);
motor_group LeftChassis = motor_group(LeftChassisMotorA, LeftChassisMotorB);
motor RightChassisMotorA = motor(PORT3, ratio18_1, false);
motor RightChassisMotorB = motor(PORT4, ratio18_1, true);
motor_group RightChassis = motor_group(RightChassisMotorA, RightChassisMotorB);
motor Puncher = motor(PORT18, ratio36_1, true);
limit PuncherSw = limit(Brain.ThreeWirePort.A);
digital_out Wings = digital_out(Brain.ThreeWirePort.B);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}