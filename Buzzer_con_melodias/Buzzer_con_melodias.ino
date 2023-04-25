//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585
int Trig = 2;
int Echo = 3;
int Buzzer = 7;
int distancia;

int c = 261;
int d = 294;
int e = 329;
int f = 349;
int g = 391;
int gS = 415;
int a = 440;
int aS = 455;
int b = 466;
int cH = 523;
int cSH = 554;
int dH = 587;
int dSH = 622;
int eH = 659;
int fH = 698;
int fSH = 740;
int gH = 783;
int gSH = 830;
int aH = 880;

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(Buzzer, OUTPUT);
}

void loop() {
  distancia = HC();
  Serial.println(distancia);
  // El buzzer empezara a sonar mientras que el objeto y el ultrasonico esten en una distancia
  // mayor a 10cm  y menor a 67cm
  // Fuera de estos rangos se apagara el buzzer
  if (distancia > 10 && distancia <= 13) {  // C
    tone(Buzzer, c);
  } else if (distancia > 13 && distancia <= 16) {  // D
    tone(Buzzer, d);
  } else if (distancia > 16 && distancia <= 19) {  // E
    tone(Buzzer, e);
  } else if (distancia > 19 && distancia <= 22) {  // F
    tone(Buzzer, f);
  } else if (distancia > 22 && distancia <= 25) {  // G
    tone(Buzzer, g);
  } else if (distancia > 25 && distancia <= 28) {  // GS
    tone(Buzzer, gS);
  } else if (distancia > 28 && distancia <= 31) {  // A
    tone(Buzzer, a);
  } else if (distancia <= 10 || distancia <= 31) {  // AS
    tone(Buzzer, aS);
  } else if (distancia > 31 && distancia <= 34) {  // B
    tone(Buzzer, b);
  } else if (distancia > 37 && distancia <= 40) {  // CH
    tone(Buzzer, cH);
  } else if (distancia > 40 && distancia <= 43) {  // CSH
    tone(Buzzer, cSH);
  } else if (distancia > 43 && distancia <= 46) {  // DH
    tone(Buzzer, dH);
  } else if (distancia > 46 && distancia <= 49) {  // DSH
    tone(Buzzer, dSH);
  } else if (distancia > 49 && distancia <= 52) {  // EH
    tone(Buzzer, eH);
  } else if (distancia <= 52 || distancia <= 55) {  // FH
    tone(Buzzer, fH);
  } else if (distancia > 55 && distancia <= 58) {  // FSH
    tone(Buzzer, fSH);
  } else if (distancia > 58 && distancia <= 61) {  // GH
    tone(Buzzer, gH);
  } else if (distancia > 61 && distancia <= 64) {  // GSH
    tone(Buzzer, gSH);
  } else if (distancia > 64 && distancia <= 67) {  // AH
    tone(Buzzer, aH);
  } else if (distancia <= 10 || distancia > 67) {  // No ruido
    noTone(Buzzer);
  }
}

int HC() {  // Funcion para hacer funcionar el ultrasonico y retornar el valor de distancia
  digitalWrite(Trig, HIGH);
  delay(1);
  digitalWrite(Trig, LOW);
  int Tiempo = pulseIn(Echo, HIGH);
  int Distancia = Tiempo / 52.8;
  return Distancia;
}
