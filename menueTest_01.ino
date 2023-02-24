/* Hardware: Arduino Duemilanove und SainSmart LCD KeypadShield
           Taste |  digits an A0
           ------|--------------
           none  |  1020
           select|   735
           left  |   498
           up    |   142
           down  |   324
           right |     0
 */
#include <LiquidCrystal.h>

//Pinbelegung fuer SainSmart LCD-Keypad-Shield:
//                        RS  E   DB4 DB5 DB6 DB7
LiquidCrystal lcd(8,  9,  4,  5,  6,  7); // LCD-Objekt erzeugen (instanziieren)

int menueStatus = 0;

void setup()
{
  lcd.begin(16, 2);                       // LCD-Objekt initialisieren: 16 Zeichen, 2 Zeilen
  lcd.blink();                            // blinkender Cursor
  Serial.begin(9600);
  updateLCD();
}

void loop() {
  if(analogRead(A0) > 100) {

    delay(15);    // prellen abwarten

    if((analogRead(A0) > 130) && (analogRead(A0) < 150)) {        // falls up-Taste
      menueStatus ++;
      if(menueStatus > 10) menueStatus = 10;
      updateLCD();
      while((analogRead(A0) > 130) && (analogRead(A0) < 150));    // scrollen verhindern
    }
  
    if((analogRead(A0) > 310) && (analogRead(A0) < 330)) {        // falls down-Taste
      menueStatus --;
      if(menueStatus < 0) menueStatus = 0;
      updateLCD();
      while((analogRead(A0) > 310) && (analogRead(A0) < 330));    // scrollen verhindern
    }
  }  

  //Serial.println(menueStatus);
}

void updateLCD() {
  switch (menueStatus) {
    case 0:
      lcd.clear();
      lcd.print("Menue 0");
    break;
    case 1:
      lcd.clear();
      lcd.print("Menue 1");    
    break;
    case 2:
      lcd.clear();
      lcd.print("Menue 2");
    break;
    case 3:
      lcd.clear();
      lcd.print("Menue 3");
    break;
    case 4:
      lcd.clear();
      lcd.print("Menue 4");
    break;    
    case 5:
      lcd.clear();
      lcd.print("Menue 5");
    break;     
    case 6:
      lcd.clear();
      lcd.print("Menue 6");
    break;     
    case 7:
      lcd.clear();
      lcd.print("Menue 7");
    break;     
    case 8:
      lcd.clear();
      lcd.print("Menue 8");
    break;    
    case 9:
      lcd.clear();
      lcd.print("Menue 9");
    break;      
    case 10:
      lcd.clear();
      lcd.print("Menue 10");
    break;    
  }
}
