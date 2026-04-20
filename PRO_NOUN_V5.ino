#include <Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

#define screen_width 128
#define screen_height 64


Adafruit_SSD1306 display(screen_width, screen_height);

const int trigPin = 9;
const int echoPin = 10;
const int buttonPin = 2; 

int power1;
int power2 = A1;
int potPin = A3; // Potentiometer output connected to analog pin 3
int potVal = 0; // Variable to store the input from the potentiometer
int stmer=1;
// OUTPUT: Use digital pins 9-11, the Pulse-width Modulation (PWM) pins
// LED's cathodes should be connected to digital GND
int redPin = 5;   // Red LED,   connected to digital pin 5
int grnPin = 4;  // Green LED, connected to digital pin 4
int bluPin = 3;  // Blue LED,  connected to digital pin 3

// Program variables
int redVal = 0;   // Variables to store the values to send to the pins
int grnVal = 0;
int bluVal = 0;

// defines variables
long duration;
int distance;
int buttonState = 0;

int modestate = 0;

void setup() {
    pinMode(redPin, OUTPUT);   // sets the pins as output
  pinMode(grnPin, OUTPUT);   
  pinMode(bluPin, OUTPUT);  
   pinMode(buttonPin, INPUT);
  // put your setup code here, to run once:
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void loop() {
  potVal = analogRead(potPin);
   digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = 0.393701*(duration * 0.034 / 2);
  power1= power2*.0293255;
buttonState = digitalRead(buttonPin);

 if (buttonState == HIGH) {
   
    modestate= ++modestate;
  }  
 
  if(modestate == 0){
if(distance>3){
  

  me();
  volt();
  
   
}
else{
  mad();
  volt();
}
  }
else if(modestate==1){
  joy();
  volt();
}
else if(modestate==2){
  stress();
  volt();
}  
    else if(modestate>2){
      modestate= 0;
    }


}




void me() {
    redVal = 247;  // Red from full to off
    grnVal = 0;        // Green from off to full
    bluVal = 0;             // Blue off

 display.clearDisplay();

display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);
display.print("Luna G. ");
display.setCursor(0, 20);
display.print("She/They");
display.display();

      analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);
 
}



void mad(void) {
    redVal = 0;  // Red from full to off
    grnVal = 0;        // Green from off to full
    bluVal = 247;             // Blue off


display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);
display.print(" BACK UP   ");
display.setCursor(20, 40);
display.print("PLEASE");
display.display();
      analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);

}

void joy(void){
    grnVal = 10*distance;        // Green from off to full
    redVal =   8*distance;  // Red from full to off
    bluVal = 6*distance;             // Blue off
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("distance");
  display.setCursor(20, 40);
  display.print(distance);
  display.display();

      analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);
  
}

void stress(void){
  display.clearDisplay();
display.setTextSize(2);
display.setTextColor(SSD1306_WHITE);
display.setCursor(0, 0);
display.print("stress");
display.display();

  potVal = analogRead(potPin);   // read the potentiometer value at the input pin

  if (potVal < 341)  // Lowest third of the potentiometer's range (0-340)
  {                  
    potVal = (potVal * 3) / 4; // Normalize to 0-255

    redVal = 256 - potVal;  // Red from full to off
    grnVal = potVal;        // Green from off to full
    bluVal = 1;             // Blue off
    stmer=1;

   
      analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);
  }
  else if (potVal < 682) // Middle third of potentiometer's range (341-681)
  {
    potVal = ( (potVal-341) * 3) / 4; // Normalize to 0-255

    redVal = 1;            // Red off
    grnVal = 256 - potVal; // Green from full to off
    bluVal = potVal;       // Blue from off to full
    stmer=2;

   
      analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);
  }
  else  // Upper third of potentiometer"s range (682-1023)
  {
    potVal = ( (potVal-683) * 3) / 4; // Normalize to 0-255

    redVal = potVal;       // Red from off to full
    grnVal = 1;            // Green off
    bluVal = 256 - potVal; // Blue from full to off
    stmer=3;

    
      analogWrite(redPin, redVal);   // Write values to LED pins
  analogWrite(grnPin, grnVal); 
  analogWrite(bluPin, bluVal);

  }

  

if(stmer==1){
     display.setCursor(20, 40);
    display.print(" (LOW) ");
    display.display();

}
else if(stmer==2){
     display.setCursor(20, 40);
    display.print(" (MEDIUM) ");
    display.display();

}
else{
       display.setCursor(20, 40);
    display.print(" (HIGH) ");
    display.display();

}
}

void volt(void){
     display.setCursor(20, 0);
    display.print(power1);
    display.display();
}




