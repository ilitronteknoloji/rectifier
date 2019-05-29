#include "keyboard.h"					// tuslarla ilgili islevler


extern void delay_ms(uint32_t nTime);


void testRelay(void)
{
	relay_alloff();
	forever{
		for(int i=0; i<MAX_RELAY; i++){
			printf("\vRole-%d", i);     // ekranda g�ster
			relay_set(i,ON);            // r�leyi ON yap
			delay_ms(1000);				// 0.5 saniye bekle
			relay_set(i,OFF);           // r�leyi OFF yap
			if(key.Valid) break;		// tusa basilinca �ik
		}
		if(GetKey()) break;				// tusa basilinca �ik
	}
}


// ---- tus panelini test eder ascii kodunu ekranda g�sterir ----
void testKeypad(void)
{ char ch,prev;
	lcd_clear();					// ekrani sildir
    for(int i=0; i<5; i++){		// 5 kez ayni tus olunca �ik
        lcd_puts("\vKeypad test\nKey: ");
        ch = GetKeyTime(30000);		// tus veya zamanasimi bekle
        if(ch==0) break;        	// zamanasimi olmussa �ik
        if(prev!=ch) i=0;   		// farkli tus ise saya� sifirla
        prev=ch;                	// mevcut tusu sakla
        if(ch==kbInc) ch=0x1E;
        if(ch==kbDec) ch=0x1F;
        if(ch==kbEnt) ch=0x10;
        if(ch==kbClr) ch='C';
        if(ch==kbS)   ch='S';
        if(ch==kbOn)  ch=0x07;
        if(ch==kbOff) ch=0x09;
        printf("%02X %c",prev,ch);  // tusu g�ster
    }
}

//---- LCD ekranda t�m karakterleri g�sterir ----
void testDisplay(void)
{ char base=0,ch,line,x;
	lcd_clear();
	forever{
        line=4;                         // 4 satir yazdirilacak
        do{ x=16;                       // her satira 16 karakter
            do{ if(base==0) lcd_putc(' ');
				else lcd_data(base);	// yazdiriliyor
				base++;					// sonraki karakter
			}while(--x);
            lcd_putc('\n');				// bitince satir atlat
        }while(--line);					// 4 satir yazdirilinca
        ch = GetKeyTime(30000);			// tus veya zamanasimi bekle
		if(ch==kbInc) base -= 0x80;		// �nceki sayfa
		else if(ch!=kbDec) break;		// sonraki sayfa degilse �ik
    }
}

