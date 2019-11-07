int led = 12;//declaro una variable llamada led y le asigno el numero del pin donde conecté el led en el arduino

void setup()//esto se ejecuta una sola vez al inicio
{
  pinMode(led, OUTPUT);//aviso que voy a usar el pin como salida
}

void loop() //esto se ejecuta muchas veces 
{ 
  digitalWrite(led, HIGH); //prendo el pin donde conecte el led
  delay(1000);  //espero 1000 milisegundos (1 segundo)
  digitalWrite(led, LOW); //apago el pin donde conecte el led
  delay(1000);//espero 1000 milisegundos (1 segundo)
  
}
