#include <RTClib.h>
#include <Wire.h>
RTC_DS3231 rtc;
char t[32];
void setup()
{
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));
  //rtc.adjust(DateTime(2024, 8, 7, 10, 45, 0));
    
}
void loop()
{
  DateTime now = rtc.now();
  sprintf(t, "%02d:%02d:%02d %02d/%02d/%02d", now.hour(), now.minute(), now.second(), now.day(), now.month(), now.year());  
  Serial.print(F("Date/Time: "));
  Serial.println(t);
  delay(500);
}
