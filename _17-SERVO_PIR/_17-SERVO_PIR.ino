#include <Servo.h>
Servo servoMotor;
int pir = 10;
int angulo = 0;            

void setup() {
  servoMotor.attach(9);
  pinMode(pir, INPUT);
}
 
void loop() 
{
  if (digitalRead(pir))
  {
     angulo = 0;
  }
  else
  {
     angulo = 180;
  }
  servoMotor.write(angulo);
  delay(500);
  
}
