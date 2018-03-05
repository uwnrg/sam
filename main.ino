// control digital pins controls direction
// sol analogwrite controls strength of the solenoid
// brake digital pins control auto shut off

#define BAUD_RATE 9600


//X-axis corresponds to pin A
const int controlX = 12;
const int solX = 3;
const int brakeX = 9;    

//Y-axis corresponds to pin B
const int controlY = 13; 
const int solY = 11;
const int brakeY = 8;

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
  pinMode(controlX, OUTPUT);
  pinMode(solX, OUTPUT);
  pinMode(brakeX, OUTPUT);
  pinMode(controlY, OUTPUT);
  pinMode(solY, OUTPUT);
  pinMode(brakeY, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);

  
  digitalWrite(brakeX, HIGH);
  digitalWrite(brakeY, HIGH);
  analogWrite(solX, 0);
  analogWrite(solY, 0);
  
  digitalWrite(controlX, HIGH);
  digitalWrite(controlY, HIGH);
   
  Serial.print("SAM is ready");
}


void moveX(short dir) {
  Serial.print("Moving ");
  if (dir == RIGHT) {
    digitalWrite(controlX, HIGH);
    Serial.print("RIGHT");
  } else if (dir == LEFT) {
    digitalWrite(controlX, LOW);
    Serial.print("LEFT");
  } else {
    return;
  }
  Serial.print(" -- ");
  
  delay(5);
  
  // Set strength of solenoid using PWM, can be any value [0, 255]
  analogWrite(solX, 200);
  analogWrite(solY, 0);

  // Turn brake on or off to allow current to flow through pins
  digitalWrite(brakeX, LOW);
  digitalWrite(brakeY, HIGH);
  int currentX = analogRead(A0);
  Serial.println("currentX is:");
  Serial.println(currentX);
  // Movement time
  delay(50);
  
//  // Stop solenoids
//  analogWrite(solX, 0);
//  analogWrite(solY, 0);
//  
//  // Brake
//  digitalWrite(brakeX, HIGH);
//  digitalWrite(brakeY, HIGH);
    
  Serial.println("done");
}

void moveY(short dir) {
  Serial.print("Moving ");
  if (dir == UP) {
    digitalWrite(controlY, HIGH);
    Serial.print("UP");
  } else if (dir == DOWN) {
    digitalWrite(controlY, LOW);
    Serial.print("DOWN");
  } else {
    return;
  }
  Serial.print(" -- ");
  
  delay(10);
  
  analogWrite(solX, 0);
  analogWrite(solY, 200);
  
  digitalWrite(brakeX, HIGH);
  digitalWrite(brakeY, LOW);
  
  int currentY = analogRead(A1);
  Serial.println("currentY is:"); 
  Serial.println(currentY);
  
  // Movement time
  delay(50);
  
  analogWrite(solX, 0);
  analogWrite(solY, 0);
  
  digitalWrite(brakeX, HIGH);
  digitalWrite(brakeY, HIGH);
  
  
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
