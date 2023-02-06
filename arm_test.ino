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

char misc_print_0[200];
char misc_print_1[200];



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
  
//myservo_1.write(40);
//delay(100);
  snprintf( misc_print_0, sizeof(misc_print_0)," inputted x = %i, y = %i, z = %i\n",1,1,10);
  Serial.print(misc_print_0);
  inv_kin(1,1,10);
  
  snprintf(misc_print_1,sizeof(misc_print_1),"angle_0 = %i, angle_1 = %i, angle_2 = %i\n",angle_0,angle_1,angle_2);
  Serial.print(misc_print_1);

  //need to test this code later
  
}

void inv_kin(int x, int y, int z){//given wanted position in x y z change angle_0..2 to get there
  angle_0 = atan(y/x);
  int l=0;
  l = sqrt(pow(x,2) + pow(y,2));
  
  int phi = 0;
  phi =  atan(z/l);
  int h;
  h = sqrt(pow(z,2) + pow(l,2));
  
  int theta = 0;
  int l_of_cos_sum;
  l_of_cos_sum = (pow(87,2)+pow(h,2) - pow(122,2))/(2*87*h);
  theta = acos(l_of_cos_sum);

  angle_1 = phi + theta;
  angle_2 = phi - theta;

  return; 
}



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

//  myservo_2.write(130);
//  delay(1000);
//    for (int x = 60; x <130; x += increment){//starting at 0 leads to it not moving for a while so start at a higher num for this servo
//    myservo_2.write(x);
//    delay(1000);
//  }
