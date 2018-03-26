// Basic Code for MOSFET Example
// Written by: Kash Pirani
// Alternates activating solenoids in X and Y axis to display capabilities of motor shield

// control digital pins controls direction
// sol analogwrite controls strength of the solenoid
// brake digital pins control auto shut off

#define BAUD_RATE 9600
// PINS REVERSED
//X-axis corresponds to pin A
const int LEDTest = 1;
const int UpPin = 11;
const int DownPin = 3;
//Y-axis corresponds to pin
const int LeftPin = 9;
const int RightPin = 6;
// were all 220 before
const int dPower = 255; //down solenoid power
const int rPower = 250; //right solenoid power
const int lPower = 250; //left solenoid power
const int uPower = 255; //up solenoid power 
const int movementTime = 2000; 
const int Brake = 4;

// TODO: make this an enum
const short UP    = 0b110100;
const short RIGHT = 0b111000;
const short LEFT  = 0b110010;
const short DOWN  = 0b110001;

// Input bytes from Controls
int incomingByte;


void setup () {
  // Initialize serial
  Serial.begin(BAUD_RATE);
  Serial.println("---------------------");
  Serial.println("-------- SAM --------");
  Serial.println("---------------------");
  Serial.println("I'm Alive!");
  while(!Serial) {}
  Serial.println("Connection Established!");
  
  //Initialization of all digital and analog pinouts to control motor shield
  pinMode(LEDTest, OUTPUT);
  pinMode(UpPin, OUTPUT);
  pinMode(DownPin, OUTPUT);
  pinMode(LeftPin, OUTPUT);
  pinMode(RightPin, OUTPUT);
  pinMode(Brake, OUTPUT);
 
  digitalWrite(LEDTest, LOW);
  digitalWrite(DownPin, LOW);
  digitalWrite(UpPin, LOW);
  digitalWrite(LeftPin, LOW);
  digitalWrite(RightPin, LOW);
  digitalWrite(Brake, LOW);
  
  Serial.print("SAM is ready");
}


void moveX(short dir) {
  Serial.print("Moving ");
  Serial.print(" -- ");
  
  delay(5);
  
  // Set strength of solenoid using PWM, can be any value [0, 255]
  
  if (dir == RIGHT) {
    analogWrite(RightPin, rPower);
    analogWrite(LeftPin, 0);
    Serial.print("RIGHT");
  } else if (dir == LEFT) {
    analogWrite(RightPin, 0);
    analogWrite(LeftPin, lPower);
    //digitalWrite(LeftPin, HIGH);
    Serial.print("LEFT");
  }
  

  // Movement time
  delay(movementTime);
  
  // Stop solenoids
 if (dir == RIGHT) {
    digitalWrite(RightPin, LOW);
    Serial.print(" RIGHT ");
  } else if (dir == LEFT) {
    digitalWrite(LeftPin, LOW);
    Serial.print(" LEFT ");
  }
  
  
  Serial.println("done");
}

void moveY(short dir) {
  Serial.print("Moving ");
  Serial.print(" -- ");
  
  delay(5);
  if (dir == UP) {
    Serial.print("UP");
    analogWrite(UpPin, uPower);
    analogWrite(DownPin, 0);
  } else if (dir == DOWN) {
    Serial.print("DOWN");
    analogWrite(UpPin, 0);
    analogWrite(DownPin, dPower);
  } 
  
  
  
  // Movement time
  delay(movementTime);
  
 // Stop solenoids
 if (dir == UP) {
    digitalWrite(UpPin, LOW);
    Serial.print("UP");
  } else if (dir == DOWN) {
    digitalWrite(DownPin, LOW);
    Serial.print("DOWN");
  }
  
  
  Serial.println("done");
}


void loop () {
  // Voltage: 3.21 V
  // Pulse Length: 30 ms
  // Delay Time: 10 ms
  
  // Set strength of the solenoid using PWM, can be any value [0,255]
  //analogWrite(solX, 255);
  //analogWrite(solY, 0);
   
  if( Serial.available() ) {
    incomingByte = Serial.read();
  
    Serial.println(incomingByte, BIN);
    // TODO: take one byte and separate it properly to X and Y directions
    if (incomingByte == UP || incomingByte == DOWN) {
      moveY(incomingByte);
    } else if (incomingByte == LEFT || incomingByte == RIGHT) {
      moveX(incomingByte);
    }
  }

 }
