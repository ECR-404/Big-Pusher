/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\ecrro                                            */
/*    Created:      Fri Sep 29 2023                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// LeftChassis          motor_group   7, 8            
// RightChassis         motor_group   3, 4            
// Puncher              motor         18              
// PuncherSw            limit         A               
// Wings                digital_out   B               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Comp;
void user();
void auton();

int main() {
  vexcodeInit();
  Comp.autonomous(auton);
  Comp.drivercontrol(user);
  user();
}