/* Incluir la libreria del LCD: */ 
#include <LiquidCrystal.h>
#include "src\Programa.h"                            /* Incluye las variables a utilizar */
#include "src\Botones.h"                             /* Instrucciones del boton con memoria */

void setup() {
  /* Inicializar el pin de la entrada del boton: */
  pinMode(boton, INPUT);                             /* Pin 2 entrada boton */
  
  /* Configuracion rele 1 y 2 */
  pinMode(rele1,OUTPUT);                             /* Pines de rele se definen como salidas */
  pinMode(rele2,OUTPUT);                             /* Pines de rele se definen como salidas */
  pinMode(rele3,OUTPUT);                             /* Pines de rele se definen como salidas */
  digitalWrite(rele3,HIGH);
//  digitalWrite(rele1,HIGH);                          /* Y se inicializan en alto (rele desactivado) */
//  digitalWrite(rele2,LOW);                           /* Y se inicializan en LOW (rele activado) */

  /* Inicializar el LCD con el número de columnas y filas del LCD */
  lcd.begin(20,4);                                   /* LCD 20x4 */

  /* Variables Sensor */
  Serial.begin(9600);                                /* Salida monitor serie (debug) */
  analogReference(INTERNAL);                         /* Lectura de puertos analogicos */
}

void loop() {
/* Llamar a las librerias para que cumplan su funcion */  
  get_programa();                                    /* Llamo a la funcion programa.h (creacion propia)*/ 
  get_boton();                                       /* Llamo a la funcion botones.h (creacion propia) */
}
