#include <Keypad.h>
#include "NOTAS.h" 

const byte filas = 4;     //Numero de filas del teclado
const byte columnas = 4;  //Numero de columnas del teclado
int buzzer = 11;//en el pin 11 tenemos conectada la pata positiva del buzzer 
int duracion = 1000;

//Defino una matriz 4x4 con la posicion de las filas y columnas
char matriz[filas][columnas] =
{
  { '1', '2', '3', 'A'},
  { '4', '5', '6', 'B'},
  { '7', '8', '9', 'C'},
  { '*', '0', '#', 'D'},

};

byte pinesFilas[filas] = {9, 8, 7, 6};       //Pines donde van conectadas las filas del teclado
byte pinesColumnas[columnas] = {5, 4, 3, 2}; //Pines donde van conectadas las columnas del teclado

//Inicializo el teclado con el numero de filas, columnas, los pines del Arduino utilizados y la matriz
Keypad teclado = Keypad( makeKeymap(matriz), pinesFilas, pinesColumnas, filas, columnas);

void setup()
{
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);   //Inicializo el puerto serie
}

void loop()
{
  char tecla_presionada = teclado.getKey();    //Almaceno en una variable la tecla presionada
  Serial.println(tecla_presionada);   //Muestra la tecla presionada en el monitor serie
  switch (tecla_presionada)
  {
    case '1':
      tocar(DO_2);
      break;
      
    case '2':
        
    tone(buzzer, DOS_3, duracion);
    int silencio = duracion * 1.30;
    delay(silencio);
    noTone(buzzer);
      break;
      
    case '3':
          tocar(RE_6);
      break;
    case '4':
          tocar(RES_4);
      break;
    case '5':
          tocar(MI_4);
      break;
    case '6':
          tocar(FA_4);
      break;
    case '7':
          tocar(FAS_4);
      break;
    case '8':
          tocar(SOL_4);
      break;
    case '9':
          tocar(SOLS_4);
      break;
    case '*':
          tocar(LA_4);
      break;
    case '0':
          tocar(LAS_4);
      break;
    case '#':
          tocar(SI_4 );
      break;
    case 'A':
          duracion = 1000;
      break;
    case 'B':
          duracion = 500;
      break;
    case 'C':
          duracion = 250;
      break;
    case 'D':
          duracion = 125;
      break;
  }
}


//definimos otra matriz donde guardamos la duracion de cada nota de la melodia
int tiempos[] = {1, 2, 4, 8};


void tocar(int nota)
{
    tone(buzzer, nota, duracion);
    int silencio = duracion * 1.30;
    delay(silencio);
    noTone(buzzer);
}
