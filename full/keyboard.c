//-----------------------------------------------------------------------------
// button giris islevleri
// buton parametreleri
#include "keyboard.h"

// kesmede butonlari okuma, 
// portu giris olarak kosullar, butonlari okur, portu tekrar çikisyapar
void _ProcessKeys(void)
{
	static int tm=0;					// statik degisken 10ms zamanlama
	if(++tm<10)							// 10ms zaman geçmemisse
		return;							// islevi bitir
	tm=0;								// süreyi sifirla

	uint8_t data;						// tus verisi
	static int repeatCtr;   			// tus tekrar sayaci
	GPIOB->MODER &= 0X0000FFFF;			// B8-B15 giris yap
	GPIOB->PUPDR |= 0x55550000;			// B8-B15 pullup dirençlerini aktif yap
	delay_us(1);						// giris için bekle
	data = (GPIOB->IDR)>>8;				// buton girislerini oku
	GPIOB->PUPDR &= 0x0000FFFF; 		// B8-B15 pullup dirençlerini pasif yap
	GPIOB->MODER |= 0x55550000;			// B8-B15 çikis yap
	data = (~data) & 0x7F;				// bitleri evir ve maskele
// --- butonlari isleme ----
	if(data!=0){						// tusa basildi
		if ((key.Valid || key.Press)==0){
			if(key.Code == data){
				key.Press = 1;
				key.Valid = 1;			// tusu kabul et
			} else {
				key.Code = data;		// tus degistir
				key.Press = 0;
			}
		}
		if(--repeatCtr==0){				// azalt ve süre bitiminde
			repeatCtr=tmKeyRepeat;		// tus tekrar hizini yükle
			key.Valid = 1;          	// tusu tekrarla
		}
	} else {                        	// tus basili degil
		key.Press = 0;              	// tus birakildi
		repeatCtr=tmKeyRepeatFirst;		// ilk tus tekrar süresini yükle
	}
}

char GetKey(void)						// basilmis tus kodunu geri döndürür
{
	char temp=0;						// geçici degisken
	if(key.Valid){						// tus varsa
		temp = key.Code;				// kodunu al
		key.Valid=0;					// tus okundu
	}
	return temp;						// tus kodunu geri döndür
}

char GetKeyR(void)          			// tus basilana dek bekle ve tusu oku
{   
	WaitKey();              			// tusa basilana dek
    return GetKey();        			// tusu al ve geri dön
}

char GetKeyTime(uint32_t ms)			// zamanasimi veya tus basilana dek bekler
{
	ms += get_timetick();				// süreyi ayarla
	do{ if(key.Valid) break;			// tusa basilmissa döngüyü bitir
	}while(get_timetick()<ms);
    return GetKey();					// tusu oku ve geri dön
}


/*
char GetKeyTime(void)
{
	return GetKeyTime(30000);
}
*/


