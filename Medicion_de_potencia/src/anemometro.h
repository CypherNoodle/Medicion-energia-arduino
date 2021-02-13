Void get_anemometro()
 {
   int sensorValue = analogRead(A1);                 /* Lectura del pin del anemometro */
   float outvoltage = sensorValue * (5.0 / 1023.0);  /* voltaje del sensor */
   int Level = 6*outvoltage;                         /* Viento=6*U  */

/* Configuracion de rangos de nivel del viento */   
   switch (int Level = 6*outvoltage) {
  case 1:
    /* do something when int Level = 6*outvoltage equals 1 */
    break;
  case 2:
    /* do something when int Level = 6*outvoltage equals 2 */
    break;
  case 3:
    /* do something when int Level = 6*outvoltage equals 3 */
    break;
  case 4:
    /* do something when int Level = 6*outvoltage equals 4 */
    break;
  case 5:
    /* do something when int Level = 6*outvoltage equals 5 */
    break;
  case 6:
    /* do something when int Level = 6*outvoltage equals 6 */
    break;
  case 7:
    /* do something when int Level = 6*outvoltage equals 7 */
    break;
  case 8:
    /* do something when int Level = 6*outvoltage equals 8 */
    break;
  case 9:
    /* do something when int Level = 6*outvoltage equals 9 */
    break;
  case 10:
    /* do something when int Level = 6*outvoltage equals 10 */
    break;  
  case 11:
    /* do something when int Level = 6*outvoltage equals 11 */
    break;  
  case 12:
    /* do something when int Level = 6*outvoltage equals 12 */
    break;  
  case 13:
    /* do something when int Level = 6*outvoltage equals 13 */
    break;  
  case 14:
    /* do something when int Level = 6*outvoltage equals 14 */
    break;  
  case 15:
    /* do something when int Level = 6*outvoltage equals 15 */
    break;  
  case 16:
    /* do something when int Level = 6*outvoltage equals 16 */
    break;  
  case 17:
    /* do something when int Level = 6*outvoltage equals 17 */
    break;
  default:
    /* if nothing else matches, do the default */
    /* default is optional */
    break;
	}
   
   Serial.print("Voltaje = ");
   Serial.print(outvoltage);
   Serial.println("V");
   Serial.print("La velocidad del viento es: ");
   Serial.print(Level);
   Serial.println(" Velocidad actual ");
   Serial.println();
   Serial.print();
   delay(500);
 }
 
 //V=6*U
 //P = V*I
 //I = P/V
 //P = I2*R
 //float p = Irms*220.0;                             /* P=I*V (Watts) */