#include "argentum.h"

// Should be x axis
Stepper a_motor(STEPPER_A_STEP_PIN, STEPPER_A_DIR_PIN, STEPPER_A_ENABLE_PIN);

// Should be y axis
Stepper b_motor(STEPPER_B_STEP_PIN, STEPPER_B_DIR_PIN, STEPPER_B_ENABLE_PIN);

Axis x_axis(Axis::X, &a_motor, &limit_x_positive, &limit_x_negative);
Axis y_axis(Axis::Y, &b_motor, &limit_y_positive, &limit_y_negative);

SerialCommand serial_command;

Rollers rollers;

SdFat sd;

long x_size = 0;
long y_size = 0;
