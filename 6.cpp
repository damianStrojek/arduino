#include <LiquidCrystal.h>
 
LiquidCrystal LCD(12, 11, 5, 4, 3, 2);
 
void setup() {
  Serial.begin(9600);
  LCD.begin(16, 2);
  LCD.clear();
  
  pinMode(8, OUTPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  
  digitalWrite(8, LOW);
}
 
void loop() {
  if (digitalRead(10)){
      LCD.setCursor(1, 0);
      LCD.print("Wykryto ruch");
  }
  else{
      LCD.setCursor(1, 0);
      LCD.print("Brak ruchu");
  }

  digitalWrite(8, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(8, LOW);

  float t = pulseIn(9, HIGH);
  float distance = (float)t / 2 / 29.1;
  if (distance > 200){
      LCD.setCursor(1,1);
      LCD.print("Poza zasiegiem");
  }
  else {
      LCD.setCursor(1,1);
      LCD.print(distance);
  }
   
  delay(600);
  LCD.clear();
}
