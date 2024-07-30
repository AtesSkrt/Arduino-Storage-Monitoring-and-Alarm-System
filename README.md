# Arduino-Storage-Monitoring-and-Alarm-System
This Arduino project can measure the fill level of a container using a distance sensor on the top. It also measures the temperature and humidity inside using a temperature and humidity sensor. The distance sensor works with sound, and it calculates the speed of sound in the air based on the temperature and humidity readings, allowing for more accurate measurements.
The system includes a rotary encoder, two buttons, and an LCD screen. Alarms can be set for desired values (fill level, temperature, humidity). The desired values and set alarms can be viewed on the LCD screen.
The system has three modes:
1.	Monitoring Mode:
•	The measured values are displayed on the screen. Pressing the second button shows the next value on the screen. Pressing the first button switches to the next mode.
2.	Alarm Setting Mode:
•	Alarms can be set for the displayed value. As the rotary encoder is turned, the number increases and eventually loops back to the beginning. Pressing the second button shows the next value to set an alarm for. Pressing the first button switches to the next mode.
3.	View Set Alarms Mode:
•	This mode shows which value's alarm is set to which level. Pressing the second button does nothing. Pressing the first button returns to Monitoring Mode.

Parts:
-	1 buzzer
-	1 rotary encoder
-	1 Hc-sr04 ultrasonic distance sensor
-	1 DHT22/11 temperature and humidity sensor
-	2 push buttons
-	1 large breadboard
-	1 arduino uno
-	1 16x2 I2C LCD display screen


Circuit Design:
![image](https://github.com/user-attachments/assets/2b3e8b91-0766-4097-a28e-ace3fdcee4c7)


Images of the finished Project:
![image](https://github.com/user-attachments/assets/a78bf670-5b02-4b29-8908-c69ba054f5b1)
![image](https://github.com/user-attachments/assets/0f01657f-b096-495b-8a06-dff05cf97f4b)
![image](https://github.com/user-attachments/assets/9ffe1dbc-15f5-4c12-b0ca-39049064dc17)
![image](https://github.com/user-attachments/assets/3d225e65-b4d9-4749-b412-76ebc3c55483)
![image](https://github.com/user-attachments/assets/33997578-2f89-41c4-927f-3c6e46df3b25)
![image](https://github.com/user-attachments/assets/2d48bcd4-f8a0-4555-837a-0692cd0d3b4c)
![image](https://github.com/user-attachments/assets/4d3f46b5-8dbf-4125-bf79-099bc39a14f0)
![image](https://github.com/user-attachments/assets/b386379b-81e2-4b0f-9942-1b79c066549a)
![image](https://github.com/user-attachments/assets/2dfe38c3-a1e2-496c-862c-82bef66e15b1)


Used Libraries:

- Easy ultrasonic: https://github.com/SpulberGeorge/EasyUltrasonic
- DHT.h: https://github.com/adafruit/DHT-sensor-library
- Blinkenlight : https://github.com/tfeldmann/Arduino-Blinkenlight

