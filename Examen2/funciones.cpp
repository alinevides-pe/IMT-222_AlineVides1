#include "funciones.h"

// =========Sensor========
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

// ======= Variables =======
float temperaturaObjeto = 0;
float temperaturaAmbiente = 0;
float tempLimite = 37.0; // Temperatura limite de alerta
EstadosFSM estadoActual = SENSOR_NO_LISTO;

// Inicializa Serial 
void iniciarSerial() {
  Serial.begin(BAUDRATE);
  delay(200);
  Serial.println("INICIANDO EL PROGRAMA:) :");
}

// Inicializa bus I2C 
void iniciarI2C() {
  Wire.begin(PIN_SDA, PIN_SCL);
  Serial.println("Bus I2C iniciado");
}

//Inicializa sensor 
void iniciarSensor() {
  if (!mlx.begin()) {
    Serial.println("ERROR :( : el sensor no fue encontrado");
    estadoActual = SENSOR_NO_LISTO;
    while(1) delay(1000);
  } else {
    estadoActual = SENSOR_LISTO;
    Serial.println("Sensor de temperatura detectado :)");
  }
}

// Inicializa LEDs 
void iniciarLEDs() {
  pinMode(LED_SENSOR, OUTPUT);
  pinMode(LED_ALERTA, OUTPUT);
  actualizarLEDs(); // Actualiza LEDs segun el estado inicial
}

// Lee temperaturas 
void leerTemperaturas() {
  temperaturaAmbiente = mlx.readAmbientTempC();
  temperaturaObjeto = mlx.readObjectTempC();

  Serial.print("Temp ambiente: ");
  Serial.print(temperaturaAmbiente);
  Serial.print(" °C, Objeto: ");
  Serial.print(temperaturaObjeto);
  Serial.println(" °C");
}

// FSM 
void actualizarFSM() {
  leerTemperaturas();

  // Cambia el estado segun la temperatura
  if (estadoActual == SENSOR_LISTO) {
    if (temperaturaObjeto >= tempLimite) {
      estadoActual = ALERTA_TEMP;
      Serial.println("ALERTA: temperatura alta :O");
    }
  } else if (estadoActual == ALERTA_TEMP) {
    if (temperaturaObjeto < tempLimite) {
      estadoActual = SENSOR_LISTO;
      Serial.println("Temperatura normal :3");
    }
  }

  actualizarLEDs();
}

// Actualiza LEDs segun el estado 
void actualizarLEDs() {
  if (estadoActual == SENSOR_LISTO) {
    digitalWrite(LED_SENSOR, HIGH);
    digitalWrite(LED_ALERTA, LOW);
  } else if (estadoActual == ALERTA_TEMP) {
    digitalWrite(LED_SENSOR, HIGH);
    digitalWrite(LED_ALERTA, HIGH);
  } else { // SENSOR_NO_LISTO
    digitalWrite(LED_SENSOR, LOW);
    digitalWrite(LED_ALERTA, LOW);
  }
}

