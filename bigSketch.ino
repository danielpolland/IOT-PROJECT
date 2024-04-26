#define BLYNK_TEMPLATE_ID           "TMPL4Krrkxw0m"
#define BLYNK_TEMPLATE_NAME         "IOT Project"
#define BLYNK_AUTH_TOKEN            "HJMTYnHCRcbFYwUVIjlILseDy0HxlCcz" 

#define BLYNK_PRINT Serial

#include <Bridge.h>
#include <BlynkSimpleYun.h>

const int ledPin = A0;
const int btnPin = A1;

int btnState = 0;

BlynkTimer timer;

void setup()
{
  // Debug console
  Serial.begin(115200);

  //Blynk.begin(BLYNK_AUTH_TOKEN);
  // You can also specify server:
  Blynk.begin(BLYNK_AUTH_TOKEN, "blynk.cloud", 8080);
  //Blynk.begin(BLYNK_AUTH_TOKEN, IPAddress(192.168.240.1), 8080);

  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
  
   timer.setInterval(1000L, sensorDataSend);
}

void sensorDataSend()
{
btnState = digitalRead(btnPin);
    if (btnState == HIGH) {
    // turn LED on:
    
    Blynk.logEvent("Security_Notification", String("Motion Detected!"));
  } 
}
void loop()
{
  Blynk.run();
  timer.run();
  btnState = digitalRead(btnPin);
    if (btnState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
