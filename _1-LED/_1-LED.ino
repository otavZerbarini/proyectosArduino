//setup() es una funcion que se ejecuta una sola vez cuando prendemos el arduino
void setup() {
  //inicializa el pin 13 digital como de salida
  pinMode(13, OUTPUT);
}

//loop() es una funcion que se ejecuta una y otra vez de forma continua hasta que apagamos el arduino
void loop() {
  digitalWrite(13, HIGH);   //prende el LED conectado en el pin 13
  delay(1000);              //espera 1 segundo
  digitalWrite(13, LOW);    //apaga el LED conectado en el pin 13
  delay(1000);              //espera un segundo
}


