const int analogPin = A0; 
const int chargePin = 8;
const int dischargePin = 9;

const long resistorValue = 10000; 

unsigned long startTime;
unsigned long elapsedTime; 

float capacitanceMicroF;
float capacitanceNanoF;

void setup() {
  pinMode(chargePin, OUTPUT);


  digitalWrite(chargePin, LOW);


  Serial.begin(9600);
}

void loop() {
  digitalWrite(chargePin, HIGH);


  startTime = millis();

  while (analogRead(analogPin) < 610) {
  }

  elapsedTime = millis() - startTime;

  capacitanceMicroF = ((float)elapsedTime / resistorValue) * 1000.0;

  Serial.print(elapsedTime);
  Serial.print("mS    ");
  if (capacitanceMicroF >= 1.0) {
    Serial.print(capacitanceMicroF, 2);
    Serial.println(" uF");

  } else {
    capacitanceNanoF = capacitanceMicroF * 1000.0;
    Serial.print(capacitanceNanoF, 2);
    Serial.println(" nF");
     delay(500);
  }

  digitalWrite(chargePin, LOW);
  pinMode(dischargePin,OUTPUT);
  digitalWrite(dischargePin, LOW);

  while (analogRead(analogPin) > 0) {
  }

  pinMode(dischargePin,INPUT);
}