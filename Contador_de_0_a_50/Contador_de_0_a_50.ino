/*
 * Fundacion Kinal
 * centro educativo laboral kinal
 * Electronica
 * Quinto
 * A
 * taller de electronica digital reparacion en computadoras 
 * javier ricardo vivar sanchez
 * 2019585
 * Uso de interrupciones externas iii 
 */
 //directivas de procesador
#define Boton1 2
#define Boton2 3
// definir los pines del primer display 
#define UA A2
#define UB A3
#define UC 4
#define UD 5
#define UE 6
#define UF 7
#define UG 8
// definir los pines del segundo display
#define DA 9
#define DB 10
#define DC 11
#define DD 12
#define DE 13
#define DF A0
#define DG A1

byte Uleds[7] = {A2, A3, 4, 5, 6, 7, 8};
byte Dleds[7] = {9, 10, 11, 12, 13, A0, A1};

int Ucontador = 0;
byte Dcontador = 0;
byte contador = 0;

void setup() {
  Serial.begin(19200);
  for (byte i = 0; i >= 6; i++) {
    pinMode(Uleds[i], OUTPUT);
  }
  attachInterrupt(digitalPinToInterrupt(Boton1), mas, RISING);
  attachInterrupt(digitalPinToInterrupt(Boton2), menos, FALLING);
}

void loop() {
  Serial.println(contador);

  switch (Ucontador) {
    case -1:
      Ucontador = 9;
      Dcontador--;
      break;
    case 0:
      cero();
      break;
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
      Ucontador = 0;
      Dcontador++;
      break;
  }
  switch (Dcontador) {
    case 0:
      Dcero();
      break;
    case 1:
      Duno();
      break;
    case 2:
      Ddos();
      break;
    case 3:
      Dtres();
      break;
    case 4:
      Dcuatro();
      break;
    case 5:
      Dcinco();
      break;
  }
}


void mas() {
  if (contador < 50) {
    Ucontador++;
    contador++;
  }
 
}

void menos() {
  if (contador > 0) {
    Ucontador--;
    contador--;
  }
}

void cero() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, HIGH);
  digitalWrite(UE, HIGH);
  digitalWrite(UF, HIGH);
  digitalWrite(UG, LOW);
}

void uno() {
  digitalWrite(UA, LOW);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, LOW);
  digitalWrite(UE, LOW);
  digitalWrite(UF, LOW);
  digitalWrite(UG, LOW);
}
void dos() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, LOW);
  digitalWrite(UD, HIGH);
  digitalWrite(UE, HIGH);
  digitalWrite(UF, LOW);
  digitalWrite(UG, HIGH);
}
void tres() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, HIGH);
  digitalWrite(UE, LOW);
  digitalWrite(UF, LOW);
  digitalWrite(UG, HIGH);
}

void cuatro() {
  digitalWrite(UA, LOW);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, LOW);
  digitalWrite(UE, LOW);
  digitalWrite(UF, HIGH);
  digitalWrite(UG, HIGH);
}

void cinco() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, LOW);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, HIGH);
  digitalWrite(UE, LOW);
  digitalWrite(UF, HIGH);
  digitalWrite(UG, HIGH);
}

void seis() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, LOW);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, HIGH);
  digitalWrite(UE, HIGH);
  digitalWrite(UF, HIGH);
  digitalWrite(UG, HIGH);
}

void siete() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, LOW);
  digitalWrite(UE, LOW);
  digitalWrite(UF, LOW);
  digitalWrite(UG, LOW);
}

void ocho() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, HIGH);
  digitalWrite(UE, HIGH);
  digitalWrite(UF, HIGH);
  digitalWrite(UG, HIGH);
}

void nueve() {
  digitalWrite(UA, HIGH);
  digitalWrite(UB, HIGH);
  digitalWrite(UC, HIGH);
  digitalWrite(UD, LOW);
  digitalWrite(UE, LOW);
  digitalWrite(UF, HIGH);
  digitalWrite(UG, HIGH);
}

void Dcero() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, HIGH);
  digitalWrite(DE, HIGH);
  digitalWrite(DF, HIGH);
  digitalWrite(DG, LOW);
}

void Duno() {
  digitalWrite(DA, LOW);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, LOW);
  digitalWrite(DE, LOW);
  digitalWrite(DF, LOW);
  digitalWrite(DG, LOW);
}
void Ddos() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, LOW);
  digitalWrite(DD, HIGH);
  digitalWrite(DE, HIGH);
  digitalWrite(DF, LOW);
  digitalWrite(DG, HIGH);
}
void Dtres() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, HIGH);
  digitalWrite(DE, LOW);
  digitalWrite(DF, LOW);
  digitalWrite(DG, HIGH);
}

void Dcuatro() {
  digitalWrite(DA, LOW);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, LOW);
  digitalWrite(DE, LOW);
  digitalWrite(DF, HIGH);
  digitalWrite(DG, HIGH);
}

void Dcinco() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, LOW);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, HIGH);
  digitalWrite(DE, LOW);
  digitalWrite(DF, HIGH);
  digitalWrite(DG, HIGH);
}

void Dseis() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, LOW);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, HIGH);
  digitalWrite(DE, HIGH);
  digitalWrite(DF, HIGH);
  digitalWrite(DG, HIGH);
}

void Dsiete() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, LOW);
  digitalWrite(DE, LOW);
  digitalWrite(DF, LOW);
  digitalWrite(DG, LOW);
}

void Docho() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, HIGH);
  digitalWrite(DE, HIGH);
  digitalWrite(DF, HIGH);
  digitalWrite(DG, HIGH);
}

void Dnueve() {
  digitalWrite(DA, HIGH);
  digitalWrite(DB, HIGH);
  digitalWrite(DC, HIGH);
  digitalWrite(DD, LOW);
  digitalWrite(DE, LOW);
  digitalWrite(DF, HIGH);
  digitalWrite(DG, HIGH);
}
