 
 
/******
*******			ADC DRIVER HEADER
*******
*******		Muhammed Çagatay Güzgün
*******		Rev 0.1
*******		
*******				ILITRON
*******	
*******
*******
*******/

#include "stdint.h"
#define ADC_DRV_H

#define adc_channel_select(n) SET_BIT(ADC1->CHSELR,n) 
#define adc_start() SET_BIT(ADC1->CR,ADC_CR_ADSTART) 

/**
  * @brief  adc kalibrasyonunu başlatır, initialize komutundan önce gelmesi gerekir.
  * @param  None
  * @retval None
  */
void adc_init(uint16_t *adcbuf,uint32_t Channels);
/**
  * @brief  Adc peripheralı için dmayı aktifleştir Channel 1
  * @param  None
  * @retval None
  */
void adc_dma_start(uint16_t *ADC_array);
/**
  * @brief  Adc clock ayarlarını yapar HSI14 kaynağı seçilidir
  * @param  None
  * @retval None
  */
void adc_clk_init();
/**
  * @brief  adc kalibrasyonunu başlatır, initialize komutundan önce gelmesi gerekir.
  * @param  None
  * @retval None
  */
void adc_calibrate();
/**
  * @brief  adc peripheralını başlatır
  * @param  None
  * @retval None
  */
void adc_enable();
/**
  * @brief  adc yi kapatır.
  * @param  None
  * @retval None
  */
void adc_disable();





