/* Asigmar pines para LCD (RS, E, d4, d5, d6, d7) */
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

/* Estados del boton */
int boton = 2;                                       /* Boton conectado al pin 2 */  
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

/* Control de rele con opcion de alternado */
int rele1 = 13;                                       /* Rele conectado al pin 13 */   
int rele2 = 12;                                       /* Rele conectado al pin 12 */ 
int rele3 = 11;                                       /* Rele conectado al pin 11 */
  
/* tiempo */
//long milisec = millis();                              /* calcular el tiempo en milisegundos */
//long time=milisec/1000;                               /* convertir de milisegundos a segundos */

/*
totamps = totamps + amperios;                         // calcular amperios total
avgamps = totamps/tiempo;                             // promedio de amps
amphr =(avgamps*time)/3600;                           // Ah
Watts = voltaje * amperios;                           // Potencia = Voltaje * corriente
energía =(watt*time)/3600;                            // Vatios-seg vuelve a convertir en Watt-hora dividiendo 1hr(3600sec)
energy=(watt*time)/(1000*3600);                       // para la lectura en kWh */