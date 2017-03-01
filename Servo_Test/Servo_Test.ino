#include <Servo.h>

const int servoPin = 9;

int degree = 0;

Servo myServo;

void rotate()
{
  if (degree <= 180) degree++;
  else {degree = 0;}
  myServo.write(degree);
  delay(100);
}

void setup() 
{
  myServo.attach(servoPin);

  myServo.write(0);
}

void loop() 
{
  rotate();
}
