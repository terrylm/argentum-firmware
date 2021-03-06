
#ifndef _SETTINGS_H_
#define _SETTINGS_H_

#include <Arduino.h>

const uint16_t SETTINGS_ADDRESS = 0;

// Insist that our structs are 1-byte boundary aligned. (No padding)
#pragma pack(push, 1)

struct AxisData {
    uint8_t motor;
    bool flipped;
    uint16_t length;
};

struct CalibrationData {
    AxisData x_axis;
    AxisData y_axis;
};

struct ProcessingOptionsData {
    int16_t horizontal_offset;
    int16_t vertical_offset;
    int16_t print_overlap;
};

struct RollerOptionsData {
    uint8_t retracted_pos;
    uint8_t deployed_pos;
};

struct PrinterSettings {
    CalibrationData calibration;
    ProcessingOptionsData processingOptions;
    char printerNumber[20];
    RollerOptionsData rollerOptions;
    uint8_t crc;
};

#pragma pack(pop)

extern PrinterSettings default_settings;
extern PrinterSettings global_settings;

bool settings_initialise();
void settings_restore_defaults(void);

void settings_print_settings(PrinterSettings *settings);
void settings_print_calibration(CalibrationData *calibration);
void settings_print_axis_data(AxisData *settings);
void settings_print_axis_data_minimal(AxisData *axis);
void settings_print_processing_options(ProcessingOptionsData *processingOptions);
void settings_print_printer_number(char *printerNumber);
void settings_print_roller_options(RollerOptionsData *rollerOptions);

uint8_t settings_calculate_crc(PrinterSettings *settings);
bool settings_integrity_check(PrinterSettings *settings);

void settings_read_settings(PrinterSettings *settings);
void settings_write_settings(PrinterSettings *settings);

void settings_update_settings(PrinterSettings *settings);
void settings_update_calibration(CalibrationData *calibration);
void settings_update_x_data(AxisData *axis_data);
void settings_update_y_data(AxisData *axis_data);
void settings_update_crc(void);

uint8_t read_byte(uint16_t address);
void write_byte(const uint16_t address, const uint8_t value, bool reduce_wear);

void read_block(uint16_t address, void *buffer, uint16_t length);
void write_block(uint16_t address, void *buffer, uint16_t length);
void replace_block(const uint16_t address, void *buffer, void *existing, const uint16_t length);

#endif
