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
	pADI_ADC0->CON |= ADCCON_ADCEN;	      //Aktiviere ADC0
	pADI_ADC0->CON |= ADCCON_ADCCP_AIN0;  //Positiver Kanal : AIN0
	pADI_ADC0->CON |= ADCCON_ADCCN_AIN5;  //Negativer Kanal : AIN5
	
	while(1){
  	analog_value = pADI_ADC0->DAT;
		current = analog_value/resistance;
	}
}
