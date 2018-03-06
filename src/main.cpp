#include <Cosa/RTT.hh>
#include <Cosa/OutputPin.hh>
#include <Cosa/PWMPin.hh>
#include <Cosa/Trace.hh>
#include <Cosa/UART.hh>

OutputPin ledPin(Board::LED);

OutputPin control_x(Board::D12);
OutputPin control_y(Board::D13);

OutputPin brake_x(Board::D9);
OutputPin brake_y(Board::D8);

PWMPin solenoid_x(Board::PWM0);
PWMPin solenoid_y(Board::PWM5);



void setup() {
    uart.begin(9600);
    trace.begin(&uart);

    RTT::begin();
    trace << "----------------------";
    trace << "----------SAM---------";
    trace << "----------------------";

    trace << endl;
    trace << "I'm Active";

}

void loop() {
    ledPin.on();
    delay(50);
    ledPin.off();
    delay(500);
}
