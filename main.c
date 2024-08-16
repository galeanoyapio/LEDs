#include "MKL25Z4.h"

int main(){
    SIM->SCGC5|=SIM_SCGC5_PORTB_MASK|SIM_SCGC5_PORTD_MASK;
    
    PORTB->PCR[18]|=(1<<8); //Pin como GPIO
    PORTB->PCR[19]|=(1<<8);
    PORTD->PCR[1]|=(1<<8);
    
    PTB->PDDR|=(1<<18); //GPIO como OUTPUT
    PTB->PDDR|=(1<<19);
    PTD->PDDR|=(1<<1);

    while(1){
        PTB->PSOR|=(1<<18); //
        PTB->PSOR&=~(1<<18);
        for(int t=70000000;t<0;t--);
        PTB->PSOR|=(1<<19);
        PTB->PSOR&=~(1<<19);
        for(int t=70000000;t<0;t--);
        PTD->PSOR|=(1<<1);
        PTD->PSOR&=~(1<<1);
        for(int t=70000000;t<0;t--);
    }
}