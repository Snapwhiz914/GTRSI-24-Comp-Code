#ifndef ARM_H
#define ARM_H

class Arm {
  public:
    void do_setup() {
      arm_zero = home_arm();
      setup_encoder();
    }

    bool run_motor(int goal) {
      //Remember to return if it is at goal
    }

  private:
    int goal;
    float arm_zero;
}

#endif
