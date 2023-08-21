#include <stdio.h>



unsigned char temp_index_i=0;
unsigned char temp_index_j=0;

unsigned char temp_index_row=0;
unsigned char temp_index_col=0;

unsigned char spriteIndex = 0;


unsigned char temp_lowByte = 0;
unsigned char temp_highByte = 0;

unsigned char temp_pixelColor = 0;


unsigned char *temp_pointer;

unsigned char temp_matriz[64];










void rotate_sprite(unsigned char sprite_tile[]){





    spriteIndex=0;
    for (temp_index_row = 0; temp_index_row < 8; temp_index_row++) {
        for (temp_index_col = 0; temp_index_col < 8; temp_index_col++) {
            temp_lowByte =  sprite_tile[spriteIndex];
            temp_highByte = sprite_tile[spriteIndex + 1];
            temp_pixelColor = 0;
            temp_pixelColor |=  (temp_highByte >> (7 - temp_index_col)) & 0x01 ;
            temp_pixelColor <<= 1;
            temp_pixelColor |=  (temp_lowByte >> (7 - temp_index_col)) & 0x01 ;
            temp_matriz[temp_index_row + (7- temp_index_col)*8 ] = temp_pixelColor;
        }
        spriteIndex += 2;
    }



  //  set_bkg_tiles(2,2,8,8,&temp_matriz[0]);

    spriteIndex = 0;
    for (temp_index_row = 0; temp_index_row < 8; temp_index_row++) {
        for (temp_index_col = 0; temp_index_col < 8; temp_index_col += 8) {
            temp_lowByte = 0;
            temp_highByte = 0;

            for (temp_index_i = 0; temp_index_i < 8; temp_index_i++) {
                temp_lowByte |= ((temp_matriz[temp_index_row*8 + temp_index_col + temp_index_i] & 0x01) << (7 - temp_index_i));
                temp_highByte |= (((temp_matriz[temp_index_row*8 + temp_index_col + temp_index_i] >> 1) & 0x01) << (7 - temp_index_i));
            }

            sprite_tile[spriteIndex] = temp_lowByte;
            sprite_tile[spriteIndex+1] = temp_highByte;
            spriteIndex += 2;
        }
    }


}

    