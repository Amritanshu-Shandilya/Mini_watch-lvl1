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
void setupText(){
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(WHITE);        // Draw white text
  display.setCursor(0,0);             // Start at top-left corner
}

void connect2Wifi(){
  // Connect to Wi-Fi
  setupText();
  display.clearDisplay();
<<<<<<< HEAD
  display.println(F("Connecting to wifi"));
  display.display();
  WiFi.begin(ssid, password);
=======
  display.println("Connecting to wifi");
  //WIFI_SSID and WIFI_PASSWORD are secret variables
  display.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
>>>>>>> bd82755af4165a84f00494df2226095d193e92fa
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); 
  }
  display.clearDisplay();
  display.println(F("Connection successful"));
  display.display();
}

void drawWatchFace(){
  //code to draw and update watchface
	int i;
  setupText();
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
  //display.clearDisplay();
  
  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
  display.println(F("Screen setup done"));
  display.display();

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

