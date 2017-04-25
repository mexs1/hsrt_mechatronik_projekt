/*
Diese Datei beinhaltet Funktionen für Standard-GPIO-Operationen

*/

void gpioWrite(int port, int pin, int value){
	
	pADI_GP(port)->GPOUT |= (0x01 << pin);
	
}