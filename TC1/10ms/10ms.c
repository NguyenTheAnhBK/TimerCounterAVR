#include<avr/io.h>
#include<avr/interrupt.h>

// Dinh thoi 10ms voi T/C1
// Tan so hoat dong cua MCU la 1MHz
// T/C1 co do phan giai 16 bits va co kha nang tao xung dieu rong PWM (Pulse Width Modulation)

int main(){
	DDRB |= 0xFF;
	PORTB = 0x00;

	// Prescaler = 1 -> T = 1us -> max t = 1us * 65536 = 65.536ms > 10ms
	TCCR1B = (1 << CS10); //  su dung Timer Counter Control Register 1B 
	
	// De tao 10ms -> dem 10000 lan -> gia tri khoi dau la: 65535 - 10000 = 55535
	TCNT1 = 55535;
	// Timer/Counter Interrupt Mask Register cho phep ngat co tran o T/C1
	TIMSK = (1 << TOIE1);
	sei(); // set bit I cho phep ngat toan cuc

	while(1){

	}

	return 0;
}

// Trinh phuc vu ngat tran T/C1
ISR(TIMER1_OVF_vect){
	TCNT1 = 55535;
	PORTB ^= 1;
}

