void get_boton()
{
/* Inicio de configuracion del boton: */
  buttonState = digitalRead(2);                      /* Lee la entrada del boton */
  if (buttonState != lastButtonState) {              /* Compara el estado previo del boton */
    if (buttonState == HIGH) {                       /* Si el estado cambia, incrementa el contador */
      buttonPushCounter += 1;                        /* Si el estado actual es HIGH, entonces va de off a on */
      Serial.println("Boton encendido");
	  Serial.println(" ");
      Serial.print("numero de pulsaciones: ");
      Serial.println(buttonPushCounter);
    } else {                                         /* Si el estado estado es LOW, entonces va de on a off */
	  Serial.println(" ");
      Serial.println("Boton apagado");
    }
    delay(5);                                        /* Retardo para prevenir el efecto rebote del boton */
  }
  lastButtonState = buttonState;                     /* Guarda el estado actual como ultimo estado conocido */
  if (buttonPushCounter % 2 == 0) {                  /* Enciende el rele 1 y apaga rele 2 */
  digitalWrite(rele1, HIGH);                         
  digitalWrite(rele2, LOW);                          
   } else {
  digitalWrite(rele1, LOW);                          /* Enciende el rele 2 y apaga rele 1 */
  digitalWrite(rele2, HIGH);
  }
}