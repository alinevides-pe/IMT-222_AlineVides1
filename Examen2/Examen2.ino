//Practica 4– Comunicación Digital: I2C y SPI
//Integrantes: 
//Aline Vides
//Jose Fernandez
//Nataly Romero

#include "funciones.h"

void setup() {
  iniciarSerial();   // Inicializa Serial
  iniciarI2C();      // Inicializa bus I2C
  iniciarSensor();   // Inicializa el sensor
  iniciarLEDs();     // Inicializa LEDs
}

void loop() {
  actualizarFSM();   // Máquina de estados que controla lectura y LEDs
  delay(500);        
}
