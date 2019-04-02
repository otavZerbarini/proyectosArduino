// le ponemos un nombre expresivo al pin 2
int boton = 2;

//setup() es una funcion que se ejecuta una sola vez cuando prendemos el arduino
void setup() {
    Serial.begin(9600);
  //inicializa el pin 13 digital como de salida
  pinMode(13, OUTPUT);
  //inicializa el pin 2 digital como de entrada
  pinMode(boton, INPUT_PULLUP);
}

//loop() es una funcion que se ejecuta una y otra vez de forma continua hasta que apagamos el arduino
void loop() {
  int prendido =  digitalRead(boton);
  Serial.println(prendido);
  
  if( prendido == LOW)
  {
      digitalWrite(13, HIGH);   //prende el LED conectado en el pin 13
  }
  else
  {
      digitalWrite(13, LOW);    //apaga el LED conectado en el pin 13
  }
  
}
