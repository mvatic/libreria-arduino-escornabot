/* Librería para mover motores paso a paso de escornabot. V 0.1 esciro por Pedro Ruiz @pedroruizf
 */

// ensure this library description is only included once
#ifndef Escornabot_h
#define Escornabot_h

// library interface description
class Escornabot {
  public:
    // constructor:
    Escornabot();
    // procedimiento para mover los motores:
    void mueve (float vueltas, int velocidad);
	//procemiento para girar:	
	void gira (float vueltas, int velocidad);
    // procedimiento para parar:
    void para();


  private:
	int paso [4][4];//matriz que describe posiciones de bobinas (4 posiciones)
	int pasosvuelta;//nº de pasos que da en una vuelta
	int pasosdados;//cuenta los pasos dados
	int posbobina;// devuelve la posiciónde la bobina en cada paso (4 posiciones)     

};

#endif

