#include<avr/io.h>
#include<avr/interrupt.h>

//Dinh thoi 1ms voi Timer/Counter 0
//Tan so hoat dong cua MCU la: 1MHz

int main(){
	DDRB |= 0xFF;
	PORTB = 0x00;
	
	//Chon tan so clk/8 (prescaler = 8) -> T = 8us -> max t = 8us * 256 = 2048us > 1ms
	TCCR0 = (1 << CS01);
	//Dinh thoi 1ms = 1000us -> bo dem can dem 125 lan de het 1ms -> gia tri khoi dau la: 256 - 125 = 131
	TCNT0 = 131;
	//Cho phep ngat khi co co tran o T/C0
	TIMSK = (1 << TOIE0);  
	sei(); //set bit I cho phep ngat toan cuc

	while(1){
		
	}

	return 0;
}

//Trinh phuc vu ngat tran T/C0
ISR (TIMER0_OVF_vect){
	TCNT0 = 131;
	PORTB ^= 1;
}
