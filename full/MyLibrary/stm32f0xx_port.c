// stm32F0xx için pin işlevleri

// ------------------------------------------------------------------------
// pin makroları

// pin çalışma tipi (2bit)
#define INPUT		0
#define OUTPUT		1
#define ALTERNATE	2
#define ANALOG		3

// pin çıkış hızı (2bit), output, alternate
#define LOWSPEED	0 
#define MIDSPEED	1
#define HIGHSPEED	3

// pin çıkış  tipi (1bit), output,alternate
#define PUSHPULL	0
#define OPENDRAIN	1

// pull-up/down direnç seçme (2bit), input
#define NORESISTOR	0
#define PULLUP		1
#define PULLDOWN	2

// pin çalışma modunu değiştirme,	(INPUT,OUTPUT,ALTERNATE,ANALOG)
#define pin_mode(port,pin,mode) port->MODER = (port->MODER & ~(3U<<((pin)<<1)) ) | ((mode)<<((pin)<<1))

// pin çıkış hızını değiştirme,		(LOWSPEED,MIDSPEED,HIGHSPEED)
#define pin_speed(port,pin,speed) port->OSPEEDR = (port->OSPEEDR & ~(3U<<((pin)<<1)) ) | ((speed)<<((pin)<<1))

// pin çıkış tipini değiştirme,		(PUSHPULL,OPENDRAIN)
#define pin_type(port,pin,type) port->OTYPER = (port->OTYPER & ~(1U<<pin) ) | (type<<pin)

// pin dirençlerini değiştirme,		(NORESISTOR,PULLUP,PULLDOWN)
#define pin_resistor(port,pin,resistor) port->PUPDR = (port->PUPDR & ~(3U<<((pin)<<1)) ) | ((resistor)<<((pin)<<1))

// pin alternatif tipini seçme,		(0-15)
#define pin_alternate(port,pin,alt) if(pin>=8) port->AFR[1] = (port->AFR[1] & ~(15U<<((pin-8)*4))) | ((alt)<<((pin-8)*4));\
									else port->AFR[0] = (port->AFR[0] & ~(15U<<((pin)*4)) ) | ((alt)<<((pin)*4)) 

// pine veri yazma
#define pin_write(port,pin,data) if(data!=0) pin_high(port,pin); else pin_low(port,pin)

// pin çıkışlarını high,low,toggle olarak değiştirme
#define pin_high(port,pin) port->BSRR = BV(pin)
#define pin_low(port,pin)  port->BRR = BV(pin)
#define pin_toggle(port,pin) port->ODR ^= BV(pin)

// pin girişini okuma
#define pin_read(port,pin) bit_test(port->IDR,pin)

// ------------------------------------------------------------------------
// port makroları

// ---- port mode seçme ----
#define port_mode(port,mode)	port->MODER = mode

// ---- port hız seçme ---- (LOWSPEED,MEDSPEED,HIGHSPEED)
#define port_speed(port,speed)	port->OSPEEDR = speed

// ---- port çıkış tipi seçme ---- (PUSHPULL,OPENDRAIN)
#define port_type(port,type)	port->TYPER = type

// ---- port direnci seçme ---- (NORESISTOR,PULLUP,PULLDOWN)
#define port_resistor(port,res)	port->PUPDR = res

// ---- port bitlerini kilitleme ----
#define port_lock(port, pins)	do{ 		\
	port->LCKR = pins | GPIO_LCKR_LCKK;		\
	port->LCKR = pins;						\
	port->LCKR = pins | GPIO_LCKR_LCKK;		\
	uint32_t tmp = port->LCKR;	}while(0);


// ---- port çıkış makroları ----
// ---- port pinlerine değer yazma ----
#define port_write(port,pins)		port->ODR = pins

// ---- port pinlerini high yapma ----
#define port_high(port,pins)		port->BSRR = pins

// ---- port pinlerini low yapma ----
#define port_low(port,pins)			port->BRR  = pins

// ---- port pinlerini konum evirme ----
#define port_toggle(port, pins)		port->ODR ^= pins

// ---- port pinlerini okuma ----
#define port_read(port)				port->IDR

// ---- port pinleri kesme özellikleri ----
//?????????????#define port_interrupt(intreq)		port->	
	


