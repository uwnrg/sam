#include <Cosa/RTT.hh>
#include <Cosa/OutputPin.hh>
#include <Cosa/PWMPin.hh>
#include <Cosa/Trace.hh>
#include <Cosa/UART.hh>

#include "types.h"
#include "utility.h"

// Solenoid control and brake pins
OutputPin control_x(Board::D12);
OutputPin control_y(Board::D13);

OutputPin brake_x(Board::D9);
OutputPin brake_y(Board::D8);

PWMPin solenoid_x(Board::PWM0);
PWMPin solenoid_y(Board::PWM5);

// Move vector and time in milliseconds received
vector2i move_vector;
uint8_t time_ms;


void setup() {
    uart.begin(9600);
    trace.begin(&uart);

    RTT::begin();
    trace << "----------------------" << endl;
    trace << "----------SAM---------" << endl;
    trace << "----------------------" << endl;

    trace << endl;
    trace << "Connection Established" << endl;

    brake_x.high();
    brake_y.high();

    control_x.high();
    control_y.high();

    solenoid_x.write(0);
    solenoid_y.write(0);

    trace << "SAM is ready" << endl;
}

/**
 * Voltage:      3.21 V
 * Pulse Length: 30 ms
 * Delay Time:   10 ms
 *
 * Set strength of solenoid using PWM [0-255].
 * @code solenoid_x.write(0)   @endcode
 * @code solenoid_y.write(255) @endcode
 */
void loop() {
    byte_array bytes = read_available(uart);
    if (!bytes.empty()) {
        trace << to_string(bytes);
    }
}
