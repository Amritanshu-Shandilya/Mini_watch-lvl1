# Mini_watch LVL1
A smartwatch project based on 0.96in OLED display and ESP32. This Embodiment of the project was an erly version of the entire project.

This version of the project successfully displays the time as per IST on the screen using the Network Time Protocol in which the time is fetched from the NTP servers using WiFi. There is a huge fault in this implementation due to which the development of this iteration has been haulted. Those problems are :
1. Use of NTP keeps the WiFi on always and this will reduce the backup time of the battery powered  verison of the project.
2. The NTP needs some time to fetch and calculate IST before which it displays 05:30 on the screen for 1-2 seconds. To solve this I had to manually include a time delay of few seconds which further reduces the performance.

### NOTE : 
  In this version I am fetching other data but I am not displaying it due to screen size constraints. But it is possible to display all of that if the font is changed or a new watch face is designed with more empty space. 

If you want to run this one on your device use the following circuit diagram to build your own smartwatch:
[Circuit Diagram](https://wokwi.com/projects/371956477034889217)

Happy Building.
