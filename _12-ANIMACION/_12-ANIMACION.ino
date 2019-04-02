#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10,  5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight

int col = 0;
int i = 0;
byte myChar1[8];
byte myChar2[8];
byte myChar3[8];
byte myChar4[8];
byte myChar5[8];
byte myChar6[8];

void setup() 
{
  Serial.begin(9600);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  createChars();
  lcd.begin(20, 4);
}

void loop() 
{
  irYvolver();
  delay(1000);
  lcd.clear();
}

void irYvolver()
{
  lcd.clear();
  lcd.setCursor(col, 1);
  for (int j = 0; j < 6; j++) {
    lcd.write(byte(j));
    if (j == 2)
    {
      lcd.setCursor(col, 2);//col and row position
    }
  }
  i++;

  if (i == 34)
  {
    i = 0;
    col = 0;
  }
  if ((i > 0) && (i < 18)) col++;
  if ((i >= 18) && (i < 35)) col--;
}

void createChars()
{
  createCharsNormal();

  lcd.createChar(0, myChar1);
  lcd.createChar(1, myChar2);
  lcd.createChar(2, myChar3);
  lcd.createChar(3, myChar4);
  lcd.createChar(4, myChar5);
  lcd.createChar(5, myChar6);
}

void createCharsNormal()
{
  byte customChar1[8] = {
    0b00001,
    0b00111,
    0b01111,
    0b01011,
    0b01011,
    0b01111,
    0b01110,
    0b00100
  };
  byte customChar2[8] = {
    0b11111,
    0b11111,
    0b11111,
    0b10001,
    0b00000,
    0b01010,
    0b01010,
    0b00000
  };
  byte customChar3[8] = {
    0b10000,
    0b11100,
    0b11110,
    0b11110,
    0b11010,
    0b11010,
    0b01110,
    0b00100
  };
  byte customChar4[8] = {
    0b00110,
    0b01010,
    0b10001,
    0b10010,
    0b01110,
    0b00010,
    0b00010,
    0b00001
  };
  byte customChar5[8] = {
    0b01110,
    0b00000,
    0b11111,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b10001
  };
  byte customChar6[8] = {
    0b01100,
    0b01010,
    0b10001,
    0b01001,
    0b01110,
    0b01000,
    0b01000,
    0b10000
  };
  memcpy(myChar1, customChar1, 8);
  memcpy(myChar2, customChar2, 8);
  memcpy(myChar3, customChar3, 8);
  memcpy(myChar4, customChar4, 8);
  memcpy(myChar5, customChar5, 8);
  memcpy(myChar6, customChar6, 8);
}
