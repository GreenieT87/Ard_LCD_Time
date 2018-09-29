
#include <DS3231.h>
DS3231  rtc;
RTCDateTime dtc;

#include <LiquidCrystal.h>
const int rs = 6, en = 7, d4 = 5, d5 = 4, d6 = 3, d7 = 10;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buttonINPUT = 12;

/**
 * Returns a string containing time and date in a short format like "HH:MM  DD-MM"
 * off the DS3231 RTC
 * @method readShortTimeDate
 */
void RTCreadShortTimeDate() {
  dtc = rtc.getDateTime();
  int hour = dtc.hour;
  int minute = dtc.minute;
  //int sec = dtc.second;
  int day = dtc.day;
  int month = dtc.month;
  //int year = dtc.year;
  char times[25];
  sprintf(times, "%02d:%02d  %02d-%02d", hour, minute, day, month);

  lcd.print(times);
}
/**
 * Returns a string containing time and date in a long format like "HH:MM:SS  DD-MM-YYYY"
 * off the DS3231 RTC
 * @method printLongTimeDate
 */
void RTCreadLongTimeDate() {
  dtc = rtc.getDateTime();
  int hour = dtc.hour;
  int minute = dtc.minute;
  int sec = dtc.second;
  int day = dtc.day;
  int month = dtc.month;
  int year = dtc.year;
  char times1[50];
  sprintf(times1, "%02d:%02d:%02d %02d-%02d-%04d", hour, minute, sec, day, month, year);
  lcd.print(times1);
}
/**
 * Retunrs an INT containing the temperature off the DS3231 RTC
 * @method printTemprature
 */
void RTCprintTemprature() {
  int temp = rtc.readTemperature();

  lcd.print(temp);
}
/**
 * Retunrs an INT containing the temperature off the DHT11
 * @method DHTreadTemprature
 */

void setup() {
  pinMode(buttonINPUT, INPUT_PULLUP);

  Serial.begin(9600);
  rtc.begin();
  rtc.setDateTime(__DATE__, __TIME__);
  lcd.begin(16,2);
}

void loop() {
  if (digitalRead(buttonINPUT) == HIGH){
    lcd.home();
    RTCreadLongTimeDate();
      delay(1000);
  }
  else{
    lcd.setCursor(0, 1);
    RTCreadShortTimeDate();
    delay(1000);
  }
}
