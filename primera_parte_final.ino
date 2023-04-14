/*
 Fundacion Kinal
centro educativo tecnico laboral kinal 
Electronica 
Quinto perito 
A
taller de elctronica digital y reparacion de computadora I
javier ricardo vivar sanchez
2019585
*/
#define boton_push1 9
#define boton_push2 10
#define led1 4
#define led2 7
#define led3 8
void setup() {
   
  pinMode(boton_push1, INPUT);
  pinMode(boton_push2, INPUT);
   pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}
void loop() {
  int RG;
  RG = digitalRead (boton_push1);
  int GB;
  GB = digitalRead (boton_push2);
     
  if (RG==1 && GB == 0 ){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  delay(500);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  }
    if (RG==0 && GB == 1 ){
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  delay(500);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
    }
      if ( RG==1 && GB == 1 ){
  digitalWrite(led1,HIGH);
  digitalWrite(led3,HIGH);
  delay(500);
  digitalWrite(led1,LOW);
  digitalWrite(led3,LOW);
      }
        if (RG==0 && GB == 0 ) {  
  digitalWrite(led3,LOW);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  delay(500);
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  delay(500);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
  digitalWrite(led1,LOW);
  delay(500);
  }
}
