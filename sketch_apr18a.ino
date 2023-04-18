#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  // initialize the LCD
  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("APA AI Assistant");

}
String home = "APA AI Assistant";
void returnhome(void)
{
  lcd.clear();
  for (int i = 0; i<16; i++)
  {
    lcd.setCursor(i,0);
    lcd.write(home.charAt(i));
    delay(250);
  }
}
  void byone(String x, int n)
  {
    for (int i = 0; i < x.length(); i++)
    {
      lcd.setCursor(i+n,1);
      lcd.write(x.charAt(i));
      delay(250);
    }
  }
 void Dial (String x)
  {
    lcd.blink();
    byone(x,3);
    delay(1000);
    byone("Dialing...",3);
    lcd.print("  ");
  }
String message[2] = {"2","01008798070"};
String data = "yes";
void loop()
{
  
  if (message[0] == "0")
  {
     byone("Power Off", 3);
    lcd.noDisplay();
  }
  if (message[0] == "1"||message[0]=="3")
    Dial(message[1]);
  if (message[0] == "2")
  {
    byone(message[1], 3);
    delay(3000);
    if (data != "yes")
    {
    message[0] = "6";
    returnhome();
    }
    else message[0] = "1";      
  }
  if (message[0] == "4")
  {
    byone("Time:", 6);
    byone(message[1], 6);
    delay(2500);
  }
  if (message[0] == "5")
  {
    byone("Balance is", 3);
    lcd.setCursor(3, 1);
    lcd.print("            ");
    byone(message[1], 5);
    delay(2500);
    lcd.setCursor(5, 1);
    lcd.print("         ");
  }
  if (message[0] == "6")
    returnhome();
}
    
  