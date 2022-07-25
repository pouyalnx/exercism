#include <LiquidCrystal.h>
#include <
#define Rs  14
#define R_W 15
#define EN  16
#define D4  17
#define D5  18
#define D6  19
#define D7  20
LiquidCrystal lcd(Rs, R_W, EN, D4, D5, D6, D7);



#define ROWS 4
#define COLS 4
byte rowPins[ROWS] = { 0, 1, 2, 3 };
byte colPins[COLS] = { 4, 5, 6, 7 };

char keys[ROWS][COLS] =
  {
    { '1', '2', '3', 'A', },
    { '4', '5', '6', 'B', },
    { '7', '8', '9', 'c', },
    { '*', '0', '#', 'D'  }
  };


Keypad kpd = Keypad (makeKeymap (keys), rowPins, colPins, ROWS, COLS);



void setup() {
  const char cols=16;
  const char rows=2;
  // put your setup code here, to run once: 
  lcd.begin(cols, rows);
  lcd.clear();
}

void loop() {
  char key;
  // put your main code here, to run repeatedly:
  lcd.print("hello");
  while(1){
   char ch = kpd.waitForKey();
   if(ch){
    lcd.print(ch);
   }
  delay(2000);
  }
}
