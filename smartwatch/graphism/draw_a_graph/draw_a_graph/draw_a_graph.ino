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

int yprev = 190;
int y0y = 190;
int y1y = 190;
int y2y = 190;
int y3 = 190;
int y4 = 190;
int y5 = 190;
int y6 = 190;
int y7 = 190;
int y8 = 190;
int y9 = 190;
int y10 = 190;
int y11 = 190;
int y12 = 190;
int y13 = 190;
int y14 = 190;
int y15 = 190;
int y16 = 190;
int y17 = 190;
int y18 = 190;

int xprev = 215;
int x0 = 205;
int x1 = 195;
int x2 = 185;
int x3 = 175; 
int x4 = 165;
int x5 = 155;
int x6 = 145; 
int x7 = 135; 
int x8 = 125; 
int x9 = 115; 
int x10 = 105; 
int x11 = 95; 
int x12 = 85; 
int x13 = 75; 
int x14 = 65; 
int x15 = 55; 
int x16 = 45; 
int x17 = 35; 
int x18 = 25;

//int x0 = 50;
//int x1 = 50;
//int x2 = 50;
//int x3 = 50;
//int x4 = 50;
//int x5 = 50;
//int x6 = 50;
//int x7 = 50;
//int x8 = 50;
//int x9 = 50;
//int x10 = 50;
//int x11 = 50;
//int x12 = 50;
//int x13 = 50;
//int x14 = 50;
//int x15 = 50;
//int x16 = 50;
//int x17 = 50;
//int x18 = 50;
//
//int y0y = 205;
//int y1y = 195;
//int y2y = 185;
//int y3 = 175; 
//int y4 = 165;
//int y5 = 155;
//int y6 = 145; 
//int y7 = 135; 
//int y8 = 125; 
//int y9 = 115; 
//int y10 = 105; 
//int y11 = 95; 
//int y12 = 85; 
//int y13 = 75; 
//int y14 = 65; 
//int y15 = 55; 
//int y16 = 45; 
//int y17 = 35; 
//int y18 = 25;

//int xmax, ymax, lengthx, lengthy;
//int w = tft.width();
//int h = tft.height();


void setup() {
  Serial.begin(9600);
  Serial.println("Start writting");
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(BLACK);
  delay(10);
    
  tft.drawPixel(x18, y18, LTGREY);
  delay(80);
  tft.drawPixel(x17, y17, LTGREY);
  delay(80);
  tft.drawPixel(x16, y16, LTGREY);
  delay(80);
  tft.drawPixel(x15, y15, LTGREY);
  delay(80);
  tft.drawPixel(x14, y14, LTGREY);
  delay(80);
  tft.drawPixel(x13, y13, LTGREY);
  delay(80);
  tft.drawPixel(x12, y12, LTGREY);
  delay(80);  
  tft.drawPixel(x11, y11, LTGREY);
  delay(80);
  tft.drawPixel(x10, y10, LTGREY);
  delay(80);
  tft.drawPixel(x9, y9, LTGREY);
  delay(80);
  tft.drawPixel(x8, y8, LTGREY);
  delay(80);
  tft.drawPixel(x7, y7, LTGREY);
  delay(80);
  tft.drawPixel(x6, y6, LTGREY);
  delay(80);
  tft.drawPixel(x5, y5, LTGREY);
  delay(80);
  tft.drawPixel(x4, y4, LTGREY);
  delay(80);
  tft.drawPixel(x3, y3, LTGREY);
  delay(80);
  tft.drawPixel(x2, y2y, LTGREY);
  delay(80);
  tft.drawPixel(x1, y1y, LTGREY);
  delay(80);
  tft.drawPixel(x0, y0y, LTGREY);
  delay(80);
  tft.drawPixel(xprev, yprev, LTGREY);
  delay(40);  

//  tft.drawLine(74, 225, 105, 225, WHITE);
//  tft.drawLine(87, 228, 105, 228, WHITE);
//  tft.drawLine(95, 230, 105, 230, WHITE);

  tft.drawFastHLine(75, 225, 30, LTGREY);
  tft.drawFastHLine(85, 228, 20, LTGREY);
  tft.drawFastHLine(98, 231, 7, LTGREY);
  delay(60);
  
  tft.setCursor(108, 225);
//  tft.setTextColor(uint16_t color, uint16_t backgroundcolor);
  tft.setTextColor(LTGREY);
  tft.setTextSize(1);
  tft.setTextWrap(false);
  tft.print("DVIC");  
  delay(60); 

  tft.drawFastHLine(134, 225, 30, LTGREY);
  tft.drawFastHLine(134, 228, 20, LTGREY);
  tft.drawFastHLine(134, 231, 7, LTGREY);
  delay(80);
  
  tft.drawCircle(120, 120, 119, WHITE);
//  tft.drawCircle(120, 120, 118, DKBLUE);
  delay(60);
  
  tft.drawRect(25, 49, 190, 143, DKTEAL);     // Rectangle intérieur centré  

//  tft.drawRect(48, 24, 144, 192, DKGREY);     // Rectangle extérieur centré
//  tft.drawRect(24, 48, 192, 144, DKGREY);     // Rectangle extérieur centré
//  tft.drawRect(35, 35, 170, 170, DKMAGENTA);  // Grand carré centré, marge 0 pixel
//  tft.drawRect(40, 40, 160, 160, DKGREY);     // Carré centré avec marge 10 pixels
//  tft.drawLine(48, 24, 192, 216, LTBLUE);    // Diagonale du rectangle extérieur
//  tft.drawLine(192, 24, 48, 216, LTBLUE);    // Diagonale du rectangle extérieur
//  tft.drawLine(0, 0, 240, 240, DKMAGENTA);     // Diagonale du grand carré
//  tft.drawLine(0, 240, 240, 0, DKMAGENTA);     // Diagonale du grand carré
}

void loop(void) {

}



unsigned long testLines(uint16_t color) {
  unsigned long start, t;
//  drawPixel(uint16_t x, uint16_t y, uint16_t color);
  tft.drawPixel(120, 50, DKYELLOW);  
  tft.drawPixel(121, 50, color);  
  tft.drawPixel(119, 50, color);  
  tft.drawPixel(120, 49, color);  
  tft.drawPixel(120, 51, color);  

}



//  tft.drawFastVLine(x0, y0, lengthx, color);
//  tft.drawFastHLine(x0, y0, lengthy, color);
//  tft.drawFastHLine(10, 120, 220, color);

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
