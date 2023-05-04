//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585

#include <LiquidCrystal_I2C.h> // libreria de LCD_I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte bloque[8] = { // Creacion de caracter perzonañlizado
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

// Pines a usar con sensor ultrasonico
int Trig = 3;
int Echo = 2;

// Variables a usar en el programa
int Distancia;
int Salto; // Variable que borrar una vez en cada if

void setup() {
  Serial.begin(9600); // inicio de comunicacion serial
  lcd.init();
  lcd.backlight();
  lcd.clear();
  // Declaracion de pines como entrada y salida
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  lcd.createChar(0, bloque); // Creacion de caracter
}


void loop() {
  Distancia = HC(); // Guardado de distancia con ultrasonico
  // Muestra en pantalla serial la distancia actual
  Serial.print("Distancia alctual: ");
  Serial.println(Distancia);

  if (Distancia >= 45 && Distancia <= 55) { // En un rango de 45cm a 55cm va a marcar una distancia de 50
    if (Salto != 1) { // Borra una vez la pantalla para evitar el parpadeo de la pantalla
      lcd.clear();
    }
    lcd.setCursor(4, 0);
    GRUPOBLOQUES(3); // Funcion para poner caracteres en pantalla
    lcd.print("50");
    GRUPOBLOQUES(3);  // Funcion para poner caracteres en pantalla
    lcd.setCursor(5, 1);
    lcd.print("Libre");
    Salto = 1;
  }
  else if (Distancia >= 25 && Distancia <= 35) { // En un rango de 25cm a 35cm va a marcar una distancia de 30
    if (Salto != 2) { // Borra una vez la pantalla para evitar el parpadeo de la pantalla
      lcd.clear();
    }
    lcd.setCursor(2, 0);
    GRUPOBLOQUES(5);  // Funcion para poner caracteres en pantalla
    lcd.print("30");
    GRUPOBLOQUES(5);  // Funcion para poner caracteres en pantalla
    lcd.setCursor(5, 1);
    lcd.print("Cuidado");
    Salto = 2;
  }
  else if (Distancia >= 5 && Distancia <= 15) { // En un rango de 5cm a 15cm va a marcar una distancia de 10
    if (Salto != 3) { // Borra una vez la pantalla para evitar el parpadeo de la pantalla
      lcd.clear();
    }
    lcd.setCursor(0, 0);
    GRUPOBLOQUES(7);  // Funcion para poner caracteres en pantalla
    lcd.print("10");
    GRUPOBLOQUES(7);  // Funcion para poner caracteres en pantalla
    lcd.setCursor(6, 1);
    lcd.print("Alto");
    Salto = 3;
  }
}
int HC () { // Funcion para usar el sensor ultrasonico y regresar un numero
  digitalWrite(Trig, HIGH);
  delay(1);
  digitalWrite(Trig, LOW);
  int DistanciaLocal = pulseIn(Echo, HIGH) / 52.8;
  return DistanciaLocal;
}

void GRUPOBLOQUES(byte Bloques) { // Crea bloques de manera ciclica en lcd
  for (byte i = 0; i < Bloques; i++) {
    lcd.write(byte(0));
  }
}
