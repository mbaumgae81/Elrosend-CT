##### benötigt gpio_lib.h
##### von    --->>    https://github.com/youyudehexie/node-cubieboard-gpio/blob/master/lib/gpio_lib.h
##### Aufruf send Steckdosennr Zustand
##### z.B. send 1 1		Schaltet Steckdose 1 Ein

#include <stdlib.h>
#include <stdio.h>

#include "gpio_lib.h"
#define PB2   SUNXI_GPB(2)
#define PBI3    SUNXI_GPB(3)
#define PB16 	 SUNXI_GPB(16)
#define PC20	SUNXI_GPC(20)
#define PD3    SUNXI_GPD(3)


#define MISO    SUNXI_GPE(3)
#define MOSI    SUNXI_GPE(2)
#define SCK     SUNXI_GPE(1)
#define CS      SUNXI_GPE(0)


int lang = 1025;  // 3 einzel pulse
int kurz = 375; // ein puls

int PIN = PB2;      // Verwendeter Ausgangs PIN


void set_output()
{
sunxi_gpio_set_cfgpin(PIN,OUTPUT);
}

        void switch1() //
        {
        	// BIT 1
         sunxi_gpio_output(PIN,HIGH);
        usleep(lang);
        sunxi_gpio_output(PIN,LOW);
        usleep(kurz);
        sunxi_gpio_output(PIN,HIGH);
        usleep(lang);
        sunxi_gpio_output(PIN,LOW);
        usleep(kurz);
        return;
     }

       void switch0() //
       {

        //switch0
 		// BIT 0
        sunxi_gpio_output(PIN,HIGH);
        usleep(kurz);
        sunxi_gpio_output(PIN,LOW);
        usleep(lang);
        sunxi_gpio_output(PIN,HIGH);
        usleep(kurz);
        sunxi_gpio_output(PIN,LOW);
        usleep(lang);
        return;
        //Bit 0
     }

        void switchF() //1hi, 3lo - - 3hi, 1lo
      {
    //Bit F
		  sunxi_gpio_output(PIN,HIGH);
        usleep(kurz);
        sunxi_gpio_output(PIN,LOW);
        usleep(lang);
        sunxi_gpio_output(PIN,HIGH);
        usleep(lang);
        sunxi_gpio_output(PIN,LOW);
        usleep(kurz);
        return;
       //Bit F
    }
		void sync_send()
		{
			sunxi_gpio_output(PIN,HIGH);
        usleep(kurz);
        sunxi_gpio_output(PIN,LOW);
        usleep(11625);

			}

int main(int argc, char *argv[])
{
    if(SETUP_OK!=sunxi_gpio_init()){
        printf("Fehler bei initialisierung!\n");
return -1;

}

 //char* systemCode = argv[1];
  int unitCode = atoi(argv[1]);
  int command  = atoi(argv[2]);
set_output();


int i, j;

for(i=0; i<10; i++) {
	sync_send();
	switch0(); //1 Hauscode au Standart alle DIP s up
	switch0(); //2
	switch0(); //3
	switch0(); //4
	switch0(); //5 Hauscode;

	switch (unitCode)
	 {
	case 1:
	switch0(); //A Steckdosennr; 1  DIP 1 UP
	switchF(); //B
	switchF(); //C
	switchF(); //D
	switchF(); //E
	break;
	case 2:
	switchF(); //A Steckdosennr;2 DIP 2 up
	switch0(); //B
	switchF(); //C
	switchF(); //D
	switchF(); //E
	break;

	case 3:
	switchF(); //A Steckdosennr; 3 DIP 3 UP
	switchF(); //B
	switch0(); //C
	switchF(); //D
	switchF(); //E
	break;

	default:
	printf("Nummer der Steckdose Wählen");
}

switch (command)
{
	case 1:
	switchF();
	switchF();
	break;

	case 0:
	switchF();
	switch0();
	break;

	default:
	//printf("unsupported command\n ");
     return -1;
}

	}

    void sunxi_gpio_cleanup();

    return 0;



}
