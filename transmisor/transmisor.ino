#include "Adafruit_VL53L0X.h"
#include <SPI.h>
#include <RF24.h>
Adafruit_VL53L0X lox = Adafruit_VL53L0X(); 
//#include "MedianFilter.h"
float y=0.0;
float a=0.18;
float s=y;


RF24 radio(7, 8); // CE, CSN
const byte identificacion[6] = "10101";

//MedianFilter test (10,0);
void setup() {
  Serial.begin(9600);
radio.begin();
  radio.openWritingPipe(identificacion);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  // wait until serial port opens for native USB devices
  
  
  Serial.println("Adafruit VL53L0X test");
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while(1);
  }
  // power 
 
}


void loop() {
 y=(lox.readRange()/10);
    s=(a*y)+((1-a)*s);
    Serial.print(lox.readRange()/10);
    Serial.print(",");
    Serial.println(s); 
    
    
     
   radio.write(&s, sizeof(s));  
 // delay(200);
 delay(10);

}
