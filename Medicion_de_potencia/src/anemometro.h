void get_anemometro()   
{   
/* Configuracion del anemometro */
int   sensorValue = analogRead(A1);                  /* Lectura del pin del anemometro */
float outvoltage = sensorValue * (5.0 / 1023.0);     /* voltaje del sensor */
int   Level = 6*outvoltage;                          /* Viento=6*U */
float potencia = 0;                                  /* Para corte de sistema (Valor float decimales) */

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
  Serial.print("Valor del sensor viento: "); 
  Serial.println(sensorValue);                       /* Para saber el valor del sensor de viento */
  Serial.print("Voltaje anemometro: ");
  Serial.print(outvoltage);
  Serial.print("V");
  Serial.println(" ");
  Serial.print("La velocidad del viento es: ");
  Serial.print(Level);
  Serial.println(" ");
  delay(1000);
}