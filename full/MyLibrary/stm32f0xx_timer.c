// stm32F0xx için sayıcı işlevleri
// ------------------------------------------------------------------------
// sayıcı makroları

// sayıcı önbölücü oku/değiştir
#define timer_prescale_get(timer)		timer->PSC
#define timer_prescale_set(timer,value)	timer->PSC=value

// sayıcı peryodu oku/değiştir
#define timer_period_get(timer)			timer->ARR
#define timer_period_set(timer,value)	timer->ARR=value

// sayıcı değeri oku/değiştir
#define timer_get(timer)		timer->CNT
#define timer_set(timer,value) 	timer->CNT=value

// sayıcı tekrar oku/değiştir
#define timer_repeat_get(timer)			timer->RCR
#define timer_repeat_set(timer,value)	timer->RCR=value

// sayıcıyı başlat/durdur
#define timer_start(timer)	bit_set(timer->CR1,TIM_CR1_CEN_Pos)
#define timer_stop(timer)	bit_clear(timer->CR1,TIM_CR1_CEN_Pos)

// sayıcı çalışma modları


// sayıcı olay ayarlamaları
#define UPDATE		UG		// yazılımla güncelle
#define TRIGGER		TG		// tetikleme (TIF değişir)
#define timer_force_update(timer)	timer->EGR=TIM_EGR_UG
#define timer_force_trigger(timer)	timer->EGR=TIM_EGR_TG

// sayıcı modülleri
// capture/compare modülü izin oku/değiştir
#define PWM1_DISABLE	0x0000
#define PWM1_NORMAL		0x0001
#define PWM1_INVERT		0x0003
#define PWM2_DISABLE	0x0000
#define PWM2_NORMAL		0x0010
#define PWM2_INVERT		0x0030
#define PWM3_DISABLE	0x0000
#define PWM3_NORMAL		0x0100
#define PWM3_INVERT		0x0300
#define PWM4_DISABLE	0x0000
#define PWM4_NORMAL		0x1000
#define PWM4_INVERT		0x3000

#define timer_pwm_enable_set(timer,value)	timer->CCER=value		

// capture/compare değerini oku/değiştir
#define PWM1		CCR1
#define PWM2		CCR2
#define PWM3		CCR3
#define PWM4		CCR4
#define CAPTURE1	CCR1
#define CAPTURE2	CCR2
#define CAPTURE3	CCR3
#define CAPTURE4	CCR4
#define timer_pwm_get(timer,reg)				timer->reg
#define timer_pwm_set(timer,reg,value)			timer->reg=value
#define timer_capture1_get(timer,reg)			timer->reg
#define timer_capture1_set(timer,reg,value)		timer->reg=value

// PWM çıkışını aktif yapma
#define timer_output_main(timer,val)		bit_copy(timer->BDTR,TIM_BDTR_MOE_Pos,val)
#define timer_output_auto(timer,val)	bit_copy(timer->BDTR,TIM_BDTR_AOE_Pos,val)
#define timer_output_break(timer,val)		bit_copy(timer->BDTR,TIM_BDTR_BKE_Pos,val)



