#include <Servo.h>

const int num_servos = 4;
int pins[] = {11, 10, 9, 5, 3};

Servo servos[num_servos];
int states[num_servos];
int val[num_servos];

int min_ang = 45; //  90 - 45
int init_ang = 90;
int max_ang = 112; // 90 + 45//2

void setup() {
  
  Serial.begin(9600);

  for (int i = 0; i < num_servos; i++){
    servos[i].attach(pins[i]);
    val[i] = init_ang;
    servos[i].write(init_ang);
    states[i] = 0;
  }
  states[0] = 1;
  
  delay(1000);
}

void loop() {

  
  // STATES and VALUES
  for (int i = 0; i < num_servos; i++){

    // CHANGE of state
    if (states[i] == 1 && val[i] >= max_ang ) {
      states[i] = 2;
    }
    else if (states[i] == 2 && val[i] <= min_ang ){
      states[i] = 3;
    }
    else if (states[i] == 3 && val[i] >= init_ang ){
      states[i] = 0;
    }
    else if (states[i] == 0){
      
      int prev = i-1;
      if (i == 0) {
        prev = num_servos-1;
      }
        
      if (states[prev] == 2 && val[prev] <= init_ang){
          states[i] = 1;
      }
    }

    // NEW value/angle of servos depending on state
    if (states[i] == 0) {
      val[i] = init_ang;
    }
    else if (states[i] == 1) {
      val[i] = val[i] + 2;
    }
    else if (states[i] == 2) {
      val[i] = val[i] - 4;
    }
    else if (states[i] == 3){
      val[i] = val[i] + 2;
    }
  }

  // MOVE servos
  for (int i = 0; i < num_servos; i++){
    servos[i].write(val[i]);
    
    Serial.print("Servo: ");
    Serial.print(i);
    Serial.print(" val: ");
    Serial.println(servos[i].read());
  }

  delay(10);

}
