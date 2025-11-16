#include <Arduino.h>

#define PIN_LED_RAPIDO 12   //Led rapido
#define PIN_LED_LENTO 14    //Led lento
#define TIMER1 50
#define TIMER2 2000
#define TIMER3 4000
#define BAUDRATE 115200

void TaskLedRapido (void * pvParameters);
void TaskLedLento (void * pvParameters);
void TaskMensajeSerial (void * pvParameters);

void setup() {
  Serial.begin(BAUDRATE);
  Serial.println ("FreeRTOS: tres tareas");
  pinMode(PIN_LED_RAPIDO, OUTPUT);
  pinMode(PIN_LED_LENTO, OUTPUT);

  xTaskCreate(
    TaskLedRapido,
    "LED_RAPIDO",
    1024,
    NULL,
    2,
    NULL
  );

  xTaskCreate(
    TaskLedLento,
    "LED_LENTO",
    1024,
    NULL,
    1,
    NULL
  );

  xTaskCreate(
    TaskMensajeSerial,
    "MSG_SERIAL",
    2048,
    NULL,
    1,
    NULL
  );

}

void loop() {
  // No se usa con FreeRTOS: Las tareas corren en paralelo
}

//------TAREA 1: LED RAPIDO-------------
void TaskLedRapido (void * pvParameters){
  (void) pvParameters;
  for (;;){
    digitalWrite (PIN_LED_RAPIDO, HIGH);
    vTaskDelay(pdMS_TO_TICKS(TIMER1));
    digitalWrite(PIN_LED_RAPIDO, LOW);
    vTaskDelay(pdMS_TO_TICKS(TIMER1));
  }
}

//------TAREA 2: LED LENTO-------------
void TaskLedLento (void * pvParameters){
  (void) pvParameters;
  for (;;){
    digitalWrite (PIN_LED_LENTO, HIGH);
    vTaskDelay(pdMS_TO_TICKS(TIMER2));
    digitalWrite(PIN_LED_LENTO, LOW);
    vTaskDelay(pdMS_TO_TICKS(TIMER2));
  }
}

//------TAREA 3: MENSAJE SERIAL-------------
void TaskMensajeSerial (void * pvParameters){
  (void) pvParameters;
  for (;;){
    Serial.println("Tarea Serial ejecutada cada 4s");
    vTaskDelay(pdMS_TO_TICKS(TIMER3));
  }
}