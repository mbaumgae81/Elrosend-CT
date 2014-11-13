Elrosend-CT
===========

Elro Funksteckdosen am Cubietruck | getestet nur mit Elro AB440

Da es auf dem Cubietruck keine alternative zu RCSwitch/WiringPI gab war es wesentlich schwieriger Funksteckdosen anzusprechen.

Ich habe das nun in einem kleinen soweit funktionsfähigem Programm getan. Ausführbar jedoch nur als Root bzw. in der Gruppe Root.

benötigt wird
https://github.com/youyudehexie/node-cubieboard-gpio/blob/master/lib/gpio_lib.h
https://github.com/youyudehexie/node-cubieboard-gpio/blob/master/lib/gpio_lib.c

Beides in das gleiche Verzeichniss kopieren.

Die send.c ebenfalls in das Verzeichniss laden und ggf. anpassen falls ein anderer PIN als der PB2 verwendet werden soll.


Kompilieren in der Kommandozeile mit
===================
gcc gpio_lib.c -c
gcc send.c -c
gcc gpio_lib.o send.o -o send

Ausführen mit ./send 1 1 10101     

                      1 = erste Steckdose DIP-Achalter A 1 rest 0
                      1 = Ein
                      10101 = Hauscode (wird an den DIP-Schaltern in der Fernbedienung und SD eingestellt.
                      
Bzw. ./send 2 0 10101
          
                      2 = zweite Steckdose DIP B up rest 0
                      0 = Aus
                      10101 = Hauscode (wird an den DIP-Schaltern in der Fernbedienung und SD eingestellt.
          
          




