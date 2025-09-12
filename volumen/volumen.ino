#include "funciones.h"

void setup() {
  conf();
}

void loop() {
  // Leer botones (activos en LOW con INPUT_PULLUP)
  if (!digitalRead(BTNUP))    { subirVol();   delay(2000); }
  if (!digitalRead(BTNDOWN))  { bajarVol();   delay(2000); }
  if (!digitalRead(BTNCHUP))  { subirCanal(); delay(2000); }
  if (!digitalRead(BTNCHDOWN)){ bajarCanal(); delay(2000); }

  // Guardar en EEPROM si pasaron 2 s sin cambios
  saveIfIdle();
}
// Esto fue dificil porque pensamos que le problema era el codigo pero en realidad fue que
//no pusismos resistencia a los pulsadores y recien dio el codigo 
