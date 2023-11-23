int sensorPin = A0;
int redLed = 7;
int blueLed = 8;
int buzzer = 9;
bool A = false;

void setup() 
{
  AlarmOFF();
  Serial.begin(9600);
  pinMode(redLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() 
{
  int sensorValue = analogRead(sensorPin);
  Serial.print("Light = ");
  Serial.println(sensorValue);
  
  if (sensorValue < 600 || A == true){
    A = true;
    AlarmON();
  }
  
  else if (sensorValue >=700){
    digitalWrite(redLed, LOW);
  }
}

void AlarmOFF() {
    A = false;
    digitalWrite(buzzer, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, LOW); 
  }
void AlarmON() {
    
    tone(buzzer, 1700);
    digitalWrite(redLed, HIGH);
    digitalWrite(blueLed, LOW);
    delay(500);

    tone(buzzer, 1319);
    digitalWrite(redLed, LOW);
    digitalWrite(blueLed, HIGH);
    delay(500);
    
    A = true;
  }
