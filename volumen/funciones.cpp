#include "funciones.h"

uint8_t vol;
uint8_t canal;

unsigned long lastChange = 0;         
const unsigned long SAVE_DELAY = 2000; 
uint8_t lastSavedVol;
uint8_t lastSavedCanal;

void conf(void){
  Serial.begin(BAUDRATE);
  pinMode(BTNUP, INPUT_PULLUP);
  pinMode(BTNDOWN, INPUT_PULLUP);
  pinMode(BTNCHUP, INPUT_PULLUP);
  pinMode(BTNCHDOWN, INPUT_PULLUP);

  // Leer valores previos de EEPROM
  vol   = EEPROM.read(ADDR_VOL);
  canal = EEPROM.read(ADDR_CH);

  // Validar rangos
  if (vol < MINVOL || vol > MAXVOL) vol = VOL_DEF;
  if (canal < MINCH || canal > MAXCH) canal = CH_DEF;

  // Guardar última versión conocida
  lastSavedVol   = vol;
  lastSavedCanal = canal;

  Serial.println(F("[INIT] Valores iniciales:"));
  printEstado();
}

void subirVol(void){
  if (vol < MAXVOL) {
    vol++;
    lastChange = millis();
    Serial.println(F("[VOL] ++"));
    printEstado();
  }
}

void bajarVol(void){
  if (vol > MINVOL) {
    vol--;
    lastChange = millis();
    Serial.println(F("[VOL] --"));
    printEstado();
  }
}

void subirCanal(void){
  canal++;
  if (canal > MAXCH) canal = MINCH; // wrap-around
  lastChange = millis();
  Serial.println(F("[CH] ++"));
  printEstado();
}

void bajarCanal(void){
  if (canal == MINCH) canal = MAXCH;
  else canal--;
  lastChange = millis();
  Serial.println(F("[CH] --"));
  printEstado();
}

void printEstado(){
  Serial.print(F("Volumen=")); Serial.print(vol);
  Serial.print(F("  Canal=")); Serial.println(canal);
}

void saveIfIdle(){
  if (lastChange > 0 && millis() - lastChange >= SAVE_DELAY) {
    if (vol != lastSavedVol || canal != lastSavedCanal) {
      EEPROM.update(ADDR_VOL, vol);
      EEPROM.update(ADDR_CH, canal);
      lastSavedVol   = vol;
      lastSavedCanal = canal;
      Serial.println(F("[SAVE] Valores guardados en EEPROM"));
    }
    lastChange = 0; // reinicia
  }
}