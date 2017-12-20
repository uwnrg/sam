// Basic Code for Motor Shield
// Written by: Alex Simmons
// Alternates activating solenoids in X and Y axis to display capabilities of motor shield

// control digital pins controls direction
// sol analogwrite controls strength of the solenoid
// brake digital pins control auto shut off

#define BAUD_RATE 9600


//X-axis corresponds to pin A
const int controlX = 12;
const int solX = 3;
const int brakeX = 9;

//Y-axis corresponds to pin B
const int controlY = 11; 
const int solY = 13;
const int brakeY = 8;

// TODO: make this an enum
const short UP = 0b110001;
const short RIGHT = 0b110010;

// Input bytes from Controls
int incomingByte;

void setup () {
  // Initialize serial
  Serial.begin(BAUD_RATE);
  while(!Serial) {}
  
  //Initialization of all digital and analog pinouts to control motor shield
  pinMode(controlX, OUTPUT);
  pinMode(solX, OUTPUT);
  pinMode(brakeX, OUTPUT);
  pinMode(controlY, OUTPUT);
  pinMode(solY, OUTPUT);
  pinMode(brakeY, OUTPUT);
  
  // Sets direction of pull for pairs of solenoids, initialized in setup as not changed in loop
  // In future, will be used to change direction of actuation
  digitalWrite(controlX, HIGH);
  digitalWrite(controlY, HIGH);
}

void moveX(short dir) {
  if (dir != RIGHT) return;   // TODO: make left direction work
  
  Serial.println("Moving RIGHT");
  
  // Set strength of solenoid using PWM, can be any value [0, 255]
  analogWrite(solX, 255);
  analogWrite(solY, 0);

  // Turn brake on or off to allow current to flow through pins
  digitalWrite(brakeX, LOW);
  digitalWrite(brakeY, HIGH);
  
  // Movement time
  delay(3000); 
}

void moveY(short dir) {
  if (dir != UP) return;   // TODO: make down direction work
  
  Serial.println("Moving UP");
  
  analogWrite(solX, 0);
  analogWrite(solY, 255);
  
  digitalWrite(brakeX, HIGH);
  digitalWrite(brakeY, LOW);
  
  delay(3000);
}

void loop () {
  // Voltage: 3.21 V
  // Pulse Length: 30 ms
  // Delay Time: 10 ms
  
  // Set strength of the solenoid using PWM, can be any value [0,255]
  analogWrite(solX, 255);
  analogWrite(solY, 0);
  
  if( Serial.available() ) {
    incomingByte = Serial.read();
    
    Serial.println(incomingByte, BIN);
    // TODO: take one byte and separate it properly to X and Y directions
    moveX(incomingByte);
    moveY(incomingByte);
  }
}
