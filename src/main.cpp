#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <WiFi.h>

// For NTP
#include "time.h"


// Resources
#include <numbers.h> //bytecode for digits

//Veiwers create your own secrets.h that currently holds wifi credentials to get time using NTP
#include <secrets.h> //passwords

#define SDA 21
#define SCL 22

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1

//NTP stuff
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 19800; //Indian Standard Time = GMT+05:30
const int daylightOffset_sec = 0; //IST doesnt observe daylight saving time or other seasonal adjustments

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void connect2Wifi(){
  // Connect to Wi-Fi
  display.clearDisplay();
  display.println("Connecting to wifi");
  //WIFI_SSID and WIFI_PASSWORD are secret variables
  display.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    display.print(".");
  }
  display.println("");
  //display.clearDisplay();
  display.println("Connection successful");
}

void drawWatchFace(){
  //code to draw and update watchface
	int i;
  display.clearDisplay();
	for (i=0; i<10; i++){
		display.clearDisplay();
  	display.drawBitmap(18, 19, number_array[i], 20, 25, 1);
		display.drawBitmap(40, 19, number_array[i], 20, 25, 1);
		display.drawBitmap(67, 19, number_array[i], 20, 25, 1);
		display.drawBitmap(88, 19, number_array[i], 20, 25, 1);
  	display.display();
		delay(1000);
		if (i==9)
			i=-1;
	}
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
  
  // Connect to Wi-Fi
  connect2Wifi();

  delay(2000);
  display.clearDisplay();
  // delay(1000);
  // drawWatchFace();
   
}

void loop(){
  //Empty
}

