float get_corriente()
{
  float voltajeSensor;
  float corriente=0;
  float Sumatoria=0;
  long tiempo=millis();
  int N=0;
  while(millis()-tiempo<500)                         /* Duración 0.5 segundos(Aprox. 25 ciclos de 50Hz) */
  { 
    voltajeSensor = analogRead(A0) * (1.1 / 1023.0); /* Voltaje del sensor */
    corriente=voltajeSensor*30.0;                    /* Corriente=VoltajeSensor*(30A/1V) */
    Sumatoria=Sumatoria+sq(corriente);               /* Sumatoria de cuadrados */
    N=N+1;
    delay(1);
  }
  Sumatoria=Sumatoria*2;                             /* Para compensar los cuadrados de los semiciclos negativos */
  corriente=sqrt((Sumatoria)/N);                     /* Ecuación de corriente RMS */
  return(corriente);
}