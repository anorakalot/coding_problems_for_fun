#include <Servo.h>
Servo myservo_0;//base set to 90 initially
Servo myservo_1;//find base angle =
Servo myservo_2;//find base angle = 

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

  for (int x = 0; x < 90; x+=increment){
    myservo_1.write(x);    
    delay(1000);
  }

  for (int x = 90; x >0; x -= increment){
    myservo_1.write(x);
    delay(1000);
  }
  //    myservo_1.write(0);
//    delay(1000);
//    myservo_1.write(90);
//    delay(1000);
}
