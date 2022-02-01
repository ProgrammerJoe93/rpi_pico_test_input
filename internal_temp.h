// Copyright (c) 2022 Joseph Russell (https://github.com/ProgrammerJoe93).
// Licensed as BSD-3-Clause, see LICENSE for details.

#ifndef INTERNAL_TEMP_H
#define INTERNAL_TEMP_H

// Retrieves the ADC reading for the internal temerature sensor and converts the reading to a usable temperature value
class Internal_temp {
public:
    explicit Internal_temp() noexcept;

    // Returns temperature in celsius
    double get_temp();

private:
    // Converts between mV and degC
    inline double potential_to_temp(double potential);
};

#endif // INTERNAL_TEMP_H
