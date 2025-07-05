#define ldr  A0
#define led  9


void setup()
{
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(ldr);
  Serial.print("ldr: ");
  Serial.println(value);
  analogWrite(led, map(value,0,1023,0,255));
  delay(100);
}