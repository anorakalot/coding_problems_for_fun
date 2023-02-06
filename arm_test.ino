#include <Servo.h>
Servo myservo_0;//base set to 90 initially
Servo myservo_1;//find base angle =
Servo myservo_2;//find base angle = 
//changed from float to int because servo.write functions uses int
void inv_kin(int x, int y, int z);//take in wanted positiong change angle
//make angle for myservo objects global to make it easier
int angle_0 = 90;
int angle_1 = 60; 
int angle_2 = 130;

int increment = 10;
void setup() {
  // put your setup code here, to run once:
  //pinMode(A0, output);
  Serial.begin(9600);
  delay(1000);
  myservo_0.attach(A0);
  myservo_1.attach(A1);
  myservo_2.attach(A2);
}

void loop() {
  // put your main code here, to run repeatedly:
  //myservo.attach(A0);
  
//  myservo_0.write(45);
//  delay(1000);
//  myservo.write(90);
//  delay(1000);

//  for (int x = 0; x < 90; x+=increment){
//    myservo_1.write(x);    
//    delay(1000);
//  }
//
//  for (int x = 90; x >0; x -= increment){
//    myservo_1.write(x);
//    delay(1000);
//  }

//  myservo_1.write(60);
//  delay(1000);
  //    myservo_1.write(0);
//    delay(1000);
//    myservo_1.write(90);
//    delay(1000);

myservo_1.write(40);
delay(100);

//  myservo_2.write(130);
//  delay(1000);
//    for (int x = 60; x <130; x += increment){//starting at 0 leads to it not moving for a while so start at a higher num for this servo
//    myservo_2.write(x);
//    delay(1000);
//  }
}

void inv_kin(int x, int y, int z){


  return; 
}
