# Control de Versiones
- 0.4 (7/11/2017): se traduce las ordenes y variables al inglés.
- 0.3 (5//11/2017): se añade la posibilidad de pasar parámetros al objeto Escornabot, si se le pasa 1, se excita una bobina en cada paso, si se le pasa dos, se excitan dos bobinas en cada paso. Si no se le pasan parámetros se excita una bobina en cada paso por defecto.
- 0.2 (5/11/2017): Se corrige y depura código (se mejora declaración de variables evitando duplicidades), se mejora el comentado y sangrado del código.
- 0.1 (4/11/2017): Primera versión de librería.
# Librería para arduino Escornabot
Repositorio para albergar librería para manejar de forma amigable los motores paso a paso de Escornabot.

![](images/escornabot.png "escornabot")
## Antecedentes
Unos de los problemas de escornabot es la ausencia de instrucciones amigables en arduino para controlar sus servomotores, todo ello pensando en el acercamiento del uso de dicho robot para estudiantes de secundaria. Para Todo ello desde el club de Tecnología, programación y robótica de Granada nos planteamos desarrollar una librería para dicho fin.
## Librería
La librería debemos cargar en arduino por los métodos tradicionales, incluyendo el zip o copiandola descomprimida en la carpeta "libraries" de arduino.
### procedimientos
- **drive (vueltas, velocidad)**: Sirve para avanzar o retroceder. Se mueve el número de vueltas indicado, si son negativas va en el sentido contrario. La velocidad se da rpm
- **turn (vueltas, velocidad)**: Sirve para girar. Se indica como antes el número de vueltas o fracción a girar, si son positivas gira en un sentido y negativas en el contrario. La velocidad se da en rpm.
- **stop ()**: detiene los dos motores.
### Ejemplo de código
~~~
#include <escornabot.h>

escornabot mirobot;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
	mirobot.drive (0.5,10);
	delay (1000);
	mirobot.drive (-0.5, 10);
	delay (1000);
	mirobot.turn (0.25,10);
	delay (1000);
	mirobot.turn (-0.25,10);
	delay (1000);
}
~~~
