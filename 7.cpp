#include <SPI.h>
#include "LCD.h"
#include "DEV_Config.h"
#include "ADXL345.h"

ADXL345 accelerometer;
char resX[20], resY[20], resZ[20];
char resA[20], resB[20], resC[20];
bool flaga = false;

void setup() {
  accelerometer.begin();
  accelerometer.setRange(ADXL345_RANGE_4G);
  
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  
  for(int i = 0; i < 20; i++){
    resX[i]='0';
    resY[i]='0';
    resZ[i]='0';
    resA[i]='0';
    resB[i]='0';
    resC[i]='0';
  }
  SPI.begin();
 
  LCD_SCAN_DIR Lcd_ScanDir = SCAN_DIR_DFT;
  LCD.LCD_Init(Lcd_ScanDir);
}

// Function to reverse the str
void reverse(char* str, int len){
    int i = 0, j = len - 1, temp;
    while (i < j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to transform int to string
int intToStr(int x, char str[], int d){
    int i = 0;
    
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
  
    // If number of digits required is more, then
    // add 0s at the beginning
    while (i < d)
        str[i++] = '0';
        
    if(flaga){
      str[i++] = '-';
      flaga = false;
    }
    
    reverse(str, i);
    str[i] = '\0';
    return i;
}

// Converts a floating-point/double number to a string.
void ftoa(float n, char* res, int afterpoint){
    if(n < 0){
      n = abs(n);
      flaga = true;
    }
    
    // Extract integer part
    int ipart = (int)n;
  
    // Extract floating part
    float fpart = n - (float)ipart;
  
    // convert integer part to string
    int i = intToStr(ipart, res, 0);
  
    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot
         
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter 
        // is needed to handle cases like 233.007
        fpart = fpart * pow(10, afterpoint);
  
        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

// Funkcja atangengs
float atangens(float l1, float l2,float z){
  float result = atan(l1/(sqrt(pow(l2,2) + pow(z, 2))));
  result = result * 180 / M_PI;
  return result;
}

void loop() {
  Vector norm = accelerometer.readNormalize();
  
  ftoa(norm.XAxis, resX, 2);
  ftoa(norm.YAxis, resY, 2);
  ftoa(norm.ZAxis, resZ, 2);
  
  float pitch = atangens(norm.XAxis, norm.YAxis, norm.ZAxis);
  float yew = atangens(norm.YAxis, norm.XAxis, norm.ZAxis);
  float roll = atangens(norm.ZAxis, norm.XAxis, norm.ZAxis);
  
  ftoa(pitch, resA, 2);
  ftoa(yew, resB, 2);
  ftoa(roll, resC, 2);
  
  LCD.LCD_Clear(WHITE);
  LCD.LCD_DisplayString(4, 6, resX, &Font12, WHITE, RED);
  LCD.LCD_DisplayString(4, 18, resY, &Font12, WHITE, GREEN);
  LCD.LCD_DisplayString(4, 30, resZ, &Font12, WHITE, BLUE);
  LCD.LCD_DisplayString(4, 42, "Orientacje:", &Font12, WHITE, BLACK);
  LCD.LCD_DisplayString(4, 54, resA, &Font12, WHITE, RED);
  LCD.LCD_DisplayString(4, 66, resB, &Font12, WHITE, GREEN);
  LCD.LCD_DisplayString(4, 78, resC, &Font12, WHITE, BLUE);
     
  delay(1000);
}
