#ifndef SAM_SAM_H
#define SAM_SAM_H

#include "types.h"

#include <Cosa/AnalogPin.hh>
#include <Cosa/OutputPin.hh>
#include <Cosa/PWMPin.hh>

#include <wlib/stl/Tuple.h>

class Sam {
public:
    Sam();

    bool execute_move(const wlp::Tuple<vector2i, uint8_t> &move);

    bool execute_move(const vector2i &vec, uint8_t time);

    uint16_t current_x() const;

    uint16_t current_y() const;

    void begin();

    void sleep();

private:
    // Analog position pins
    AnalogPin m_position_x;
    AnalogPin m_position_y;

    // Control digital pins
    OutputPin m_control_x;
    OutputPin m_control_y;

    // Brake digital pins
    OutputPin m_brake_x;
    OutputPin m_brake_y;

    // Solenoid PWM pins
    PWMPin m_solenoid_x;
    PWMPin m_solenoid_y;

    // (x, y) position of SAM
    uint16_t m_current_x;
    uint16_t m_current_y;
};

#endif //SAM_SAM_H
