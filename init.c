#include <ADuCM360.H>
#include "AdcLib.h"
#include "DioLib.h"

void spiInit (void){
	
	//SD   TO DO..............

		pADI_SPI0->SPIDIV |= SPIDIV_DIV_MSK;	

		pADI_SPI0->SPICON |= SPICON_MASEN_EN;
	  pADI_SPI0->SPICON |= SPICON_LSB_EN;
		pADI_SPI0->SPICON |= SPICON_ENABLE_EN;
	
	//Can-Controller
		DioPulPin(pADI_GP1,4,0);													//Alle Pull-Up-Widerstände abschalten
		DioPulPin(pADI_GP1,5,0);
		DioPulPin(pADI_GP1,6,0);
	  DioPulPin(pADI_GP1,7,0);
	
		pADI_CLKCTL->CLKCON1 |= CLKCON1_SPI1CD_DIV2;			//Clock is set to UCLK/2 = 8MHz. Can-Controller kann bis zu 10 MHz unterstützen uC bis 8MHz
	  pADI_SPI1->SPIDIV |= SPIDIV_DIV_MSK;
		pADI_SPI1->SPICON |= SPICON_CPOL_LOW;							//Clock Polarity Low
	  pADI_SPI1->SPICON |= SPICON_CPHA_SAMPLELEADING;		//Clock Phase -> rising edge of SCK
	  pADI_SPI1->SPICON |= SPICON_MASEN_EN;							//Enable Master Operation
	  pADI_SPI1->SPICON |= SPICON_LSB_DIS;							//MSB first
	
	  pADI_SPI1->SPICON |= SPICON_ENABLE_EN;						//Enable SPI1
	  
}

void gpioInit(void){
	
/*--------SPI-------------------------------------*/
	
	//Multiplexen der SPI1-Pins (Can-Controller)
	  pADI_GP1->GPCON |= GP1CON_CON4_SPI0MISO;
		pADI_GP1->GPCON |= GP1CON_CON5_SPI0SCLK;
	  pADI_GP1->GPCON |= GP1CON_CON6_SPI0MOSI;
	  //pADI_GP1->GPCON |= GP1CON_CON7_SPI0CS;    //Kann auch alternativ normaler GPIO Output sein
	//Zusätzlicher Pin für INT - Pin vom Can controller
	
	//Multiplexen der SPI0-Pins (SD)
		pADI_GP0->GPCON |= GP0CON_CON0_SPI1MISO;
	  pADI_GP0->GPCON |= GP0CON_CON1_SPI1SCLK;
	  pADI_GP0->GPCON |= GP0CON_CON2_SPI1MOSI;
	  //pADI_GP0->GPCON |= GP0CON_CON3_SPI1CS0;   //Kann auch alternativ normaler GPIO Output sein

/*--------GPIO-------------------------------------*/
	
		pADI_GP1->GPOEN |= GP1OEN_OEN6_OUT;						//MOSI1 -> Output
		pADI_GP1->GPOEN |= GP1OEN_OEN7_OUT;						//CS1  -> Output
		DioOenPin(pADI_GP1,4,0);											//MISO1 -> Input
		DioOenPin(pADI_GP1,5,1);											//SCLK1 -> Output
		pADI_GP0->GPOEN |= GP0OEN_OEN2_OUT;						//MOSI0 -> Output
	  pADI_GP0->GPOEN |= GP0OEN_OEN3_OUT;						//CS0 -> Output
		pADI_GP1->GPOEN |= GP1OEN_OEN3_OUT;						//MCP2515 INT -> Output
}	

void adc1Init(void){
	pADI_ADC0->MDE |= ADCMDE_ADCMD_IDLE;    		//Idle-Mode zur Kalibrierung
	pADI_ADC0->CON |= ADCCON_ADCEN;	      			//Aktiviere ADC0
	pADI_ADC0->CON |= ADCCON_ADCCP_AIN0;  			//Positiver Kanal : AIN0
	pADI_ADC0->CON |= ADCCON_ADCCN_AIN1;  			//Negativer Kanal : AIN1
	pADI_ADC0->MDE |= ADCMDE_ADCMD_INTOCAL; 		//Zero-Scale-Calibration
	pADI_ADC0->MDE = ADCMDE_ADCMD_CONT;    			//Kontinuierliche Messung über
}

/*--------ADC -> Thermoelement ----------------------*/
void adc2Init(void){
	AdcPin(pADI_ADC1,ADCCON_ADCCN_TEMP,ADCCON_ADCCN_AIN5);	//Pin Konfiguriert; Eingang auf ADC-Temp. Eingang und GND auf AIN5
	AdcGo(pADI_ADC1,ADCMDE_ADCMD_CONT);					//Starte kontinuierliche Messung
	
	
}


//TO DO : Clock Inits
