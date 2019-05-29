
/******************************************************
*******			   ADC DRIVER 					*******
*******											*******
*******		Muhammed Çagatay Güzgün				*******
*******		Rev 0.1								*******
*******											*******
*******				ILITRON						*******
*******											*******
*******											*******
*******************************************************/
#include "stm32f0xx.h"                  // Device header
/**********************************************************
***														***
***														***
***														***
***********************************************************/
#define ADC_CONV_CLK_1_5  		0x00
#define ADC_CONV_CLK_7_5		0x01
#define ADC_CONV_CLK_13_5		0x02
#define ADC_CONV_CLK_28_5		0x03
#define ADC_CONV_CLK_41_5		0x04
#define ADC_CONV_CLK_55_5		0x05
#define ADC_CONV_CLK_71_5		0x06
#define ADC_CONV_CLK_239_5		0x07
#define adc_set_conv_time(n) ADCREG->SMPR=a

/**********************************************************
***														***
***														***
***														***
***********************************************************/
#define adc_conv_start() SET_BIT(ADCREG->CR,ADC_CR_ADSTART)
#define adc_conv_stop() SET_BIT(ADCREG->CR,ADC_CR_ADSTP)
/**********************************************************
***														***
***														***
***														***
***********************************************************/
#define ADC_RES_12_BIT  		0x00<<3
#define ADC_RES_10_BIT			0x01<<3
#define ADC_RES_8_BIT			0x02<<3
#define ADC_RES_6_BIT			0x03<<3
#define adc_set_res(n) ADCREG->CFGR1 &=  ~(0x03<<3);\
					   ADCREG->CFGR1 |= n;
/**********************************************************
***														***
***														***
***														***
***********************************************************/
#ifndef ADC_DRV_H
#include "adc_drv.h"
#endif
/**********************************************************
***														***
***														***
***														***
***********************************************************/
ADC_TypeDef  *ADCREG = (ADC_TypeDef *)ADC1_BASE;
RCC_TypeDef  *RCCREG = (RCC_TypeDef *)RCC_BASE;



inline int ACTIVE_CHANNEL_COUNT(){
int count=0;
uint32_t reg=ADC1->CHSELR;	
	for(uint32_t a=0;a<18;a++){	
		if((reg & 1<<a) != 0)count++;
	}
	return count;
}


/**		
  * @brief  Adc peripheralı için dmayı aktifleştir Channel 1
  * @param  None
  * @retval None
  */
void adc_dma_start(uint16_t *ADC_array){
RCC->AHBENR |= RCC_AHBENR_DMA1EN; 												// DMA clock açılışı
ADC1->CFGR1 |= ADC_CFGR1_DMAEN | ADC_CFGR1_DMACFG; 								// ADC dma moduna alınır ve circular moda geçilir
DMA1_Channel1->CPAR = (uint32_t) (&(ADC1->DR)); 								// peripheral adresi yazılır
DMA1_Channel1->CMAR = (uint32_t)(ADC_array); 									// memory adresi yazılır
DMA1_Channel1->CNDTR = ACTIVE_CHANNEL_COUNT(); 									// adress boyutu yazıkıt
DMA1_Channel1->CCR |= DMA_CCR_MINC | DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_1			// artış tipi boyutu ve circular hareket bilgisi girilir
 | DMA_CCR_TEIE | DMA_CCR_CIRC; 												//
DMA1_Channel1->CCR |= DMA_CCR_EN; 												// DMA1 çalıştırılır

}
/**
  * @brief  Adc clock ayarlarını yapar HSI14 kaynağı seçilidir
  * @param  None
  * @retval None
  */
void adc_clk_init(){
SET_BIT(RCCREG->APB2ENR,RCC_APB2ENR_ADC1EN);									// Adc clokc çalıştır
SET_BIT(RCCREG->CR2,RCC_CR2_HSI14ON); 											// High speed internal rc oscilatorünü devreye sok
while ((RCC->CR2 & RCC_CR2_HSI14RDY) == 0); 									// oscilatör çalışmasını bekle

ADC1->CFGR2 &= (~ADC_CFGR2_CKMODE); 											// kaynak olarak HSI14 ü seç
};


/**
  * @brief  adc kalibrasyonunu başlatır, initialize komutundan önce gelmesi gerekir.
  * @param  None
  * @retval None
  */
void adc_calibrate(){
CLEAR_BIT(ADCREG->CR,ADC_CR_ADEN);												// ADC kapat
CLEAR_BIT(RCCREG->AHBENR,RCC_AHBENR_DMAEN);										// DMA kapat

SET_BIT(ADCREG->CR,ADC_CR_ADCAL);												// Kalibrasyon baslat
		
while(READ_BIT(ADCREG->CR,ADC_CR_ADCAL));										// Kalibrasyonu bekle
};

/**
  * @brief  adc peripheralını başlatır
  * @param  None
  * @retval None
  */
void adc_enable(){

if (READ_BIT(ADCREG->ISR,ADC_ISR_ADRDY) != 0) 
{
 ADCREG->ISR |= ADC_ISR_ADRDY;													// adc_calibrate ready bitini resetlemek için 1 durumuna getir
}

SET_BIT(ADCREG->CR,ADC_CR_ADEN);												// Adc �alistir

while(READ_BIT(ADCREG->ISR,ADC_ISR_ADRDY) != 1);								// Adc hazirlanmasini bekle
};
/**
  * @brief  adc kalibrasyonunu başlatır, initialize komutundan önce gelmesi gerekir.
  * @param  None
  * @retval None
  */
void adc_init(uint16_t *adcbuf,uint32_t Channels){
	adc_calibrate();																// Kalibrasyonu yap
	adc_clk_init();																	// Clock ayarlarini yap
	adc_enable();																	// adcyi çalıştır												
	adc_channel_select(Channels);													// adc kanallarını başlat

	SET_BIT(ADCREG->CFGR1,ADC_CFGR1_CONT);											// adcyi devamlı çalışma moduna al
	CLEAR_BIT(ADCREG->CFGR1,ADC_CFGR1_DISCEN);										// emin olmak için disc mode kapalı
	SET_BIT(ADCREG->CFGR1,ADC_CFGR1_SCANDIR);										// ileri yönde çalıştır kanal 0 -> kanal 1 -> kanal 2 -> kanal 3 ....
	adc_set_res(ADC_RES_12_BIT);													// resolution 12 bit 
	CLEAR_BIT(ADCREG->CFGR1,ADC_CFGR1_ALIGN);										// little endian modu
	SET_BIT(ADCREG->CFGR1,ADC_CFGR1_OVRMOD);										// overrun durumu ile ilgilenme
	adc_dma_start(adcbuf);


};
/**
  * @brief  adc yi kapatır.
  * @param  None
  * @retval None
  */
void adc_disable(){

ADC1->CR |= ADC_CR_ADSTP;														//
while ((ADC1->CR & ADC_CR_ADSTP) != 0);
ADC1->CR |= ADC_CR_ADDIS; 
while ((ADC1->CR & ADC_CR_ADEN) != 0);
};


