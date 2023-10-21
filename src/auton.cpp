#include "iostream"
#include "vex.h"
#include "robot-config.h"
#include "thread"
#include "math.h"

using namespace vex;

void reset() {
  LeftChassis.resetPosition();
  RightChassis.resetPosition();
}

void driveStraight(double position) {
  reset();
  if (position > 0) {
    while (LeftChassis.position(degrees) < position) {
      LeftChassis.spin(forward, 100, percent);
      RightChassis.spin(forward, 100, percent);
    }
    LeftChassis.stop(hold);
    RightChassis.stop(hold);
    reset();
  } else if (position < 0) {
    while (LeftChassis.position(degrees) > position) {
      LeftChassis.spin(reverse, 100, percent);
      RightChassis.spin(reverse, 100, percent);
    }
    LeftChassis.stop(hold);
    RightChassis.stop(hold);
    reset();
  } else {
    LeftChassis.stop(hold);
    RightChassis.stop(hold);
    reset();
  }
}

void driveStraight(double position, int pow) {
  reset();
  if (position > 0) {
    while (LeftChassis.position(degrees) < position) {
      LeftChassis.spin(forward, 100, percent);
      RightChassis.spin(forward, 100, percent);
    }
    LeftChassis.stop(hold);
    RightChassis.stop(hold);
    reset();
  } else if (position < 0) {
    while (LeftChassis.position(degrees) > position) {
      LeftChassis.spin(reverse, 100, percent);
      RightChassis.spin(reverse, 100, percent);
    }
    LeftChassis.stop(hold);
    RightChassis.stop(hold);
    reset();
  } else {
    LeftChassis.stop(hold);
    RightChassis.stop(hold);
    reset();
  }
}

void turnInPlace(double deg, int pow) {
  reset();
  int rightWheelDegrees = deg * 4.1; // 4.0278;
  // int leftWheelDegrees = -deg*4.1;   //4.0278;
  if (deg > 0) {
    while (RightChassis.position(degrees) < rightWheelDegrees) {
      RightChassis.spin(forward, pow, percent);
      LeftChassis.spin(reverse, pow, percent);
    }
    RightChassis.stop(hold);
    LeftChassis.stop(hold);
    reset();
  } else if (deg < 0) {
    while (RightChassis.position(degrees) > rightWheelDegrees) {
      RightChassis.spin(reverse, pow, percent);
      LeftChassis.spin(forward, pow, percent);
    }
    RightChassis.stop(hold);
    LeftChassis.stop(hold);
    reset();
  }
  reset();
}

void wings(bool x) {
  Wings = x;
}

void punch(int rep) {
  int c = rep;
  while(c<0) {
    Puncher.spin(forward, 100, percent);
    if(PuncherSw.pressing()) {
      c++;
    }
  }
}

void auton() {
  reset();
  wings(false);
}