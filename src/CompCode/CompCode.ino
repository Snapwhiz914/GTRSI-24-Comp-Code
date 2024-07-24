#include "MeMegaPi.h"
#include "Pixy2I2C.h"
#include <SoftwareSerial.h>

#include "Homing.h"
#include "Motors.h"
#include "Utilities.h"


/****************************** Global Variables ******************************/

Pixy2I2C pixy;
Drive drive;
Arm arm;
Gripper gripper;

/*********************************** Setup ************************************/

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing Robot...");
  drive.do_setup();
  arm.do_setup();
  gripper.do_setup();
  Serial.println("Subsystems set up");
  //Game auto sequence can go here
  //Remember to use the non blocking feature to do things simultaneously!
}


/************************************ Loop ************************************/

void loop() {
  
}
