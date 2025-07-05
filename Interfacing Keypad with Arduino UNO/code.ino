#include <Keypad.h>

const byte row=4;
const byte col=4;

char keys [row][col] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};


byte rowPin[row]={9,8,7,6};
byte colPin[col]={5,4,3,2};


Keypad keypad = Keypad(makeKeymap (keys), rowPin, colPin, row, col);

void setup()
{
  Serial.begin(9600);
}

void loop()
{ char key=keypad.getKey(); 


 if(key){
   Serial.print("Key pressed: ");
   Serial.println(key);
 }
}