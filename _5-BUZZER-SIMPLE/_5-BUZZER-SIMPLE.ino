//incluimos en nuestro programa una biblioteca externa
#include "NOTAS.h"   

int boton =2;
//TIEMPOS 1, 2, 4 ,8
int tiempo = 4;

void setup()
{
  //en el pin 8 tenemos conectada la pata positiva del buzzer 
  pinMode(8, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

//repetimos la melodia infinitas veces
void loop()
{
  int prendido =  digitalRead(boton);

  if( prendido == LOW)
  {
      int duracion = 1000/tiempo;
      tone(8, DO_4, duracion);
      int silencio = duracion * 1.30;
      delay(silencio);
      noTone(8);
  }
}
