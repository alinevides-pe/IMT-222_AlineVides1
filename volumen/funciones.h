#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <EEPROM.h>

// Pulsadores
#define BTNUP     2   // Subir volumen
#define BTNDOWN   3   // Bajar volumen
#define BTNCHUP   8   // Subir canal
#define BTNCHDOWN 9   // Bajar canal
#define BAUDRATE  9600
#define MINVOL    0
#define MAXVOL    100
#define MINCH     1
#define MAXCH     9
#define ADDR_VOL  0
#define ADDR_CH   1
#define VOL_DEF   50
#define CH_DEF    1

extern uint8_t vol;
extern uint8_t canal;

void conf(void);
void subirVol();
void bajarVol();
void subirCanal();
void bajarCanal();
void printEstado();
void saveIfIdle();

#endif