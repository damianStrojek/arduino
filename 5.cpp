#include <LiquidCrystal.h>
#include <TimerOne.h>
 
LiquidCrystal LCD(12, 11, 7, 6, 5, 4);
float t = 2.7;
float voltage;
int state = 0;

void function() {
  Serial.println("funkcja dziala");
  float temp = analogRead(A5);
  voltage = temp/1023*5;
  Serial.println(voltage);
}

void interruptHandler(){
  if(state){
      detachInterrupt(digitalPinToInterrupt(2));
      Timer1.attachInterrupt(function);
    }
  else {
      Timer1.detachInterrupt();
      attachInterrupt(digitalPinToInterrupt(2), function, FALLING);  
  }
}

void setup() {
  Serial.begin(9600);
  LCD.begin(16, 2);
  LCD.clear();

  pinMode(2, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(6, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  Timer1.initialize(3600000);
  interruptHandler();
}  
 
void loop() {
  // Przerwanie :
  if (!digitalRead(2)){
    Serial.println("dwojka dziala");
  }
  if (!digitalRead(8)){
      Serial.println("osemka dziala");
      state = !state;
      interruptHandler();
  }
  
  LCD.setCursor(1, 0);
  LCD.print(voltage);
  LCD.setCursor(1, 1);
  LCD.print(t);
 
  delay(1000);
  LCD.clear();
}
