// stm32F030 islemcisi için tanımlanan çeşitli işlev ve makrolar
#ifndef __MYLIB__
#define __MYLIB__

#include "stm32f0xx.h"				// device header

// ------------------------------------------------------------------------
// bazı yararlı makrolar
#define enable_interrupts()		__enable_irq()
#define disable_interrupts()	__disable_irq()
#define wait_interrupts()		__wfi
#define wait_exceptions()		__wfe

#define forever for(;;)
#define lock forever

// ------------------------------------------------------------------------
// bit işlemleri
#define BV(n) (1UL<<(n))
#define bit_test(data,bit) 		(((data) & BV(bit)) ? 1 : 0)
#define bit_set(data,bit) 		data |= BV(bit)
#define bit_clear(data,bit) 	data &= ~BV(bit)
#define bit_toggle(data,bit) 	data ^= BV(bit)
#define bit_copy(data,bit,val) 	if((val)!=0) bit_set(data,bit); else bit_clear(data,bit)

#include "us_delay.h"			// mikrosaniye gecikme işlevleri
#include "adc_drv.h"
#include "stm32f0xx_clock.c"	// sistem saati kütüphanesi
#include "stm32f0xx_port.c"		// port ve pin kütüphanesi
#include "stm32f0xx_timer.c"	// timer kütüphanesi

//#include "stm32f0xx_uart.c"		// seri port kütüphanesi


#endif
