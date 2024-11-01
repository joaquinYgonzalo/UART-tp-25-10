//este codigo depende de librerias externas

#include "I2C.h"
#include "MKL25Z4.h"
#include "LCD.h"
#define LCD_I2C_ADDRESS 0x27
int i, j;
int lcd[2][16];
int D[8]={0,1,2,3,4,5,6,7};
uint8_t data
void LCD_init(){
    SIM->SCGC5|=SIM_SCGC5_PORTD_MASK;
    I2C0_Init();
    for( i=0;i<8;i++){
        PORTD->PCR[D[i]] |=(1<<8); 
        PTD->PDDR|=(1<<D[i]);
    }
}
void LCD_sendByte(uint8_t byte){
    I2C_WriteByte();
    printf("");
    scanf("%c\n", &lcd[i][j]); 
}
void LCD_sendCmd(uint8_t command){
    I2C_WriteRegister();
}
void LCD_clear(){
    I2C_Stop();
    for( i=0;i<8;i++){
        PTD->PCOR|=(1<<D[i]);
    } 
}
void LCD_scrollDisplayLeft(){
    for(i=0; i<2;i++){
        for(j=0; j<16;j++){
            if (lcd[i][j]== 0x0 ){
                if(j!=0){
                    j--;
                }
            }
        }
    }
}
void LCD_scrollDisplayRight(){
    for(i=0; i<2;i++){
        for(j=0; j<16;j++){
            if (lcd[i][j]== 0x0 ){
                if(j!=15){
                    j++;
                }
            }
        }
    }
}
void LCD_print(){
    I2C_WriteRegister();
    for(i=0; i<2;i++){
        for(j=0; j<16;j++){
            if(( lcd[i][j])==0x0){
                if(i== 0x40){
                    i=1;
                    for( int z=0;z<8;z++){
                        PTD->PCOR|=(1<<D[z]);
                    }
                }else{
                    i=0;
                    for( int z=0;z<8;z++){
                        PTD->PCOR|=(1<<D[z]);
                    }
                }
            }
            scanf("%c\n", &lcd[i][j]); 
        }
    }
}

void LCD_setCursor(int row, int col){
    uint8_t addr;
    if(row==0){
        addr=0X00 + col;
    }else{
        addr=0X80 + col;
    }
}
void LCD_createChar(uint8_t nByte, uint8_t nuevoCaracter[]){
    if(nByte>7){return I2C1->D;};
    LCD_sendCmd(0x40 |(nByte<<3));
    for(i=0; i<8;i++){
        for (int i = 0; i < 8; i++) {
            LCD_sendByte(nuevoCaracter[i]);  
        }
    }
}