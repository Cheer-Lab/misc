/*
 * Modified by James Irving - Sparta Lab - 07/07/16 for new variable names
 * 
Script from Garret Stuber Lab to activate Laser unit at a specific
frequency, triggered by a TTL from MED Associates.

TTL to laser is connected to pin 12 and input from med is connected
to pin 2. Pulse frequency and duration are controlled by the two
lines with delays. First line with delay defines the pulse duration
in miliseconds and second line with delay defines the interpulse
interreadTTL in miliseconds. To control the length of the pulse train,
change the length of the pulse sent from med pc to the arduino.
*/
//Change these variables to customize the stimulation parameters to your needs
int freq=20;
int pulsesPerTrain=20; 
int dur=5;

//Do NOT alter these variables, or the script will not work
int outPin = 12;                // Laser is connected to pin 12
int inPin = 2;              // med associates is connected to pin 2;
int readTTL;                    // variable for reading the pin status
//int count=0;


void setup() {
  pinMode(outPin, OUTPUT);      // Set the LED pin as output
  pinMode(inPin, INPUT);    // Set the switch pin as input
}
void loop(){
  readTTL = digitalRead(inPin);   // read input readTTLue and store it in readTTL
  if (readTTL == LOW) 
  {    // check if external trigger is present
      digitalWrite(outPin, HIGH);   // turn Laser on 
      delay(dur);                     // Pulse duration (ms) - change this to change pulse duration
      digitalWrite(outPin, LOW);   // turn Laser off
      delay(1000/freq-dur);    //Period (ms) Change this to modify the frequency
  }
}

