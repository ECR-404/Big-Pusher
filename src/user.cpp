#include "iostream"
#include "vex.h"
#include "robot-config.h"

using namespace vex;

static bool puncher = false;

void _StartPuncher() { puncher = true; }

void _StopPuncher() { /*puncher = false;*/ }

void _Wing() { Wings = !Wings; }

void user() {
  Puncher.setStopping(hold);
  while (true) {
    // Chassis
    LeftChassis.spin(forward, Controller1.Axis3.position(percent), percent);
    RightChassis.spin(forward, Controller1.Axis2.position(percent), percent);
    // Wing
    Controller1.ButtonR2.pressed(_Wing);
    // Puncher
    Controller1.ButtonL1.pressed(_StartPuncher);
    Controller1.ButtonL2.pressed(_StopPuncher);
    PuncherSw.pressed(_StopPuncher);
    if (Controller1.ButtonL2.pressing()) {
      puncher = true;
    } else if (PuncherSw.pressing()) {
      puncher = false;
    }
    if (puncher) {
      Puncher.spin(forward, 100, percent);
    } else if (!puncher) {
      Puncher.stop();
    }
  }
}
