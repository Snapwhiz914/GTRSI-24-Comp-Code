#ifndef DRIVE_H
#define DRIVE_H

#include "MeMegaPi.h"
#include "Homing.h"
#include "Motors.h"
#include "Utilities.h"
#include "Pixy2I2C.h"
#include <SoftwareSerial.h>

class Drive {
  public:
    void do_setup() {
      Serial2.begin(9600);
      pixy.init();
      pixy.setLamp(255, 255);
    }
  
    void move(int u_lin, int u_ang);

    bool follow_line_until_mag(bool blocking) {
      if (!blocking) {
        followLine();
        return check_mag();
      } else {
        while (!check_mag()) follow_line();
        return true
      }
    }

    bool check_mag();

    int get_visible_bcid() {
      if (pixy.line.numBarcodes == 0) return -1;
      return pixy.line.barcodes[0].value;
    }

    bool center_bar_code(bool blocking) {
      if (!blocking) {
        return center_barcode();
      } else {
        while (!center_barcode()) {}
        return true
      }
    }

  private:
    float get_line_linear_error();
    float get_line_angular_error();
    void follow_line();
    bool center_barcode(int id);
}

#endif
