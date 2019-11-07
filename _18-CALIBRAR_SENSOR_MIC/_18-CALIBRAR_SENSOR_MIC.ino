/*
  Ejemplo que utiliza un sensor de sonido KY-038 (viene con dos leds integrados, un mic y un preset), dos leds y dos resistencias de 1k.
  Para que funcione correctamente hace falta calibrar el preset de sensibilidad que viene en el sensor.
  Los 2 leds integrados en el sensor son indicadores, cuando se prende el de la derecha muestra que esta bien alimentado a 5v.
  Cuando prende el led izquierdo indica que se supero el umbral calibrado con el preset.
  Para saber que valores esta leyendo el sensor en cada momento usamos el monitor serie.
  Para hacer funcionar el sensor por primera vez se buscó la posicion del preset que apagaba el led izquierdo,
  en este caso, en una habitacion sin ruidos, fue aproximadamente 583.
  Es decir que el led prendia si el sonido superaba el 583 y apagaba en cualquier valor menor o igual a 583.
  Una vez seteado el preset este ejemplo deberia funcionar bien. 
  Podria hacer falta modificar la variable umbral en el codigo.
  Usamos un led para mostrar el tiempo de calibracion durante el setup, 
  y para mostrar que se supero el umbral durante el loop.
  Usamos otro led para mostrar los cambios de valores que obtenemos del sensor durante la ejecucion,
  estos cambios se muestran dimerizando un led en una salida pwm usando la funcion map().
*/

//constantes
const int sensorPin = A0;    // configuramos el pin para el sensor
const int ledPin = 9;        // configuramos un pin para el LED del umbral y el calibrado
const int ledDim = 10;        // configuramos otro pin para el LED dimerizable segun el valor leido

// variables
int umbral = 585; //este numero depende de la sensibilidad del sensor

// variables para la calibracion
int sensorValue = 0;         // Valor del sensor
int sensorMin = 1023;        // valor mínimo del sensor
int sensorMax = 0;           // valor máximo del sensor

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledDim, OUTPUT);
  calibrarSensor();
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  if (sensorValue > umbral)
  {
    prenderLed();
  }
  dimerizarLed();
}

//funciones auxiliares
void dimerizarLed()
{
  imprimir(sensorValue, "lectura: ");
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
  imprimir(sensorValue, "mapeado: ");
  sensorValue = constrain(sensorValue, 0, 255);
  imprimir(sensorValue, "constrain: ");
  analogWrite(ledDim, sensorValue);
}
void calibrarSensor()
{
  // El LED se enciende para indicar el periodo de calibración
  digitalWrite(ledPin, HIGH);

  // Calibrar durante los primeros cinco segundos
  while (millis() < 5000)
  {
    sensorValue = analogRead(sensorPin);
    if (sensorValue > sensorMax)
    {
      sensorMax = sensorValue;
    }
    if (sensorValue < sensorMin)
    {
      sensorMin = sensorValue;
    }
  }
  digitalWrite(ledPin, LOW);
}

void prenderLed()
{
  digitalWrite(ledPin, HIGH);
  delay(5000);
  digitalWrite(ledPin, LOW);
  imprimir(sensorValue, "XXXXXXXXX- Se supero el umbral : ");
  delay(2000);
}

void imprimir(int valor, String tex)
{
  String texto = tex + valor;
  Serial.println(texto);
}
