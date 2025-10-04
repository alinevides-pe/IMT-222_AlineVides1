#include "funciones.h"

// Variables globales
bool ESTADOBTN_UP = HIGH;
bool ESTADOBTN_DOWN = HIGH;
bool ESTADOBTN_MODE = HIGH;
bool ESTADOBTN_SAVE = HIGH;

int MIN = 0;
int SEG = 0;
bool activoEnMin = true; // true = MIN, false = SEG

// Límites
int MINMAX = 59;
int SEGMAX = 59;
int MINMIN = 0;
int SEGMIN = 0;

void conf(){
  Serial.begin(BAUDRATE);

  MIN = EEPROM.read(DIR_MIN);
  SEG = EEPROM.read(DIR_SEG);

  // Mecanismo fantasma
  if (MIN < MINMIN || MIN > MINMAX) MIN = 0;
  if (SEG < SEGMIN || SEG > SEGMAX) SEG = 0;

  Serial.print("Minutos inicial: ");
  Serial.println(MIN);
  Serial.print("Segundos inicial: ");
  Serial.println(SEG);

  digitalWrite(LED_MIN, HIGH);
  digitalWrite(LED_SEG, LOW);
}

void PinModes(){
  pinMode(BTN_UP, INPUT);
  pinMode(BTN_DOWN, INPUT);
  pinMode(BTN_MODE, INPUT);
  pinMode(BTN_SAVE, INPUT);

  pinMode(LED_MIN, OUTPUT);
  pinMode(LED_SEG, OUTPUT);
}

void SubirMin(){
  ESTADOBTN_UP = digitalRead(BTN_UP);
  if (ESTADOBTN_UP == LOW && activoEnMin) {
    if (MIN < MINMAX) MIN++;
    Serial.print("MIN: ");
    Serial.println(MIN);
    delay(250);
  }
}

void BajarMin(){
  ESTADOBTN_DOWN = digitalRead(BTN_DOWN);
  if (ESTADOBTN_DOWN == LOW && activoEnMin) {
    if (MIN > MINMIN) MIN--;
    Serial.print("MIN: ");
    Serial.println(MIN);
    delay(250);
  }
}

void SubirSeg(){
  ESTADOBTN_UP = digitalRead(BTN_UP);
  if (ESTADOBTN_UP == LOW && !activoEnMin) {
    if (SEG < SEGMAX) SEG++;
    Serial.print("SEG: ");
    Serial.println(SEG);
    delay(250);
  }
}

void BajarSeg(){
  ESTADOBTN_DOWN = digitalRead(BTN_DOWN);
  if (ESTADOBTN_DOWN == LOW && !activoEnMin) {
    if (SEG > SEGMIN) SEG--;
    Serial.print("SEG: ");
    Serial.println(SEG);
    delay(250);
  }
}

void CambiarModo(){
  ESTADOBTN_MODE = digitalRead(BTN_MODE);
  if (ESTADOBTN_MODE == LOW) {
    activoEnMin = !activoEnMin;
    digitalWrite(LED_MIN, activoEnMin);
    digitalWrite(LED_SEG, !activoEnMin);
    Serial.println(activoEnMin ? "Configurando MIN" : "Configurando SEG");
    delay(250);
  }
}

void GuardarTiempo(){
  ESTADOBTN_SAVE = digitalRead(BTN_SAVE);
  if (ESTADOBTN_SAVE == LOW) {
    EEPROM.update(DIR_MIN, MIN);
    EEPROM.update(DIR_SEG, SEG);
    Serial.print("Guardado -> MIN: ");
    Serial.print(MIN);
    Serial.print(" SEG: ");
    Serial.println(SEG);
    delay(250);
  }
}