#include <ADuCM360.H>

void spiInit (void){

		pADI_SPI0->SPIDIV |= SPIDIV_DIV_MSK;	

		pADI_SPI0->SPICON |= SPICON_MASEN_EN;
	  pADI_SPI0->SPICON |= SPICON_LSB_EN;
		pADI_SPI0->SPICON |= SPICON_ENABLE_EN;
	
}

void gpioInit(void){
	
/*--------SPI-------------------------------------*/
	
	//Multiplexen der SPI0-Pins
	  pADI_GP1->GPCON |= GP1CON_CON4_SPI0MISO;
		pADI_GP1->GPCON |= GP1CON_CON5_SPI0SCLK;
	  pADI_GP1->GPCON |= GP1CON_CON6_SPI0MOSI;
	  pADI_GP1->GPCON |= GP1CON_CON7_SPI0CS;    //Kann auch alternativ normaler GPIO Output sein

/*--------GPIO-------------------------------------*/
	
		pADI_GP1->GPOEN |= GP1OEN_OEN6;						//MOSI -> Output
		pADI_GP1->GPOEN |= GP1OEN_OEN7;						//CS   -> Output
	
/*--------CAN-Transceiver--------------------------*/	
	  pADI_GP0->GPCON |= GPOEN_OEN1_IN;         //UART Serial Input 
	  pADI_GP0->GPCON |= GPOEN_OEN2_OUT;				//UART Serial Output
	  pADI_GP0->GPCON |= GP0CON_CON1_UARTRXD;		//P0.1 Funktion UART RX
		pADI_GP0->GPCON |= GP0CON_CON2_UARTTXD;   //P0.2 Funktion UART TX
	  pADI_GP1->GPCON |= GPOEN_OEN0_OUT;				//P1.0 STBN -> Output
	  pADI_GP1->GPCON |= GPOEN_OEN2_IN;					//P1.2 ERRN -> Input
		pADI_GP1->GPCON |= GPOEN_OEN4_OUT;				//P1.4 EN -> Output
}	

/*---------ADC -> SHUNT ----------------------------*/
void adc0Init(void){

	pADI_ADC0->MDE |= ADCMDE_ADCMD_IDLE;    		//Idle-Mode zur Kalibrierung
	pADI_ADC0->CON |= ADCCON_ADCEN;	      			//Aktiviere ADC0
	pADI_ADC0->CON |= ADCCON_ADCCP_AIN0;  			//Positiver Kanal : AIN0
	pADI_ADC0->CON |= ADCCON_ADCCN_AIN5;  			//Negativer Kanal : AIN5
	pADI_ADC0->MDE |= ADCMDE_ADCMD_INTOCAL; 		//Zero-Scale-Calibration
	pADI_ADC0->MDE = ADCMDE_ADCMD_CONT;    			//Kontinuierliche Messung über
}

/*--------ADC -> Spannungsmessung -------------------*/
void adc1Init(void){
}

/*--------ADC -> Thermoelement ----------------------*/
void adc2Init(void){
}


void uartInit(void){

	pADI_UART->COMDIV |= COMLCR_WLS_8BITS;				//8-Bit Wortlänge
	
	
	
}

//TO DO : Clock Inits
