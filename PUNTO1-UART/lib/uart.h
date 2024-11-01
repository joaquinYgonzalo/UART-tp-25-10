#ifndef "uart_h"
#define "uart_h"
char UART0_SEND(char dato);
void UART_SendString(const char* str);
void UART0_INIT(uint32_t baud_rate);
char HC05_RECIBE(void);
void UART_ReceiveString(char* palabra, uint16_t tMax);

#endif
