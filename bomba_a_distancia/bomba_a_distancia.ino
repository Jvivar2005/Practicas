//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585

#include <LiquidCrystal_I2C.h>// Libreria de la LCD 

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pines a usar
int Buzzer =  5;
int Trig = 3;
int Echo = 2;
int Led1 = 4;
int Led2 = 6;
int Led3 = 7;
int Led4 = 8;

// Variables a usar 
int distancia;
int salto = 0;

void setup() {
  Serial.begin(9600);
  // Inicio de LCD con I2C
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(Buzzer, OUTPUT);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
}

void loop() {
  distancia = HC(); // Lectura de la distancia
  if (distancia >= 45) {
    if (salto != 1) { // Con esto se borra la pantalla una vez
      lcd.clear();
    }
    lcd.setCursor(5, 0);
    lcd.print("Fuera");
    lcd.setCursor(3, 1);
    lcd.print("de alcance");
    salto = 1;
    LedsLejos();
  } else if (distancia >= 30 && distancia < 45) {
    if (salto != 2) { // Con esto se borra la pantalla una vez
      lcd.clear();
    }
    lcd.setCursor(1, 0);
    lcd.print("Persona/Objeto");
    lcd.setCursor(3, 1);
    lcd.print("Acercandose");
    salto = 2;
    LedsAcercandose();
  } else if (distancia >= 15 && distancia < 30) {
    if (salto != 3) { // Con esto se borra la pantalla una vez
      lcd.clear();
    }
    lcd.setCursor(3, 0);
    lcd.print("Cuidado,");
    lcd.setCursor(0, 1);
    lcd.print("Espacio Privado");
    tone(Buzzer, 50);
    LedsCerca();
    delay(5000);
    noTone(Buzzer);
    salto = 3;
  } else if (distancia < 15) {
    if (salto != 4) { // Con esto se borra la pantalla una vez
      lcd.clear();
    }
    lcd.setCursor(2, 0);
    lcd.print("invadiendo,");
    lcd.setCursor(0, 1);
    lcd.print("Espacio Privado");
    tone(Buzzer, 100);
    LedsInvasor();
    delay(10000);
    noTone(Buzzer);
    salto = 4;
  }
  Serial.println(distancia);
  delay(250);
}

int HC() { // Funcion de ultrasonico
  digitalWrite(Trig, HIGH);
  delay(1);
  digitalWrite(Trig, LOW);
  int Distancia = pulseIn(Echo, HIGH) / 52.8;
  return Distancia;
}

// Funciones para que se enciendan los leds indicados
void LedsLejos() {
  digitalWrite(Led1, LOW);
  digitalWrite(Led2, LOW);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
}

void LedsAcercandose() {
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, LOW);
  digitalWrite(Led4, LOW);
}
void LedsCerca() {
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, LOW);
}

void LedsInvasor() {
  digitalWrite(Led1, HIGH);
  digitalWrite(Led2, HIGH);
  digitalWrite(Led3, HIGH);
  digitalWrite(Led4, HIGH);
}
