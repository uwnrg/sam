#include <Arduino.h>

#define LEFT  97
#define RIGHT 100
#define DOWN  115
#define UP    119
#define POWER 112

#define sol_a 3
#define sol_b 6
#define sol_c 9
#define sol_d 11

#define sol_left  sol_c
#define sol_right sol_d
#define sol_down  sol_b
#define sol_up    sol_a

int power[4] = {255, 255, 255, 255}; //UP DOWN LEFT RIGHT
int solenoids[4] = {sol_up, sol_down, sol_left, sol_right};
int state = 0; //0 is default, 1 means getting solenoid, 2 means getting power level
int solenoid = 0;

void setup() {
  pinMode(sol_a, OUTPUT);
  pinMode(sol_b, OUTPUT);
  pinMode(sol_c, OUTPUT);
  pinMode(sol_d, OUTPUT);
  
  analogWrite(sol_a, 0);
  analogWrite(sol_b, 0);
  analogWrite(sol_c, 0);
  analogWrite(sol_d, 0);
  
  Serial.begin(9600);
  while (!Serial) {}
  Serial.println("SAM Begin");
}

void pulse_sol(int sol_pin, int power = 255) {
  Serial.print("Pulsing with power:");
  Serial.print(power);
  Serial.print('\n');
  analogWrite(sol_pin, power);
  delay(50);//was 10
  analogWrite(sol_pin, 0);
}

int read_msg(byte msg) {
  switch (msg) {
    case UP:
      Serial.println("UP");
      return 0;
    case DOWN:
      Serial.println("DOWN");
      return 1;
    case LEFT:
      Serial.println("LEFT");
      return 2;
    case RIGHT:
      Serial.println("RIGHT");
      return 3;
    case POWER:
      Serial.println("CHANGE POWER LEVEL");
      return 4;
    default:
      Serial.println("Unknown message");
      return -1;
  }
}

int handle_msg(byte msg, int power[4], int solenoids[4]) {
  int id = read_msg(msg);
  if (id >= 0 && id < 4) { 
    pulse_sol(solenoids[id], power[id]);
  }
  return id;
}

void loop() {
  if (Serial.available()) {
    Serial.println("----");
    if (state == 0) {
      byte msg = Serial.read();
      Serial.println(msg, BIN);
      if (handle_msg(msg, power, solenoids) == 4) {
        state = 1;
      }
    } else if (state == 1) {
      byte msg = Serial.read();
      solenoid = read_msg(msg);
      if (solenoid >= 0 && solenoid < 4) {
        state = 2;
        Serial.println("Changing solenoid power");
      } else {
        solenoid = 0;
        state = 0;
        Serial.println("Invalid solenoid");
      }
    } else if (state == 2) {
      byte msg = Serial.read();
      int value = msg;
      Serial.print("New solenoid power: ");
      Serial.print(value);
      Serial.print('\n');
      power[solenoid] = value;
      state = 0;
    }
  }
}

