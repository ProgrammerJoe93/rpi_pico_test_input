// Copyright (c) 2022 Joseph Russell (https://github.com/ProgrammerJoe93).
// Licensed as BSD-3-Clause, see LICENSE for details.

#include "internal_temp.h"
#include <hardware/adc.h>

const int TEMP_ADC_PIN = 4;
const double VREF = 3.3;
const double POTENTIAL_ADJUSTMENT = VREF / 4095;

Internal_temp::Internal_temp() noexcept {
    adc_init();
    adc_set_temp_sensor_enabled(true);
}

double Internal_temp::get_temp() {
    adc_select_input(TEMP_ADC_PIN);
    double adjusted_potential = adc_read() * POTENTIAL_ADJUSTMENT;
    return potential_to_temp(adjusted_potential);
}

inline double Internal_temp::potential_to_temp(double potential) {
    return 27.0 - (potential - 0.706) / 0.001721;
}
