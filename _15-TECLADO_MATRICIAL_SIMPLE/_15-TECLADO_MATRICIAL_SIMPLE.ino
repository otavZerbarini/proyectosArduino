//VER LINK PARA DESCARGAR LA LIBRERIA KEYPAD: http://arduparatodos.blogspot.com/2017/12/teclado-matricial-con-arduino-varios.html
#include <Keypad.h>

const byte filas = 4;     //Numero de filas del teclado
const byte columnas = 4;  //Numero de columnas del teclado

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
  Serial.begin(9600);   //Inicializo el puerto serie
}

void loop()
{
  char tecla_presionada = teclado.getKey();    //Almaceno en una variable la tecla presionada

  if (tecla_presionada)
  {
    Serial.println(tecla_presionada);   //Muestra la tecla presionada en el monitor serie
  }
}
