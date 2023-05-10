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

// Librerias usadas en el codigo
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd (0x27, 16, 2);

#include <Servo.h>
Servo myServo;

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWireObjeto(6);
DallasTemperature Temp(&oneWireObjeto);

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel strip(8, 8, NEO_RGB + NEO_KHZ800);

// Numero de pines usados
#define Rele1 2
#define Buzzer 3
#define Rele2 4
#define pinServo 5
#define Radar 7
#define NeoPixel 8
#define LedB 9
#define LedG 10
#define LedR 11
#define BotonL1 A0
#define BotonL2 A1
#define BotonL3 A2

bool estadoB1 = true;
bool estadoB2 = true;
bool estadoP = false;
byte estadop = 0;

byte termometro1[] = {
  B00100,
  B01010,
  B01010,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte termometro2[] = {
  B00100,
  B01010,
  B01110,
  B01110,
  B01110,
  B11111,
  B11111,
  B01110
};

byte foco1[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B01110,
  B00100
};
byte foco2[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B00100
};

byte persona[] = {
  B00000,
  B01110,
  B01110,
  B00100,
  B01110,
  B00100,
  B01010,
  B01010
};

byte puerta1[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11101,
  B11111,
  B11111,
  B00000
};

byte puerta2[] = {
  B11111,
  B11001,
  B11001,
  B11001,
  B11001,
  B11001,
  B11111,
  B00000
};

void setup() {
  Serial.begin(9600);
  Serial.println("practica 7");
  myServo.attach(pinServo); // Declaracion de pin servomotor
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(Rele1, OUTPUT);
  pinMode(Rele2, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedB, OUTPUT);
  pinMode(BotonL1, INPUT);
  pinMode(BotonL2, INPUT);
  pinMode(BotonL3, INPUT);
  pinMode(Radar, INPUT);
  digitalWrite(Rele1, estadoB1);
  digitalWrite(Rele2, estadoB2);
  myServo.write(estadop);
  Temp.begin();
  strip.begin();
  strip.clear();
  strip.show();
  lcd.createChar(0, termometro1);
  lcd.createChar(1, termometro2);
  lcd.createChar(2, foco1);
  lcd.createChar(3, foco2);
  lcd.createChar(4, persona);
  lcd.createChar(5, puerta1);
  lcd.createChar(6, puerta2);
}

void loop() {
  Temp.requestTemperatures();
  int Temperatura = Temp.getTempCByIndex(0); // guardado de temperatura en variable
  // Muestra en pantalla las variables
 
  lcd.setCursor(1, 0);
  lcd.write(0);
  lcd.print(" :");
  lcd.print(Temperatura);
  lcd.print("C ");
  lcd.setCursor(9, 0);
  lcd.write(4);
  lcd.print(" :");
  YesNo();
  lcd.setCursor(1, 1);
  foco(estadoB1);
  lcd.print("1:");
  OnOff(estadoB1);
  lcd.setCursor(9, 1);
  foco(estadoB2);
  lcd.print("2:");
  OnOff(estadoB2);
  if (digitalRead(BotonL1) == HIGH) {
    while (digitalRead(BotonL1) == HIGH);
    estadoB1 = !estadoB1;
    digitalWrite(Rele1, estadoB1);
  }
  else if (digitalRead(BotonL2) == HIGH) {
    while (digitalRead(BotonL2) == HIGH);
    estadoB2 = !estadoB2;
    digitalWrite(Rele2, estadoB2);
  }
  if (digitalRead(BotonL3) == HIGH && estadoP == true) {
    estadop = 90;
    Serial.println("Abierto");
    estadoP = false;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Puerta");
    lcd.setCursor(5, 1);
    lcd.write(6);
    lcd.print("abierta");
    delay(1500);
    lcd.clear();
  }
  else if (digitalRead(BotonL3) == LOW && estadoP == LOW) {
    estadop = 0;
    Serial.println("Cerrado");
    estadoP = true;
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Puerta");
    lcd.setCursor(5, 1);
    lcd.write(5);
    lcd.print("cerrada");
    delay(1500);
    lcd.clear();
  }
  myServo.write(estadop);
  if (Temperatura >= 15 && Temperatura < 21) {
    ledRGB(112, 0, 255);
  }
  else if (Temperatura >= 21 && Temperatura < 25) {
    ledRGB(20, 255, 0);
  }
  else if (Temperatura >= 25 && Temperatura < 45) {
    ledRGB(255, 50, 0);
  }
}

void OnOff(bool estadolocal) { // Mostrara On u Off dependiendo de la variable recibida
  if (estadolocal == LOW) {
    lcd.print("ON ");
  }
  else {
    lcd.print("OFF");
  }
}

void YesNo() { // mostra en pantalla si hay precencia
  if (digitalRead(Radar) == HIGH) {
    lcd.print("yes");
    analogWrite(Buzzer, 100);
    for (int i = 0; i < 7; i++) {
      strip.setPixelColor(i, 100, 0, 50);// (Posision de pixel, VERDE, ROJO, AZUL)
      strip.show();// Manda lo antrior a los pixeles
    }
  }
  else {
    lcd.print("No ");
    analogWrite(Buzzer, 0);
    for (int i = 0; i < 7; i++) {
      strip.setPixelColor(i, 0, 0, 0);// (Posision de pixel, VERDE, ROJO, AZUL)
      strip.show();// Manda lo antrior a los pixeles
    }
  }
}

void ledRGB(byte R, byte G, byte B) { // Funcion para encender colores diferentes en LedRGC
  analogWrite(LedR, R);
  analogWrite(LedG, G);
  analogWrite(LedB, B);
}

void foco(bool estadob) {
  if (estadob == HIGH) {
    lcd.write(2);
  }
  else {
    lcd.write(3);
  }
}
