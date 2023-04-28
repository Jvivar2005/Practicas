//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585
#include <LiquidCrystal.h>// Libreria de LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


// Pines a usar
// Pines de sensor ultrasonico
int Trig = 7;
int Echo = 6;
// Pin buzzer
int Buzzer = 9;

// Variables a usar en el programa
int Personas;
int Distancia;

// Codigos de caracteres personalizados
byte Persona[8] = {
  B01101,
  B11101,
  B11111,
  B01100,
  B01100,
  B01100,
  B10010,
  B10001
  };

byte Persona2 [8] = {
  B00000,
  B01110,
  B01110,
  B00100,
  B10101,
  B01110,
  B00100,
  B01010
};
void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(Echo, INPUT);
  lcd.begin(16, 2);
  // Creacion de los caracteres
  lcd.createChar(0, Persona);
  lcd.createChar(1, Persona2);
}

void loop() {
  Distancia = HC(); // Guardado de la distancia de la funcion HC
  // Si encuentra una persona en un radio mayor a 6cm y menor a 10cm contara
  if (Distancia >= 6 && Distancia <= 10) {
    Personas++;
    lcd.setCursor(0, 0);
    lcd.print("Bienvenido");
    animacionpersona();
  }
  while (Personas >= 16) { // Al llegar a las 16 personas entrara en bucle de texto y sonido evitando que siga contando
    lcd.setCursor(0, 0);
    lcd.print("limite alcanzado");
    animacionpersona();
    delay(500);
  }
}

int HC () { // Funcion con retorno de variable
  digitalWrite(Trig, HIGH);
  delay(1);
  digitalWrite(Trig, LOW);
  int distancia = pulseIn(Echo, HIGH) / 52.8;
  return distancia;
}

void animacionpersona() { // Realiza la animacion con fotogramas
  lcd.setCursor(0, 1);
  lcd.print("NO.");
  lcd.print(Personas);
  lcd.write(byte(0));
  tone(Buzzer, 200); // Funcion para que suele el buzzer
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("NO.");
  lcd.print(Personas);
  lcd.write(byte(1));
  noTone(Buzzer); // apaga el buzzer
  delay(500);
  lcd.setCursor(0, 1);
  lcd.print("NO.");
  lcd.print(Personas);
  lcd.write(byte(0));
  tone(Buzzer, 200); // Funcion para que suele el buzzer
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("NO.");
  lcd.print(Personas);
  lcd.write(byte(1));
  noTone(Buzzer); // apaga el buzzer
}
