int pin= 13; 
void setup()
{
  pinMode(pin, OUTPUT);
}

void loop() 
{
  digitalWrite(13, HIGH);   
  delay(1000);  
  digitalWrite(13, LOW);
  delay(1000);              
}
