/*
        *************************** Wiring ***************************************
                 Pin Definitions for OLED and ESP8266 (NodeMCU)

// OLED_RESET ==> GPIO-4  (D2)
// OLED_DC/D0    ==> GPIO-5  (D1)
// OLED_MOSI/D1  ==> GPIO-13 (D7)
// OLED_CLK   ==> GPIO-14 (D5)
// OLED_CS    ==> GPIO-15 (D8)
// OLED_VCC   ==> 3.3V
// OLED_GND   ==> GND
*
*
*/
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


#define OLED_RESET  4 // ===> GPIO-4(D2)
#define OLED_DC     5 // ===> GPIO-5(D1)
#define OLED_MOSI   13 // ===> GPIO-13(D7)
#define OLED_CLK    14 // ===> GPIO-14(D5)
#define OLED_CS     15 // ===> GPIO-15(D8)


Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

void AllPixels();
void TextDisplay();
void InvertedTextDisplay();
void ScrollText();
void DisplayChars();
void TextSize();

void setup() {
  Serial.begin(115200);

  if (!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Stay in loop if initialization fails
  }

  display.clearDisplay();
  display.display();
  delay(100);
}

void loop() {
//  AllPixels(); // (1).
//  TextDisplay(); // (2).
//  InvertedTextDisplay(); // (3).
//  ScrollText(); // (4).
  DisplayChars(); // (5).
//  TextSize(); // (6).
}

/* (1). Ye wala code OLED Display par sare pixels ko line by line increase-karega(left to right) aur remove-karega(left to right) */
void AllPixels() {
  display.clearDisplay();
  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 64; j++) {
      display.drawPixel(i, j, SSD1306_WHITE);
    }
    display.display();
    delay(20);
  }

  for (int i = 0; i < 128; i++) {
    for (int j = 0; j < 64; j++) {
      display.drawPixel(i, j, SSD1306_BLACK);
    }
    display.display();
    delay(20);
  }
}

/* (2). Ye wala code OLED Display par Text ko show karega((Background-color-black-rahega) aur (Text-ka-color-wight-rahega)) */
void TextDisplay() {
  display.clearDisplay(); // It will clear the OLED Display.
  display.setTextSize(1); // This will set the size to the text 1X times the standart size.
  display.setTextColor(SSD1306_WHITE); // Set the "text color to black" and the "background color to white".
  display.setCursor(5, 28); // It will set the coursor at (5+1)th-row and (28+1)th-column , from where you want Start Printing or writing the text.
  display.println("Araham Abeddin"); 
  display.display(); // Ye OLED Display ko given text se updata kar dega aur ise nahi denge to diplay par kuch bhi print nahi hoga.
  delay(3000); // This will keep the text on the display for 3000-milisecond(ms)=3second.
}

/* (3). Ye wala code OLED Display par Text ko show karega((Background-color-wight-rahega) aur (Text-ka-color-black-rahega)) */
void InvertedTextDisplay() {
  display.clearDisplay(); // It will clear the OLED Display.
  display.setTextSize(2); // This will set the size to the text 1X times the standart size.
  display.clearDisplay(); // It will clear the OLED Display.
  display.setTextColor(SSD1306_BLACK, SSD1306_WHITE); // Set the "text color to black" and the "background color to white".
  display.setCursor(5, 28); // It will set the coursor at (5+1)th-row and (28+1)th-column , from where you want Start Printing or writing the text.
  display.println("Araham Abeddin"); // This text will be print on the OLED Display.
  display.display(); // Ye OLED Display ko given text se updata kar dega aur ise nahi denge to diplay par kuch bhi print nahi hoga.
  delay(3000); // This will keep the text on the display for 3000-milisecond(ms)=3second.
}

/*  (4). Text-Scrolling In OLED Display */
void ScrollText() {
  display.clearDisplay(); // OLED screen ko saaf kar deta hai, taaki pehle ka text na dikhe.
  display.setCursor(0, 0); // Cursor ka position (top-left corner) par set karta hai.
  display.setTextSize(1); // Text ka size set karta hai (size 1 means default small size).
  display.setTextColor(SSD1306_WHITE); // Text ka color white set karta hai.

  /* Diya gaya text OLED screen par likhta hai, aur ek line ke baad cursor ko agle line par shift kar deta hai. */
  display.println("This is a"); // "This is a"
  display.println("Scrolling"); // "Scrolling"
  display.println("Text!"); // "Text!"
  display.display(); // Saara likha hua content screen par dikhata hai.
  delay(100); // Screen ko 100 milliseconds ke liye pause karta hai.

  display.startscrollright(0x00, 0x0F); // Ye code text ko left se right leke-jayega.
  delay(2000); // Ye code text ko left se right leke-jayega 2000ms tak left to right tak leke jayega.

  display.startscrollleft(0x00, 0x0F); // Ye code text ko right se left leke-jayega.
  delay(2000); // Ye code text ko left se right leke-jayega 2000ms tak left to right tak leke jayega.

  display.startscrolldiagright(0x00, 0x0F);
  delay(2000);

  display.startscrolldiagleft(0x00, 0x0F);
  delay(2000);

  display.stopscroll();
}

/** (5). This function-code will display the ASCII character set (characters from 0 to 255) on the OLED display. **/
void DisplayChars() {
  display.clearDisplay(); //  OLED screen ko puri tarah clear kar deta hai.
  display.setTextSize(1); // Text ka size set karta hai (size = 1, jo sabse chhota hai).
  display.setTextColor(SSD1306_WHITE); // Text ka color white set karta hai.
  display.setCursor(0, 0); // Cursor ko screen ke top-left corner (x = 0, y = 0) par set karta hai.
  display.cp437(true); // Code page 437 ko enable karta hai (jo ki ek standard ASCII character set hai).


  for (int16_t i = 0; i < 256; i++) {
    if (i == '\n') { /* Agar character '\n' (new line) hai, to uski jagah ' ' (space) likhta hai, taki line break na ho. */
      display.write(' ');
    } else { /* Baaki sab characters ko directly OLED par likhta hai. */
      display.write(i);
    }
  }

  display.display(); // OLED screen par ab tak buffer mein jo bhi data hai, usse show kar deta hai.
  delay(3000); // 3000 milliseconds (3 seconds) ka delay lagata hai, taki output clearly dekh sake.
}

/*  (6). This function displays the text of different sizes on an OLED display. */
void TextSize() {
  display.clearDisplay(); // Clear the OLED display buffer before starting.

  // Text size 1
  display.setTextSize(1);             // Set text size to 1 (smallest size).
  display.setTextColor(SSD1306_WHITE); // Set text color to white for display visibility.
  display.setCursor(0, 0);             // Set the cursor position to the top-left corner (0,0).
  display.println(F("Size: 1"));       // Print "Size: 1" on the OLED.The `F` macro stores the string in Flash memory to save SRAM.
  display.println(F("ABC"));           // Print "ABC" below "Size: 1".The `F` macro stores the string in Flash memory to save SRAM.

  // Text size 2
  display.setTextSize(2);             // Increase text size to 2 (medium size).
  display.setCursor(0, 20);           // Move the cursor down to prevent overlapping with previous text.
  display.println(F("Size: 2"));       // Print "Size: 2" on the OLED.The `F` macro stores the string in Flash memory to save SRAM.
  display.println(F("ABC"));           // Print "ABC" below "Size: 2" at size 2.The `F` macro stores the string in Flash memory to save SRAM.

  display.display(); // Render the text to the OLED by sending the buffer content to the display.
  delay(3000);       // Pause for 3 seconds to allow the user to view the output before clearing.
}



