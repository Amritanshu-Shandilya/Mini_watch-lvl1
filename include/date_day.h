/*Code for displaying date, time and day of week*/
#include "numbers.h"

void drawWatchFace(int h1, int h2, int m1, int m2){
  //code to draw and update watchface
    display.clearDisplay();
    display.drawBitmap(18, 19, number_array[h1], 20, 25, 1);
	display.drawBitmap(40, 19, number_array[h2], 20, 25, 1);
	display.drawBitmap(67, 19, number_array[m1], 20, 25, 1);
	display.drawBitmap(88, 19, number_array[m2], 20, 25, 1);
    display.display();
	delay(1000);
}

void displayDay(int w_day){
    /*Code for displaying day of week on the screen.*/
    if (w_day == 0){

        display.println("Sunday");
    }
    else if (w_day == 1){
        display.println("Monday");
    }
    else if (w_day == 2){
        display.println("Tuesday");
    }
    else if (w_day == 3){
        display.println("Wednessday");
    }
    else if (w_day == 4){
        display.println("Thursday");
    }
    else if (w_day == 5){
        display.println("Friday");
    }
    else if (w_day == 6){
        display.println("Saturday");
    }
    else if (w_day == 7){
        display.println("Sunday");
    }
}


void display_hr(int h,int m){
    int h1,m1,h2,m2;
    if (h<9){
        h1 = 0;
        h2 = h;
    }
    else {
        h1 = h / 10;
        h2 = h % 10;
    }
    if (m<9){
        m1 = 0;
        m2 = m;
    }
    else{
        m1 = m / 10;
        m2 = m % 10;
    }
    drawWatchFace(h1, h2, m1, m2);
}