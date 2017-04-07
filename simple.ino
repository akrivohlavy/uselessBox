#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int buttonPin = 2;    
const int servoPin = 9;
int buttonState = 0;   

void setup() {
  pinMode(buttonPin, INPUT);  
  myservo.attach(servoPin);   
  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
        Serial.println("on");            
        myservo.write(180);  
      } 
      else {
        Serial.println("off");
        myservo.write(0);  
      }    
  
  delay(200);   

}
