#include<avr/io.h>
#include<avr/interrupt.h>

// Pulse Width Modulation (PWM) tren chan OC1A va OC1B 

int main(){
	DDRB |= 0xFF;
	PORTB = 0x00;
	
	// Fast PWM: mode 14, Clear OC1A/OC1B on Compare Match, set OC1A/OC1B at Top
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10); // CS10 = 1: no prescaler -> T = 1us

	OCR1A = 1000; // Duty cycle = 1000us = 1ms
	OCR1B = 5000; // Duty cycle = 1500us = 1.5ms

	ICR1 = 20000; // Time period = 20ms -> Top = 20ms

	sei(); // set bit I cho phep ngat toan cuc

	while(1){
		//
	}	
}

ISR(INT0_vect){
	
}

ISR(INT1_vect){

}
