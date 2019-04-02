#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10,  5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight

void setup() {
    Serial.begin(9600);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
 
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
    lcd.clear();
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(1, 1);
  // print the number of seconds since reset:
  lcd.print("Hola mundo!");

  lcd.setCursor(1, 2);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
  delay(1000);
}
