//incluimos en nuestro programa una biblioteca externa
#include "NOTAS.h"   

//definimos una array donde guardamos todas las notas de la melodia que queremos tocar
int tetris[] = {
  LA_6, MI_6, FA_6, RE_6, RE_6, FA_6, LA_6, SOL_6, FA_6, MI_6, MI_6, FA_6, SOL_6, LA_6,
  FA_6, RE_6, RE_6, SOL_6, LAS_6, 
  RE_7, RE_7, DO_6, LAS_6, LA_6, FA_6, LA_6, LA_6, SOL_6, FA_6, MI_6, MI_6, FA_6,
  SOL_6, LA_6, RE_6,
  LA_6, MI_6, FA_6, RE_6, RE_6, FA_6, LA_6, SOL_6, FA_6, MI_6, MI_6, FA_6, SOL_6, LA_6,
  FA_6, RE_6, RE_6, SOL_6, LAS_6,
  RE_7, RE_7, DO_6, LAS_6, LA_6, FA_6, LA_6, LA_6, SOL_6, FA_6, MI_6, MI_6, FA_6,
  SOL_6, LA_6, RE_6,
  FA_6, RE_6, DOS_6, MI_6, LA_6, FA_6, SOL_6, MI_6, FA_6, LA_6
};

//definimos otra matriz donde guardamos la duracion de cada nota de la melodia
int tiempos[] = {
  4,8,8,4,8,8,4,8,8,4,
  8,8,4,4,4,4,2,4,4,8,
  8,8,8,4,8,8,8,8,8,4,
  8,8,4,4,2,4,8,8,4,8,
  8,4,8,8,4,8,8,4,4,4,
  4,2,4,4,8,8,8,8,4,8,
  8,8,8,8,4,8,8,4,4,2,
  2,2,2,2,2,2,2,2,2,1
};

void setup()
{
  //en el pin 8 tenemos conectada la pata positiva del buzzer 
  pinMode(8, OUTPUT);
}

//repetimos la melodia infinitas veces
void loop()
{
  //tocamos las 80 notas que componen la melodia una por una
  for (int I = 0; I < 79; I++) {

    int duracion = 1000/tiempos[I];
    tone(8, tetris[I],duracion);
    int silencio = duracion * 1.30;
    delay(silencio);

    noTone(8);
  }
}
