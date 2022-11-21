#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
//Servo servo_mov; // servo que se mueve en el momento

int val1;
int val2;
//int num_servo;
bool wait4next1;
bool wait4next2;
int val;
char serial_val; 

int min_ang = 0;
int max_ang = 100;
int retardo = 15;

void setup() {
  Serial.begin(9600);
  servo1.attach(10);  // attaches the servo on pin 9 to the servo object
  servo2.attach(9);
  
  //servo_mov = servo1;
  //num_servo = 1;

  val1 = 0;
  val2 = 0; // retardo
  wait4next1 = false;
  wait4next2 = true;

  servo1.write(0);
  servo2.write(0);
  delay(1000);
  
}

void loop() {

   /* movimiento secuencial , primero 1 luego el otro:
  servo_mov.write(val);
  val = val + 1;
 
  if (val > 180) {
    val = 0;
    if ( num_servo == 1) {
      servo_mov = servo2;
      num_servo = 2;
    } else {
      servo_mov = servo1;
      num_servo = 1;
    }
  }
  */

  
  servo1.write(val1);
  servo2.write(val2);

  if (! wait4next1) {
    val1 = val1 + 1;
  }
  if (! wait4next2) {
    val2 = val2 + 1;
  }

  if (val1 > max_ang-retardo) {
      wait4next2 = false; 
  }
  if (val1 > max_ang) {
      val1 = 0;
      wait4next1 = true;
  }
  if (val2 > max_ang) {
      val2 = 0;
      wait4next2 = true;
      wait4next1 = false;
  }

 

  
  servo1.write(val1);
  //delay(1000);
  servo2.write(val2);
   delay(15);
}
