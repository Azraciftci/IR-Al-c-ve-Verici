#include <IRremote.h>
int IR_RECEIVE_PIN = 11;
long artir = 0xF50ABF00;
long azalt = 0xF708BF00;
long bir = 0xEF10BF00;
long iki = 0xEE118F00;
long uc = 0xED12BF00;
long kumanda=0;
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT); 
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() 
{
  if(IrReceiver.decode()) {
    Serial.print(IrReceiver.decodedIRData.decodedRawData, HEX);
  }
   kumanda=IrReceiver.decodedIRData.decodedRawData;
    
    if (kumanda== artir) {
      
      digitalWrite(2,1);
      Serial.println("yesil");
      delay(500);
      digitalWrite(2,0);
      
    }
    else if (kumanda== azalt) {
      digitalWrite(3,1);
      Serial.println("kirmizi");
      delay(500);
      digitalWrite(3,0);
    }
else if(kumanda== azalt) {
  digitalWrite(3,1);
  Serial.println("kirmizi");
  delay(500);
  digitalWrite(3,0);
  }
else if (kumanda==bir) {
  
  digitalWrite(4,1);
  delay(500);
  digitalWrite(4,0);
  }                  
else if(kumanda== iki) {
  
  digitalWrite(5,1);
  delay(500);
  digitalWrite(5,0);
  } 
else if(kumanda== uc) {
  
  digitalWrite(65,1);
  delay(500);
  digitalWrite(6,0);
  }
  IrReceiver.resume();
 }


  
    


