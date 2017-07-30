/*

Dieses C-File dient der tatsächlichen Operationen des System (SoC und SoH Berechnung)

*/


#include <ADuCM360.h>
#include "AdcLib.h"
//Funktionsdeklaration
float interpolate_segment(double x0, double y0, double x1, double y1, double x);


int stateOfCharge(int voltage){
	//4,2 4 3,8 3,6 3,4 3,2 3 2,8
	const unsigned int LuT_SoC[] = {100,95,77,56,19,4,1};
	const double voltage_ranges[] = {4.2,4,3.8,3.6,3.4,3.2,2.8};
	int soc = 0;
	int i = 0;			//Zählvariable
	//double temperature_battery
	
	for(i=0;i<=6;i++){
		
		if (voltage <= voltage_ranges[i] && voltage >= voltage_ranges[i+1]){
				soc = interpolate_segment(voltage_ranges[i],LuT_SoC[i],voltage_ranges[i+1],LuT_SoC[i+1],voltage);
			}
	}
	//temperature_battery = measureTemperature();
	
	return soc;
	
}

float interpolate_segment(double x0, double y0, double x1, double y1, double x)
{
    float t;

    if (x <= x0) { return y0; }
    if (x >= x1) { return y1; }

    t =  (x-x0);
    t /= (x1-x0);

    return y0 + t*(y1-y0);
}

//Diese Funktion dient der Zählung der geflossenen Ladung durch Integration des Stromes über die Zeit
void coulombCounting(){

}

double measureTemperature(){
	
	//Das Thermoelement TI LM35 liefert einen linearen Spannungswert mit 10mv/°C
	//Eingänge Sind AIN4 (VIN) und AIN5(GND)
	
	double temperature = 0;
	temperature = (double)((AdcRd(pADI_ADC1)*(3300/1<<28))/10);	//Temperatur in °C
	
	return temperature;
}



void putLUTtoFlash(void){
	
}

/*
TO DO:

State of Health
Look Up Table in EEPROM laden



*/
