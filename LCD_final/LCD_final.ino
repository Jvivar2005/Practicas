//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585
#include <LiquidCrystal.h>//
int rs= 12;
int E= 11;
int D4= 5;
int D5= 4;
int D6= 3;
int D7= 2;

LiquidCrystal Vivar_LCD(rs,E,D4,D5,D6,D7);

void setup() {
  // put your setup code here, to run once:
Vivar_LCD.begin(16,2);
}
void loop() {
  // put your main code here, to run repeatedly:
Vivar_LCD.setCursor(4,0);
Vivar_LCD.print("Javier");
Vivar_LCD.setCursor(3,3);
Vivar_LCD.print("2019585");
}
