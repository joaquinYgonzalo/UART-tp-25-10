#include "MKL25Z4.h"
#include "uart.h"
char data;

void UART0_Init(uint32_t baud_rate) {
	uint32_t divisor;

	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
    SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;
    PORTA->PCR[1]=PORT_PCR_MUX(2);
    PORTA->PCR[2]=PORT_PCR_MUX(2);

	UART0->C2 &= ~(UART_C2_TE_MASK | UART_C2_RE_MASK);

	divisor = (SystemCoreClock / (16 * baud_rate)); 
	UART0->BDH = (divisor >> 8) & UART_BDH_SBR_MASK;
	UART0->BDL = divisor & UART_BDL_SBR_MASK;

	UART0->C1 = 0x00;

	UART0->C2 |= (UART_C2_TE_MASK | UART_C2_RE_MASK);
}

void UART0_Send(char data) {
	while (!(UART0->S1 & UART_S1_TDRE_MASK));
	UART0->D = data;   
}

char UART0_Receive(void) {
	while (!(UART0->S1 & UART_S1_RDRF_MASK));
	return UART0->D;  
}

void UART_SendString(const char* str) {
    while (*str) {
        while (!(UART0->S1 & UART_S1_TDRE_MASK));
        UART0->D = *str++;
    }
}
void UART_ReceiveString(char* palabra, uint16_t tMax) {
    int i = 0;
    
    while (i < (maxLength - 1)) {  
        while (!(UART0->S1 & UART_S1_RDRF_MASK));
        
        char c = UART0->D;
        
        if (c == '\n' || c == '\r') {
            break;
        }
        
        palabra[i++] = c;
    }
    
    palabra[i] = '\0';
}
