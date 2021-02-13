#include <LiquidCrystal.h>
#include "variables.h"
#include "corriente.h"

void get_programa()
{
float Irms = get_corriente();
float p = Irms*220.0;                                /* P=I*V (Watts) */
float P = p/1000;                                    /* Potencia en Kw */
long milisec = millis();                             /* calcular el tiempo en milisegundos */
long time = milisec/1000;                            /* convertir de milisegundos a segundos */
float energy=(p*time)/(3600000);                     /* para la lectura en kWh */

int sensorValue = analogRead(A1);                    /* Lectura del pin del anemometro */
float outvoltage = sensorValue * (5.0 / 1023.0);     /* voltaje del sensor */
int Level = 6*outvoltage;                            /* Viento=6*U  */
float potencia = 0;                                  /* Definir corte en funcion del viento*/

/* Configuracion de rangos de nivel del viento */   
   switch (int Level = 6*outvoltage) {
  case 1:
    potencia = 0.76;
    break;
  case 2:
    potencia = 0.76;
    break;
  case 3:
    potencia = 0.96;
    break;
  case 4:
    potencia = 1.04;
    break;
  case 5:
    potencia = 2.94;
    break;
  case 6:
    potencia = 4.84;
    break;
  case 7:
    potencia = 7.64;
    break;
  case 8:
    potencia = 10.44;
    break;
  case 9:
    potencia = 12.84;
    break;
  case 10:
    potencia = 15.24;
    break;  
  case 11:
    potencia = 17.24;
    break;  
   default:
    potencia = 17.24;
    break;
  }
   Serial.print("Voltaje:");
   Serial.print(outvoltage);
   Serial.print("V");
   Serial.print("La velocidad del viento es:");
   Serial.print(Level);
   Serial.print(" Velocidad actual:");
   Serial.print("");
   delay(500);

/* Bloqueo del sistema */
if (float energy=(p*time)/(3600000) >= potencia){    /* Condicion para cambio de tension */
  digitalWrite(rele3, LOW);                        
  }
  /* Configuracion del LCD 20x4: */
  lcd.clear();
  lcd.setCursor(0,0);                                /* Cursor en la 1° posicion de la 1° fila */
  lcd.print("Medicion de consumo:");
  lcd.setCursor(0,1);                                /* Cursor en la 1° posicion de la 3° fila */
  lcd.print("Diario:");
  lcd.print(energy,2);                               /* 2 decimales */
  lcd.print("kWh"); 
  lcd.setCursor(0,2);                                /* Cursor en la 1° posicion de la 3° fila */
  lcd.print("Corriente:");
  lcd.print(Irms,2);                                 /* 2 decimales */
  lcd.print("A");                                    /* Valor de corriente */
  lcd.setCursor(0,3);                                /* Cursor en la 1° posicion de la 4° fila */
  lcd.print("Potencia:");
  lcd.print(P,2);                                    /* 2 decimales */
  lcd.print("kW");                                   /* Valor de potencia */
  delay(200);                                        /* Retraso mostrar valores */
     
  /* Valores para modo consola Serial port USB/9600 baudios */
  Serial.print("Corriente:");                       /* Texto "Irms:" */
  Serial.print(Irms,2);                              /* Valor de la corriente */
  Serial.print("A");                                 /* Unidad de medida, 2 decimales */
  Serial.print("Potencia (W):");                     /* Texto "Pontecia:" */
  Serial.print(p,2);                                 /* Valor de la potencia en Watts */
  Serial.print("W");                                 /* Unidad de medida, 2 decimales */
  Serial.print("Potencia (kW):");                    /* Texto "Pontecia:" */
  Serial.print(p,2);                                 /* Valor de la potencia en kW */
  Serial.print("kW");                                /* Unidad de medida, 2 decimales */
  Serial.print("Diario:");                           /* Texto "Pontecia:" */
  Serial.print(energy,2);                            /* Valor de la potencia en Watts-hora */
  Serial.print("kWh");                               /* Unidad de medida, 2 decimales */
  delay(200);                                        /* Retraso valores */
}
