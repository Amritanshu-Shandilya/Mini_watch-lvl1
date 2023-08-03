#include <Arduino.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>

#include <numbers.h>

#define SDA 21
#define SCL 22

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1


// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawWatchFace(){
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

  delay(2000);
  display.clearDisplay();
  delay(1000);
  drawWatchFace();
   
}

void loop(){
  //Empty
}

