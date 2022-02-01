// Copyright (c) 2022 Joseph Russell (https://github.com/ProgrammerJoe93).
// Licensed as BSD-3-Clause, see LICENSE for details.

// Digital input: switch
// Analogue input: Internal_temp

#include <cstdio>
#include <string>
#include "pico/stdlib.h"
#include "internal_temp.h"

const int SWITCH_PIN = 15;

int main() {
    stdio_init_all();

    // Initialise button
    gpio_init(SWITCH_PIN);
    gpio_set_dir(SWITCH_PIN, GPIO_IN);
    gpio_pull_up(SWITCH_PIN);

    // Temperature handler object
    Internal_temp temp;

    // Every second print the temperature and button state
    while (true) {
        std::string switch_state{(gpio_get(SWITCH_PIN) ? "open" : "closed")};
        std::printf("Internal temperature: %.1f %cC, Switch is %s\n", temp.get_temp(), 176, switch_state.c_str());
        sleep_ms(1000);
    }

    return 0;
}
