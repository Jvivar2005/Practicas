//Fundación Kinal
//Centro Educativo Técnico Labral Kinal
//Electrónica
//Grado: Quinto
//Sección: A
//Curso: Taller de Electrónica Digital y Reparación de Computadoras I
//Nombre: Javier ricardo vivar sanchez 
//Carné: 2019585
//  Pines a utilizar en arduino
// Pines de Ultrasonico
int Trig = 2;
int Echo = 3;

// Pines de Display
int A = 4;
int B = 5;
int C = 6;
int D = 7;
int E = 8;
int F = 9;
int G = 10;

// Pin de Rele
int Rele = 11;

// Variables de programa
int personas;  // Lleva el conteo de las personas

void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(Rele, OUTPUT);
  digitalWrite(Rele, HIGH);
  cero();  // inicia mostrando el cero
}

void loop() {
  int distancia = DH();
  Serial.println(distancia);
  if (distancia >= 6 && distancia <= 10) {
    personas++;
    switch (personas) {
      case 1:
        uno();
        break;
      case 2:
        dos();
        break;
      case 3:
        tres();
        break;
      case 4:
        cuatro();
        break;
      case 5:
        cinco();
        break;
      case 6:
        seis();
        break;
      case 7:
        siete();
        break;
      case 8:
        ocho();
        break;
      case 9:
        nueve();
        break;
      case 10:
        Serial.println("9 personas");
        digitalWrite(Rele, LOW);
        cero();
        break;
    }
  }
  delay(700);
}

int DH() {  // Funcion para hacer funcionar el ultrasonico y retornar el valor de distancia
  digitalWrite(Trig, HIGH);
  delay(1);
  digitalWrite(Trig, LOW);
  int Tiempo = pulseIn(Echo, HIGH);
  int Distancia = Tiempo / 52.8;
  return Distancia;
}

// Funciones para mostrar numeros en el display
// Cada funcion enciende y apaga cada led necesario para mostrar su numero
void cero() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}
void uno() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void dos() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void tres() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}
void cuatro() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void cinco() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void seis() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void siete() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}
void ocho() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
void nueve() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}
