#include <Arduino.h>

#define LEFT  97
#define RIGHT 100
#define DOWN  115
#define UP    119

#define sol_a 3
#define sol_b 6
#define sol_c 9
#define sol_d 11

#define sol_left  sol_c
#define sol_right sol_d
#define sol_down  sol_b
#define sol_up    sol_a

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
  analogWrite(sol_pin, power);
  delay(50);//was 10
  analogWrite(sol_pin, 0);
}

void handle_msg(byte msg) {
  switch (msg) {
    case UP:
      Serial.println("UP");
      pulse_sol(sol_up);
      break;
    case DOWN:
      Serial.println("DOWM");
      pulse_sol(sol_down);
      break;
    case LEFT:
      Serial.println("LEFT");
      pulse_sol(sol_left);
      break;
    case RIGHT:
      Serial.println("RIGHT");
      pulse_sol(sol_right);
      break;
    default:
      Serial.println("Unknown message");
      break;
  }
}

void loop() {
  if (Serial.available()) {
    byte msg = Serial.read();
    Serial.println(msg, BIN);
    handle_msg(msg);
  }
}

