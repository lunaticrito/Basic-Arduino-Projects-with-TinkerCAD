int rp=12;
int gp=11;
int bp=10;

void setup()
{
  pinMode(rp, OUTPUT);
  pinMode(gp, OUTPUT);
  pinMode(bp, OUTPUT);
}

void loop()
{
  color(255,0,0);
  delay(1000); 
  color(0,255,0);
  delay(1000); 
  color(0,0,255);
  delay(1000); 
  color(255,255,255);
  delay(1000);
  color(0,0,0);
  delay(1000); 
}
void color(unsigned char red,unsigned char green, unsigned char blue)
{
  analogWrite(rp, red);
  analogWrite(gp, green);
  analogWrite(bp, blue);
}
  