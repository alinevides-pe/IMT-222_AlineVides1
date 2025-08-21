# IMT-222_AlineVides1
// Programa: Encender 10 LEDs en secuencia con 2s de intervalo
// Autor: Aline Vides
// Materia: Sistemas Embebidos

// Definimos los pines para los 10 LEDs
int leds[10] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

void setup() {
  // Configuramos todos los pines como salida
  for (int i = 0; i < 10; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Encender LEDs uno por uno en secuencia
  for (int i = 0; i < 10; i++) {
    digitalWrite(leds[i], HIGH);   // Enciende LED i
    delay(2000);                   // Espera 2 segundos
    digitalWrite(leds[i], LOW);    // Apaga LED i
  }
}
