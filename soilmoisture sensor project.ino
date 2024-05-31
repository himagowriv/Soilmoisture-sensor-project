int sensorPin = A0;
int sensor_analog;
int limit = 80 ;
const int motorpin1 = 7;
const int motorpin2 = 6;


void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);
}

void loop() {

  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensorPin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");
  delay(1000);

  if ( moisture_percentage < limit) {
    digitalWrite(3, LOW);
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
  }
  else {
    digitalWrite(13, HIGH);
    digitalWrite(motorpin1, LOW);
    digitalWrite(motorpin2, LOW);
  }
}
