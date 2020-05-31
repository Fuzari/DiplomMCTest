#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

void USART_Init( unsigned int baud );
void portsInit(void);
void turnOffMethod(void);

void turnOnMethod1(void);
void inUpravl1Choose(void);
void inUpravl1Save(void);

void turnOnMethod2(void);
void setSig0(void);
void setSig1(void);
void setSig2(void);

void turnOnMethod3(void);
void setSigs3_4(void);
void offSigs3_4(void);

void turnOnMethod4(void);
void inUpravl4Choose(void);
void inUpravl4Save(void);
void setSigs5_6In2(void);
void setSig5In1(void);
void changeSigs5_6States(void);
void setSigs5_6In1(void);

void turnOnMethod5(void);

int main(void)
{	
	portsInit();
    USART_Init(51); 
	unsigned char a = '/';
    while (1) 
    {
		if (UCSR2A & (1<<RXC2)) {
			while(!(UCSR2A & (1<<UDRE2)))	
			{}
			a = UDR2;
			if (a == 'A') {
				turnOnMethod1();
			}
			if (a == 'B') {
				turnOffMethod();
			}
			if (a == 'C') {
				inUpravl1Choose();
			}
			if (a == 'D') {
				inUpravl1Save();
			}
			//////////////////////////
			if (a == 'E') {
				turnOnMethod2();
				setSig0();
			}
			if (a == 'F') {
				turnOffMethod();
			}
			if (a == 'G') {
				setSig1();
			}
			if (a == 'H') {
				setSig2();
			}
			//////////////////////////
			if (a == 'I') {
				turnOnMethod3();
			}
			if (a == 'J') {
				turnOffMethod();
			}
			if (a == 'K') {
				setSigs3_4();
			}
			if (a == 'L') {
				offSigs3_4();
			}
			//////////////////////////
			if (a == 'M') {
				turnOnMethod4();
			}
			if (a == 'O') {
				inUpravl4Choose();
			}
			if (a == 'P') {
				inUpravl4Save();
			}
			if (a == 'Q') {
				setSigs5_6In2();
			}
			if (a == 'R') {
				setSig5In1();
			}
			if (a == 'S') {
				changeSigs5_6States();
			}
			if (a == 'T') {
				setSigs5_6In1();
			}
			//////////////////////////
			if (a == 'U') {
				turnOnMethod5();
			}
			//while ( UCSR2A & (1<<UDRE2) ) {	
			//UDR2 = 'B';
			//}
		}
    }
}

void USART_Init( unsigned int baud )
{
	UBRR2 = 0;
	/* Set MSPI mode of operation and SPI data mode 0. */
	//UCSR2C = (1<<UMSEL21)|(1<<UMSEL20)|(0<<UCPOL2);
	UCSR2C = (1<<UCSZ21)|(1<<UCSZ20); //8 бит посылка 1 стоп бит
	/* Enable receiver and transmitter. */
	UCSR2B = (1<<RXEN2)|(1<<TXEN2);
	/* Set baud rate. */
	/* IMPORTANT: The Baud Rate must be set after the transmitter is
	enabled */
	UBRR2 = baud;
}

void portsInit(void) {
	DDRA = 0xFF;
	PORTA = 0x00;
	
	DDRB = 0xFF;
	PORTB = 0x00;
	
	DDRC = 0xFF;
	PORTC = 0x00;
	
	DDRD = 0xFF;
	PORTD = 0x00;
	
	DDRE = 0xFF;
	PORTE = 0x00;
}

void turnOffMethod(void) {
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
}

// Функции метода 1
void turnOnMethod1(void) {
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	
	PORTB = 0b00000001;
}

void inUpravl1Choose(void) {
	PORTE = 0b00000001;
}

void inUpravl1Save(void) {
	PORTE = 0b00000000;
}

// Функции метода 2
void turnOnMethod2(void) {
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	
	PORTB = 0b00100000;
}

void setSig0(void) {
	PORTA = 0b00000001;
}

void setSig1(void) {
	PORTA = 0b00000010;
}

void setSig2(void) {
	PORTA = 0b00000100;
}

// Функции метода 3
void turnOnMethod3(void) {
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	
	PORTB = 0b01000000;
}

void setSigs3_4(void) {
	PORTA = 0b00011000;
}

void offSigs3_4(void) {
	PORTA = 0b00000000;
}

// Функции метода 4
void turnOnMethod4(void) {
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	
	PORTB = 0b10000000;
}

void inUpravl4Choose(void) {
	PORTE = 0b00000010;
}

void inUpravl4Save(void) {
	PORTE = 0b00000000;
}

void setSigs5_6In2(void) {
	PORTA = 0b01100000;
}

void setSig5In1(void) {
	PORTA = 0b01000000;
}

void changeSigs5_6States(void) {
	PORTA = 0b00100000;
	
}

void setSigs5_6In1(void) {
	PORTA = 0b00000000;
}

// Функции метода 5
void turnOnMethod5(void) {
	PORTA = 0x00;
	PORTB = 0x00;
	PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	
	PORTB = 0b00010000;
}
