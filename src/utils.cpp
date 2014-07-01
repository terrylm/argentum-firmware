#include "utils.h"

#include "settings.h"

int ram_free(void) {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

double ram_utilisation(void) {
    return (ram_free() / 81.92); // 8192 bytes total * 100 to be percent.
}

void print_settings(AxisSettings *settings) {
    Serial.println("Axis Settings:");
    Serial.println(settings->axis);
    Serial.println(settings->flipped);
    Serial.println(settings->length);
}
