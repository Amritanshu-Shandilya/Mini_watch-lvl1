/*Code for displaying date, time and day of week*/

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