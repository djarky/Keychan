#include <gb/gb.h>
#include "gbt_player.h"

#include "mylibs/load_pic.c"

extern const unsigned char *dead_Data[];
extern const unsigned char *anime_Data[];
extern const unsigned char *inicio_Data[];
extern const unsigned char *doll_Data[];

unsigned char nero1[6];
unsigned char nero2[6];
unsigned char nero3[6];
unsigned char nero4[6];

void ddr_play(UBYTE nero[]){

	UBYTE ii=0;
	UBYTE joy= joypad();

	for(ii=0;ii<6;ii++){
		
		if ( joy & J_LEFT   && nero[ii]==1){nero[ii]= 8;} 
		if ( joy & J_UP     && nero[ii]==2){nero[ii]= 9;}
		if ( joy & J_RIGHT  && nero[ii]==3){nero[ii]=10;}
		if ( joy & J_DOWN   && nero[ii]==4){nero[ii]=11;}
		if ( joy & J_B      && nero[ii]==5){nero[ii]=12;}
		if ( joy & J_A      && nero[ii]==6){nero[ii]=13;}
		if ( joy & J_SELECT && nero[ii]==7){nero[ii]=14;}

		
	}





}


void anime_s(void) {
    nero1[2] = NR12_REG >> 5;
    nero2[2] = NR22_REG >> 5;
    nero3[2] = NR32_REG >> 5;

    nero4[2] = NR42_REG >> 5;
    nero4[3] = NR43_REG >> 5;

    if (nero4[3]) {
        nero1[3] = NR12_REG >> 5;
        nero2[3] = NR22_REG >> 5;
        nero3[3] = NR32_REG >> 5;
    } else {
        nero1[3] = 0;
        nero2[3] = 0;
        nero3[3] = 0;
    }

    ddr_play(nero1);
    ddr_play(nero2);
    ddr_play(nero3);
    ddr_play(nero4);

    set_bkg_tiles(2, 8, 1, 6, nero1);
    set_bkg_tiles(4, 8, 1, 6, nero2);
    set_bkg_tiles(14, 8, 1, 6, nero3);
    set_bkg_tiles(16, 8, 1, 6, nero4);
}

void splat_screen(void) {
    load_picture_s(keychan_title, 5);
    set_bkg_data(0, 16, music_notes);
    set_sprite_data(0, 16, music_notes);
    SHOW_BKG;

    disable_interrupts();

    switch (rand() % 4) {
        case 0: gbt_play(dead_Data, 7, 14); break;
        case 1: gbt_play(anime_Data, 7, 14); break;
        case 2: gbt_play(inicio_Data, 7, 7); break;
        case 3: gbt_play(doll_Data, 7, 16); break;
        default: gbt_play(anime_Data, 7, 14); break;
    }

    gbt_loop(1);

    set_interrupts(VBL_IFLAG);
    enable_interrupts();

    while (1) {
        wait_vbl_done();
        anime_s();
        i = rand();
        gbt_update(); // This will change to ROM bank 1.
        if (joypad() == J_START) {
            break;
        }
    }
    gbt_loop(0);
    gbt_stop();
}
