 #include "MFRC522.h"
#include <SPI.h>

MFRC522 rfid(10, 9);
//MFRC522::MIFARE_Key key;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

  SPI.begin();
  rfid.PCD_Init(); 
}

void loop() {
  //tone(A5, 1500, 0);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    Serial.print("Card ");
    for(int i = 0; i < 4; i++){
      Serial.print(rfid.uid.uidByte[i]);
    }
    Serial.print("\n");
    // 218 or 249
    if (rfid.uid.uidByte[0] == 249) {
      tone(A5, 1500, 500);
      digitalWrite(2, LOW);
      delay(1000);
      digitalWrite(2, HIGH);
    }
    else if (rfid.uid.uidByte[0] == 234) {
      tone(A5, 500, 600);
      digitalWrite(3, LOW);
      delay(1000);
      digitalWrite(3, HIGH);
    }
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
