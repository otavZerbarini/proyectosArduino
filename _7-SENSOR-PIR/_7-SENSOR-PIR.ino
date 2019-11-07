const int led = 6 ;
const int sensor = 7 ;

void setup()
{  
    pinMode(led , OUTPUT) ;
    pinMode (sensor , INPUT);
}

void loop()
{  
    if (digitalRead(sensor))
        digitalWrite(led , HIGH);
    else
        digitalWrite(led , LOW);
}
