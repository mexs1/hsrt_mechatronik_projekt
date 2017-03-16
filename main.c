/*
Software zur Anbindung des Shunts zur Messung der Ströme
Autor: Maximilian Serfas
Datum: 19.10.2016
*/

#include <stdio.h>
#include <ADuCM360.H>
#include "main.h"

int main (void) {
	
	//Variablen
	const double resistance = 0.0001; 
	double analog_value_voltage = 0;
	int temp_value = 0;
	double current = 0;
	
	SystemCoreClockUpdate();
	
	
	while(1){
  	temp_value = pADI_ADC0->DAT;
		analog_value_voltage = 0.1966953277 * (double)temp_value;
		analog_value_voltage = analog_value_voltage/1000000;
		current = analog_value_voltage/resistance;
		
		stateOfCharge(analog_value_voltage);
	}
}
