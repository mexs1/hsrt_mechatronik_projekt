#include <ADuCM360.H>

void spiInit (void){
	
	//SD

		pADI_SPI0->SPIDIV |= SPIDIV_DIV_MSK;	

		pADI_SPI0->SPICON |= SPICON_MASEN_EN;
	  pADI_SPI0->SPICON |= SPICON_LSB_EN;
		pADI_SPI0->SPICON |= SPICON_ENABLE_EN;
	
	//Can-Controller
		pADI_SPI1->SPICON |= SPICON_CPOL_LOW;
	  pADI_SPI1->SPICON |= SPICON_CPHA_SAMPLETRAILING;
	  pADI_SPI1->SPICON |= SPICON_MASEN_EN;
	
	  pADI_SPI1->SPICON |= SPICON_ENABLE_EN;
	  
	
	  
	
}

void gpioInit(void){
	
/*--------SPI-------------------------------------*/
	
	//Multiplexen der SPI1-Pins (Can-Controller)
	  pADI_GP1->GPCON |= GP1CON_CON4_SPI0MISO;
		pADI_GP1->GPCON |= GP1CON_CON5_SPI0SCLK;
	  pADI_GP1->GPCON |= GP1CON_CON6_SPI0MOSI;
	  pADI_GP1->GPCON |= GP1CON_CON7_SPI0CS;    //Kann auch alternativ normaler GPIO Output sein
	
	//Multiplexen der SPI0-Pins (SD)
		pADI_GP0->GPCON |= GP0CON_CON0_SPI1MISO;
	  pADI_GP0->GPCON |= GP0CON_CON1_SPI1SCLK;
	  pADI_GP0->GPCON |= GP0CON_CON2_SPI1MOSI;
	  pADI_GP0->GPCON |= GP0CON_CON3_SPI1CS0;   //Kann auch alternativ normaler GPIO Output sein

/*--------GPIO-------------------------------------*/
	
		pADI_GP1->GPOEN |= GP1OEN_OEN6_OUT;						//MOSI1 -> Output
		pADI_GP1->GPOEN |= GP1OEN_OEN7_OUT;						//CS1  -> Output
		pADI_GP0->GPOEN |= GP0OEN_OEN2_OUT;						//MOSI0 -> Output
	  pADI_GP0->GPOEN |= GP0OEN_OEN3_OUT;						//CS0 -> Output
	
/*--------CAN-Transceiver--------------------------*/	
	  pADI_GP0->GPCON |= GPOEN_OEN1_IN;         //UART Serial Input 
	  pADI_GP0->GPCON |= GPOEN_OEN2_OUT;				//UART Serial Output
	  pADI_GP0->GPCON |= GP0CON_CON1_UARTRXD;		//P0.1 Funktion UART RX
		pADI_GP0->GPCON |= GP0CON_CON2_UARTTXD;   //P0.2 Funktion UART TX
	  pADI_GP1->GPCON |= GPOEN_OEN0_OUT;				//P1.0 STBN -> Output
	  pADI_GP1->GPCON |= GPOEN_OEN2_IN;					//P1.2 ERRN -> Input
		pADI_GP1->GPCON |= GPOEN_OEN4_OUT;				//P1.4 EN -> Output
}	

void adc1Init(void){
	pADI_ADC0->MDE |= ADCMDE_ADCMD_IDLE;    		//Idle-Mode zur Kalibrierung
	pADI_ADC0->CON |= ADCCON_ADCEN;	      			//Aktiviere ADC0
	pADI_ADC0->CON |= ADCCON_ADCCP_AIN0;  			//Positiver Kanal : AIN0
	pADI_ADC0->CON |= ADCCON_ADCCN_AIN5;  			//Negativer Kanal : AIN5
	pADI_ADC0->MDE |= ADCMDE_ADCMD_INTOCAL; 		//Zero-Scale-Calibration
	pADI_ADC0->MDE = ADCMDE_ADCMD_CONT;    			//Kontinuierliche Messung über
}

/*--------ADC -> Thermoelement ----------------------*/
void adc2Init(void){
}


//TO DO : Clock Inits
