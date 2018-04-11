// Declaración de variables
float tempC = 0.1;

union float2bytes { float f; char b[sizeof(float)]; };

void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
}

void loop()
{
    float2bytes f2b;
    f2b.f = tempC;
    /*Serial.print(f2b.f);
    Serial.print("\n");
    Serial.print(f2b.b);
    Serial.print("\n");*/
    
    for ( int i=0; i < sizeof(float); i++ )
        Serial.writre(f2b.b[i]);

    tempC++;
    delay(2000);
}
 

