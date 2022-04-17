// Print a line between 2 points.

// #include "SPI.h"
#include <Wire.h>  // I2C library
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"
#include "Adafruit_GC9A01A.h"

#define TFT_DC 4    // SDA
#define TFT_CS 5    // SCL
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 128

// Hardware SPI on Feather or other boards
Adafruit_GC9A01A tft(TFT_CS, TFT_DC);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


#define LTBLUE    0xB6DF
#define LTTEAL    0xBF5F
#define LTGREEN   0xBFF7
#define LTCYAN    0xC7FF
#define LTRED     0xFD34
#define LTMAGENTA 0xFD5F
#define LTYELLOW  0xFFF8
#define LTORANGE  0xFE73
#define LTPINK    0xFDDF
#define LTPURPLE  0xCCFF
#define LTGREY    0xE71C

#define BLUE      0x001F
#define TEAL      0x0438
#define GREEN     0x07E0
#define CYAN      0x07FF
#define RED       0xF800
#define MAGENTA   0xF81F
#define YELLOW    0xFFE0
#define ORANGE    0xFC00
#define PINK      0xF81F
#define PURPLE    0x8010
#define GREY      0xC618
#define WHITE     0xFFFF
#define BLACK     0x0000

#define DKBLUE    0x000D
#define DKTEAL    0x020C
#define DKGREEN   0x03E0
#define DKCYAN    0x03EF
#define DKRED     0x6000
#define DKMAGENTA 0x8008
#define DKYELLOW  0x8400
#define DKORANGE  0x8200
#define DKPINK    0x9009
#define DKPURPLE  0x4010
#define DKGREY    0x4A49



void setup() {
  Serial.begin(9600);
  Serial.println("GC9A01A Test!");

  tft.begin();

  Serial.print(F("Lines                    "));
  Serial.println(testLines(GC9A01A_CYAN));
  delay(500);

  Serial.println(F("Done!"));
}



void loop(void) {

}



unsigned long testLines(uint16_t color) {
  unsigned long start, t;
  tft.setRotation(0);
  int x1, y1, x2, y2,
      x0, y0, xmax, ymax, lengthx, lengthy,
      w = tft.width(),
      h = tft.height();

//  drawPixel(uint16_t x, uint16_t y, uint16_t color);
  tft.drawPixel(120, 50, DKYELLOW);  
  tft.drawPixel(121, 50, color);  
  tft.drawPixel(119, 50, color);  
  tft.drawPixel(120, 49, color);  
  tft.drawPixel(120, 51, color);  
  
  tft.fillScreen(GC9A01A_BLACK);
  yield();

  x0 = 55;
  y0 = 45;
  lengthx = 130;
  lengthy = 140;
  color = LTRED;
  x1 = 50;
  x2 = 50;
  y1 = 50;
  y2 = 160;
  
  
  tft.drawLine(x1, y1, x2, y2, color);

  tft.drawFastVLine(x0, y0, lengthx, color);
  tft.drawFastHLine(x0, y0, lengthy, color);
  



//  x1 = 160;
//  y1 = 0;
//  y2    = h - 80;
//  start = micros();
//  for(x2=80; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  x2    = w - 1;
//  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  t     = micros() - start; // fillScreen doesn't count against timing



//  yield();
//  tft.fillScreen(GC9A01A_BLACK);
//  yield();
//
//  x1    = w - 1;
//  y1    = 0;
//  y2    = h - 1;
//  start = micros();
//  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  x2    = 0;
//  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  t    += micros() - start;
//
//  yield();
//  tft.fillScreen(GC9A01A_BLACK);
//  yield();
//
//  x1    = 0;
//  y1    = h - 1;
//  y2    = 0;
//  start = micros();
//  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  x2    = w - 1;
//  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  t    += micros() - start;
//
//  yield();
//  tft.fillScreen(GC9A01A_BLACK);
//  yield();
//
//  x1    = w - 1;
//  y1    = h - 1;
//  y2    = 0;
//  start = micros();
//  for(x2=0; x2<w; x2+=6) tft.drawLine(x1, y1, x2, y2, color);
//  x2    = 0;
//  for(y2=0; y2<h; y2+=6) tft.drawLine(x1, y1, x2, y2, color);
//
//  yield();
//  return micros() - start;
}
