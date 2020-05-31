#include <Servo.h>
Servo myservo1;  // bottom servo

int pos1=80;

const int right_X = A2;
const int right_Y = A5;
const int right_key = 7;

const int left_X = A3;
const int left_Y = A4;
const int left_key = 8;

int x1,y1,z1;
int x2,y2,z2;


void setup()
{  
  myservo1.write(pos1);
  delay(1000);

  pinMode(right_key, INPUT);
  pinMode(left_key, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  myservo1.attach(A1);

  x1 = analogRead(right_X); //default joystick x1 = 354; final right x1 = 0; final left x1 = 720;
  y1 = analogRead(right_Y);
  z1 = analogRead(right_key);

  x2 = analogRead(left_X);
  y2 = analogRead(left_Y);
  z2 = analogRead(left_key);

  delay(5);

  rotateControl();
}


void rotateControl()
{
  Serial.print("X1:");
  Serial.println(x1);
  Serial.print("Position:");
  Serial.println(pos1);
  
  if(x1<50)  // if push the right joystick to the right
  {
    pos1=pos1-5;  //pos1 subtracts 1
    myservo1.write(pos1);  // servo 1 operates the motion, the arm turns right.
    delay(5);
    if(pos1<1)   // limit the angle when turn right
    {
      pos1=0;
    }
  }
  
  if(x1>600)  // if push the right joystick to the let
  {
    pos1=pos1+5;  //pos1 plus 1
    myservo1.write(pos1);  // arm turns left 
    delay(5);
    if(pos1>180)  // limit the angle when turn left 
    {
      pos1=180;
    }
  }
}
