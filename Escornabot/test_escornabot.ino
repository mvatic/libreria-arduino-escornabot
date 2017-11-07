#include <Escornabot.h>

Escornabot mirobot;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
mirobot.mueve (0.5,10);
delay (1000);
mirobot.mueve (-0.5, 10);
delay (1000);
mirobot.gira (0.25,10);
delay (1000);
mirobot.gira (-0.25,10);
delay (1000);
}
