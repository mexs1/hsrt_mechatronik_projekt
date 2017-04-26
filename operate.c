/*

Dieses C-File dient der tatsächlichen Operationen des System (SoC und SoH Berechnung)

*/


//Funktionsdeklaration
float interpolate_segment(double x0, double y0, double x1, double y1, double x);


int stateOfCharge(double voltage){
	//4,2 4 3,8 3,6 3,4 3,2 3 2,8
	const unsigned int LuT_SoC[] = {100,95,77,56,19,4,1};
	const double voltage_ranges[] = {4.2,4,3.8,3.6,3.4,3.2,2.8};
	int soc = 0;
	int i = 0;			//Zählvariable
	
	for(i=0;i<=6;i++){
		
		if (voltage <= voltage_ranges[i] && voltage >= voltage_ranges[i+1]){
				soc = interpolate_segment(voltage_ranges[i],LuT_SoC[i],voltage_ranges[i+1],LuT_SoC[i+1],voltage);
			}
	}
	
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

void measureTemperature(){
}


/*
TO DO:
State of Health
Look Up Table in EEPROM laden



*/