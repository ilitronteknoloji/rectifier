// Röle ile ilgili islevler
#include <assert.h>

// ---- Röle pinleriyle ilgili donanim tanimlamalari ----
// Relay1-6: PB4,PA15,PF7,PF6,PA11,PA14
#define MAX_RELAY	6
#define rlFan	0		// fan
#define rlValve	1		// valf
#define rlDelta	2		// Run-üçgen
#define rlStar	3		// Run-Yildiz
#define rlRun	4		// Run-Ana motor
#define	rlAlarm	5		// Alarm


GPIO_TypeDef * RELAY_PORT[MAX_RELAY] ={GPIOB,GPIOA,GPIOF,GPIOF,GPIOA,GPIOA};
#ifdef DEBUG
unsigned char RELAY_PIN[MAX_RELAY]   ={    4,   15,    7,    6,   11,   11};
#else
unsigned char RELAY_PIN[MAX_RELAY]   ={    4,   15,    7,    6,   11,   14};
#endif


// röle portlarini kosullama
void relay_init(void)
{
	for(int i=0; i<MAX_RELAY; i++){
		pin_mode(RELAY_PORT[i],RELAY_PIN[i], OUTPUT);
	}
}

// Röle ON OFF tanimlamalari
#define ON  1
#define OFF 0

// istenen röleyi on veya off yapar
void relay_set(int relay, int data)
{
//	assert(relay>=MAX_RELAY);	
	pin_write(RELAY_PORT[relay],RELAY_PIN[relay],data);
}

// istenen röle durumunu okur
int relay_get(int relay)
{
//	assert(relay>=MAX_RELAY);	
	return pin_read(RELAY_PORT[relay],RELAY_PIN[relay]);
}

// tüm röleleri kapat!
void relay_alloff(void)
{
//	assert(relay>=MAX_RELAY);	
	for(int i=0; i<MAX_RELAY; i++){
		relay_set(i,0);
	}
}
	
	



