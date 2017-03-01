// Constants for pin setup
const int sensorPin = A0;
const int ledPin = 0;

// Variables for changing
int threshold = 500;
int ledState = LOW;

void soundSensor()
{
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);    // print out the value you read
  delay(1);   // delay in between reads for stability
}

int getSound()
{
  int sensorValue = analogRead(sensorPin);
  delay(1);
  return sensorValue;
}

void ledToggle()
{
  if (ledState == LOW) ledState = HIGH;
  else ledState = LOW;
}

void setup() 
{
  // Initialize serial communication at 9600 bits per second:
  //Serial.begin(9600);

  // Set the digital pin as output
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  digitalWrite(ledPin, ledState);
  soundSensor();

  if (getSound() > threshold) ledToggle();
}
