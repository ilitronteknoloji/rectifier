#define DEBUG				// debugger varken mutlaka bu tanımlanmalı

#define F_CPU 48000000UL		// gecikme için CPU frekansı tanımlama
#include "mylib.c"				// benim standart kütüphanelerim
#include "relay.c"				// röle ile ilgili işlevler
#include "inputs.c"				// sayısal girişler ile ilgili işlevler
#include "delay.c"				// gecikme ile ilgili işlevler

#define DEBUG
uint16_t ADC_buffer[10];
// ---- main.c dosyası işlev prototipleri ----
//void initClock(void);
//void initPorts(void);


#define USE_XTAL 0				// kristal kullan
// ---- sistem saatini 48MHz olarak ayarla ----
/**
  * @brief  Clock başlangıc fonksyounu
  * @param  None
  * @retval None
  */
inline void initClock(void)		// sistem saatini koşulla
{
#if USE_XTAL==1
// Dış osilatör 4MHz kristal kullanılıyor, PLL ile *12 yapılıyor
	clock_hse(ENABLE);									// HSE başlat
	set_PLL(PLLx12 | PLLSRC_HSE_PREDIV, HSE_PREDIV1);	// PLLMUL=12, HSE(4MHz) => 48MHz
#else
// Alternatif olarak iç osilatör/2, PLL ile * 12 yapılıyor
	set_PLL(PLLx12 | PLLSRC_HSI_DIV2,HSE_PREDIV1);		// PLLMUL=12, HSI/2 => 48MHz
#endif
	set_clock_source(CLOCK_PLL);						// sistem saati pll seç	
	while(!is_PLLlocked());								// PLL kilitlenene dek bekle!
	SystemCoreClockUpdate();							// sistem frekansını hesaplat!
}


// sistem başlangıç koşullamaları
inline void initialize(void)
{	// portların saatlerini aç
	clock_AHB(PORTAEN | PORTBEN | PORTCEN | PORTFEN);
	relay_init();					// röleleri koşulla
	//initDigitalInputs();			// sayısal girişleri koşulla (boş)
	//initAnalogInputs();				// analog girişleri koşullama
	adc_init(ADC_buffer,ADC_CHSELR_CHSEL1 | ADC_CHSELR_CHSEL3);
//	initTimers();					// zamanlayıcıları koşulla

		
}
inline void init_analog(void)
{	
	pin_mode(GPIOA,1,ANALOG);
	pin_mode(GPIOA,3,ANALOG);
		
}



// ---- 1ms sistem saati kesmesi ----
void SysTick_Handler(void)
{
	TimeTick++;
	// ---- 1ms gecikme zamanlayıcı ----	
	if(TimingDelay!=0)
		TimingDelay --;
}


int main(void)
{
	logging=0;
	initClock();					// sistem saatini ayarla, 48MHz
	// SysTick zamanlayıcısını koşullama
	if (SysTick_Config(SystemCoreClock / 1000)){
		forever;					// hata olunca burada dur...
	}
	initialize();					// sistemi koşulla	
	adc_start();
// bundan sonra kendi denemelerimiz yer alıyor

	forever;
}


#ifdef USE_FULL_ASSERT
void assert_failed(uint8_t* file , uint32_t line)
{
		/* Infinite loop */
		/* Use GDB to find out why we're here */
			while (1);
}
#endif


/******************************************************************************/
/*            Cortex-M0 İşlemcisi Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  RCC güvenlik hatası, RAM parite hatası
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
	forever;
}

/**
  * @brief  Bus hatası, tanımsız kod, adres hatası...
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
	forever;	// HardFault olduğunda sonsuz döngü
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}


