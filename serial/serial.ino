const int SOL_EAST_PIN = 7;
const int SOL_SOUTH_PIN = 8;
const int SOL_BRAKE_PIN = 9;
const int SOL_WEST_PIN = 10;
const int SOL_NORTH_PIN = 11;

int incomingByte;

#define BAUD_RATE 9600

void setup () {
  // setup the serial port
  Serial.begin(BAUD_RATE);
  Serial.write("I'm Alive!!\n");
  // Wait until serial port opens
  while (!Serial) {
  }
  Serial.write("Connection established\n");
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
  if(Serial.available()) {
    incomingByte = Serial.read();
    Serial.println(incomingByte);
  }
  digitalWrite(SOL_SOUTH_PIN, HIGH);
  delay(3000);
  digitalWrite(SOL_SOUTH_PIN, LOW);
  delay(10);
  //digitalWrite(SOL_WEST_PIN, HIGH);
  //delay(30);
  //digitalWrite(SOL_WEST_PIN, LOW);
  //delay(10);
  //digitalWrite(SOL_SOUTH_PIN, HIGH);
  //delay(30 
  //digitalWrite(SOL_SOUTH_PIN, LOW);8uu8iki,,km,k,m,
  //delay(10);
  //digitalWrite(SOL_EAST_PIN, HIGH);
  //delay(30);
  //digitalWrite(SOL_EAST_PIN, LOW);
  //delay(10);
}
