/*
Diese Datei beinhaltet alle Funktionen, die für die Kommunikation 
mit dem CAN-Transceiver benötigt werden

*/

#include <stdio.h>
#include "mcp2515.h"
#include "can.h"

void startCommunicationCanController(void){
	
	//Bis jetzt nur ein Beispiel
	/*---------SEND-----------*/
	
	tCAN message;
	int i=0;
	
	mcp2515_init(CANSPEED_250);
	
	message.id = 0x631;
	message.header.rtr = 0;
  message.header.length = 8; //formatted in DEC
  message.data[0] = 0x40;
	message.data[1] = 0x05;
	message.data[2] = 0x30;
	message.data[3] = 0xFF; //formatted in HEX
	message.data[4] = 0x00;
	message.data[5] = 0x40;
	message.data[6] = 0x00;
  message.data[7] = 0x00;
	
	mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
	mcp2515_send_message(&message);
	
	/*---------RECEIVE-----------*/
	
	if(mcp2515_check_message())
	{
		if(mcp2515_get_message(&message))
		{
			 printf("ID: ");
			 printf("%x \n", message.id);
			 printf(", ");
			 printf("Data: ");
			 printf("%x \n",message.header.length);
			 for(i=0;i<message.header.length;i++) 
				{	
					printf("%x \n",message.data[i]);
					printf(" ");
				}
			  printf("");
		}
	}
	
	
	
}

void sendVoltageCan(int voltage){
	
	tCAN message;
	
	message.id = 0x001;
	message.header.rtr = 0;
  message.header.length = 4; //formatted in DEC
	
	message.data[0] = voltage & 0xFF000000;
	message.data[1] = voltage & 0xFF0000;
	message.data[2] = voltage & 0xFF00;
	message.data[3] = voltage & 0xFF;
	
	mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0); //Set CanCtrl-Register to normal Operation mode
	mcp2515_send_message(&message);

}
