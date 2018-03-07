#include <Cosa/RTT.hh>
#include <Cosa/Trace.hh>
#include <Cosa/UART.hh>

#include "types.h"
#include "utility.h"
#include "sam.h"

using wlp::get;

Sam sam;

void setup() {
    uart.begin(9600);
    trace.begin(&uart);

    RTT::begin();
    trace << "----------------------" << endl;
    trace << "----------SAM---------" << endl;
    trace << "----------------------" << endl;

    trace << endl;
    trace << "Connection Established" << endl;

    // Power-up SAM
    sam.begin();

    trace << "SAM is ready" << endl;
}

/**
 * Voltage:      3.21 V
 * Pulse Length: 30 ms
 * Delay Time:   10 ms
 *
 * Set strength of solenoid using PWM [0-255].
 * @code m_solenoid_x.write(0)   @endcode
 * @code m_solenoid_y.write(255) @endcode
 */
void loop() {
    byte_array bytes = read_available(uart);
    if (bytes.size() == 5) {
        auto data = decode_message(bytes);
        trace << get<0>(data) << " : " << get<1>(data) << endl;
        sam.execute_move(data);
    }
}
