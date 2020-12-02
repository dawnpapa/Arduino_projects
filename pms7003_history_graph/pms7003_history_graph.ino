
#include <SPI.h>
//#include <SD.h>
#include <TFT_eSPI.h> 
#include "PMS.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(4, 12); // D2RX, D6TX

PMS pms(mySerial);
PMS::DATA data;


#include "alert.h" // Out of range alert icon
#include "colors.h" 

TFT_eSPI tft = TFT_eSPI();

// this is the only external variable used by the graph
// it's a flat to draw the coordinate system only on the first pass
boolean display1 = true;
boolean newds1 = true;
boolean display2 = true;
boolean display3 = true;
boolean display4 = true;
boolean display5 = true;
boolean display6 = true;
boolean display7 = true;
boolean display8 = true;
boolean display9 = true;
double ox , oy1, oy2, oy3;
String ods;
//int index;

double dust10[101];
double dust25[101];
double dust1[101];


boolean range_error = 0;


void setup() {

  for(int i=0;i<100;i++){
    dust10[i] = 0;
    dust25[i] = 0;
    dust1[i] = 0;
  }
  
  pinMode(D1,OUTPUT);
  digitalWrite(D1,HIGH); 
  tft.init();
  tft.setRotation(3);
  tft.setSwapBytes(true);
  tft.fillScreen(BLACK); 
  
  Serial.begin(115200);
  mySerial.begin(9600);  // D2,D6 pin on ESP-12E Development Board
  pms.passiveMode();    // Switch to passive mode



}


void loop(void) {
  
  double x, y1, y2, y3;
  Serial.println("\nWaking up, wait 30 seconds for stable readings...");
  pms.wakeUp();
  delay(20000);

  Serial.println("Send read request...");
  pms.requestRead();

  Serial.println("Wait max. 1 second for read...");
  for(int i=0; i<10; i++){
    if (pms.readUntil(data))
    {
      Serial.print("PM 1.0 (ug/m3): ");
      dust1[0]=data.PM_AE_UG_1_0;
      Serial.println(dust1[0]);
  
      Serial.print("PM 2.5 (ug/m3): ");
      dust25[0]=data.PM_AE_UG_2_5;
      Serial.println(dust25[0]);
  
      Serial.print("PM 10.0 (ug/m3): ");
      dust10[0]=data.PM_AE_UG_10_0;
      Serial.println(dust10[0]);
      break;
    }
    else
    {
      Serial.println("No data.");
      dust1[0]=0;dust25[0]=0;dust10[0]=0;
    }
  }
  Serial.println("Going to sleep for 60 seconds.");
  pms.sleep();

  ////history graph
  int interval = 2; //measurement interval (min)
  int noOfdata =20;
  int xpos = 50, ypos = 5, gap = 6, radius = 56;
  
  tft.fillScreen(BLACK);
  tft.setTextSize(2);
  tft.setTextColor(YELLOW, BLACK);
  tft.setCursor(400, 50);
  tft.print(" PM10");//tft.print((int)dust10[0]);
  tft.setCursor(400, 70);
  tft.setTextColor(CYAN, BLACK);
  tft.print(" PM2.5");//tft.print((int)dust25[0]);
  tft.setCursor(400, 90);
  tft.setTextColor(GREEN, BLACK);
  tft.print(" PM1.0");//tft.print((int)dust1[0]);
  
  xpos = gap +ringMeter(dust10[0], 0, 130, xpos, ypos, radius, "PM10", BLUE2RED); // Draw analogue meter
  xpos = gap +ringMeter(dust25[0], 0, 80, xpos, ypos, radius, "PM2.5", BLUE2RED); // Draw analogue meter
  xpos = gap +ringMeter(dust1[0], 0, 80, xpos, ypos, radius, "PM1.0", BLUE2RED); // Draw analogue meter
  
  
  for (x = 0; x < noOfdata+1; x++){
    y1 = dust10[(int)x];
    y2 = dust25[(int)x];
    y3 = dust1[(int)x];
    Graph3y(tft, x*interval, y1, y2, y3, 40, 290, 410, 180, interval*noOfdata, 0, -interval, 0, 100, 10, "", "Time(min)", "ug/m3", 
    LTGREY, RED, YELLOW, CYAN, GREEN, WHITE, BLACK,x);
    
  }

  for(int i=100;i>0;i--){
    dust10[i]=dust10[i-1];
    dust25[i]=dust25[i-1];
    dust1[i]=dust1[i-1];
    
  }

  delay(60000*interval);
  

}

/*
  function to draw a cartesian coordinate system and plot whatever data you want
  just pass x and y and the graph will be drawn
  huge arguement list
  &d name of your display object
  x = x data point
  y = y datapont
  gx = x graph location (lower left)
  gy = y graph location (lower left)
  w = width of graph
  h = height of graph
  xlo = lower bound of x axis
  xhi = upper bound of x asis
  xinc = division of x axis (distance not count)
  ylo = lower bound of y axis
  yhi = upper bound of y asis
  yinc = division of y axis (distance not count)
  title = title of graph
  xlabel = x asis label
  ylabel = y asis label
  gcolor = graph line colors
  acolor = axi ine colors
  pcolor = color of your plotted data
  tcolor = text color
  bcolor = background color
  &redraw = flag to redraw graph on fist call only
*/


void Graph3y(TFT_eSPI &d, double x, double y1,double y2,double y3,double gx, double gy, double w, double h, double xlo, 
double xhi, double xinc, double ylo, double yhi, double yinc, String title, String xlabel, String ylabel, 
unsigned int gcolor, unsigned int acolor, unsigned int p1color, unsigned int p2color, unsigned int p3color, 
unsigned int tcolor, unsigned int bcolor, unsigned int fData) {

  double ydiv, xdiv;
  // initialize old x and old y in order to draw the first point of the graph
  // but save the transformed value
  // note my transform funcition is the same as the map function, except the map uses long and we need doubles
  //static double ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
  //static double oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  int i;
  double temp;
  int rot, newrot;
  
    ////// draw y scale
    for ( i = (int)ylo; i <= yhi; i += yinc) {
      // compute the transform
      temp =  (i - ylo) * (gy - h - gy) / (yhi - ylo) + gy;

      if (i == 0) {
        d.drawLine(gx, temp, gx + w, temp, acolor);
      }
      else {
        d.drawLine(gx, temp, gx + w, temp, gcolor);
      }

      d.setTextSize(1);
      d.setTextColor(tcolor, bcolor);
      d.setCursor(gx - 20, temp);
      // precision is default Arduino--this could really use some format control
      d.println(i);
    }
    
    /////// draw x scale
    for (i = (int)xlo; i >= xhi; i += (int)xinc) {

      // compute the transform

      temp =  (i - xlo) * ( w) / (xhi - xlo) + gx;
      if (i == 0) {
        d.drawLine(temp, gy, temp, gy - h, acolor);
      }
      else {
        d.drawLine(temp, gy, temp, gy - h, gcolor);
      }

      d.setTextSize(1);
      d.setTextColor(tcolor, bcolor);
      d.setCursor(temp, gy + 10);
      // precision is default Arduino--this could really use some format control
      d.println(i);
    }

    ///////now draw the labels
    d.setTextSize(2);
    d.setTextColor(tcolor, bcolor);
    d.setCursor(gx , gy - h - 30);
    d.println(title);

    d.setTextSize(1);
    d.setTextColor(acolor, bcolor);
    d.setCursor(gx , gy + 20);
    d.println(xlabel);

    d.setTextSize(1);
    d.setTextColor(acolor, bcolor);
    d.setCursor(gx - 30, gy - h - 10);
    d.println(ylabel);


  // //첫번째 데이터에 이전 데이터와 선긋지 않도록 oxy를  xy값과 일치 시킴 
  if (fData == 0) {
    ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
    oy1 = (y1 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    oy2 = (y2 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    oy3 = (y3 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  }

  //graph drawn now plot the data
  // the entire plotting code are these few lines...
  // recall that ox and oy are initialized as static above
  x =  (x - xlo) * ( w) / (xhi - xlo) + gx;
  y1 =  (y1 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  y2 =  (y2 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  y3 =  (y3 - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  d.drawLine(ox, oy1, x, y1, p1color);
  d.drawLine(ox, oy2, x, y2, p2color);
  d.drawLine(ox, oy3, x, y3, p3color);
  d.drawLine(ox, oy1 + 1, x, y1 + 1, p1color);
  d.drawLine(ox, oy1 - 1, x, y1 - 1, p1color);
  d.drawLine(ox, oy2 + 1, x, y2 + 1, p2color);
  d.drawLine(ox, oy2 - 1, x, y2 - 1, p2color);
  d.drawLine(ox, oy3 + 1, x, y3 + 1, p3color);
  d.drawLine(ox, oy3 - 1, x, y3 - 1, p3color);
  ox = x;
  oy1 = y1; oy2 = y2; oy3 = y3;

}

/*
  End of graphing functioin
*/
// #########################################################################
//  Draw the meter on the screen, returns x coord of righthand side
// #########################################################################
int ringMeter(int value, int vmin, int vmax, int x, int y, int r, const char *units, byte scheme)
{
  // Minimum value of r is about 52 before value text intrudes on ring
  // drawing the text first is an option
  
  x += r; y += r;   // Calculate coords of centre of ring

  int w = r / 3;    // Width of outer ring is 1/4 of radius
  
  int angle = 150;  // Half the sweep angle of meter (300 degrees)

  int v = map(value, vmin, vmax, -angle, angle); // Map the value to an angle v

  byte seg = 3; // Segments are 3 degrees wide = 100 segments for 300 degrees
  byte inc = 6; // Draw segments every 3 degrees, increase to 6 for segmented ring

  // Variable to save "value" text colour from scheme and set default
  int colour = TFT_BLUE;
 
  // Draw colour blocks every inc degrees
  for (int i = -angle+inc/2; i < angle-inc/2; i += inc) {
    // Calculate pair of coordinates for segment start
    float sx = cos((i - 90) * 0.0174532925);
    float sy = sin((i - 90) * 0.0174532925);
    uint16_t x0 = sx * (r - w) + x;
    uint16_t y0 = sy * (r - w) + y;
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;

    // Calculate pair of coordinates for segment end
    float sx2 = cos((i + seg - 90) * 0.0174532925);
    float sy2 = sin((i + seg - 90) * 0.0174532925);
    int x2 = sx2 * (r - w) + x;
    int y2 = sy2 * (r - w) + y;
    int x3 = sx2 * r + x;
    int y3 = sy2 * r + y;

    if (i < v) { // Fill in coloured segments with 2 triangles
      switch (scheme) {
        case 0: colour = TFT_RED; break; // Fixed colour
        case 1: colour = TFT_GREEN; break; // Fixed colour
        case 2: colour = TFT_BLUE; break; // Fixed colour
        case 3: colour = rainbow(map(i, -angle, angle, 0, 127)); break; // Full spectrum blue to red
        case 4: colour = rainbow(map(i, -angle, angle, 70, 127)); break; // Green to red (high temperature etc)
        case 5: colour = rainbow(map(i, -angle, angle, 127, 63)); break; // Red to green (low battery etc)
        default: colour = TFT_BLUE; break; // Fixed colour
      }
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, colour);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, colour);
      //text_colour = colour; // Save the last colour drawn
    }
    else // Fill in blank segments
    {
      tft.fillTriangle(x0, y0, x1, y1, x2, y2, TFT_GREY);
      tft.fillTriangle(x1, y1, x2, y2, x3, y3, TFT_GREY);
    }
  }
  // Convert value to a string
  char buf[10];
  byte len = 3; if (value > 999) len = 5;
  dtostrf(value, len, 0, buf);
  buf[len] = ' '; buf[len+1] = 0; // Add blanking space and terminator, helps to centre text too!
  // Set the text colour to default
  tft.setTextSize(1);

  if (value<vmin || value>vmax) {
    drawAlert(x,y+90,50,1);
  }
  else {
    drawAlert(x,y+90,50,0);
  }

  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  // Uncomment next line to set the text colour to the last segment value!
  tft.setTextColor(colour, TFT_BLACK);
  tft.setTextDatum(MC_DATUM);
  // Print value, if the meter is large then use big font 8, othewise use 4
  if (r > 84) {
    tft.setTextPadding(55*3); // Allow for 3 digits each 55 pixels wide
    tft.drawString(buf, x, y, 8); // Value in middle
  }
  else {
    tft.setTextPadding(3 * 14); // Allow for 3 digits each 14 pixels wide
    tft.drawString(buf, x, y, 4); // Value in middle
  }
  tft.setTextSize(1);
  tft.setTextPadding(0);
  // Print units, if the meter is large then use big font 4, othewise use 2
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  if (r > 84) tft.drawString(units, x, y + 60, 4); // Units display
  else tft.drawString(units, x, y + 15, 2); // Units display

  // Calculate and return right hand side x coordinate
  return x + r;
}

void drawAlert(int x, int y , int side, boolean draw)
{
  if (draw && !range_error) {
    drawIcon(alert, x - alertWidth/2, y - alertHeight/2, alertWidth, alertHeight);
    range_error = 1;
  }
  else if (!draw) {
    tft.fillRect(x - alertWidth/2, y - alertHeight/2, alertWidth, alertHeight, TFT_BLACK);
    range_error = 0;
  }
}

// #########################################################################
// Return a 16 bit rainbow colour
// #########################################################################
unsigned int rainbow(byte value)
{
  // Value is expected to be in range 0-127
  // The value is converted to a spectrum colour from 0 = blue through to 127 = red

  byte red = 0; // Red is the top 5 bits of a 16 bit colour value
  byte green = 0;// Green is the middle 6 bits
  byte blue = 0; // Blue is the bottom 5 bits

  byte quadrant = value / 32;

  if (quadrant == 0) {
    blue = 31;
    green = 2 * (value % 32);
    red = 0;
  }
  if (quadrant == 1) {
    blue = 31 - (value % 32);
    green = 63;
    red = 0;
  }
  if (quadrant == 2) {
    blue = 0;
    green = 63;
    red = value % 32;
  }
  if (quadrant == 3) {
    blue = 0;
    green = 63 - 2 * (value % 32);
    red = 31;
  }
  return (red << 11) + (green << 5) + blue;
}

// #########################################################################
// Return a value in range -1 to +1 for a given phase angle in degrees
// #########################################################################
float sineWave(int phase) {
  return sin(phase * 0.0174532925);
}


//====================================================================================
// This is the function to draw the icon stored as an array in program memory (FLASH)
//====================================================================================

// To speed up rendering we use a 64 pixel buffer
#define BUFF_SIZE 64

// Draw array "icon" of defined width and height at coordinate x,y
// Maximum icon size is 255x255 pixels to avoid integer overflow

void drawIcon(const unsigned short* icon, int16_t x, int16_t y, int8_t width, int8_t height) {

  uint16_t  pix_buffer[BUFF_SIZE];   // Pixel buffer (16 bits per pixel)

  tft.startWrite();

  // Set up a window the right size to stream pixels into
  tft.setAddrWindow(x, y, width, height);

  // Work out the number whole buffers to send
  uint16_t nb = ((uint16_t)height * width) / BUFF_SIZE;

  // Fill and send "nb" buffers to TFT
  for (int i = 0; i < nb; i++) {
    for (int j = 0; j < BUFF_SIZE; j++) {
      pix_buffer[j] = pgm_read_word(&icon[i * BUFF_SIZE + j]);
    }
    tft.pushColors(pix_buffer, BUFF_SIZE);
  }

  // Work out number of pixels not yet sent
  uint16_t np = ((uint16_t)height * width) % BUFF_SIZE;

  // Send any partial buffer left over
  if (np) {
    for (int i = 0; i < np; i++) pix_buffer[i] = pgm_read_word(&icon[nb * BUFF_SIZE + i]);
    tft.pushColors(pix_buffer, np);
  }

  tft.endWrite();
}

