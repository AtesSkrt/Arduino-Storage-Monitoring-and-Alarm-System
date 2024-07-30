#include <EasyUltrasonic.h>
#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Blinkenlight.h>

// Define LCD address (modify if different)
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define DHTPIN 2  // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11 // The type of DHT sensor that is used

#define TRIGPIN 5  // Digital pin connected to the trig pin of the ultrasonic sensor
#define ECHOPIN 6  // Digital pin connected to the echo pin of the ultrasonic sensor

#define scbutton 11
#define rotbutton 10
#define outputA 8
#define outputB 9

int counter = 99;
int tempalarm = 99;
int humalarm = 99;
int volalarm = 999;
int peralarm = 99;

int aState;
int aLastState;
int mode = 2;
int alarmto = 1;

int buzzer = 13;

EasyUltrasonic ultrasonic; // Create the ultrasonic object
DHT dht(DHTPIN, DHTTYPE);  // Initialize DHT sensor

void setup() {
  pinMode (outputA,INPUT);
  pinMode (outputB,INPUT);
  pinMode(rotbutton, INPUT);
  pinMode(scbutton, INPUT);

  Serial.begin(9600);
  ultrasonic.attach(TRIGPIN, ECHOPIN);
  dht.begin();
  lcd.init();
  lcd.backlight();
  pinMode(buzzer, OUTPUT);

  aLastState = digitalRead(outputA); 

}

void loop() {
    float temp = dht.readTemperature();
    float hum = dht.readHumidity();
    float distance = ultrasonic.getPreciseDistanceCM(temp, hum);
    float su = 15-distance;
    float vol = (su*10) * 7.69;
    float per = (100/13)*su;


  if(mode == 6){
    //show alarms
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("temp:");
    lcd.print(tempalarm);
    lcd.print(" hum:");
    lcd.print(humalarm);
    lcd.setCursor(0, 1);
    lcd.print("vol:");
    lcd.print(volalarm);
    lcd.print(" per:");
    lcd.print(peralarm);

    delay(200);

    if (digitalRead(rotbutton) == HIGH) {
    mode = 2;
    delay(200);
    lcd.clear();
    }

  }
  

  if(mode == 2){
    //show temperature

    lcd.setCursor(0, 0);
    lcd.print("temperature:");
    lcd.setCursor(0, 1);
    lcd.print((int)temp);
    lcd.print("C");
    delay(200);
    lcd.clear();

    if (digitalRead(scbutton) == HIGH) {
    mode = 3;
    delay(200);
    }
    if (digitalRead(rotbutton) == HIGH) {
    mode = 1;
    delay(200);
    lcd.clear();
    }

  

    if ((int(temp) >= tempalarm - 1 && int(temp) <= tempalarm + 1) ||
    (int(hum) > humalarm - 1 && int(hum) < humalarm + 1) ||
    (int(vol) >= volalarm - 30 && int(vol) <= volalarm + 30) ||
    (int(per) >= peralarm - 1 && int(per) <= peralarm + 1)){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }else{
    digitalWrite(buzzer, LOW);
  }

  }
  if(mode == 3){
    //show humidity

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("humidity:");
    lcd.print((int)hum);
    lcd.print("%");
    delay(200);

    if (digitalRead(scbutton) == HIGH) {
    mode = 4;
    delay(200);
    }
    if (digitalRead(rotbutton) == HIGH) {
    mode = 1;
    delay(200);
    lcd.clear();
  }

  if ((int(temp) >= tempalarm - 1 && int(temp) <= tempalarm + 1) ||
    (int(hum) > humalarm - 1 && int(hum) < humalarm + 1) ||
    (int(vol) >= volalarm - 30 && int(vol) <= volalarm + 30) ||
    (int(per) >= peralarm - 1 && int(per) <= peralarm + 1)){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }else{
    digitalWrite(buzzer, LOW);
  }

  }
  if(mode == 4){
    //show volume

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("volume:");
    lcd.print((int)vol);
    lcd.print("ml");
    delay(200);

    if (digitalRead(scbutton) == HIGH) {
    mode = 5;
    delay(200);
    }
    if (digitalRead(rotbutton) == HIGH) {
    mode = 1;
    delay(200);
    lcd.clear();
  }

  if ((int(temp) >= tempalarm - 1 && int(temp) <= tempalarm + 1) ||
    (int(hum) > humalarm - 1 && int(hum) < humalarm + 1) ||
    (int(vol) >= volalarm - 30 && int(vol) <= volalarm + 30) ||
    (int(per) >= peralarm - 1 && int(per) <= peralarm + 1)){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }else{
    digitalWrite(buzzer, LOW);
  }

  }
  if(mode == 5){
    //show fill percentage

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("persentage:");
    lcd.print((int)per);
    lcd.print("%");
    delay(200);

    if (digitalRead(scbutton) == HIGH) {
    mode = 2;
    delay(200);
    }
    if (digitalRead(rotbutton) == HIGH) {
    mode = 1;
    delay(200);
    lcd.clear();
  }

  if ((int(temp) >= tempalarm - 1 && int(temp) <= tempalarm + 1) ||
    (int(hum) > humalarm - 1 && int(hum) < humalarm + 1) ||
    (int(vol) >= volalarm - 30 && int(vol) <= volalarm + 30) ||
    (int(per) >= peralarm - 1 && int(per) <= peralarm + 1)){
    digitalWrite(buzzer, HIGH);
    delay(200);
    digitalWrite(buzzer, LOW);
    delay(200);
  }else{
    digitalWrite(buzzer, LOW);
  }

  }


  if(mode == 0){
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  float distance = ultrasonic.getPreciseDistanceCM(temp, hum);
  float su = 15-distance;
  float vol = (su*10) * 7.69;
  float per = (100/13)*su;


  // Print humidity and temperature
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("hum:");
  lcd.print((int)hum);
  lcd.print("%,temp:");
  lcd.print((int)temp);
  lcd.print("C");

  // Print distance on the second row
  lcd.setCursor(0, 1);
  lcd.print("Volume:");
  lcd.print(per);
  lcd.print("%");

  Serial.println(int(hum));
  Serial.println(int(temp));
  Serial.print(distance);

  if(int(temp)>=counter){
    digitalWrite(buzzer, HIGH);
    delay(200);        
    digitalWrite(buzzer, LOW);    
    delay(200);
  }else{
    digitalWrite(buzzer, LOW);
  }
  

  if (digitalRead(rotbutton) == HIGH) {
    mode = 1;
    delay(200);
    lcd.clear();
  }
  delay(200);

  }
  else if(mode == 1){

    if(alarmto == 1){
      //set alarm to temperature

      lcd.setCursor(0, 0);
      lcd.print("set alarm temp:");
      aState = digitalRead(outputA);

      if (aState != aLastState){
        if (digitalRead(outputB) != aState){
          tempalarm ++;
          lcd.setCursor(0, 1);
          lcd.print(tempalarm);
          
          if(tempalarm > 100){
            lcd.clear();
            tempalarm = -50;
        }
    }
    else{
      tempalarm++;
      lcd.setCursor(0, 1);
      lcd.print(tempalarm);
      
      if(tempalarm > 100){
        lcd.clear();
        tempalarm = -50;
      }else if(tempalarm == 0 || tempalarm == -9){
        lcd.clear();
      }
    }
  aLastState = aState;  
  }

  lcd.setCursor(5, 1);
  lcd.print("degrees");

  if (digitalRead(scbutton) == HIGH) {
    lcd.clear();
    alarmto = 2;
    delay(200);
  }
  if (digitalRead(rotbutton) == HIGH) {
    mode = 6;
    delay(200);
  }
  //set alarm to temperature ends here
    }

    if(alarmto == 2){
      //set alarm to humidity

      lcd.setCursor(0, 0);
      lcd.print("set alarm hum:");
      aState = digitalRead(outputA);

      if (aState != aLastState){
    if (digitalRead(outputB) != aState){
      humalarm++;
      lcd.setCursor(0, 1);
      lcd.print(humalarm);
      
      if(humalarm > 100){
        lcd.clear();
        humalarm = 0;
      }
    }
    else{
      humalarm++;
      lcd.setCursor(0, 1);
      lcd.print(humalarm);
      if(humalarm > 100){
        lcd.clear();
        humalarm = 0;
      }
    }
  aLastState = aState;
  }

  lcd.setCursor(5, 1);
  lcd.print("percent");

  if (digitalRead(scbutton) == HIGH) {
    lcd.clear();
    alarmto = 3;
    delay(200);
  }
  if (digitalRead(rotbutton) == HIGH) {
    mode = 6;
    delay(200);
  }
  //set alarm to humidity ends here
    }
    if(alarmto == 3){
      //vol ayarla

      lcd.setCursor(0, 0);
      lcd.print("set alarm vol:");
      aState = digitalRead(outputA);

      if (aState != aLastState){
    if (digitalRead(outputB) != aState){
      volalarm += 10;
      lcd.setCursor(0, 1);
      lcd.print(volalarm);
  
      if(volalarm > 1000){
        lcd.clear();
        volalarm = 0;
      }
    }
    else{
      volalarm += 10;
      lcd.setCursor(0, 1);
      lcd.print(volalarm);

      if(volalarm > 1000){
        lcd.clear();
        volalarm = 0;
      }
    }
  aLastState = aState;
  }

  lcd.setCursor(5, 1);
  lcd.print("ml");

  if (digitalRead(scbutton) == HIGH) {
    lcd.clear();
    alarmto = 4;
    delay(200);
  }
  if (digitalRead(rotbutton) == HIGH) {
    mode = 6;
    delay(200);
  }

  // set alarm to volume ends here
    }
    if(alarmto == 4){
      //set alarm to fill percentage

    lcd.setCursor(0, 0);
      lcd.print("set alarm %full:");
      aState = digitalRead(outputA);

      if (aState != aLastState){
    if (digitalRead(outputB) != aState){
      peralarm++;
      lcd.setCursor(0, 1);
      lcd.print(peralarm);
      
      if(peralarm > 100){
        lcd.clear();
        peralarm = 0;
      }
    }
    else{
      peralarm++;
      lcd.setCursor(0, 1);
      lcd.print(peralarm);

      if(peralarm > 100){
        lcd.clear();
        peralarm = 0;
      }
    }
  aLastState = aState;
  }

  lcd.setCursor(5, 1);
  lcd.print("%full");

  if (digitalRead(scbutton) == HIGH) {
    lcd.clear();
    alarmto = 1;
    delay(200);
  }
  if (digitalRead(rotbutton) == HIGH) {
    mode = 6;
    delay(200);
  }

    //set alarm to fill percentage ends here
    }

  }

  delay(20);
}
