void get_anemometro()   
{   
   int sensorValue = analogRead(A1);                 /* Lectura del pin del anemometro */
   float outvoltage = sensorValue * (5.0 / 1023.0);  /* voltaje del sensor */
   int Level = 6*outvoltage;                         /* Viento=6*U  */
   float potencia = 0;                               /* Definir corte en funcion del viento*/

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
}
