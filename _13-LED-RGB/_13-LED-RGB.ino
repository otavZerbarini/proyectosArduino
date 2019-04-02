
int pinRojo = 9; 
int pinVerde = 10; 
int pinAzul = 11;
 
int potPin_red = A2;  
int potPin_green = A1;  
int potPin_blue = A0; 
 
int readValue_red; 
int readValue_green; 
int readValue_blue; 
 
int writeValue_red; 
int writeValue_green; 
int writeValue_blue;
 
void setup() {
  pinMode(potPin_red, INPUT); 
  pinMode(potPin_green, INPUT); 
  pinMode(potPin_blue, INPUT); 
  
  pinMode(pinRojo,OUTPUT); 
  pinMode(pinAzul,OUTPUT); 
  pinMode(pinVerde, OUTPUT); 
}
 
void loop() {
  readValue_red = analogRead(potPin_red); //Read voltage from potentiometer to control red LED
  readValue_green = analogRead(potPin_green); //Read voltage from potentiometer to control green LED
  readValue_blue = analogRead(potPin_blue); //Read voltage from potentiometer to control blue LED
  
  writeValue_red = (255./1023.)*readValue_red; //Calculate the value to write on the red LED (add point to change to float point)
  writeValue_green = (255./1023.)*readValue_green; //Calculate the value to write on the green LED
  writeValue_blue = (255./1023.)*readValue_blue; ///Calculate the value to write on the blue LED
  
  analogWrite(pinRojo,writeValue_red); //write value to set the brightness of the red LED
  analogWrite(pinVerde,writeValue_green); //write value to set the brightness of the green LED
  analogWrite(pinAzul,writeValue_blue); //write value to set the brightness of the blue LED
}
