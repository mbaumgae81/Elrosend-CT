Elrosend-CT
===========

Elro Funksteckdosen Steuern am Cubietruck | getestet nur mit Elro AB440

Da es auf dem Cubietruck keine alternative zu RCSwitch/WiringPI gab war es wesentlich schwieriger Funksteckdosen anzusprechen.

Ich habe das nun in einem kleinen soweit funktionsfähigem Programm getan.

benötigt
https://github.com/youyudehexie/node-cubieboard-gpio/blob/master/lib/gpio_lib.h

send.c anpassen falls ein anderer PIN als der PB2 verwendet werden soll.


Compile
===================
gcc gpio_lib.h -c
gcc send.c -c
gcc gpio_lib.o send.o -o send

ausführen mit ./send 1 1      

                      1 erste Steckdose DIP A 1 rest 0
                      1 Ein
                      
./send 2 0
          
          2 zweite Steckdose DIP B up rest 0
          0 Aus
          
          
Hauscode Hardcoded in Send.c  Standart Hauscode DIP 1 - 5  1



