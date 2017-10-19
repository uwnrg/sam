const int SOL_EAST_PIN = 7;
const int SOL_SOUTH_PIN = 8;
const int SOL_BRAKE_PIN = 9;
const int SOL_WEST_PIN = 10;
const int SOL_NORTH_PIN = 11;

#define BAUD_RATE 9600

void setup () {
  // setup the serial port
  Serial.begin(BAUD_RATE);

  // Wait until serial port opens
  while (!Serial) {
  }
  pinMode(SOL_EAST_PIN, OUTPUT);
  pinMode(SOL_SOUTH_PIN, OUTPUT);
  pinMode(SOL_BRAKE_PIN, OUTPUT);
  pinMode(SOL_WEST_PIN, OUTPUT);
  pinMode(SOL_NORTH_PIN, OUTPUT);
}

void loop () {
  //Voltage: 3.21 V
  //Pulse Length: 30 ms
  //Delay Time: 10 ms
  digitalWrite(SOL_NORTH_PIN, HIGH);
  delay(30);
  digitalWrite(SOL_NORTH_PIN, LOW);
  delay(10);
  digitalWrite(SOL_WEST_PIN, HIGH);
  delay(30);
  digitalWrite(SOL_WEST_PIN, LOW);
  delay(10);
  digitalWrite(SOL_SOUTH_PIN, HIGH);
  delay(30);
  digitalWrite(SOL_SOUTH_PIN, LOW);
  delay(10);
  digitalWrite(SOL_EAST_PIN, HIGH);
  delay(30);
  digitalWrite(SOL_EAST_PIN, LOW);
  delay(10);
}
