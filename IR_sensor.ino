/*
IR Proximity Sensor interface code
Turns on an LED on when obstacle is 
detected, else off.
*/

const int ProxSensor=2;

void setup() 
{ 
// initialize the digital Serial port.

Serial.begin(9600);               
// initialize the digital pin as an output.
pinMode(13, OUTPUT);     
pinMode(ProxSensor,INPUT);
}
void loop() 
{
  if(digitalRead(ProxSensor)==LOW)
//Check the sensor output
  {
  digitalWrite(13, HIGH);   // set the LED on
  Serial.println("Stop something is ahead!! ");  //Message on Serial Monitor
  }
  else
  {
  digitalWrite(13, LOW);    // set the LED off
  Serial.println("Path is clear"); 
//Message on Serial Monitor
  }
delay(1000);              // wait for a second
}
