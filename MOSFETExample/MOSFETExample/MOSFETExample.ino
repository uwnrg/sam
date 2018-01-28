// Basic Code for MSOSFET Example
// Written by: Kash Pirani
// Alternates activating solenoids in X and Y axis to display capabilities of motor shield

// control digital pins controls direction
// sol analogwrite controls strength of the solenoid
// brake digital pins control auto shut off

#define BAUD_RATE 9600


//X-axis corresponds to pin A
const int LEDTest = 5;
const int UpPin = 6;
const int DownPin = 9;    

//Y-axis corresponds to pin B
const int LeftPin = 11; 
const int RightPin = 10;
const int Brake = 3;

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
  
  Serial.print("SAM is ready");
}


void moveX(short dir) {
  Serial.print("Moving ");
  if (dir == RIGHT) {
    digitalWrite(RightPin, HIGH);
    Serial.print("RIGHT");
  } else if (dir == LEFT) {
    digitalWrite(LeftPin, HIGH);
    Serial.print("LEFT");
  } else {
    return;
  }
  Serial.print(" -- ");
  
  delay(5);
  
  // Set strength of solenoid using PWM, can be any value [0, 255]
  if (dir == RIGHT) {
    analogWrite(RightPin, 200);
    analogWrite(LeftPin, 0);
  } else if (dir == LEFT) {
    analogWrite(RightPin, 0);
    analogWrite(LeftPin, 200);
  } 
  

  // Movement time
  delay(50);
  
  // Stop solenoids
 if (dir == RIGHT) {
    digitalWrite(RightPin, LOW);
    Serial.print("RIGHT");
  } else if (dir == LEFT) {
    digitalWrite(LeftPin, LOW);
    Serial.print("LEFT");
  }
  
  
  Serial.println("done");
}

void moveY(short dir) {
  Serial.print("Moving ");
   if (dir == UP) {
    digitalWrite(UpPin, HIGH);
    Serial.print("UP");
  } else if (dir == DOWN) {
    digitalWrite(DownPin, HIGH);
    Serial.print("DOWN");
  } else {
    return;
  }
  Serial.print(" -- ");
  
  delay(5);
  
  if (dir == UP) {
    analogWrite(UpPin, 200);
    analogWrite(DownPin, 0);
  } else if (dir == DOWN) {
    analogWrite(UpPin, 0);
    analogWrite(DownPin, 200);
  } 
  
  
  
  // Movement time
  delay(50);
  
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
