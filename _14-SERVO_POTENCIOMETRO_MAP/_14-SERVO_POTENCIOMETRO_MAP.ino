#include <Servo.h>
Servo servoMotor;
 
void setup() {
  Serial.begin(9600);
  servoMotor.attach(9);
}
 
void loop() 
{
  int valorSensor = analogRead(A0);
  valorSensor = map(valorSensor,0, 1023,0,180);
  servoMotor.write(valorSensor);

}
