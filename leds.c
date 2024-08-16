#include "leds.h"
#include "MKL25Z4.h"

void secuencia(){
    PTB -> PDDR |=(1<<18);
    PTB -> PDDR |=(1<<19);
    PTD -> PDDR |=(1<<1);
}