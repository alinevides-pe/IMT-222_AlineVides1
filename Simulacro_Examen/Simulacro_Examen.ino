#include "funciones.h"
void setup() {
  PinModes();
  conf();
}

void loop() {
  SubirMin();
  BajarMin();
  SubirSeg();
  BajarSeg();
  CambiarModo();
  GuardarTiempo();
}
