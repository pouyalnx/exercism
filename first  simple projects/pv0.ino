#include <Keypad.h>
//*********************************************Setup Keypad
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//*********************************************Config Pin_Keypad
const byte Pin_ROW1 = 13;
const byte Pin_ROW2 = 12;
const byte Pin_ROW3 = 11;
const byte Pin_ROW4 = 10;
const byte Pin_column1 = 9;
const byte Pin_column2 = 8;
const byte Pin_column3 = 7;
const byte Pin_column4 = 6;
byte rowPins[ROWS] = {Pin_ROW1, Pin_ROW2, Pin_ROW3, Pin_ROW4};
byte colPins[COLS] = {Pin_column1, Pin_column2, Pin_column3, Pin_column4};
//*********************************************Layout Keypad
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
//*********************************************Start Program
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  char customKey = customKeypad.getKey();
  if (customKey) {
    Serial.println(customKey);
  }
}