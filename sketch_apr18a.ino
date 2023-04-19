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
// functions clears screen and types logo with animation(home screen)
void returnhome(void)
{
  //clear LCD screen
  lcd.clear();
  //first letter starts at beginning (0,0)
  for (int i = 0; i<16; i++)
  {
    //cursor set a i position
    lcd.setCursor(i,0);
    //ith letter is written on screen 
    lcd.write(home.charAt(i));
    //delay between each letter displayed on screen
    delay(250);
  }
}
//functions prints each character one by one
  void byone(String x, int n)
  {
    //for i = 0 until length of string
    for (int i = 0; i < x.length(); i++)
    {
    //cursor set at ith position
      lcd.setCursor(i+n,1);
    //ith letter shown on screen
      lcd.write(x.charAt(i));
      delay(250);
    }
  }
 //function that calls number x
 void Dial (String x)
  {
    lcd.blink();
    // x is typed each character one by one
    byone(x,3);
  //delay of 1 second to leave to the user time to read number
    delay(1000);
    
    byone("Dialing...",3);
    lcd.print("  ");
  }
String message[2] = {"2","01008798070"};
String data = "yes";
void loop()
{
  //if mode 0, power off
  if (message[0] == "0")
  {
     byone("Power Off", 3);
    lcd.noDisplay();
  }
  //if mode 1, call favorite number, if mode 3 call last number
  if (message[0] == "1"||message[0]=="3")
    Dial(message[1]);
  //if mode 2 call number inputted by user
  if (message[0] == "2")
  {
    byone(message[1], 3);
    delay(3000);
    // if user says no go back to home screen
    if (data != "yes")
    {
    message[0] = "6";
    returnhome();
    }
    //else dial number
    else message[0] = "1";      
  }
  // if mode 4 print time
  if (message[0] == "4")
  {
    byone("Time:", 6);
    byone(message[1], 6);
    delay(2500);
  }
  // if mode 5 print balance
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
  //if mode 6 go to home screen
  if (message[0] == "6")
    returnhome();
}
    
