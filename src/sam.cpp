#include "sam.h"

Sam::Sam() :
    m_position_x(Board::A0),
    m_position_y(Board::A1),
    m_control_x(Board::D12),
    m_control_y(Board::D13),
    m_brake_x(Board::D9),
    m_brake_y(Board::D8),
    m_solenoid_x(Board::PWM0),
    m_solenoid_y(Board::PWM5),
    m_current_x(0),
    m_current_y(0) {}

void Sam::begin() {
    // Power-up all pins
    m_position_x.powerup();
    m_position_y.powerup();

    // Initial state
    m_brake_x.high();
    m_brake_y.high();
    m_control_x.high();
    m_control_y.high();
    m_solenoid_x.write(0);
    m_solenoid_y.write(0);
}

void Sam::sleep() {
    m_position_x.powerdown();
    m_position_y.powerdown();
}

bool Sam::execute_move(const wlp::Tuple<vector2i, uint8_t> &move) {
    return execute_move(wlp::get<0>(move), wlp::get<1>(move));
}

bool Sam::execute_move(const vector2i &vec, uint8_t time) {
    // Set solenoids to strength
    if (vec.x() > 0) { m_control_x.high(); }
    else { m_control_x.low(); }
    if (vec.y() > 0) { m_control_y.high(); }
    else { m_control_y.low(); }
    m_solenoid_x.write(static_cast<uint8_t>(abs(vec.x())));
    m_solenoid_y.write(static_cast<uint8_t>(abs(vec.y())));

    // Disengage brakes
    m_brake_x.low();
    m_brake_y.low();

    // Read in current position
    m_current_x = m_position_x.sample();
    m_current_y = m_position_y.sample();

    // Movement time
    delay(time);

    // Shut off solenoids and engage brakes
    m_solenoid_x.write(0);
    m_solenoid_y.write(0);
    m_brake_x.high();
    m_brake_y.high();
}

uint16_t Sam::current_x() const {
    return m_current_x;
}

uint16_t Sam::current_y() const {
    return m_current_y;
}
