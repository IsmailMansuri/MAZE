#include <Arduino.h>



//motor a

#define in1 3
#define in2 2
//motor b

#define in3 5
#define in4 4

int front_trig = 9; 
int front_echo = 10; 

int left_trig = 6;
int left_echo = 7;

int right_trig = 11;
int right_echo = 12;

void right();
void Stop();
void forward();
void left();
void back();
//distance,time
long front_time, front_dis, right_time, right_dis, left_time, left_dis;

void setup() {
  pinMode(front_trig, OUTPUT); 
  pinMode(front_echo, INPUT);

  pinMode(left_trig, OUTPUT);
  pinMode(left_echo, INPUT);

  pinMode(right_trig, OUTPUT);
  pinMode(right_echo, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  digitalWrite(front_trig, LOW);  
  delayMicroseconds(2);               
  digitalWrite(front_trig, HIGH); 
  delayMicroseconds(5);               
  digitalWrite(front_trig, LOW);  
  front_time = pulseIn(front_echo, HIGH); 
  front_dis = front_time/ 29 / 2;

  digitalWrite(left_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(left_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(left_trig, LOW);
  left_time= pulseIn(left_echo, HIGH);
  left_dis= left_time / 29 / 2;

  digitalWrite(right_trig, LOW);
  delayMicroseconds(2);
  digitalWrite(right_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(right_trig, LOW);
  right_time = pulseIn(right_echo, HIGH);
  right_dis = right_time / 29 / 2;
  Serial.print(right_dis);
  Serial.print(":");
  Serial.print(front_dis);
  Serial.print(":");
  Serial.println(left_dis);
  
  delay(1500);
  
  if (right_dis <= 9&& left_dis <= 9&& front_dis<8){
   back;
   delay(4000)
   Serial.println("back");
 }
  
  else if (right_dis <= 9&& left_dis <= 9&& front_dis>8){
   forward();
   Serial.println("forward");
 }
  
  else if(right_dis > 9&&left_dis <= 9&& front_dis>7){
    right();
    Serial.println("right");
  }

  else if (left_dis >9&&right_dis <= 9&& front_dis>7){
    left();
    Serial.println("left");
  }


}
void right() {
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
}
void Stop () {
 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void left() {
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void forward() {
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}
void back(){

   
  digitalWrite(in1, LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}
