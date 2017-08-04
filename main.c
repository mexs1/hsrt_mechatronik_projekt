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
	adc1Init();
	adc2Init();
	gpioInit();
	spiInit();
	
	startCommunicationCanController();
	
	while(1){
		temp_value = pADI_ADC0->DAT; //0,00000001229345798492431640625 Umrechnungsfaktor: 3,3V/2^28
  analog_value_voltage = 0.01229345798 * temp_value;
	current = analog_value_voltage/resistance;
	//analog_value_voltage = 200;
		//stateOfCharge(analog_value_voltage);
		
		
		sendVoltageCan(analog_value_voltage);
	}
}
