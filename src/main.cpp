#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFi.h>

#include <time.h>



// Resources
#include <numbers.h> //bytecode for digits

//Veiwers create your own secrets.h that currently holds wifi credentials to get time using NTP
#include "secrets.h" //passwords


#define SDA 21
#define SCL 22

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1

// Variables to save date and time
int GMT_offset = 19800;
int daylight_offset = 0;

int h,m,s,w;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
//#include "date_day.h" //including this after the display() object is created because diplay() is used in this header file

void watch_init()
{
  /*Focuses on display screen during booting*/
  display.clearDisplay();
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);
  display.println(F("Details :"));
  display.setCursor(38,17);
  display.println(F("On Github"));
  display.display();
  display.setCursor(0,25);             // Start at top-left corner
  display.println(F("@Amritanshu-Shandilya"));
  display.setCursor(38,40);
  display.println(F("Mini-watch"));
  display.display();
  delay(3000);
}




// void setupText(int size){
//   // Function to be called for setting size color and cursor position
//   display.setTextSize(size);             // Normal 1:1 pixel scale
//   display.setTextColor(WHITE);        // Draw white text
//   display.setCursor(0,0);             // Start at top-left corner
// }

// void drawWatchFace(int h1, int h2, int m1, int m2){
//   //code to draw and update watchface
// 	int i;
//   setupText(1);
//   display.clearDisplay();
// 	display.clearDisplay();
//   display.drawBitmap(18, 19, number_array[h1], 20, 25, 1);
// 	display.drawBitmap(40, 19, number_array[h2], 20, 25, 1);
// 	display.drawBitmap(67, 19, number_array[m1], 20, 25, 1);
// 	display.drawBitmap(88, 19, number_array[m2], 20, 25, 1);
//   display.display();
// 	delay(1000);
// }

// void connect2Wifi(){
//   // Connect to Wi-Fi
//   setupText(1);
//   display.clearDisplay();
//   display.println(F("Connecting to wifi"));
//   display.display();
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500); 
//   }
//   display.clearDisplay();
//   display.println(F("Connection successful"));
//   display.println(WiFi.localIP());
//   display.display();
// }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //display.clearDisplay();
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    // Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  watch_init();

  // // Connect to Wi-Fi
  // connect2Wifi();

  // display.clearDisplay();
  // // delay(1000);
  // // drawWatchFace();

  // configTime(GMT_offset, daylight_offset, "pool.ntp.org","time.nist.gov");
 
}

void loop(){

  // time_t rawtime = time(nullptr);
  // struct tm* timeinfo = localtime(&rawtime);

  // h = timeinfo -> tm_hour;
  // m = timeinfo -> tm_min;
  // s = timeinfo -> tm_sec;
  // w = timeinfo -> tm_wday;

  // display_hr(h,m);

  // // display.setCursor(0,40);
  // // displayDay(w);
  // // display.display();

  
  // delay(1000); 

}

