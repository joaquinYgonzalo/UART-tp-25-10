#include "MKL25Z4.h"
#include "UART.h"

char dato;
void HC05_INIT(){
SIM->SCGC4|=SIM_SCGC4_UART0_MASK;//habilitacion del modulo 
SIM->SCGC5|=SIM_SCGC5_PORTA_MASK;//habilitacion de los puertos
PORTA->PCR[1]=PORT_PCR_MUX(2);//pines del puerto
PORTA->PCR[2]=PORT_PCR_MUX(2);//pines del puerto
UART0->C2=0;
UART0->BDH=A0;//9600 BAUDIOS //parte alta
UART0->BDL=26;//9600 BAUDIOS //parte baja
UART0->AT+RESET\r\n;
UART0->AT+ADDR?\r\n;
UART0->AT+ ROLE?;
if()
HC05->C1=0x00; //deshabilitacion
UART0->0x0C;//habilitacion
}
char HC05_SEND(char dato){
while(!(UART0->S1&UART_S1_TDRE_MASK));
    UART0->D=dato;
}
char HC05_RECIBE(){
    while(!(UART0->S1&UART_S1_TDRE_MASK));
    return UART0->D;
}