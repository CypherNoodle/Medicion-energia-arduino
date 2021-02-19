#include <LiquidCrystal.h>
#include "Variables.h"
#include "Corriente.h"

void get_programa()
{
/* Configuracion del sensor de corriente */	
float Irms = get_corriente();
float p = Irms*220.0;                                /* P=I*V (Watts) */
float P = p/1000;                                    /* Potencia en kW */
long  milisec = millis();                            /* Calcular el tiempo en milisegundos */
long  time = milisec/1000;                           /* Convertir de milisegundos a segundos */
float energy=(p*time)/(3600000);                     /* Lectura en kWh a tiempo real */

/* Configuracion del anemometro */
int   sensorValue = analogRead(A1);                  /* Lectura del pin del anemometro */
float outvoltage = sensorValue * (5.0 / 1023.0);     /* Voltaje del sensor */
int   Level = 6*outvoltage;                          /* Viento=6*U, valor entero */
float potencia = 0;                                  /* Corte de sistema (Valor float decimales) */

/* Configuracion de rangos de nivel del viento */   
   switch (Level) {                                  /* Si la variable "Level"... */
  case 1:                                            /* toma el valor 1... */
    potencia = 0.76;                                 /* potencia suministra un maximo de 0.76kWh */
    break;
  case 2:                                            /* toma el valor 2... */
    potencia = 0.76;                                 /* potencia suministra un maximo de 0.76kWh */
    break;
  case 3:                                            /* toma el valor 3... */
    potencia = 0.96;                                 /* potencia suministra un maximo de 0.96kWh */
    break;
  case 4:                                            /* toma el valor 4... */
    potencia = 1.04;                                 /* potencia suministra un maximo de 1.04kWh */
    break;
  case 5:                                            /* toma el valor 5... */
    potencia = 2.94;                                 /* potencia suministra un maximo de 2.94kWh */
    break;
  case 6:                                            /* toma el valor 6... */
    potencia = 4.84;                                 /* potencia suministra un maximo de 4.84kWh */
    break;
  case 7:                                            /* toma el valor 7... */
    potencia = 7.64;                                 /* potencia suministra un maximo de 7.64kWh */
    break;
  case 8:                                            /* toma el valor 8... */
    potencia = 10.44;                                /* potencia suministra un maximo de 10.44kWh */
    break;
  case 9:                                            /* toma el valor 9... */
    potencia = 12.84;                                /* potencia suministra un maximo de 12.84kWh */
    break;
  case 10:                                           /* toma el valor 10... */
    potencia = 15.24;                                /* potencia suministra un maximo de 15.24kWh */
    break;  
  case 11:                                           /* toma el valor 11... */
    potencia = 17.24;                                /* potencia suministra un maximo de 17.24kWh */
    break;  
   default:                                          /* no es ninguno de los anteriores o mayor a 11...*/
    potencia = 17.24;                                /* potencia suministra un maximo de 17.24Wh */
    break;
  }

/* Bloqueo del sistema */
if (float energy=(p*time)/(3600000) >= potencia){    /* Condicion para cambio de tension */
  digitalWrite(rele3, LOW);                          /* Rele 3 dentro de variables.h */
  }
  /* Configuracion del LCD 20x4: */
  lcd.clear();
  lcd.setCursor(0,0);                                /* Cursor en la 1° posicion de la 1° fila */
  lcd.print("Medicion de consumo: ");
  lcd.setCursor(0,1);                                /* Cursor en la 1° posicion de la 3° fila */
  lcd.print("Diario: ");
  lcd.print(energy,2);                               /* kWh, 2 decimales */
  lcd.print(" kWh "); 
  lcd.setCursor(0,2);                                /* Cursor en la 1° posicion de la 3° fila */
  lcd.print("Corriente: ");
  lcd.print(Irms,2);                                 /* Corriente, 2 decimales */
  lcd.print(" A ");                                  /* Valor de corriente */
  lcd.setCursor(0,3);                                /* Cursor en la 1° posicion de la 4° fila */
  lcd.print("Potencia: ");
  lcd.print(P,2);                                    /* kW, 2 decimales */
  lcd.print(" kW ");                                 /* Valor de potencia */
  delay(1000);                                       /* Retraso mostrar valores */
     
  /* Valores para modo consola Serial port USB/9600 baudios */
  Serial.print("Valor del sensor viento: "); 
  Serial.println(sensorValue);                       /* Para saber el valor del sensor de viento */
  Serial.print("Voltaje anemometro: ");
  Serial.print(outvoltage);
  Serial.print("V");
  Serial.println(" ");
  Serial.print("La velocidad del viento es: ");
  Serial.print(Level);
  Serial.println(" ");
  Serial.print("Corriente: ");                       /* Texto "Irms:" */
  Serial.print(Irms,2);                              /* Valor de la corriente */
  Serial.print("A");                                 /* Unidad de medida, 2 decimales */
  Serial.println(" ");
  Serial.print("Potencia (W): ");                    /* Texto "Pontecia:" */
  Serial.print(p,2);                                 /* Valor de la potencia en Watts */
  Serial.print("W");                                 /* Unidad de medida, 2 decimales */
  Serial.println(" ");
  Serial.print("Potencia (kW): ");                   /* Texto "Pontecia:" */
  Serial.print(p,2);                                 /* Valor de la potencia en kW */
  Serial.print("kW");                                /* Unidad de medida, 2 decimales */
  Serial.println(" ");
  Serial.print("Diario: ");                          /* Texto "Pontecia:" */
  Serial.print(energy,2);                            /* Valor de la potencia en Watts-hora */
  Serial.print("kWh");                               /* Unidad de medida, 2 decimales */
  Serial.println(" ");
  Serial.println(" ");
  delay(1000);                                       /* Retraso valores */
}