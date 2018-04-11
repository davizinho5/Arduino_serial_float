// Declaración de variables
union float2bytes { float f; char b[sizeof(float)]; };

void setup()
{
    // Abre puerto serial y lo configura a 9600 bps
    Serial.begin(9600);
    Serial1.begin(9600);
   
}
void loop()
{
    float2bytes f2b;

    while (Serial1.available() == 0){
      //No hago nada
      delay(10);
      //Serial.print("No hay datos\n");
    }   
    do {
      for ( int i=0; i < sizeof(float); i++ )
          f2b.b[i] = Serial1.read();
        
      // Check for nan  
      Serial.print(f2b.f);
      Serial.print("\n");

      //delay(10);
    } while (Serial1.available() > 0);  
}


