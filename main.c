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
	double resistance = 0.0001; 
	double analog_value = 0;
	int temp_value = 0;
	double current = 0;
	
	SystemCoreClockUpdate();
	
	//Initialisierung
	pADI_ADC0->CON |= ADCCON_ADCEN;	      //Aktiviere ADC0
	pADI_ADC0->CON |= ADCCON_ADCCP_AIN0;  //Positiver Kanal : AIN0
	pADI_ADC0->CON |= ADCCON_ADCCN_AIN5;  //Negativer Kanal : AIN5
	
	pADI_ADC0->MDE |= ADCMDE_ADCMD_IDLE;    //Idle-Mode zur Kalibrierung
	pADI_ADC0->MDE |= ADCMDE_ADCMD_INTOCAL; //Zero-Scale-Calibration
	pADI_ADC0->MDE = ADCMDE_ADCMD_CONT;    //Kontinuierliche Messung über
	
	while(1){
  	temp_value = pADI_ADC0->DAT;
		//analog_value = ADC_FACTOR * analog_value;
		analog_value = 0.1966953277 * (double)temp_value;
		analog_value = analog_value/1000000;
		current = analog_value/resistance;
	}
}
