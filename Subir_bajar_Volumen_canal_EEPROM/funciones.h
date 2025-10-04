#ifndef FUNCIONES_C
#define FUNCIONES_C

#include <Arduino.h>
#include <EEPROM.h>


// Define
#define BOTON1 5
#define BOTON2 2
#define BOTON3 3
#define BOTON4 4
#define BAUDRATE 9600
#define Direccion_canal 0
#define Direccion_vol 1


// Variables
extern bool ESTADODEBOTON1;
extern bool ESTADODEBOTON2;
extern bool ESTADODEBOTON3;
extern bool ESTADODEBOTON4;
extern int VOL;
extern int CANAL;
extern int VOLMAX;
extern int VOLMIN;
extern int CANALMAX;
extern int CANALMIN;

void conf();
void PinModes();
void SubirVol();
void BajarVol();
void SubirCanal();
void BajarCanal();
#endif