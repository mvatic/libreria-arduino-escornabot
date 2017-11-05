/* 
Librería Escornabot v 0.2 escrita por Pedro Ruiz @pedroruizf
 */

#include "Arduino.h"
#include "Escornabot.h"

/*
 Constructor
 */
Escornabot::Escornabot()
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

/*
Procedimiento apara avanzar y retroceder 
*/

void Escornabot::mueve (float vueltas, int velocidad) {//vueltas son el nº de vueltas a dar (+ avanza o - retrocede) y velocidad en rpm

	pasosdados=0;
	if (vueltas>=0) {//si las vueltas son positivas las bobinas se excitan en el sentido de avance
		while (int(vueltas*pasosvuelta)>=pasosdados)  {
     		pasosdados ++;
     		posbobina=pasosdados % 4;//calcula el resto para saber en la posición de bobina que está
      		digitalWrite(2, paso[posbobina][3]);
      		digitalWrite(6, paso[posbobina][0]);
      		digitalWrite(3, paso[posbobina][2]);
      		digitalWrite(7, paso[posbobina][1]);
      		digitalWrite(4, paso[posbobina][1]);
      		digitalWrite(8, paso[posbobina][2]);
      		digitalWrite(5, paso[posbobina][0]);
      		digitalWrite(9, paso[posbobina][3]);
      		delayMicroseconds(29297/velocidad);//velocidad en rpm 29297 es el nº de microsegundos que tardaría en dar 2048 pasos (una vuelta) en un minuto
    	}
	}

	else {//si las vueltas son negativas las bobinas se excitan en el sentido de retroceso
		while (int(-vueltas*pasosvuelta)>=pasosdados)  {
     		pasosdados ++;
     		posbobina=pasosdados % 4;
      		digitalWrite(2, paso[posbobina][0]);
      		digitalWrite(6, paso[posbobina][3]);
      		digitalWrite(3, paso[posbobina][1]);
      		digitalWrite(7, paso[posbobina][2]);
      		digitalWrite(4, paso[posbobina][2]);
      		digitalWrite(8, paso[posbobina][1]);
      		digitalWrite(5, paso[posbobina][3]);
      		digitalWrite(9, paso[posbobina][0]);
      		delayMicroseconds(29297/velocidad);
    	}
  
	}

}


/*
Procedimiento de paro de los motores
 */

void Escornabot::para () {

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

void Escornabot::gira (float vueltas, int velocidad) {//vueltas son el nº de vueltas a girar (+ en un sentido o - en el otro) y velocidad en rpm

	pasosdados=0;
	if (vueltas>=0) {//si las vueltas son positivas provoca giro a la derecha moviendo rueda izquierda adelante y derecha atrás
		while (int(vueltas*pasosvuelta)>=pasosdados)  {
			pasosdados ++;
			posbobina=pasosdados % 4;
			digitalWrite(2, paso[posbobina][0]);
			digitalWrite(6, paso[posbobina][0]);
			digitalWrite(3, paso[posbobina][1]);
			digitalWrite(7, paso[posbobina][1]);
			digitalWrite(4, paso[posbobina][2]);
			digitalWrite(8, paso[posbobina][2]);
			digitalWrite(5, paso[posbobina][3]);
			digitalWrite(9, paso[posbobina][3]);
			delayMicroseconds(29297/velocidad);
		}

	}

	else {//si las vueltas son negativas provoca giro a la izquierda moviendo rueda derecha adelante e izquierda atrás
		while (int(-vueltas*pasosvuelta)>=pasosdados)  {
			pasosdados ++;
			posbobina=pasosdados % 4;
			digitalWrite(2, paso[posbobina][3]);
			digitalWrite(6, paso[posbobina][3]);
			digitalWrite(3, paso[posbobina][2]);
			digitalWrite(7, paso[posbobina][2]);
			digitalWrite(4, paso[posbobina][1]);
			digitalWrite(8, paso[posbobina][1]);
			digitalWrite(5, paso[posbobina][0]);
			digitalWrite(9, paso[posbobina][0]);
			delayMicroseconds(29297/velocidad);
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
