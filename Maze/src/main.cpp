#include <Arduino.h>


//motor a

#define m1a 3
#define m1b 2

//motor b

#define m2a 5
#define m2b 4

int topSpeed = 200; //set the top speed for analog motor control (0-255)

//front sensor
int front_trig = 9; 
int front_echo = 10; 

//left sensor
int left_trig = 6;
int left_echo = 7;

//right sensor
int right_trig = 11;
int right_echo = 12;

//initialize all functions
void readRight(), readLeft(), readCenter(), right(), Stop(), forward(), left(), back(), turnAround();

//initialize global variables
long front_time, front_dis, right_time, right_dis, left_time, left_dis;

void setup() {
//declare pins for ultrasonic sensors
  pinMode(front_trig, OUTPUT); 
  pinMode(front_echo, INPUT);

  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);

  pinMode(m1a, OUTPUT);
  pinMode(m1b, OUTPUT);
  pinMode(m2a, OUTPUT);
  pinMode(m2b, OUTPUT);
  
  //start serial monitor
  Serial.begin(9600);
}

void loop() {
  //print all the distances
  Serial.print(right_dis);
  Serial.print(":");
  Serial.print(front_dis);
  Serial.print(":");
  Serial.println(left_dis);  

  if (right_dis <= 6&& left_dis <= 6&& front_dis>5){ //if the left and right are walls, and if the front is open, go forward
    forward(); 
    Serial.println("Going Forward");
  }
  else if(right_dis > 6&&left_dis <= 6&& front_dis<=5){ //if the front and left are blocked, go right
    right();
    Serial.println("Turning Left");
  }
  else if (left_dis >6&&right_dis <= 6&& front_dis<=5){//if the right and front are blocked, turn left
    left();
    Serial.println("Turning Left");
   }
  else if (left_dis <=6&&right_dis <= 6&& front_dis <=6){//if all sides are blocked, turn around
    back();
    turnAround();
    Serial.println("Turning Around");
   }
}


void readRight() { //reads right ultrasonic sensor

  digitalWrite(front_trig, LOW);  
  delayMicroseconds(2);               
  digitalWrite(front_trig, HIGH); 
  delayMicroseconds(5);               
  digitalWrite(front_trig, LOW);  
  front_time = pulseIn(front_echo, HIGH); 
  front_dis = front_time/ 29 / 2;

}

void readLeft() { //reads left ultrasonic sensor


  digitalWrite(left_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(left_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(left_trig, LOW);
  left_time= pulseIn(left_echo, HIGH);
  left_dis= left_time / 29 / 2;

}

void readCenter() { //reads center ultrasonic sensor

  digitalWrite(right_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(right_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(right_trig, LOW);
  right_time = pulseIn(right_echo, HIGH);
  right_dis = right_time / 29 / 2;

}


void right() { //turn right function
  
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  
}
void Stop () { //Stop function
 
  digitalWrite(m1a, LOW);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
  delay(500);
  
}
void left() { //turn left function
  
  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, LOW);
  digitalWrite(m2b, LOW);
 
}
void forward() { //go forward function

  digitalWrite(m1a, HIGH);
  digitalWrite(m1b, LOW);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);

}

void back(){ //backup function

  analogWrite(m1a, 0);
  analogWrite(m1b,topSpeed);
  analogWrite(m2a, 0);
  analogWrite(m2b, topSpeed);
  delay(500);

}

void turnAround(){ //turn around function

  digitalWrite(m1a, LOW);
  digitalWrite(m1b,HIGH);
  digitalWrite(m2a, HIGH);
  digitalWrite(m2b, LOW);
  delay(500);

}
