#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

int val1;
int val2;
int val3;
int val4;
int val5;

int state_1 = 0;
int state_2 = 0;
int state_3 = 0;
int state_4 = 0;
int state_5 = 0;

int min_ang = 0;
int init_ang = 90;
int max_ang = 135;
int retardo = 15;

int increment_1 = 0;
int increment_2 = 0;
int increment_3 = 0;
int increment_4 = 0;
int increment_5 = 0;

int pin1 = 11;
int pin2 = 10;
int pin3 = 9;
int pin4 = 5;
int pin5 = 3;


void setup() {
  
  Serial.begin(9600);
  
  servo1.attach(pin1);
  servo2.attach(pin2);
  servo3.attach(pin3);
  servo4.attach(pin4);
  servo5.attach(pin5);
  
  val1 = init_ang;
  val2 = init_ang;
  val3 = init_ang;
  val4 = init_ang;
  val5 = init_ang;

  state_1 = 1;
  
  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5);
  
  delay(1000);
  
}

void loop() {

  // Change value of sevos' angles if needed
  // Servo 1  
  if (state_1 == 1) {
    val1 = val1 + 1;
  }
  else if (state_1 == 2) {
    val1 = val1 - 3;
  }
  else if (state_1 == 3) {
    val1 = val1 + 1;
  }
  else {
    val1 = init_ang;
  }
  // Servo 2
  if (state_2 == 1) {
    val2 = val2 + 1;
  }
  else if (state_2 == 2) {
    val2 = val2 - 3;
  }
  else if (state_2 == 3) {
    val2 = val2 + 1;
  }
  else {
    val2 = init_ang;
  }
  // Servo 3
  if (state_3 == 1) {
    val3 = val3 + 1;
  }
  else if (state_3 == 2) {
    val3 = val3 - 3;
  }
  else if (state_3 == 3) {
    val3 = val3 + 1;
  }
  else {
    val3 = init_ang;
  }
  // Servo 4
  if (state_4 == 1) {
    val4 = val4 + 1;
  }
  else if (state_4 == 2) {
    val4 = val4 - 3;
  }
  else if (state_4 == 3) {
    val4 = val4 + 1;
  }
  else {
    val4 = init_ang;
  }
  // Servo 5
  if (state_5 == 1) {
    val5 = val5 + 1;
  }
  else if (state_5 == 2) {
    val5 = val5 - 3;
  }
  else if (state_5 == 3) {
    val5 = val5 + 1;
  }
  else {
    val5 = init_ang;
  }

  // Check if arrived to critical point
  if (val1 > max_ang && state_1 == 1) {
    state_1 = 2;
    state_2 = 1;
  }
  if (val2 > max_ang && state_2 == 1) {
    state_2 = 2;
    state_3 = 1;
  }
  if (val3 > max_ang && state_3 == 1) {
    state_3 = 2;
    state_4 = 1;
  }
  if (val4 > max_ang && state_4 == 1) {
    state_4 = 2;
    state_5 = 1;
  }
  if (val5 > max_ang && state_5 == 1) {
    state_5 = 2;
  }

  if (val1 < min_ang && state_1 == 2) {
    state_1 = 3;
    state_2 = 2;
  }
  if (val2 < min_ang && state_2 == 2) {
    state_2 = 3;
    state_3 = 2;
  }
  if (val3 < min_ang && state_3 == 2) {
    state_3 = 3;
    state_4 = 2;
  }
  if (val4 < min_ang && state_4 == 2) {
    state_4 = 3;
    state_5 = 2;
  }
  if (val5 < min_ang && state_5 == 2) {
    state_5 = 3;
  }

  if (val1 > max_ang && state_1 == 3) {
    state_1 = 0;
    state_2 = 3;
  }
  if (val2 > max_ang && state_2 == 3) {
    state_2 = 0;
    state_3 = 3;
  }
  if (val3 > max_ang && state_3 == 3) {
    state_3 = 0;
    state_4 = 3;
  }
  if (val4 > max_ang && state_4 == 3) {
    state_4 = 0;
    state_5 = 3;
  }
  if (val5 > max_ang && state_5 == 3) {
    state_5 = 0;
    state_1 = 1;
  }

  // Move servos to desired position
  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5);
  
  delay(15);

}
