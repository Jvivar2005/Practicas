//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585

#include <OneWire.h>
#include <DallasTemperature.h>
//libreria del LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define Direccion_LCD 0x27
#define FILAS 2
#define COLUMNAS 16
#define Pin_de_datos 9

#define D1 6
#define D2 4
#define D3 3
int Fahrenheit;
int TEMPFahrenheit();
int Celsius;
int TEMPCelsius();
void LCD_Viva();
byte Termometro[] = {
  B00100,
  B01010,
  B01010,
  B01010,
  B10001,
  B10001,
  B01110,
  B00000
};
byte Signo_de_grados[] = {
  B11100,
  B10100,
  B11100,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};
OneWire ourWire(2);
DallasTemperature SENSOR(&ourWire);
LiquidCrystal_I2C LCD_Vivar(Direccion_LCD, COLUMNAS, FILAS);
void setup() {
  delay(1000);
  Serial.begin(9600);
  SENSOR.begin();
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  LCD_Vivar.begin(16, 2);
  LCD_Vivar.init();
  LCD_Vivar.backlight();
  LCD_Vivar.createChar(1, Termometro);
  LCD_Vivar.write(1);
  LCD_Vivar.createChar(2, Signo_de_grados);
  LCD_Vivar.write(2);
}
void loop()
{
  LCD_Viva();
}
int TEMPCelsius() {
  SENSOR.requestTemperatures();
  int TEMPC = SENSOR.getTempCByIndex(0);
  return TEMPC;
}
int TEMPFahrenheit() {
  SENSOR.requestTemperatures();
  int TEMPF = SENSOR.getTempFByIndex(0);
  return TEMPF;
}

void LCD_Viva() {
  Fahrenheit = TEMPFahrenheit();
  Celsius = TEMPCelsius();
  if (Celsius > 30) {
    LCD_Vivar.setCursor(0, 0);
    LCD_Vivar.print("TERMOMETRO");
    LCD_Vivar.setCursor(10, 0);
    LCD_Vivar.write(1);
    LCD_Vivar.setCursor(0, 1);
    LCD_Vivar.print("C");
    LCD_Vivar.setCursor(2, 1);
    LCD_Vivar.print(SENSOR.getTempCByIndex(0));
    LCD_Vivar.setCursor(1, 1);
    LCD_Vivar.write(2);
    LCD_Vivar.setCursor(9, 1);
    LCD_Vivar.print(SENSOR.getTempFByIndex(0));
    LCD_Vivar.setCursor(8, 1);
    LCD_Vivar.write(2);
    LCD_Vivar.setCursor(7, 1);
    LCD_Vivar.print("F");
    digitalWrite(D1, HIGH);
    digitalWrite(D2, LOW);
    digitalWrite(D3, LOW);
  }
  if (Celsius > 15 && Celsius < 30) {
    LCD_Vivar.setCursor(0, 0);
    LCD_Vivar.print("TERMOMETRO");
    LCD_Vivar.setCursor(10, 0);
    LCD_Vivar.write(1);
    LCD_Vivar.setCursor(0, 1);
    LCD_Vivar.print("C");
    LCD_Vivar.setCursor(2, 1);
    LCD_Vivar.print(SENSOR.getTempCByIndex(0));
    LCD_Vivar.setCursor(1, 1);
    LCD_Vivar.write(2);
    LCD_Vivar.setCursor(9, 1);
    LCD_Vivar.print(SENSOR.getTempFByIndex(0));
    LCD_Vivar.setCursor(8, 1);
    LCD_Vivar.write(2);
    LCD_Vivar.setCursor(7, 1);
    LCD_Vivar.print("F");
    digitalWrite(D1, LOW);
    digitalWrite(D2, HIGH);
    digitalWrite(D3, LOW);

  }
  if (Celsius < 15 ) {
    LCD_Vivar.setCursor(0, 0);
    LCD_Vivar.print("TERMOMETRO");
    LCD_Vivar.setCursor(10, 0);
    LCD_Vivar.write(1);
    LCD_Vivar.setCursor(0, 1);
    LCD_Vivar.print("C");
    LCD_Vivar.setCursor(2, 1);
    LCD_Vivar.print(SENSOR.getTempCByIndex(0));
    LCD_Vivar.setCursor(1, 1);
    LCD_Vivar.write(2);
    LCD_Vivar.setCursor(9, 1);
    LCD_Vivar.print(SENSOR.getTempFByIndex(0));
    LCD_Vivar.setCursor(8, 1);
    LCD_Vivar.write(2);
    LCD_Vivar.setCursor(7, 1);
    LCD_Vivar.print("F");
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    digitalWrite(D3, HIGH);
  }
}  
