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


