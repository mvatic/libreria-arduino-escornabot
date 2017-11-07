/*
 Librería para mover motores paso a paso de escornabot. V 0.3 escrito por Pedro Ruiz @pedroruizf
V 0.3: Se añade posibilidad de elegir el tipo de excitación de bobinas 1 o 2, por defecto tipo 1 
V 0.2: se depura y sangra código evitando duplicidades en procedimientos
V 0.1: primera versión funcional del programa
*/

#include "Arduino.h"
#include "escornabot.h"

// Declaración y asignación de variables privadas
	
int step [4][4] =//matriz que describe puesta en marcha de bobinas por defecto (4 posiciones)
		{
	  	{1, 0, 0, 0},
	  	{0, 1, 0, 0},
	  	{0, 0, 1, 0},
	  	{0, 0, 0, 1}
		};	

	int stepsLap=2048;//nº de pasos que da en una vuelta
	int stepsDone=0;//cuenta los pasos dados
	int coilPosition=0;// devuelve la posición de la bobina en cada paso (4 posiciones)      


/*
 Constructor
 */

escornabot::escornabot() //si no se pasan prámetros al constructor por defecto coge el paso 1 (1 solo motor a la vez)
{
//se definen los pines de escornabot como de salida
	pinMode (2,OUTPUT);
	pinMode (3,OUTPUT);
	pinMode (4,OUTPUT);
	pinMode (5,OUTPUT);
	pinMode (6,OUTPUT);
	pinMode (7,OUTPUT);
	pinMode (8,OUTPUT);
	pinMode (9,OUTPUT);

}

escornabot::escornabot(int kindStep) //aquí se construye el objeto escornabot con el tipo de paso (excitación de bobinas) 1 o 2
{
//se definen los pines de escornabot como de salida
	pinMode (2,OUTPUT);
	pinMode (3,OUTPUT);
	pinMode (4,OUTPUT);
	pinMode (5,OUTPUT);
	pinMode (6,OUTPUT);
	pinMode (7,OUTPUT);
	pinMode (8,OUTPUT);
	pinMode (9,OUTPUT);

	if (kindStep==1) {// se excita una bobina cada vez
		int step [4][4] =//matriz que describe orden de excitación de bobinas (4 posiciones)
		{
	  	{1, 0, 0, 0},
	  	{0, 1, 0, 0},
	  	{0, 0, 1, 0},
	  	{0, 0, 0, 1}
		};
	}
	if (kindStep==2) {// se excitan dos bobinas a la vez
		int step [4][4] =//matriz que describe orden de excitación de bobinas (4 posiciones)
		{
	  	{1, 1, 0, 0},
	  	{0, 1, 1, 0},
	  	{0, 0, 1, 1},
	  	{1, 0, 0, 1}
		};
	}
}


/*
Procedimiento apara avanzar y retroceder 
*/

void escornabot::drive (float laps, int speed) {//vueltas son el nº de vueltas a dar (+ avanza o - retrocede) y velocidad en rpm

	stepsDone=0;
	if (laps>=0) {//si las vueltas son positivas las bobinas se excitan en el sentido de avance
		while (int(laps*stepsLap)>=stepsDone)  {
     		stepsDone ++;
     		coilPosition=stepsDone % 4;//calcula el resto para saber en la posición de bobina que está
      		digitalWrite(2, step[coilPosition][3]);
      		digitalWrite(6, step[coilPosition][0]);
      		digitalWrite(3, step[coilPosition][2]);
      		digitalWrite(7, step[coilPosition][1]);
      		digitalWrite(4, step[coilPosition][1]);
      		digitalWrite(8, step[coilPosition][2]);
      		digitalWrite(5, step[coilPosition][0]);
      		digitalWrite(9, step[coilPosition][3]);
      		delayMicroseconds(29297/speed);//velocidad en rpm 29297 es el nº de microsegundos que tardaría en dar 2048 pasos (una vuelta) en un minuto
    	}
	}

	else {//si las vueltas son negativas las bobinas se excitan en el sentido de retroceso
		while (int(-laps*stepsLap)>=stepsDone)  {
     		stepsDone ++;
     		coilPosition=stepsDone % 4;
      		digitalWrite(2, step[coilPosition][0]);
      		digitalWrite(6, step[coilPosition][3]);
      		digitalWrite(3, step[coilPosition][1]);
      		digitalWrite(7, step[coilPosition][2]);
      		digitalWrite(4, step[coilPosition][2]);
      		digitalWrite(8, step[coilPosition][1]);
      		digitalWrite(5, step[coilPosition][3]);
      		digitalWrite(9, step[coilPosition][0]);
      		delayMicroseconds(29297/speed);
    	}
  
	}

}


/*
Procedimiento de paro de los motores
 */

void escornabot::stop () {

	digitalWrite(2, 0);
    digitalWrite(6, 0);
	digitalWrite(3, 0);
	digitalWrite(7, 0);
	digitalWrite(4, 0);
	digitalWrite(8, 0);
	digitalWrite(5, 0);
	digitalWrite(9, 0);

}

/*
Procedimiento para girar
*/

void escornabot::turn (float laps, int speed) {//vueltas son el nº de vueltas a girar (+ en un sentido o - en el otro) y velocidad en rpm

	stepsDone=0;
	if (laps>=0) {//si las vueltas son positivas provoca giro a la derecha moviendo rueda izquierda adelante y derecha atrás
		while (int(laps*stepsLap)>=stepsDone)  {
			stepsDone ++;
			coilPosition=stepsDone % 4;
			digitalWrite(2, step[coilPosition][0]);
			digitalWrite(6, step[coilPosition][0]);
			digitalWrite(3, step[coilPosition][1]);
			digitalWrite(7, step[coilPosition][1]);
			digitalWrite(4, step[coilPosition][2]);
			digitalWrite(8, step[coilPosition][2]);
			digitalWrite(5, step[coilPosition][3]);
			digitalWrite(9, step[coilPosition][3]);
			delayMicroseconds(29297/speed);
		}

	}

	else {//si las vueltas son negativas provoca giro a la izquierda moviendo rueda derecha adelante e izquierda atrás
		while (int(-laps*stepsLap)>=stepsDone)  {
			stepsDone ++;
			coilPosition=stepsDone % 4;
			digitalWrite(2, step[coilPosition][3]);
			digitalWrite(6, step[coilPosition][3]);
			digitalWrite(3, step[coilPosition][2]);
			digitalWrite(7, step[coilPosition][2]);
			digitalWrite(4, step[coilPosition][1]);
			digitalWrite(8, step[coilPosition][1]);
			digitalWrite(5, step[coilPosition][0]);
			digitalWrite(9, step[coilPosition][0]);
			delayMicroseconds(29297/speed);
		}
  
	}

}



/*
  version() devuelve la versión de la librería:
*/
//int Escornabot::version(void)
//{
//  return 0.2;
//}
