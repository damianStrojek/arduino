int tab[4] = {1,2,3,4};
int tab2[4] = {12,11,10,9};
int tab3[3] = {6,7,8};
int stany[4] = {0, 0, 0, 0};
int stanyRGB[3] = {0,0,0};
int wartosci[8][3] = {{0,0,0}, {0,0,1}, {0,1,0}, {0,1,1}, {1,0,0}, {1,0,1}, {1,1,0}, {1,1,1}};
int iterator = 0;

const int SW1 = 1;
const int SW2 = 2;
const int SW3 = 3;
const int SW4 = 4;
const int SW5 = 5;
const int LEDR = 12;
const int LEDG = 11;
const int LEDB = 10;
const int LEDY = 9;
const int BLUE = 8;
const int RED = 7;
const int GREEN = 6;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDY, OUTPUT);
  
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(SW1, INPUT_PULLUP);
  pinMode(SW2, INPUT_PULLUP);
  pinMode(SW3, INPUT_PULLUP);
  pinMode(SW4, INPUT_PULLUP);
  pinMode(SW5, INPUT_PULLUP);
}

void loop() {
  for(int i = 0; i <= 3; i++){
      if(digitalRead(tab[i]) == 0){
        stany[i] = (stany[i]+1)%2;
      }
  }
  for(int j = 0; j <= 3; j++){
    digitalWrite(tab2[j], stany[j]);
  }

  if(digitalRead(SW5) == 0){
    iterator++;
    if(iterator == 8){
      iterator = 0;
    }
  }
  for(int i = 0 ; i <= 2; i++){
    stanyRGB[i] = wartosci[iterator][i];
  }

  for(int i = 0; i <= 2; i++){
    digitalWrite(tab3[i], stanyRGB[i]);
  }
  
  delay(250);                          
}
