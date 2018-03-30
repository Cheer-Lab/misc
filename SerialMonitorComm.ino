/*
Author: James Irving - Sparta Lab - 07/07/16
Change Log:
1/2018: Edited by Brian Carson to receive serial communication as input trigger as well as input pin

Input-Triggered Adjustable Stimulation Parameters - Guaranteed # of pulses regardless of length of TTL
Script from Garret Stuber Lab to activate Laser unit at a specific
frequency, triggered by a TTL from MED Associates.

TTL to laser is connected to pin 12 and input from med is connected
to pin 2. Pulse frequency and duration are controlled by the two
lines with delays. First line with delay defines the pulse duration
in miliseconds and second line with delay defines the interpulse
interreadTTL in miliseconds. To control the length of the pulse train,
change the length of the pulse sent from med pc to the arduino.
*/
#include <Keyboard.h>

//Change these variables to customize the stimulation parameters to your needs
int freq=20;
int pulsesPerTrain=20; 
int dur=5;

//Do NOT alter these variables, or the script will not work
int outPin = 12;                // Laser is connected to pin 12
int inPin = 2;              // med associates is connected to pin 2;
int readTTL;                    // variable for reading the pin status
int count=0;


//variable for counting repetitions

/*
Script from Garret Stuber Lab to activate Laser unit at a specific
frequency, triggered by a TTL from MED Associates.

TTL to laser is connected to pin 12 and input from med is connected
to pin 2. Pulse frequency and duration are controlled by the two
lines with delays. First line with delay defines the pulse duration
in miliseconds and second line with delay defines the interpulse
interreadTTL in miliseconds. To control the length of the pulse train,
change the length of the pulse sent from med pc to the arduino.
*/
void setup() {
  Serial.begin(9600);
  pinMode(outPin, OUTPUT); // Set the LED pin as output
  pinMode(inPin, INPUT); // Set the switch pin as input
  //Keyboard.begin();
  }
  void loop()
  {
     if (Serial.available() > 0) {
    // read incoming serial data:
    char inChar = Serial.read();
    // Type the next ASCII value from what you received:
    Serial.write(inChar + 1);
  }
    readTTL = digitalRead(inPin); // read input readTTLue and store it in readTTL
    if (readTTL == LOW) 
    { // check if external trigger is present 
     while (count<pulsesPerTrain)
      {
        digitalWrite(outPin, HIGH); // turn Laser on 
        delay(dur); // Pulse duration (ms) - change this to change pulse duration
        digitalWrite(outPin, LOW); // turn Laser off
        delay(1000/freq-dur); //Period (ms) Change this to modify the frequency
        
        if (count>=pulsesPerTrain)
          {
            break;
            count=0;
          }
          else 
          {
          count=count+1;
          }
      }
    }
    else if (readTTL==HIGH)
      {
      count=0;
      }
}

