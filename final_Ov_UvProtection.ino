#include <LiquidCrystal.h>

#define rs 12
#define en 11 
#define d4 5 
#define d5 4  
#define d6 3 
#define d7 2 
#define HIGH 0x1
#define LOW  0x0

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String TextForSms ;
int analogInput = A1; 
float vout = 0; 
//int vin = 0; 
int relay = 7;

int value = 0; 
float vol = 0;

void setup() {
  Serial.begin(9600); 
    // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Voltage:");
  pinMode(relay, OUTPUT);
  pinMode(analogInput, INPUT);

}
void loop()
{
   // read the value at analog input 
   value = analogRead(analogInput); 
   
   vout = (value / 1023.0)*5.0;
   vol = vout*100;
    lcd.setCursor(10,0); 
    lcd.print(vol);
    if (vout > 2.6) 
    {
      digitalWrite(relay,LOW);
      lcd.setCursor(0,1);
      lcd.print("Overvoltage"); 
    }
    if (vout<2.0) 
    {
      digitalWrite(relay,LOW);
      lcd.setCursor(0,1);
      lcd.print("Undervoltage "); 
    }
    if ((vout > 2.0)&&(vout<2.6))
    {
      digitalWrite(relay,HIGH);
      lcd.setCursor(0,1);
      lcd.print("Normal Voltage "); 
    }
}
