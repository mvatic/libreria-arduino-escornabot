/*
 Librería para mover motores paso a paso de escornabot. V 0.2 escrito por Pedro Ruiz @pedroruizf
*/

// ensure this library description is only included once
#ifndef Escornabot_h
#define Escornabot_h

// Descripción de la clase Escornabot
class Escornabot {
  //Definición de elementos públicos
   public:
    // constructor:
    Escornabot();
    // procedimiento para mover los motores:
    void mueve (float vueltas, int velocidad);
	//procemiento para girar:	
	void gira (float vueltas, int velocidad);
    // procedimiento para parar:
    void para();

  //Definición de elementos privados
  private:

	int paso [4][4] =//matriz que describe posiciones de bobinas (4 posiciones)
	{
  	{1, 0, 0, 0},
  	{0, 1, 0, 0},
  	{0, 0, 1, 0},
  	{0, 0, 0, 1}
	};
	int pasosvuelta=2048;//nº de pasos que da en una vuelta
	int pasosdados=0;//cuenta los pasos dados
	int posbobina=0;// devuelve la posiciónde la bobina en cada paso (4 posiciones)*/      

};

#endif

