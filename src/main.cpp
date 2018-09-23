
#include <DS3231.h>
DS3231  rtc;
RTCDateTime dtc;

#include <LiquidCrystal.h>
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <dht.h>
dht DHT;
#define DHT11_PIN 2

int buttonINPUT = 12;

void printShortTimeDate() {
  dtc = rtc.getDateTime();
  int hour = dtc.hour;
  int minute = dtc.minute;
  //int sec = dtc.second;
  int day = dtc.day;
  int month = dtc.month;
  //int year = dtc.year;
  char times[25];
  sprintf(times, "  %02d %02d  %02d-%02d  ", hour, minute, day, month);
  char times1[25];
  sprintf(times1, "  %02d:%02d  %02d-%02d  ", hour, minute, day, month);
  char date[25];
  sprintf(date, "%02d-%02d", day, month);

  lcd.home();
  lcd.print(times);
  delay(500);
  lcd.home();
  lcd.print(times1);
}
void printLongTimeDate() {
  dtc = rtc.getDateTime();
  int hour = dtc.hour;
  int minute = dtc.minute;
  //int sec = dtc.second;
  int day = dtc.day;
  int month = dtc.month;
  int year = dtc.year;
  char times[25];
  sprintf(times, "%02d %02d %02d %02d %02d", hour, minute, day, month, year);
  char times1[25];
  sprintf(times1, "%02d:%02d %02d-%02d-%02d", hour, minute, day, month, year);

  lcd.home();
  lcd.print(times);
  delay(500);
  lcd.home();
  lcd.print(times1);
}
void printTemprature() {
  dtc = rtc.getDateTime();
  int hour = dtc.hour;
  int minute = dtc.minute;
  int sec = dtc.second;

  char times[25];
  sprintf(times, "%02d:%02d:%02d", hour, minute, sec);
  lcd.setCursor(0,0);
  lcd.print("Time: ");
  lcd.print(times);
  lcd.setCursor(0,1);

  int temp = rtc.readTemperature();
  lcd.print("Temp: ");
  lcd.print(temp);
  lcd.print(" C        ");
}
void printDHT() {
  int chk = DHT.read11(DHT11_PIN);
  dtc = rtc.getDateTime();
  int hour = dtc.hour;
  int minute = dtc.minute;
  int sec = dtc.second;
  int temps = int(DHT.temperature);
  int hums = int(DHT.humidity);

  char times[25];
  sprintf(times, "    %02d:%02d:%02d    ", hour, minute, sec);
  char temp[25];
  sprintf(temp, "T: %02d*C  H: %02d", temps, hums);

  if (chk == -1) {
    lcd.home();
    lcd.print(times);
    lcd.setCursor(0,1);
    lcd.print(temp);lcd.print("%  ");
  }
}

void setup() {
  pinMode(buttonINPUT, INPUT_PULLUP);

  Serial.begin(9600);
  rtc.begin();
  rtc.setDateTime(__DATE__, __TIME__);
  lcd.begin(16,2);
}

void loop() {
  if (digitalRead(buttonINPUT) == HIGH){
    lcd.setCursor(0, 1);
    lcd.print("                ");
    printShortTimeDate();
    delay(1000);
  }
  else{
    delay(500);
    printDHT();
  }
}
