#pragma bank 15

#include <gb/gb.h>

#include "sample_player.h"


#include "wav/arigato.c"


void play_sample1() __banked {
  set_sample(_current_bank, arigato_gbw, sizeof(arigato_gbw)); 
}

