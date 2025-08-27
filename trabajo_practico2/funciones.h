// cabezeras o prototipos de nuestras funciones
#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#define DELAY 1000
#define LED1 10
#define LED2 11
#define LED3 12
#define LED4 13  //NO SON VARIABLES
#define BTN 18
#define BAUDRATE 9600 //reloj del serial 
bool flag = false;
//uint8_t flag = 0; 
void configuracion();
void espera();
void secuencia();


#endif