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

int min_ang = 68;
int to_calibrate = 100;
int max_ang = 135;
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
  
  val1 = to_calibrate;
  val2 = to_calibrate;
  val3 = to_calibrate;
  val4 = to_calibrate;
  val5 = to_calibrate;

  servo1.write(val1);
  servo2.write(val2);
  servo3.write(val3);
  servo4.write(val4);
  servo5.write(val5);
  
}
void loop() {
  // put your main code here, to run repeatedly:

 /*
  servo1.write(val1);
  val1 = val1 +1;

  if(val1 > max_ang){
    val1 = to_calibrate;
  }
  delay(15);
  */
  
  Serial.println(servo1.read());
  

}
