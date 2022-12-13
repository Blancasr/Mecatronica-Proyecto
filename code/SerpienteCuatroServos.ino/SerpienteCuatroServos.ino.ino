#include <Servo.h>

const int num_servos = 4;
int pins[] = {11, 10, 9, 5, 3};

Servo servos[num_servos];
int states[num_servos];
int val[num_servos];

int gap_ang = 45;
int init_ang = 90;
int min_rest = init_ang - gap_ang; 
int max_rest = init_ang + gap_ang/2;
int min_last = min_rest - 20; // el ultimo se gura mas para empujar la estructura
int max_first = max_rest + 20; // el primero haga mas angulo porque pesa mais

int prev;
int max_ang;
int min_ang;


void setup() {
  
  Serial.begin(9600);

  for (int i = 0; i < num_servos; i++){
    servos[i].attach(pins[i]);
    val[i] = init_ang;
    servos[i].write(init_ang);
    states[i] = 0;
  }
  states[0] = 1;
  
  delay(2000);
}

void loop() {

  
  
  // STATES and VALUES
  for (int i = 0; i < num_servos; i++){
    
    // CHANGE of state
    if ( i==0 ){
      max_ang = max_first;
      min_ang = min_rest;
    }else if (i == num_servos-1){
      min_ang = min_last;
      max_ang = max_rest;
    }else{  
      max_ang = max_rest;
      min_ang = min_rest;
    }
    
    if (states[i] == 1 && val[i] >= max_ang ) {
      states[i] = 2;
    }
    else if (states[i] == 2 && val[i] <= min_ang ){
      states[i] = 3;
    }
    else if (states[i] == 3 && val[i] >= init_ang ){
      states[i] = 0;
    }
    else if (states[i] == 0 ){
      prev = i-1;
      
      if (i == 0) {
        prev = num_servos-1;
        if (states[prev] == 3 && val[prev] >= init_ang){
          states[i] = 1;
        }
      }
      else if (states[prev] == 2 && val[prev] <= init_ang){
          states[i] = 1;
      }
    }

    // NEW value/angle of servos depending on state
    if (states[i] == 0) {
      val[i] = init_ang;
    }
    else if (states[i] == 1) {
      val[i] = val[i] + 1;
    }
    else if (states[i] == 2) {
      val[i] = val[i] - 3;
    }
    else if (states[i] == 3){
      val[i] = val[i] + 2;
    }
  }

  // MOVE servos
  for (int i = 0; i < num_servos; i++){
    servos[i].write(val[i]);

    /*
    Serial.print("Servo: ");
    Serial.print(i);
    Serial.print(" val: ");
    Serial.println(servos[i].read());
    */
    
  }
  delay(25);

}
