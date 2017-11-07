/*
 Librería para mover motores paso a paso de escornabot. V 0.3 escrito por Pedro Ruiz @pedroruizf
V 0.3: Se añade posibilidad de elegir el tipo de excitación de bobinas 1 o 2, por defecto tipo 1 
V 0.2: se depura y sangra código evitando duplicidades en procedimientos
V 0.1: primera versión funcional del programa
*/

// ensure this library description is only included once
#ifndef escornabot_h
#define escornabot_h

// Descripción de la clase Escornabot
class escornabot {
  //Definición de elementos públicos
   public:
    // constructor:
 	escornabot();//sin pasar parámetros   
	escornabot(int kindStep);// pasa el tipo de paso 1 (un solo motor a la vez), paso 2 (dos motores a la vez)
    // procedimiento para mover los motores:
    void drive (float laps, int speed);
	//procemiento para girar:	
	void turn (float laps, int speed);
    // procedimiento para parar:
    void stop();

  //Definición de elementos privados
  private:

	
};

#endif

