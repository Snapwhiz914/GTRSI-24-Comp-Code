#ifndef GRIPPER_H
#define GRIPPER_H

class Gripper {
  public:
    void do_setup() {
      motorG.run(GripperHomeSpeed);
      delay(GripperHomeTime);
      motorG.run(0);
    }

    void open() {
      motorG.run(GripperOpenSpeed);
      delay(GripperOpenTime);
      motorG.run(0);
    }

    void close(bool set_idle) {
      motorG.run(GripperCloseSpeed);
      delay(GripperCloseTime);
      if (set_idle) {
        motorG.run(GripperIdleSpeed);
      } else {
        motorG.run(0);
      }
    }
}

#endif
