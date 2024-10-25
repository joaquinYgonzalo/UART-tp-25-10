#ifndef "UART_h"
#define "UART_h"
void HC05_INIT();
void UART0_INIT();
char UART0_SEND(char dato);
char UART0_RECIBE();
char HC05_SEND(char dato);
char HC05_RECIBE();
#endif