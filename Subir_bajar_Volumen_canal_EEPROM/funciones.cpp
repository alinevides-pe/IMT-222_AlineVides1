#include "funciones.h"

// Variables
bool ESTADODEBOTON1 = HIGH;
bool ESTADODEBOTON2 = HIGH;
bool ESTADODEBOTON3 = HIGH;
bool ESTADODEBOTON4 = HIGH;
int VOL = 5;
int CANAL = 1;
int VOLMAX = 10;
int VOLMIN = 0;
int CANALMAX = 10;
int CANALMIN = 1;


void conf(){

  Serial.begin(BAUDRATE);
  VOL   = EEPROM.read(Direccion_vol);
  CANAL = EEPROM.read(Direccion_canal);


  // Mecanismo fantasma 
  if (VOL   < VOLMIN   || VOL   > VOLMAX)   VOL   = 5;
  if (CANAL < CANALMIN || CANAL > CANALMAX) CANAL = 1;


  Serial.print("Volumen inicial: ");
  Serial.println(VOL);
  Serial.print("Canal inicial: ");
  Serial.println(CANAL);
}
void PinModes(){
  pinMode(BOTON1, INPUT);
  pinMode(BOTON2, INPUT);
  pinMode(BOTON3, INPUT);
  pinMode(BOTON4, INPUT);
}
void SubirVol(){
  ESTADODEBOTON1 = digitalRead(BOTON1); 
  if(ESTADODEBOTON1 == LOW){
    if(VOL< VOLMAX){
      VOL++;
      Serial.print("Volumen: ");
      Serial.println(VOL);
      EEPROM.update(Direccion_vol, VOL);
      delay(250);
   
    }
    else{
      Serial.print("Volumen: ");
      Serial.println(VOL);
      delay(250);
    }
 }
}

void BajarVol(){
 ESTADODEBOTON2 = digitalRead(BOTON2); 
 if(ESTADODEBOTON2 == LOW){
  if(VOL>VOLMIN){
    VOL--;
    Serial.print("Volumen: ");
    Serial.println(VOL);
    delay(250);
    EEPROM.update(Direccion_vol, VOL);
    

  }
  else{
      Serial.print("Volumen: ");
      Serial.println(VOL);
      delay(250);
    }
 }
}

void SubirCanal(){
 ESTADODEBOTON3 = digitalRead(BOTON3); 
 if(ESTADODEBOTON3 == LOW){
  if(CANAL<CANALMAX){
    CANAL++;
    Serial.print("Canal: ");
    Serial.println(CANAL);
    EEPROM.update(Direccion_canal, CANAL);
    delay(250);
  }
  else{
      Serial.print("Canal: ");
      Serial.println(CANAL);
      delay(250);
    }
 }
}
void BajarCanal(){
 ESTADODEBOTON4 = digitalRead(BOTON4); 
 if(ESTADODEBOTON4 == LOW){
  if(CANAL>CANALMIN){
    CANAL--;
    Serial.print("Canal: ");
    Serial.println(CANAL);
    EEPROM.update(Direccion_canal, CANAL);
    delay(250);
  }
  else{
      Serial.print("Canal: ");
      Serial.println(CANAL);
      delay(250);
    }
 }

}