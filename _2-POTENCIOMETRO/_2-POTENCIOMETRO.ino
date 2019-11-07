
//setup() es una funcion que se ejecuta una sola vez cuando prendemos el arduino
void setup() 
{
  //inicializa la comunicacion a traves del puerto serie de la pc a 9600 bits por segundo:
  Serial.begin(9600);
}

//loop() es una funcion que se ejecuta una y otra vez de forma continua hasta que apagamos el arduino
void loop() 
{
  //crea una variable entera llamada valorSensor y lee el valor del potenciometro(un numero entre 0 y 1023)
  int valorSensor = analogRead(A0);
  //muestra por pantalla el valor actual leido del potenciometro
  Serial.println(valorSensor);
   //espera entre leidas por un tema de estabilidad del sensor
   delay(50);
}
