#include <SPI.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN  
#define Buzzer 10
#define Led 9
#define Button 5
const byte identificacion[6] = "10101";
float valorDado;

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, identificacion);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  pinMode(10, 1);            // Define el pin 10 como salida
  pinMode(9, 1);
  pinMode(5, INPUT);            // Define el pin 9 como entrada

}

void loop() {
  digitalWrite(Buzzer, LOW);
  digitalWrite(Led, LOW);
  
  if (radio.available()) {
    radio.read(&valorDado, sizeof(valorDado));
    boolean x = digitalRead(Button);
  if(valorDado<145){
    if (valorDado <=118 && valorDado > 0|| x==HIGH){
      digitalWrite(10,1);
      digitalWrite(9,1);
      //Serial.println("Alarma.......");  
      delay(200);
      }
  }
    
    
    Serial.println(valorDado);
  }
//COMENTARIO
}
