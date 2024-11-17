/*
*
* (1). 0x3F ===> This is the I2C address of the LiquidCrystal display that I am using.
* (2). This code writes some text to the display, keeps it visible for 2 seconds, 
*      and then clears the display. The code runs only once as it is inside the setup() function.
*
*/


#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Create an LCD object. Use the I2C address of your display (usually 0x27 or 0x3F)
LiquidCrystal_I2C lcd(0x3F, 16, 2); // Replace "0x3F" with your actual I2C address

void setup() {
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight

  // Display text on the LCD
  lcd.setCursor(0, 0); // Set cursor to column 0, row 0
  lcd.print("Hello, World!");

  lcd.setCursor(0, 1); // Set cursor to column 0, row 1
  lcd.print("ESP8266 + LCD");

  delay(2000); // Wait for 2 seconds

  // Clear the display
  lcd.clear(); // Clears the display and resets the cursor
}

void loop() {
  // Nothing to do in the loop
}