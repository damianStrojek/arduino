// ZADANIE 1
int SW[18];


void setup() {
  for(int i = 0; i < 18; i++){
    SW[i] = i;
  }
  for(int i = 0; i < 8; i++){
    pinMode(SW[i], OUTPUT);
  }
  for(int i = 14; i < 18; i++){
    pinMode(SW[i], OUTPUT);
  }
  
  pinMode(SW[9], INPUT);
  pinMode(SW[10], INPUT);
  pinMode(SW[11], INPUT);
  pinMode(SW[12], INPUT);

}

void loop() {
  
  digitalWrite(SW[14], HIGH); 
  digitalWrite(SW[0], LOW);
  digitalWrite(SW[1], LOW);
  digitalWrite(SW[2], LOW);
  digitalWrite(SW[3], LOW);
  digitalWrite(SW[4], LOW);
  digitalWrite(SW[6], LOW);
  delay(1);
  digitalWrite(SW[14], LOW);

  for(int i = 0; i < 8; i++){
    digitalWrite(SW[i], 1);
  }

  digitalWrite(SW[15], HIGH); 
  digitalWrite(SW[0], LOW);
  digitalWrite(SW[1], LOW);
  digitalWrite(SW[2], LOW);
  digitalWrite(SW[3], LOW);
  digitalWrite(SW[4], LOW);
  digitalWrite(SW[5], LOW);
  digitalWrite(SW[6], LOW);
  digitalWrite(SW[7], LOW);
  delay(1);
  digitalWrite(SW[15], LOW);

  for(int i = 0; i < 8; i++){
    digitalWrite(SW[i], 1);
  }

  digitalWrite(SW[16], HIGH); 
  digitalWrite(SW[1], LOW);
  digitalWrite(SW[2], LOW);
  delay(1);
  digitalWrite(SW[16], LOW);

  for(int i = 0; i < 8; i++){
    digitalWrite(SW[i], 1);
  }

  digitalWrite(SW[17], HIGH); 
  digitalWrite(SW[0], LOW);
  digitalWrite(SW[1], LOW);
  digitalWrite(SW[2], LOW);
  digitalWrite(SW[3], LOW);
  digitalWrite(SW[6], LOW);
  delay(1);
  digitalWrite(SW[17], LOW);

  for(int i = 0; i < 8; i++){
    digitalWrite(SW[i], 1);
  }
  
}


// ZADANIE 3
int SW[18];
int licznik = 14;

void setup() {
  for(int i = 0; i < 18; i++){
    SW[i] = i;
  }
  for(int i = 0; i < 8; i++){
    pinMode(SW[i], OUTPUT);
  }
  for(int i = 14; i < 18; i++){
    pinMode(SW[i], OUTPUT);
  }
  
  pinMode(SW[9], INPUT_PULLUP);
  pinMode(SW[10], INPUT_PULLUP);
  pinMode(SW[11], INPUT_PULLUP);
  pinMode(SW[12], INPUT_PULLUP);

}

void loop() {
  if(licznik > 17){
    licznik = 14;
  }

  for(int i = 14; i < 18; i++){
    digitalWrite(SW[i], 1);
  }

  digitalWrite(SW[licznik], 0);
  licznik++;

  int i = 0;
  for(i = 9; i < 13; i++){
    if(digitalRead(SW[i]) == 0){
      break;
    }
  }
  
  if(i == 9){
    digitalWrite(SW[14], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[4], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[14], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[15], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[4], LOW);
    digitalWrite(SW[5], LOW);
    digitalWrite(SW[6], LOW);
    digitalWrite(SW[7], LOW);
    delay(1);
    digitalWrite(SW[15], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[16], HIGH); 
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    delay(1);
    digitalWrite(SW[16], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[17], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[17], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  }
  else if(i == 10){
    digitalWrite(SW[14], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    delay(1);
    digitalWrite(SW[14], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[15], HIGH); 
    digitalWrite(SW[4], LOW);
    digitalWrite(SW[5], LOW);
    digitalWrite(SW[6], LOW);
    digitalWrite(SW[7], LOW);
    delay(1);
    digitalWrite(SW[15], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[16], HIGH); 
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    delay(1);
    digitalWrite(SW[16], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[17], HIGH); 
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[17], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  }
  else if(i == 11){
    digitalWrite(SW[14], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[4], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[14], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[15], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[6], LOW);
    digitalWrite(SW[7], LOW);
    delay(1);
    digitalWrite(SW[15], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[16], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[16], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[17], HIGH); 
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[17], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  }
  else if(i == 12){
    digitalWrite(SW[14], HIGH); 
    digitalWrite(SW[0], LOW);
    digitalWrite(SW[1], LOW);
    delay(1);
    digitalWrite(SW[14], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[15], HIGH); 
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    delay(1);
    digitalWrite(SW[15], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[16], HIGH); 
    digitalWrite(SW[1], LOW);
    digitalWrite(SW[2], LOW);
    delay(1);
    digitalWrite(SW[16], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  
    digitalWrite(SW[17], HIGH); 
    digitalWrite(SW[2], LOW);
    digitalWrite(SW[3], LOW);
    digitalWrite(SW[6], LOW);
    delay(1);
    digitalWrite(SW[17], LOW);
  
    for(int i = 0; i < 8; i++){
      digitalWrite(SW[i], 1);
    }
  }
 
}
