//este codigo depende de librerias externas

#include "MKL25Z4.h"
#include "tp_UART.h"
#include "uart.h"
#define HC05Test "AT"
#define HC05Reset "AT+RESET\r\n"
#define HC05Version "AT+VERSION?"
#define HC05Default "AT+ORGL"
#define HC05SetMode "AT+ROLE=<Param>"
#define HC05CheckMode "AT+ROLE?"
#define HC05SetPinOutput "AT+PIO=<Param1>,<Param2>""
void HC05_INIT(){
    UART0_INIT();
}
char HC05_SEND(char dato){
    UART_SendString(HC05Test);
    
}
char HC05_RECIBE(){
    UART_ReceiveString();
}
