#include <EEPROM.h>

int buttonPressed = 0;
int value = 0;
int address = 0;

char cmd;

int i,j;

int vote, result;


void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);

  pinMode(13,OUTPUT);
  pinMode(12,INPUT);

  Serial.begin(9600);
}

void loop() {

  if(Serial.available()){
    cmd = Serial.read();
    if(cmd == 'C')
      readResult();
    if(cmd == 'R')
      resetResult();
  }

  if(digitalRead(12) == HIGH){
    digitalWrite(13,HIGH);
    vote = 0;

    while(1){
      for(i=4;i<8;i++)
      {
        digitalWrite(i,HIGH);
        Serial.println(i);    
        for(j=8;j<12;j++){
          if(digitalRead(j) == HIGH){
            value = EEPROM.read(address);
            value = value + 1;
            EEPROM.write(address,value);
            Serial.print(j);
            Serial.print("---");
            Serial.print(address);
            Serial.print("---");
            Serial.println(value);
            vote = 1;
            break;
          }
          
          if(vote == 1)
            break;
          address = address+2;
          delay(50);
        }
        reset();
      }
      if(vote == 1)
        break;
        
      delay(100);
      address = 0;
    }
  }
  digitalWrite(13,LOW);
}

void reset(){
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

void resetResult(){
  Serial.println("Resetting Result... Please Wait...");

  for (int k = 0 ; k < EEPROM.length() ; k++) {
      EEPROM.write(k, 0);
    }

  delay(2000);
  Serial.println("Resetting Result Done.. !!");
}

void readResult(){
  Serial.println("Calculating Result... Please Wait...");
  delay(2000);
  for (int k = 0 ; k < 32 ; k+=2) {
      result = EEPROM.read(k);
      Serial.print(1+k/2);
      Serial.print(" ====>> ");
      Serial.println(result);
    }
}
