

// ms gecikme islevleri

// Timer code
volatile uint32_t TimingDelay;

volatile uint32_t TimeTick;

#define get_timetick()	TimeTick

void delay_ms(uint32_t ms)
{
	ms += get_timetick();
	while(get_timetick()<ms);
}

void delay_s(uint32_t sec)
{
	while(sec-->0){
		delay_ms(1000);
	}
}



