const int SOL_1_PIN = 7;
const int SOL_2_PIN = 8;
const int SOL_3_PIN = 9;
const int SOL_4_PIN = 10;

#define BAUD_RATE 9600

void setup () {
    // setup the serial port
    Serial.begin(BAUD_RATE);
    
    // Wait until serial port opens
    while (!Serial) {}

    pinMode(SOL_1_PIN, OUTPUT);
    pinMode(SOL_2_PIN, OUTPUT);
    pinMode(SOL_3_PIN, OUTPUT);
    pinMode(SOL_4_PIN, OUTPUT);
}

void loop () {
    digitalWrite(SOL_1_PIN, HIGH);
    delay(1000);
    digitalWrite(SOL_1_PIN, LOW);
    delay(1000);
}

