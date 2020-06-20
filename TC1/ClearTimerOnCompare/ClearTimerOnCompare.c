#include<avr/io.h>
#include<avr/interrupt.h>

// Clear Timer On Compare Match: Counter se xoa ve 0 khi Counter = OCR1A
// OCR1A chua gia tri TOP (gia tri so sanh do nguoi dung dat)

volatile unsigned char val = 0; // bien volatile duoc dung trong ca chuong trinh chinh va trong cac
//trinh phuc vu ngat

int main(){
	DDRB |= 0xFF;
	PORTB = 0x00;
	
	// mode 4
	TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS11); // Set Timer/Counter Control Register 
// mode 4 (CTC), xung nhip tu chan T1 (canh xuong)
	OCR1A = 4; // Output Compare Register gia tri can so sanh

	// mode 12
	//TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS12) | (1 << CS11);
	//ICR1 = 4;
	

	TIMSK = (1 << OCIE1A); // Timer/Counter Interrupt Mask Register cho phep ngat khi dem = 4
	sei(); // set bit I cho phep ngat toan cuc
	
	while(1){
		//PORTB = 0x00;
	}	

	return 0;
}

// Trinh phuc vu ngat compare match
ISR(TIMER1_COMPA_vect){
	val += 1;
	if(val == 10)
		val = 0;
	PORTB = val;
}
