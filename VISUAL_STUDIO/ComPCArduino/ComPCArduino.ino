/*
Ejemplo de comunicacion entre la pc y el arduino usando un cable usb
Este ejemplo usa dos leds en los pines 8 y 9 que se prenderan o apagaran a pedido de la pc,
un potenciometro en A0 que enviara datos a la pc segun el valor leido,
Una pantallita que se debera conectar igual que la imagen de ejemplo "11-LCD.png"
La pc podra enviar varios comandos (numeros del 1 al 9, letras de la A a la D, * y #), algunos no estan siendo utiliados, 
para hacerlos funcionar agregar las opciones al switch de serialEvent() usando case ' ':
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10,  5, 4, 3, 2);
int backLight = 13;    // pin 13 will control the backlight

int i =0;
int led1 = 8;
int led2 = 9;
 
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(backLight, OUTPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
 
  // set up the LCD's number of columns and rows:
  lcd.begin(20, 4);
  Serial.begin(9600);
}

void loop() 
{
  int valorSensor = analogRead(A0); //en A0
  Serial.println(valorSensor);
  delay(200);
}

// Evento de recepción de datos por puerto serie.
void serialEvent() {
  while(Serial.available()){ // Si el puerto está listo para recibir datos..
    // Tomamos los datos entrantes.
    char caracter = (char)Serial.read();  
    switch(caracter)
    {
        case '1':
        digitalWrite(led1, HIGH);
        break;
        case '2':
        digitalWrite(led2, HIGH);
        break;
        case '3':
        digitalWrite(led1, LOW);
        break;
        case '4':
        digitalWrite(led2, LOW);
        break;
    }
    mostrar(caracter);
  }
}

void mostrar(char caracter)
{
  lcd.clear();
  // set the cursor to column 0, line 1
  lcd.setCursor(1, 1);
  lcd.print(caracter);
  
  delay(1000);
}
