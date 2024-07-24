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
int gameObjectsCollected = 0;

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
  while(gameObjectsCollected < 3) {
    drive.follow_line_til_mag(True);
    drive.turn(90);
    int bcid = -1;
    while (bcid == -1) {
      drive.follow_line_til_mag(False);
      arm.run_motor(ChestArmPosition);
      bcid = drive.get_visible_bcid();
    }
    int arm_pos = get_arm_position_for(bcid);
    while (!drive.center_barcode(bcid, false)) {
      arm.run_motor(arm_pos);
    }
    while (!arm.run_motor(arm_pos)) {}
    gripper.close(true);
    delay(250);
    drive.turn(180);
    while (drive.follow_line_til_mag(False)) {
      arm.run_motor(IdleArmHeight);
    }
    drive.turn(-90);
    drive.follow_line_til_mag(true);
    gripper.open();
    drive.turn(180);
    gameObjectsCollected++;
  }
}

int get_arm_position_for(int bcid) {
  switch (bcid) {
    case ChestBarcodeID: return ChestArmPosition;
    case PineappleBarcodeID: return PineappleArmPosition;
    case TridentBarcodeID: return TridentArmPosition;
  }
}

/************************************ Loop ************************************/

void loop() {
  
}
