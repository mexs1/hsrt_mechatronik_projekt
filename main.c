/*
Software zur Anbindung des Shunts zur Messung der Ströme
Autor: Maximilian Serfas
Datum: 19.10.2016
*/

#include <stdio.h>
#include <ADuCM360.H>

int main (void) {
	
	//Variablen
	double resistance = 0.0001; 
	int analog_value = 0;
	double current = 0;
	
	SystemCoreClockUpdate();
	
	//Initialisierung
	pADI_ADC0->CON = ADCCON_ADCEN;
	
	while(1){
		analog_value = pADI_ADC0->DAT;
		current = analog_value/resistance;
	}
}
