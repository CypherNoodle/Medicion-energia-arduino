void get_boton()
{
/* Inicio de configuracion del boton: */
  buttonState = digitalRead(2);                      /* Leer la entrada del boton */
  if (buttonState != lastButtonState) {              /* Compara el estado previo del boton */
    if (buttonState == HIGH) {                       /* Si el estado cambio, incrementa el contador */
      buttonPushCounter += 1;                        /* Si el estado actual es HIGH, entonces el boton va de off a on */
      Serial.println("Boton encendido");
      Serial.print("numero de pulsaciones: ");
      Serial.println(buttonPushCounter);
    } else {                                         /* Si el estado estado es LOW, entonces el boton va de on a off */
      Serial.println("Boton apagado");
    }
    delay(5);                                        /* Un poco de retraso para prevenir el efecto rebote del boton */
  }
  lastButtonState = buttonState;                     /* Guarda el estado actual como ultimo estado conocido */
  if (buttonPushCounter % 2 == 0) {                  /* Enciende el rele cada 2 pulsaciones ya que divide en 2 el estado actual */
  digitalWrite(rele1, HIGH);                         /* Normanlmente abierto */
  digitalWrite(rele2, LOW);                          /* Normanlmente cerrado */
   } else {
  digitalWrite(rele1, LOW);
  digitalWrite(rele2, HIGH);
  }
}

