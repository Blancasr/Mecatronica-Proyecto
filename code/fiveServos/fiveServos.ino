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

bool wait1;
bool wait2;
bool wait3;
bool wait4;
bool wait5;

int min_ang = 0;
int max_ang = 100;
int retardo = 15;

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
  
  val1 = 0;
  val2 = 0;
  val3 = 0;
  val4 = 0;
  val5 = 0;
  
  wait1 = false;
  wait2 = true;
  wait3 = true;
  wait4 = true;
  wait5 = true;

  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5);
  
  delay(1000);
  
}

void loop() {

  // change value of sevos' angles if needed
  if (! wait1) {
    val1 = val1 + 1;
  }
  if (! wait2) {
    val2 = val2 + 1;
  }
  if (! wait3) {
    val3 = val3 + 1;
  }
  if (! wait4) {
    val4 = val4 + 1;
  }
  if (! wait5) {
    val5 = val5 + 1;
  }


  if (val1 > max_ang-retardo) {
      wait2 = false;
  }
  if (val2 > max_ang-retardo) {
      wait3 = false;
  }
  if (val3 > max_ang-retardo) {
      wait4 = false;
  }
  if (val4 > max_ang-retardo) {
      wait5 = false;
  }
  /*if (val5 > max_ang-retardo) {
      wait1 = false;
  }*/



  if (val1 > max_ang) {
      val1 = 0;
      wait1 = true;
  }
  if (val2 > max_ang) {
      val2 = 0;
      wait2 = true;
  }
  if (val3 > max_ang) {
      val3 = 0;
      wait3 = true;
  }
  if (val4 > max_ang) {
      val4 = 0;
      wait4 = true;
  }
  if (val5 > max_ang) {
      val5 = 0;
      wait5 = true;
      wait1 = false;
  }

    // move servos
  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5);
  
  delay(15);

}
