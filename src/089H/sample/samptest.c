#include <gb/gb.h>
#include <stdio.h>

#include "sample_player.h"

#include "samples_bank2.h"



void play_arigato(void)
{

		disable_interrupts() ;

    NR52_REG = 0x80u;
    NR51_REG = 0xffu;
    NR50_REG = 0x77u;

    __critical {
        TMA_REG = 0xC0u, TAC_REG = 0x07u;
        add_TIM(play_isr);    
        set_interrupts(VBL_IFLAG | TIM_IFLAG);
    }

 		enable_interrupts() ;
		play_sample1();
    
}
