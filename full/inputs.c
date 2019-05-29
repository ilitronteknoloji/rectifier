// Sayisal girisler ile ilgili islevler

// in1,in2,in3 :  PC15,PC14,PC13 sayisal girisleri

// birsey kosullama yapmak gerekmez
#define initDigitalInputs()

// n=1,2,3 ile in1 (PC15), in2 (PC14), in3 (PC13) girislerini okur
#define getInput(n) bit_test(port_read(GPIOC),16-(n))

#define isStop()	(getInput(1)==0)	// AcilDur aktif
#define isRemote()	(getInput(2)==1)	// Remote aktif 
#define isFilter()	(getInput(3)==0)	// Filtre aktif tikanma durumu

// ---- analog girisler ----
// PA0: +24V besleme
// PA1: Ua	Gerilim �l�me
// PA2: Ub	Gerilim �l�me
// PA3: Uc	Gerilim �l�me
// PA4: a	Akim �l�me
// PA5: b	Akim �l�me
// PA6: A	Akim �l�me
// PA7: B	Akim �l�me
// PB0: Basin� 4-20mA
// PB1: Sicaklik PT100/1000

// analog girisleri kosullar
void initAnalogInputs(void)
{
	for(int i=0; i<8; i++){		// PA0-PA7
		pin_mode(GPIOA,i,ANALOG);
	}	
	pin_mode(GPIOB,0,ANALOG);	// PB0
	pin_mode(GPIOB,1,ANALOG);	// PB1
}

// istenen analog girisi oku
unsigned int getAnalog(int channel)
{
	return 0;
}


