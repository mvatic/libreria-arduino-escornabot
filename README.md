# Librería para arduino Escornabot
Repositorio para albergar librería para manejar de forma amigable los motores paso a paso de Escornabot.

![](images/escornabot.png "escornabot")
## Antecedentes
Unos de los problemas de escornabot es la ausencia de instrucciones amigables en arduino para controlar sus servomotores, todo ello pensando en el acercamiento del uso de dicho robot para estudiantes de secundaria. Para Todo ello desde el club de Tecnología, programación y robótica de Granada nos planteamos desarrollar una librería para dicho fin.
## Librería
La librería debemos cargar en arduino por los métodos tradicionales, incluyendo el zip o copiandola descomprimida en la carpeta "libraries" de arduino.
### procedimientos
- **mueve (vueltas, velocidad)**: Sirve para avanzar o retroceder. Se mueve el número de vueltas indicado, si son negativas va en el sentido contrario. La velocidad se da rpm
- **gira (vueltas, velocidad)**: Sirve para girar. Se indica como antes el número de vueltas o fracción a girar, si son positivas gira en un sentido y negativas en el contrario. La velocidad se da en rpm.
- **para ()**: detiene los dos motores.
### Ejemplo de código
~~~
#include <Escornabot.h>

Escornabot mirobot;//declaramos el objeto mirobot del tipo Escornabot

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  if (analogRead(7) == 769) { //si el botón adelante de escornabot está pulsado

    mirobot.mueve (1, 14); //mueve al objeto escornabot 1 vuelta hacia delante con velocidad 14 rpm
  }

  if (analogRead(7) == 516) { //si el botón atrás de escornabot está pulsado
    mirobot.mueve (-1, 14); //mueve al objeto escornabot 1 vuelta hacia atrás con velocidad 14 rpm

  }

  Serial.println (analogRead (7));

}
~~~
