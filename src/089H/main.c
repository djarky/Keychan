#include<stdio.h>
#include<gb/gb.h>
#include<gb/drawing.h>
#include<time.h>
#include<stdlib.h>
#include<rand.h>

/*#include<gb/sample.h>*/
#include"sample/samptest.c"

#include"mylibs/sound.c"
#include"mylibs/sprite_rotate.c"
#include"mylibs/colider.c"



#include"assets/sprites.h"
#include"assets/font.h"

#include"player_control.h"
#include"npc_control.h"



extern const unsigned char arky750[];
extern const unsigned char keychan_title[];
extern const unsigned char keychan_title_tilemap[];
extern const unsigned char music_notes[];

unsigned char i=0;
unsigned char k=0;

unsigned char x=0;
unsigned char y=0;


unsigned char temp_ram[360];
unsigned char temp_ram2[360];

unsigned char joy_pad=0x00;



//this contain maps fuctions for bank 4
#include"level.h"


//doors libs
#include"mylibs/rand_pos.c"
#include"mylibs/doors.c"
#include"mylibs/doors_manager.h"
#include"assets/doors_rotated.h"

#include"mylibs/fade.c"
#include"mylibs/door_teleport.c"



//batery load save 
#include"BaterySaveFun.c"

//splat screens
#include"historia.c"
#include"splat_screen.c"

/*
this is like mario galaxy or similar
player rotacion was determinate by head orientacion ie 
player_rot=J_UP -> floor on down , move left and right , normal
player_rot=J_DOWN -> floor on up , gravity on up
player_rot=J_LEFT ->floor on right etc , move up and down , gravity sideways etc
*/






void musical_mice(void);


void shoter_game(void);




#include"game.c"



void main(void) {
DISPLAY_OFF;

printf("DEMO-089C fix");
delay(3000);
load_picture_s(arky750,5);
delay(2000);

DISPLAY_OFF;
SWITCH_ROM_MBC5(10);
shoter_game();
SWITCH_ROM_MBC5(12);
historia();

waitpadup();
splat_screen();





//new game menu
waitpadup();
set_sprite_tile(0,0x03);
move_sprite(0,80,136);
SHOW_SPRITES;
print_text("CONTINUE          NEW GAME");
while(1){
if(joypad()==J_UP)    {k--; scroll_sprite(0,0,-8);waitpadup();}
if(joypad()==J_DOWN)  {k++; scroll_sprite(0,0, 8);waitpadup();}
if(k>0x01){k=0;move_sprite(0,80,136);}
if(joypad()==J_A || joypad()==J_START){set_sprite_tile(0,0x0A);waitpadup();break;}
}
move_sprite(0,178,178);
HIDE_SPRITES;
if(k==0x01){DEL_BATERY();}
move_win(0,0);SHOW_WIN;
SWITCH_ROM_MBC5(5);
set_bkg_data(0x1A,6,bars_tiles);

LOAD_BATERY();
HIDE_WIN;
game_setup();



while(1){


switch(current_map){

case 1:game_loop(map1);break;
case 2:game_loop(map2);break;
case 3:game_loop(map3);break;
case 4:game_loop(map4);break;
case 5:game_loop(map5);break;
case 6:game_loop(map6);break;
case 7:game_loop(map7);break;
case 8:game_loop(map8);break;
case 9:game_loop(map9);break;

}

if(player_hp==0){break;}

}


HIDE_SPRITES;HIDE_WIN;
load_picture(keychan_title,5);
print_text("THANKS FOR PLAYING THIS DEMO");
play_arigato();
print_text("FULL GAME AVALIBLE ON SEPEMBER");
print_text("ON GB COMPO JAM 23 ITCH IO");
print_text("ARIGATO");
reset();
}