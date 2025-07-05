#include <Keypad.h>

const byte row=4;
const byte col=4;
const int red=10;
const int green=11;
const int buzz=12;


char numpad [row][col] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};


byte rowPin[row]={9,8,7,6};
byte colPin[col]={5,4,3,2};


String password = "4321";
String vstup ="";

Keypad cKeypad = Keypad(makeKeymap (numpad), rowPin, colPin, row, col);

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(buzz, OUTPUT);
  digitalWrite(red,HIGH);
  Serial.begin(9600);
  Serial.print("Enter Passcode: ");
}

void loop()
{
  char cKey=cKeypad.getKey();
  
  if(cKey){
    if(vstup.length()<4){
      Serial.print("*");
      vstup += cKey;
    }
  }
  if (vstup.length()==4){
    delay(1500);
    if(password==vstup){
      Serial.println("\nEnter");
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
      tone(buzz,500);
      delay(100);
      noTone(buzz);
    } else {
      Serial.println("\nWrong Passcode");
      digitalWrite(red, HIGH);
      digitalWrite(green,LOW);
      tone(buzz, 1000);
      delay(800);
      noTone(buzz);
    }
    delay(1500);
    vstup="";
    Serial.println("Enter Passcode:");
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
  }
}
      
                           
                           