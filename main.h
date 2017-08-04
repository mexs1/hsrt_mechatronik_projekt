/*
Header-Datei für Konstanten
*/

#ifndef __MAIN_H__
#define __MAIN_H__

#define ADC_FACTOR = 0.1966953277; //Faktor zwecks Umrechnung aus Datenregister zur tatsächlichen Spannung
extern int stateOfCharge(double voltage);
extern void adc1Init();
extern void adc2Init();
extern void gpioInit();
extern void spiInit();


#endif //MAIN_H
