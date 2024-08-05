#include <WiFi.h>  
#include <WiFiClient.h>  
#include <BlynkSimpleEsp32.h>  
char auth[] = "VaR5IeI6cX-w-0HELi-hcMSQ-c6VzoDf"; // Blynk Auth Token 
char ssid[] = "Galaxy"; // WiFi SSID char pass[] = "1234Nagu@"; // WiFi Password  
int irSensorPin = 5; // IR sensor connected to pin 5 of ESP32  
BlynkTimer timer;  
void setup() {   
    Serial.begin(115200);   
    pinMode(irSensorPin, INPUT);  
    Blynk.begin(auth, ssid, pass);  
    timer.setInterval(1000L, checkIrSensor); // Check IR sensor every second  
}
void loop() {   
    Blynk.run();   
    timer.run();  
}  
void checkIrSensor() {   int sensorValue = 
digitalRead(irSensorPin);  
if (sensorValue == HIGH) {  
    Blynk.virtualWrite(V1, "Present"); // Send "Present" to V1 in Blynk app   
    } else {  
        Blynk.virtualWrite(V1, "Not Present"); // Send "Not Present" to V1 in Blynk app  
        }  
}    
BLYNK_WRITE(V0) { // Scheduled time input widget on V0 in Blynk app   
    TimeInputParam t(param);   if (t.hasStartTime()) {  
    Serial.println("Scheduled time set!");    
    timer.setTimeout(t.getStartHour() * 3600000L + t.getStartMinute() * 60000L, rotateServo);
    }
}