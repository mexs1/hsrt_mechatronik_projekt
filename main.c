/*
Software zur Anbindung des Shunts zur Messung der Ströme
Autor: Maximilian Serfas
Datum: 19.10.2016
*/

#include <stdio.h>
#include <ADuCM360.H>
#include "main.h"
#include "can.h"
#include "AdcLib.h"


int main (void) {
	
	//Variablen
	const unsigned int resistance = 100; //uOhm
	int analog_value_voltage = 0;			//uV
	int temp_value = 0;
	int current = 0;									//uA
	
	SystemCoreClockUpdate();
	
	
	while(1){
  	temp_value = pADI_ADC0->DAT;
		analog_value_voltage = 0.1966953277 * temp_value;
		current = analog_value_voltage/resistance;
		
		//stateOfCharge(analog_value_voltage);
		
		startCommunicationCanController();
		sendVoltageCan(analog_value_voltage);
	}
}
