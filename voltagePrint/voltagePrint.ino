int voltageOne=0;
int voltageTwo=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  voltageOne=analogRead(2); // pin reads 
  delay(1);
  voltageTwo=analogRead(5);

  // print values to serial port
  Serial.print(voltageOne);
  Serial.print("\t");
  Serial.print(voltageTwo);
  Serial.println("\t");
  delay(1);
}