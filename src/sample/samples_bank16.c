#pragma bank 16

#include <gb/gb.h>

#include "sample_player.h"



#include "wav/keychan.c"


void play_sample2() __banked {
  set_sample(_current_bank, keychan_gbw, sizeof(keychan_gbw)); 
}