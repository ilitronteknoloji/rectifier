#ifndef	_US_DELAY_H_
#define	_US_DELAY_H_

#ifndef F_CPU
#define F_CPU 48000000UL
#warning "F_CPU defined as 48MHz"
#endif

// us'den cycle sayisini hesaplar 
#define us2cycle(us)  (F_CPU/4000000UL*us)

// delay cpu cycles
#define delay_cpu_cycles(cycle) for(uint32_t i=cycle; i; i--)

// delay microseconds
#define delay_us(us) delay_cpu_cycles(us2cycle(us))

#endif
