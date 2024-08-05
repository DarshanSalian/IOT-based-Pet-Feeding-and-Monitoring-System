#include <Servo.h>  
Servo servo;  
void setup() {   
    Serial.begin(115200);  
    servo.attach(9); // Servo connected to pin 9 of Arduino Nano  
}  
void loop() {   if (Serial.available() > 0) 
{     
    int servoPosition = 
    Serial.parseInt();  
    if (servoPosition >= 0 && servoPosition <= 180) 
    {       
        servo.write(servoPosition);  
        Serial.print("Servo position set to: ");  
        Serial.println(servoPosition);  
    }  
    }  
}