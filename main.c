#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int LEDPin = 7 , Button = A3;
float val = 0;
LiquidCrystal LCD(rs, en, d4, d5, d6, d7);
void setup() {
Serial.begin(9600);          // Introducing The Series
pinMode(LEDPin, OUTPUT);
LCD.begin(16, 2);          // Introducing LCD Resolution

}

void loop() {
val = analogRead(Button);                  // Get Value From Base Button
float FO = val * 5 / 1023;
Serial.print("POT Voltage : ");          // Print The Desired Message
Serial.println(FO);                     // Show The Desired Value
analogWrite(LEDPin, FO);
LCD.setCursor(0, 1);
LCD.print("POT Voltage : ");
LCD.print(FO);
}
