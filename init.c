#include <ADuCM360.H>

int spiInit (void){

		pADI_SPI0->SPIDIV |= SPIDIV_DIV_MSK;	

		pADI_SPI0->SPICON |= SPICON_MASEN_EN;
	  pADI_SPI0->SPICON |= SPICON_LSB_EN;
		pADI_SPI0->SPICON |= SPICON_ENABLE_EN;
	
}

int gpioInit(void){
	
/*--------SPI-------------------------------------*/
	
	//Multiplexen der SPI0-Pins
	  pADI_GP1->GPCON |= GP1CON_CON4_SPI0MISO;
		pADI_GP1->GPCON |= GP1CON_CON5_SPI0SCLK;
	  pADI_GP1->GPCON |= GP1CON_CON6_SPI0MOSI;
	  pADI_GP1->GPCON |= GP1CON_CON7_SPI0CS;    //Kann auch alternativ normaler GPIO Output sein

/*--------GPIO-------------------------------------*/
	
		pADI_GP1->GPOEN |= GP1OEN_OEN6;						//MOSI -> Output
		pADI_GP1->GPOEN |= GP1OEN_OEN7;						//CS   -> Output
	
}

int adc0Init(void){

	pADI_ADC0->MDE |= ADCMDE_ADCMD_IDLE;    		//Idle-Mode zur Kalibrierung
	pADI_ADC0->CON |= ADCCON_ADCEN;	      			//Aktiviere ADC0
	pADI_ADC0->CON |= ADCCON_ADCCP_AIN0;  			//Positiver Kanal : AIN0
	pADI_ADC0->CON |= ADCCON_ADCCN_AIN5;  			//Negativer Kanal : AIN5
	pADI_ADC0->MDE |= ADCMDE_ADCMD_INTOCAL; 		//Zero-Scale-Calibration
	pADI_ADC0->MDE = ADCMDE_ADCMD_CONT;    			//Kontinuierliche Messung über
}

int uartInit(void){

	
	
}

//TO DO : Clock Inits
