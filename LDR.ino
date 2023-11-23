const int ledPin = 13; //pin at which LED is connected
const int ldrPin = A0; //pin at which LDR is connected
int threshold = 127;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); //Make LED pin as output
  pinMode(ldrPin, INPUT); //Make LDR pin as input
}
void loop()
{
  //analogWrite(9,(1023-analogRead(ldrPin)));
  //delay(100);
  int ldrStatus = analogRead(ldrPin); //saving the analog values received from LDR into "ldrStatus" variable
  if (ldrStatus <= threshold) //set the threshold value below at which the LED will turn on
  {               //you can check in the serial monior to get approprite value for your LDR
    digitalWrite(ledPin, HIGH);  //Turing LED ON
    Serial.print("Its DARK, Turning ON the LED : ");
      Serial.println(ldrStatus);
    delay(1000); 
  }
  else
  {
    digitalWrite(ledPin, LOW); //Turing OFF the LED
    Serial.print("Its BRIGHT, Turning OFF the LED : ");
    Serial.println(ldrStatus);
    delay(1000); 
  }
}
