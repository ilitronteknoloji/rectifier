// stm32F0xx için sistem saati kontrolü
// ---- portx resetleme ----
#define porta_reset() bit_set(RCC->AHBRSTR, RCC_AHBRSTR_GPIOARST_Pos)
#define portb_reset() bit_set(RCC->AHBRSTR, RCC_AHBRSTR_GPIOBRST_Pos)
#define portc_reset() bit_set(RCC->AHBRSTR, RCC_AHBRSTR_GPIOCRST_Pos)
#define portd_reset() bit_set(RCC->AHBRSTR, RCC_AHBRSTR_GPIODRST_Pos)
#define portf_reset() bit_set(RCC->AHBRSTR, RCC_AHBRSTR_GPIOFRST_Pos)

// ---- portlara clock sinyalini açar/kapatır ----
#define OFF 0
#define ON 1
// ------------------------------------------------------------------------
#define clock_porta(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_GPIOAEN_Pos,data)
#define clock_portb(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_GPIOBEN_Pos,data) 
#define clock_portc(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_GPIOCEN_Pos,data)
#define clock_portd(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_GPIODEN_Pos,data)
#define clock_portf(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_GPIOFEN_Pos,data)
#define clock_dma(data)		bit_copy(RCC->AHBENR,RCC_AHBENR_DMAEN_Pos,data)
#define clock_sram(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_SRAMEN_Pos,data)
#define clock_flitfen(data)	bit_copy(RCC->AHBENR,RCC_AHBENR_DMAEN_Pos,data)
#define clock_crc(data)		bit_copy(RCC->AHBENR,RCC_AHBENR_CRCEN_Pos,data)
// ------------------------------------------------------------------------
#define clock_syscfg(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_SYSCFGCOMPEN_Pos,data)
#define clock_adc(data)		bit_copy(RCC->APB2ENR,RCC_APB2ENR_ADCEN_Pos,data)
#define clock_tim1(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_TIM1EN_Pos,data)
#define clock_spi1(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_SPI1EN_Pos,data)
#define clock_usart1(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_USART1EN_Pos,data)
#define clock_tim15(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_TIM15EN_Pos,data)
#define clock_tim16(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_TIM16EN_Pos,data)
#define clock_tim17(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_TIM17EN_Pos,data)
#define clock_dbgmcu(data)	bit_copy(RCC->APB2ENR,RCC_APB2ENR_DBGMCUEN_Pos,data)
// ------------------------------------------------------------------------
#define clock_tim3(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_TIM3EN_Pos,data)
#define clock_tim6(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_TIM6EN_Pos,data)
#define clock_tim14(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_TIM14EN_Pos,data)
#define clock_wwdg(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_WWDGEN_Pos,data)
#define clock_spi2(data)	bit_copy(RCC->APB1ENR,RCC_APB2ENR_SPI2EN_Pos,data)
#define clock_usart2(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_USART2EN_Pos,data)
#define clock_i2c1(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_I2C1EN_Pos,data)
#define clock_i2c2(data)	bit_copy(RCC->APB1ENR,RCC_APB1ENR_I2C2EN_Pos,data)
#define clock_pwr(data)		bit_copy(RCC->APB1ENR,RCC_APB1ENR_PWREN_Pos,data)
// ------------------------------------------------------------------------
// AHB donanımlarına clock sinyali verme
#define PORTAEN		RCC_AHBENR_GPIOAEN		// porta
#define PORTBEN		RCC_AHBENR_GPIOBEN		// portb
#define PORTCEN		RCC_AHBENR_GPIOCEN		// portc
#define PORTDEN		RCC_AHBENR_GPIODEN		// portd
#define PORTFEN		RCC_AHBENR_GPIOFEN		// portf
#define DMAEN		RCC_AHBENR_DMAEN		// dma
#define SRAMEN		RCC_AHBENR_SRAMEN		// sram
#define FLITFEN		RCC_AHBENR_FLITFEN		// flash interface
#define CRCEN		RCC_AHBENR_CRCEN		// crc

#define clock_AHB(data) RCC->AHBENR = data

// ------------------------------------------------------------------------
// APB2 donanımlarına clock sinyali verme

#define SYSCFGCOMPEN	RCC_APB2ENR_SYSCFGCOMPEN	// Syscfg & comp
#define ADCEN			RCC_APB2ENR_ADCEN			// ADC
#define TIM1EN			RCC_APB2ENR_TIM1EN			// TIM1
#define SPI1EN			RCC_APB2ENR_SPI1EN			// SPI1
#define USART1EN		RCC_APB2ENR_USART1EN		// USART1
#define TIM15EN			RCC_APB2ENR_TIM15EN			// TIM15
#define TIM16EN			RCC_APB2ENR_TIM16EN			// TIM16
#define TIM17EN			RCC_APB2ENR_TIM17EN			// TIM17
#define DBGMCUEN		RCC_APB2ENR_DBGMCUEN		// DEBUG MCU

#define clock_APB2(data) RCC->APB2ENR = data

// ------------------------------------------------------------------------
// APB1 donanımlarına clock sinyali verme

#define TIM3EN			RCC_APB1ENR_TIM3EN			// TIM3
#define TIM6EN			RCC_APB1ENR_TIM6EN			// TIM6
#define TIM14EN			RCC_APB1ENR_TIM14EN			// TIM14
#define WWDGEN 			RCC_APB1ENR_WWDGEN			// WWDG
#define SPI2EN			RCC_APB2ENR_SPI2EN			// SPI2
#define USART2EN		RCC_APB1ENR_USART2EN		// USART2
#define I2C1EN			RCC_APB1ENR_I2C1EN			// I2C1
#define I2C2EN			RCC_APB1ENR_I2C2EN 			// I2C2
#define PWREN			RCC_APB1ENR_PWREN			// Power 

#define clock_APB1(data) RCC->APB1ENR = data

// ------------------------------------------------------------------------
// setup_clockout islevi için parametreler, PA8 pininden clock sinyali çıkar
#define MCO_OFF			RCC_CFGR_MCO_NOCLOCK
#define MCO_HSI14		RCC_CFGR_MCO_HSI14
#define MCO_SYSCLK		RCC_CFGR_MCO_SYSCLK
#define MCO_HSI			RCC_CFGR_MCO_HSI
#define MCO_HSE			RCC_CFGR_MCO_HSE
#define MCO_PLL			RCC_CFGR_MCO_PLL

#ifndef	__STM32F030x8_H		// STM32F030x8 serisinde mevcut değildir
#define MCO_LSI			RCC_CFGR_MCO_LSI
#define MCO_LSE			RCC_CFGR_MCO_LSE
#endif

// MCO_DIVx degerleri sadece STM32F030x6 için geçerlidir
#ifdef __STM32F030x6_H
//RCC_CFGR_MCOPRE_DIV2
#define MCO_DIV1		0x00000000
#define MCO_DIV2		0x10000000
#define MCO_DIV4		0x20000000
#define MCO_DIV8		0x30000000
#define MCO_DIV16		0x40000000
#define MCO_DIV32		0x50000000
#define MCO_DIV64		0x60000000
#define MCO_DIV128		0x70000000
#endif

#define setup_clockout(data)	do{	\
		RCC->CFGR = (RCC->CFGR & ~(RCC_CFGR_MCO)) | option;	\
		clock_porta(ON);									\
		GPIOA->MODER &= ~(3 << 16);							\
		if(option != MCO_OFF){								\
			GPIOA->MODER   |= ALTERNATE << (16);			\
			GPIOA->OSPEEDR |= HIGHSPEED << (16);			\
		}													\
	} while(0)

// ------------------------------------------------------------------------
// iç osilatör ile ilgili makrolar
// PLL, HSE, HSI çalıştır veya durdur, HSE baypass çalıştır/durdur
#define clock_hsi(data) bit_copy(RCC->CR,RCC_CR_HSION_Pos,data)
#define clock_pll(data) bit_copy(RCC->CR,RCC_CR_PLLON_Pos,data)
#define clock_hse(data) bit_copy(RCC->CR,RCC_CR_HSEON_Pos,data)
#define clock_bypass(data) bit_copy(RCC->CR,RCC_CR_HSEBYP_Pos,data)

// HSE, HSI, PLL sorgulama
#define is_HSIready() bit_test(RCC->CR,RCC_CR_HSIRDY_Pos)
#define is_HSEready() bit_test(RCC->CR,RCC_CR_HSERDY_Pos)
#define is_PLLlocked() bit_test(RCC->CR,RCC_CR_PLLRDY_Pos)

// HSICAL ve HSITRIM değerlerini okuma
#define get_HSIcal() ((RCC->CR & RCC_CR_HSICAL)>>RCC_CR_HSICAL_Pos)
#define set_HSItrim(data) RCC->CR = (RCC->CR & ~RCC_CR_HSITRIM) | ((data)<<RCC_CR_HSITRIM_Pos)
// HSITRIM değerini değiştirme
#define get_HSItrim() ((RCC->CR & RCC_CR_HSITRIM)>>RCC_CR_HSITRIM_Pos)

// ------------------------------------------------------------------------
// PLL kaynağını ve çarpma değerini ayarlama, 
#define PLLSRC_HSE_PREDIV	RCC_CFGR_PLLSRC_HSE_PREDIV
#define PLLSRC_HSI_DIV2		RCC_CFGR_PLLSRC_HSI_DIV2
#define PLLx2				RCC_CFGR_PLLMUL2
#define PLLx3				RCC_CFGR_PLLMUL3
#define PLLx4				RCC_CFGR_PLLMUL4
#define PLLx5				RCC_CFGR_PLLMUL5
#define PLLx6				RCC_CFGR_PLLMUL6
#define PLLx7				RCC_CFGR_PLLMUL7
#define PLLx8				RCC_CFGR_PLLMUL8
#define PLLx9				RCC_CFGR_PLLMUL9
#define PLLx10				RCC_CFGR_PLLMUL10
#define PLLx11				RCC_CFGR_PLLMUL11
#define PLLx12				RCC_CFGR_PLLMUL12
#define PLLx13				RCC_CFGR_PLLMUL13
#define PLLx14				RCC_CFGR_PLLMUL14
#define PLLx15				RCC_CFGR_PLLMUL15
#define PLLx16				RCC_CFGR_PLLMUL16

// Dış HSE frekansını PLL girişinde bölme değerini ayarlama, 
#define HSE_PREDIV1		0
#define HSE_PREDIV2		1
#define HSE_PREDIV3		2
#define HSE_PREDIV4		3
#define HSE_PREDIV5		4
#define HSE_PREDIV6		5
#define HSE_PREDIV7		6
#define HSE_PREDIV8		7
#define HSE_PREDIV9		8
#define HSE_PREDIV10	9
#define HSE_PREDIV11	10
#define HSE_PREDIV12	11
#define HSE_PREDIV13	12
#define HSE_PREDIV14	13
#define HSE_PREDIV15	14
#define HSE_PREDIV16	15

// PLL değerini değiştirir, önce PLL durdurur, sonra başlatır.

#define set_PLL(mul,div)		do { bit_clear(RCC->CR,RCC_CR_PLLON_Pos);	\
	while(bit_test(RCC->CR,RCC_CR_PLLRDY_Pos));								\
	RCC->CFGR = (RCC->CFGR & ~(RCC_CFGR_PLLMUL | RCC_CFGR_PLLSRC)) | (mul);	\
	RCC->CFGR2 = div;														\
	bit_set(RCC->CR,RCC_CR_PLLON_Pos);	} while(0)

/*
void set_PLL(int mul,int div)
{ 
	bit_clear(RCC->CR,RCC_CR_PLLON_Pos);			// pll off
//	while(bit_test(RCC->CR,RCC_CR_PLLRDY_Pos));		// pllrdy=0 olana dek bekle
	RCC->CFGR = (RCC->CFGR & ~(RCC_CFGR_PLLMUL | RCC_CFGR_PLLSRC)) | (mul);
	RCC->CFGR2 = div;								// bölme oranını ayarla
	bit_set(RCC->CR,RCC_CR_PLLON_Pos);				// pll on
}
*/
	
// ------------------------------------------------------------------------
// Saat kaynağını okuma ve değiştirme: HSI,HSE,PLL
#define CLOCK_HSI RCC_CFGR_SW_HSI
#define CLOCK_HSE RCC_CFGR_SW_HSE
#define CLOCK_PLL RCC_CFGR_SW_PLL

#define set_clock_source(data) RCC->CFGR=(RCC->CFGR & ~RCC_CFGR_SW) | (data)
#define get_clock_source() ((RCC->CFGR & RCC_CFGR_SWS)>>RCC_CFGR_SWS_Pos)

// ------------------------------------------------------------------------
// AHB ve APB clock hızını ayarla
#define AHB_DIV1	RCC_CFGR_HPRE_DIV1
#define AHB_DIV2	RCC_CFGR_HPRE_DIV2
#define AHB_DIV4	RCC_CFGR_HPRE_DIV4
#define AHB_DIV8	RCC_CFGR_HPRE_DIV8
#define AHB_DIV16	RCC_CFGR_HPRE_DIV16
#define AHB_DIV64	RCC_CFGR_HPRE_DIV64
#define AHB_DIV128	RCC_CFGR_HPRE_DIV128
#define AHB_DIV256	RCC_CFGR_HPRE_DIV256
#define AHB_DIV512	RCC_CFGR_HPRE_DIV512

#define APB_DIV1	RCC_CFGR_PPRE_DIV1
#define APB_DIV2	RCC_CFGR_PPRE_DIV2
#define APB_DIV4	RCC_CFGR_PPRE_DIV4
#define APB_DIV8	RCC_CFGR_PPRE_DIV8
#define APB_DIV16	RCC_CFGR_PPRE_DIV16

#define set_peripheral_clock(data) RCC->CFGR=(RCC->CFGR & ~(RCC_CFGR_PPRE | RCC_CFGR_HPRE)) | (data) 

// ------------------------------------------------------------------------
// LSI çalıştırma/durdurma
#define clock_lsi(data) bit_copy(RCC->CSR,RCC_CSR_LSION_Pos,data)
// LSI sorgulama
#define is_LSIready() bit_test(RCC->CSR,RCC_CSR_LSIRDY_Pos)

// ------------------------------------------------------------------------
// restart nedenini sorgulama
// low power,wwatcdog,iwatchdog,sofware, powerup,resetpin,optionbit, 1.8V domain
#define LOW_POWER	RCC_CSR_LPWRRSTF
#define WWATCHDOG	RCC_CSR_WWDGRSTF
#define IWATCHDOG	RCC_CSR_IWDGRSTF
#define SOFT_RESET	RCC_CSR_SFTRSTF
#define POWERON		RCC_CSR_PORRSTF
#define NRSTPIN		RCC_CSR_PINRSTF
#define OPTIONBIT	RCC_CSR_OBLRSTF
#define VOLT1V8		RCC_CSR_V18PWRRSTF

// restart nedenini geri döndürür ve sıfırlar
unsigned int restart_cause(void)
{
	unsigned int temp = RCC->CSR;
	bit_set(RCC->CSR,RCC_CSR_RMVF_Pos);
	return temp;
}

// ------------------------------------------------------------------------
