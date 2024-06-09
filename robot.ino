#include "ObstacleAvoider.h"
#include "EdgeAvoider.h"

int output1 = 8;
int output2 = 9;
int output3 = 10;
int output4 = 11;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int leftsensor = 5;
int rightsensor = 6;
int midsensor = 7;
int rightsensorval = 0;
int leftsensorval = 0;
int midsensorval = 0;


ObstacleAvoider obstacle_avoider;
EdgeAvoider edge_avoider;

void setup() {

  pinMode(output1, HIGH);
  pinMode(output2, LOW);
  pinMode(output3, HIGH);
  pinMode(output4, LOW);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(leftsensor, INPUT);
  pinMode(rightsensor, INPUT);
  pinMode(midsensor, INPUT);
  Serial.begin(9600);
}

void loop() {
    obstacle_avoider.run();
    //edge_avoider.run();
}



void DriveControls(){
  /*Not very suitable if we need to add multiple IR sensors. 
  For n = number of IR sensors, i = specific sensor and sensor[i].possible_states = 2, I can't keep writing 2^n many if else statements.
  or in other words i can't write times = power(sensor[i].possible, 2); times many statments as there's my energy_loss = t^2 where = time in     seconds therefore 
  
  my_energy = my_energy - my_energy_loss
  
  
  my_energy_loss(n) = sum(t^2).range(1, n)
  
  my_total_energy(t) = my_init_energy*t - my_energy_loss(t)
  
  since 1 ir sensor state == 1 unit of my_energy
  and i ir state = 5 sec
  
  for eg:  7 ir sensors = 2 ^ 7 = 128 state
  
  total_energy_cost = 128*5 = 640 energy units
  
  my_moody_time = 200 sec
  my_final_energy = my_total_energy(200)
  
  i had init energy of 500units
  
  then my_total_energy(200)
  = 500*200 - sum(t^2).range(1, 200).for(t)
  
  = 100000 - 40000
  = - 30000
  
  this means i would pass out writing all of this at 1/4 of 200 seconds. 1/4 * 200 = 50 
  at t = 50s i would be dead. 
  
  
  recovering rate of my energy is defined by (t^2)/2 half of my energy loss rate at time t. 
  at t = 50 it is 2500/2 = 1250. my recovery rate would 1250 at t = 50. 
  
  */
  Serial.print("leftsensorval = ");
  Serial.println(leftsensorval);
  Serial.print("rightsensorval = ");
  Serial.println(rightsensorval);

  leftsensorval = digitalRead(leftsensor);
  rightsensorval = digitalRead(rightsensor);

  if ((leftsensorval == HIGH) && (rightsensorval == LOW)) {
        //Avoid by turning right if there's an obstacle infront of left sensor
        DriveLeftMotor();
         delay(440);
  }

 else if ((leftsensorval == LOW) && (rightsensorval == HIGH)) {
    //Avoid by turning left if there's an obstacle infront of right sensor
       DriveRightMotor();
        delay(440);

    }

 else if ((leftsensorval == HIGH) && (rightsensorval == HIGH)) {
    //Avoid by obstacle by first turning left then turning right if there's an obstacle infront of left and right sensor
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    DriveRightMotor();
    delay(800);
    DriveLeftMotor();
    delay(600);
 }

 else if ((leftsensorval == LOW) && (rightsensorval == LOW)) {
    //Keep moving if both sensor values are low.
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    DriveForward();
 }
}
void DriveLeftMotor(){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(output1, HIGH);
    digitalWrite(output2, LOW);
    digitalWrite(output3, LOW);
    digitalWrite(output4, HIGH);
    delay(440);
}

void DriveRightMotor(){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(output1, LOW);
    digitalWrite(output2, HIGH);
    digitalWrite(output3, HIGH);
    digitalWrite(output4, LOW);
}


void StopRightMotor(){
    digitalWrite(output1, LOW);
    digitalWrite(output2, LOW);
}

void StopLeftMotor(){
    digitalWrite(output3, LOW);
    digitalWrite(output4, LOW);
}

void DriveForward(){
    digitalWrite(output1, HIGH);
    digitalWrite(output2, LOW);
    digitalWrite(output3, HIGH);
    digitalWrite(output4, LOW);
}

void DriveBackward(){
    digitalWrite(output1, HIGH);
    digitalWrite(output2, LOW);
    digitalWrite(output3, HIGH);
    digitalWrite(output4, LOW);
}

void DriveLeft(){
    DriveRightMotor();
}

void DriveRight(){
    DriveLeftMotor();   
}
