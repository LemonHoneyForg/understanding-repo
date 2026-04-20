#include <Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define screen_width 128
#define screen_height 64
#define LED_PIN 12
#define LED_PIN2 13

Adafruit_SSD1306 display(screen_width, screen_height);

const int trigPin = 9;
const int echoPin = 10;
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// defines variables
long duration;
int distance;
int buttonState = 0;

void setup() {
   pinMode(buttonPin, INPUT);
   pinMode(LED_PIN , OUTPUT);
    pinMode(LED_PIN2 , OUTPUT);
  // put your setup code here, to run once:
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void loop() {
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
buttonState = digitalRead(buttonPin);

 if (buttonState == HIGH) {
   joy();
    
  } else {
if(distance>10){
  

  me();
  
  
   
}
else{
  mad();
  
}
  }



}




void me() {
    digitalWrite(LED_PIN, LOW);
   digitalWrite(LED_PIN2 , HIGH);
    
 display.clearDisplay();

display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);
display.print("Luna G. ");
display.setCursor(0, 20);
display.print("She/They");
display.display();

 
}



void mad(void) {
digitalWrite(LED_PIN2 , LOW);
 digitalWrite(LED_PIN , HIGH);
display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);
display.print(" BACK UP   ");
display.setCursor(20, 40);
display.print("PLEASE");
display.display();


}

void joy(void){

  digitalRead(JOY , LOW);


  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("distance");
  display.setCursor(20, 40);
  display.print(distance);
  display.display();

  
}






