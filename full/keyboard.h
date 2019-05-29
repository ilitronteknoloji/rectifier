// keyboard
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#define tmKeyRepeatFirst    100     	// 1.0 sn ilk tus tekrar s�resi
#define tmKeyRepeat          10     	// 0.1 sn tus tekrar s�resi
#define tmKeyBeep1            5     	//  40 ms ilk tus basma sesi
#define tmKeyBeep2            2     	//  10 ms tekrar basma sesi
#define tmKeyTimeout      30000     	//  30sn tus zamanasimi s�resi

// butonlarin baglandigi pinler ve buton tanimlamalari
#define kbOn	BV(0)
#define kbOff	BV(1)
#define kbClr	BV(2)
#define kbEnt	BV(3)
#define kbInc	BV(4)
#define kbDec	BV(5)
#define kbS		BV(6)

// tus yapisal degiskeni
typedef struct{
	volatile char Code;
	volatile char Valid;
	volatile char Press;
} Tkey;

Tkey key = {0,0,0};

// gecikme ile ilgili tanimlamalar
#define StartDelay(ms)	TimingDelay=ms
#define WaitDelay()	while(TimingDelay)
#define isTimeOver() (TimingDelay==0)

// tus bassilana dek bekler
#define WaitKey()	while(!key.Valid)

// islev prototipleri
char GetKey(void);					// basilmis tus kodunu geri d�nd�r�r
char GetKeyR(void);         		// tus basilana dek bekle ve tusu oku
char GetKeyTime(uint32_t ms);		// zamanasimi veya tus basilana dek bekler


#endif /*_KEYBOARD_H_*/
