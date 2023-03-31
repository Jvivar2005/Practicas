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
#define  adelante 2// boton para adelantar
#define  atras 3//boton para ir para atras 
bool adelantar, atrasar;// 
int i=1; 
int e=1;
struct comercio {
  char nombre[25];
  float precio;
  int stock;
  char reserva[40];
  float plote;
  };
    comercio Chocolate= {"Chocolate Granada",12.50,15,"1 en el comercial de miraflores"};
    comercio coca = {"coca-cola",20,44,"Se agotaron en bodega"};
    comercio Galletas  = {"Galletas Chiky",40,16,"2 en la tienda de zona 12" };
    comercio Chocolate1  = {"Chocolate Crispin",3.50,20,"15 en el mercado de esquipulas"};
   
void setup() {
  Serial.begin(9600);
  pinMode(adelante,INPUT);
  pinMode(atras,INPUT);
  Serial.println("Bienvenido buenos dias");
  Serial.println("Que va querer para digustar");
  }
void loop() {
  adelantar = digitalRead(adelante);
  atrasar = digitalRead(atras);
 if (adelantar == 1)
  {
    e = 1;
  }
  if (atrasar == 1)
  {
    e = 1;
  }
  while(e == 1)
  {
  if(adelantar == 1)
  {
    i++;
    delay(200);
    }
  if(i > 4)
  {
    i = 1;
    delay(200);
    }
  if(atrasar == 1){
    i--;
    delay(200);
    }
  if(i< 1){
  i= 4;
  delay(200); 
  }
  switch(i){
  case (1):
  Serial.println(" ");
  Serial.println(Chocolate.nombre);
  Serial.print("Q");
  Serial.println(Chocolate.precio);
  Serial.println(Chocolate.stock);
  Serial.println(Chocolate.reserva);
  Serial.print("El precio Total Q");
  Serial.println(Chocolate.precio *Chocolate.stock);
  e = 2;
 break;
 case (2):
  Serial.println(" ");
  Serial.println(coca.nombre);
  Serial.print("Q");
  Serial.println(coca.precio);
  Serial.println(coca.stock);
  Serial.println(coca.reserva);
  Serial.print("El precio Total Q");  
  Serial.println(coca.precio * coca.stock);
  e = 2;
 break;
 case (3):
  Serial.println(" ");
  Serial.println(Galletas.nombre);
  Serial.print("Q");
  Serial.println(Galletas.precio);
  Serial.println(Galletas.stock);
  Serial.println(Galletas.reserva);
  Serial.print("El precio Total Q");  
  Serial.println(Galletas.precio * Galletas.stock);
  e = 2;
 break;
 case (4):
  Serial.println(" ");
  Serial.println(Chocolate1.nombre);
  Serial.print("Q");  
  Serial.println(Chocolate1.precio);
  Serial.println(Chocolate1.stock);
  Serial.println(Chocolate1.reserva);
  Serial.print("El precio Total Q");  
  Serial.println(Chocolate1.precio * Chocolate1.stock);
  e = 2;
 break;
   }
  }
 }
  
