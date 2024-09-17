#include <Servo.h>

Servo servo;

int vibrationPin = 10;    
int vibrationState = 0;  
bool servoMoved = false; 

void setup() {
  servo.attach(9);      
  
  pinMode(vibrationPin, INPUT);
}

void loop() {
  vibrationState = digitalRead(vibrationPin);
  
  if (vibrationState == HIGH && !servoMoved) {
    servo.write(180);
    servoMoved = true; 
    delay(10000);     
    servo.write(0);    
    servoMoved = false; 
  }
}
