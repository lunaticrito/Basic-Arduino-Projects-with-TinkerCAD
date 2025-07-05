#include <IRremote.h>

int IR = 12;
int B=2;
int O=3;
int G=4;

IRrecv irrecv(IR);//reading input
decode_results results; //decodes input

void setup() 
{
  Serial.begin(9600); 
  irrecv.enableIRIn();// starts the receiver
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
 //decodes the ir input
  if(irrecv.decode(&results))
  {
    long int decCode = results.value;
    Serial.println(results.value);
    // switch case to use selected remote control
    switch (results.value){
      case 16582903: //pressing 1
      digitalWrite(2,HIGH);
      break;
      case 16615543: // pressing 2
      digitalWrite(2,LOW);
      break;
      case 16599223: // pressing 3
      digitalWrite(3,HIGH);
      break;
      case 16591063: // pressing 4
      digitalWrite(3,LOW);
      break;
      case 16623703: // pressing 5
      digitalWrite(4,HIGH);
      break;
      case 16607383: // pressing 6
      digitalWrite(4,LOW);
      break;
    }
    irrecv.resume(); // receives the next value fromm the button u press
  }
  delay(10);
}


     