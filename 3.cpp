#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

byte customChar[8] = {0x00,0x00,0x04,0x04,0x15,0x0E,0x04,0x00};
byte smiley[] = { 
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};

int x = 0;
int y = 0;
char c;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(x, y);
  lcd.write("A");
}

void loop() {
  
  lcd.clear();

  if(Serial.available() > 0){
      c = Serial.read();
      switch(c){
        // LEWY
        case 97:
        if(x > 0){
          x--;
        }
        break;
        // PRAWY
        case 100:
        if(x < 31){
          x++;
        }
        break;
        // GORA
        case 119:
        if(y > 0){
          y--;
        }
        break;
        // DOL
        case 115:
        if(y < 1){
          y++;
        }
        break;
      }
    }
  
  lcd.setCursor(x, y);
  lcd.write("A");
  delay(500);
}
