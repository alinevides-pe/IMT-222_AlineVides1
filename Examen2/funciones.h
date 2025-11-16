#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>

#define PIN_SDA 21
#define PIN_SCL 22
#define LED_SENSOR 2    // LED indica que el sensor está listo
#define LED_ALERTA 4    // LED se enciende si la temperatura es alta

// Sensor
extern Adafruit_MLX90614 mlx;

// Variables 
#define BAUDRATE 115200
extern float temperaturaObjeto;
extern float temperaturaAmbiente;
extern float tempLimite; // Temperatura de alerta
enum EstadosFSM { SENSOR_NO_LISTO, SENSOR_LISTO, ALERTA_TEMP };
extern EstadosFSM estadoActual;

// Funciones 
void iniciarSerial();
void iniciarI2C();
void iniciarSensor();
void iniciarLEDs();
void leerTemperaturas();
void actualizarFSM();
void actualizarLEDs();

#endif
