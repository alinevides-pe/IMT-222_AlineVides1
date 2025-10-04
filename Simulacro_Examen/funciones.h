#ifndef FUNCIONES_C
#define FUNCIONES_C

#include <Arduino.h>
#include <EEPROM.h>

// Definiciones
#define BTN_UP    2
#define BTN_DOWN  3
#define BTN_MODE  4
#define BTN_SAVE  5

#define LED_MIN   6
#define LED_SEG   7

#define BAUDRATE 9600

#define DIR_MIN  0
#define DIR_SEG  1

// Variables globales
extern bool ESTADOBTN_UP;
extern bool ESTADOBTN_DOWN;
extern bool ESTADOBTN_MODE;
extern bool ESTADOBTN_SAVE;
extern int MIN;
extern int SEG;
extern bool activoEnMin;

void conf();
void PinModes();
void SubirMin();
void BajarMin();
void SubirSeg();
void BajarSeg();
void CambiarModo();
void GuardarTiempo();

#endif
