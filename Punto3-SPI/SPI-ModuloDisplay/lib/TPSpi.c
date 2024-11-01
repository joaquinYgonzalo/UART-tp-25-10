#include "MKL25Z4.h"
#include "SPI.h"
#include "TPSPI.h"
int contador [8]={17,16, 13, 12, 6, 5, 4, 3 };
int display[10][7]={
//   a  b  c  d  e  f  g
    {1, 1, 1, 1, 1, 1, 0},//0
    {0, 1, 1, 0, 0, 0, 0},//1
    {1, 1, 0, 1, 1, 0, 1},//2
    {1, 1, 1, 1, 0, 0, 1},//3
    {0, 1, 1, 0, 0, 1, 1},//4
    {1, 0, 1, 1, 0, 1, 1},//5
    {1, 0, 1, 1, 1, 1, 1},//6
    {1, 1, 1, 0, 0, 0, 0},//7
    {1, 1, 1, 1, 1, 1, 1},//8
    {1, 1, 1, 1, 0, 1, 1}//9
};
int i, j;
void display_Init(void){
    SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;
     for(i=0;i<7;i++){
        for(j=0;j<10;j++){
            PORTC->PCR[contador[i]]|=(1<<8);
            PTC->PDDR|=(1<<contador[i]);
        }
     }
    SPI_Init();
}
void display_Send(uint8_t data){
    for(i=0;i<7;i++){
        SPI_Send(contador[i]);
    }
}
uint8_t display_Receive(void){
    SPI_Receive();

}
