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
#define LED1 2
#define LED2 3
#define LED3 4
#define LED4 5
#define LED5 6
#define LED6 7
#define LED7 8
#define LED8 9
#define LED9 10
void setup() {
  
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
}

void loop() {
  
  digitalWrite(LED1, HIGH);
  delay(50);
  digitalWrite(LED2, HIGH);
  delay(50);
  digitalWrite(LED3, HIGH);
  delay(50);
  digitalWrite(LED4, HIGH);
  delay(50);
  digitalWrite(LED5, HIGH);
  delay(50);
  digitalWrite(LED6, HIGH);
  delay(50);
  digitalWrite(LED7, HIGH);
  delay(50);
  digitalWrite(LED8, HIGH);
  delay(50);
  digitalWrite(LED9, HIGH);
  delay(50);

  
  digitalWrite(LED1, LOW);
  delay(50);
  digitalWrite(LED2, LOW);
  delay(50);
  digitalWrite(LED3, LOW);
  delay(50);
  digitalWrite(LED4, LOW);
  delay(50);
  digitalWrite(LED5, LOW);
  delay(50);
  digitalWrite(LED6, LOW);
  delay(50);
  digitalWrite(LED7, LOW);
  delay(50);
  digitalWrite(LED8, LOW);
  delay(50);
  digitalWrite(LED9, LOW);
  delay(50);


  
  digitalWrite(LED9, HIGH);
  delay(50);
  digitalWrite(LED8, HIGH);
  delay(50);
  digitalWrite(LED7, HIGH);
  delay(50);
  digitalWrite(LED6, HIGH);
  delay(50);
  digitalWrite(LED5, HIGH);
  delay(50);
  digitalWrite(LED4, HIGH);
  delay(50);
  digitalWrite(LED3, HIGH);
  delay(50);
  digitalWrite(LED2, HIGH);
  delay(50);
  digitalWrite(LED1, HIGH);
  delay(50);
  digitalWrite(LED9, LOW);//Apagado de forma descendente
  delay(50);
  digitalWrite(LED8, LOW);
  delay(50);
  digitalWrite(LED7, LOW);
  delay(50);
  digitalWrite(LED6, LOW);
  delay(50);
  digitalWrite(LED5, LOW);
  delay(50);
  digitalWrite(LED4, LOW);
  delay(50);
  digitalWrite(LED3, LOW);
  delay(50);
  digitalWrite(LED2, LOW);
  delay(50);
  digitalWrite(LED1, LOW);
  delay(50);
}
