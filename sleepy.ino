#include <Servo.h>
#include <avr/sleep.h>

Servo myservo;  

const int buttonPin = 2;    
const int servoPin = 9;  
int buttonState = 0;   
int offCounter = 0;

void wakeUpNow(){
  //called on interrupt
}

void sleepNow(){
    Serial.println("sleepNow");
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);   
    sleep_enable();                                      
    
    pinMode(servoPin, INPUT);
    digitalWrite(servoPin, HIGH);                             
    
    attachInterrupt(1, wakeUpNow, RISING);                                               
    sleep_mode();            // here the device is actually put to sleep!!
                             
    //continue from here after waking up
    
    sleep_disable();         // first thing after waking from sleep:                             
    detachInterrupt(0);     
    
    pinMode(servoPin, OUTPUT);                             
}

 
void setup() {
  pinMode(buttonPin, INPUT);  
  myservo.attach(servoPin);    
}

void loop() {
     
    buttonState = digitalRead(buttonPin);   
    
    if (buttonState == HIGH) {        
        myservo.write(180);          
    } 
    else {            
      myservo.write(0);          
      offCounter++;
      
      if (offCounter > 1000) { 
        offCounter = 0;       
        sleepNow();  
      } 
      
    }

    delay(100);
    
}
