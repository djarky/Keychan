#ifndef _MAP_MANAGER_C
#define _MAP_MANAGER_C


#define MAP_WIDTH 10
#define MAP_HEIGHT 9
#define playerRow 1



extern unsigned char player_rot;
extern unsigned char player_hp;
extern unsigned char current_map;


#include"musical_map.c"

void scroll_all_sprites(BYTE x_des,BYTE y_des){
for(k=0;k<24;k++){scroll_sprite(k,x_des,y_des);}
musical_map();
}


void load_map_down(UBYTE mapa[]){

get_bkg_tiles(0,0,20,18,temp_ram);
set_win_tiles(0,0,20,18,temp_ram);
move_win(7,0);
SHOW_WIN;

draw_map(mapa);
get_bkg_tiles(0,0,20,18,temp_ram2);
set_bkg_tiles(0,0,20,18,temp_ram);
HIDE_WIN;
set_win_tiles(0,0,20,18,temp_ram2);
move_win(7,144);
SHOW_WIN;
for(i=0;i<144;i++){scroll_win(0,-1);scroll_bkg(0,1);scroll_all_sprites(0,-1);delay(10);wait_vbl_done();}
set_bkg_tiles(0,0,20,18,temp_ram2);
move_bkg(0,0);
HIDE_WIN;

}


void load_map_right(UBYTE mapa[]){

get_bkg_tiles(0,0,20,18,temp_ram);
set_win_tiles(0,0,20,18,temp_ram);
move_win(7,0);
SHOW_WIN;

draw_map(mapa);
get_bkg_tiles(0,0,20,18,temp_ram2);
set_bkg_tiles(0,0,20,18,temp_ram);
HIDE_WIN;
set_win_tiles(0,0,20,18,temp_ram2);
move_win(167,0);
SHOW_WIN;
for(i=0;i<160;i++){scroll_win(-1,0);scroll_bkg(1,0);scroll_all_sprites(-1,0);delay(10);wait_vbl_done();}
set_bkg_tiles(0,0,20,18,temp_ram2);
move_bkg(0,0);
HIDE_WIN;

}




void load_map_up(UBYTE mapa[]){

get_bkg_tiles(0,0,20,18,temp_ram);
set_win_tiles(0,0,20,18,temp_ram);
move_bkg(0,144);
move_win(7,0);
SHOW_WIN;

draw_map(mapa);
for(i=0;i<144;i++){scroll_win(0,1);scroll_bkg(0,-1);scroll_all_sprites(0,1);delay(10);wait_vbl_done();}
move_bkg(0,0);
move_win(8,0);
HIDE_WIN;

}

void load_map_left(UBYTE mapa[]){

get_bkg_tiles(0,0,20,18,temp_ram);
set_win_tiles(0,0,20,18,temp_ram);
move_bkg(160,0);
move_win(7,0);
SHOW_WIN;

draw_map(mapa);
for(i=0;i<160;i++){scroll_win(1,0);scroll_bkg(-1,0);scroll_all_sprites(1,0);delay(10);wait_vbl_done();}
move_bkg(0,0);
move_win(8,0);
HIDE_WIN;

}




void manage_maps(UBYTE dir){
switch(current_map){
 case 1:
       if(dir==J_RIGHT){load_map_right(map2);current_map=2;}
       if(dir==J_DOWN) {load_map_down(map4); current_map=4;}
 break;
 case 2:
       if(dir==J_RIGHT){load_map_right(map3);current_map=3;}	
       if(dir==J_DOWN) {load_map_down(map5); current_map=5;}
       if(dir==J_LEFT) {load_map_left(map1); current_map=1;}
 break;
 case 3:
       if(dir==J_LEFT) {load_map_left(map2); current_map=2;}
       if(dir==J_DOWN) {load_map_down(map6); current_map=6;}
 break;
 case 4:
       if(dir==J_RIGHT){load_map_right(map5);current_map=5;}
       if(dir==J_DOWN) {load_map_down(map7); current_map=7;}
       if(dir==J_UP) {  load_map_up(map1);   current_map=1;}
 break;
 case 5:
       if(dir==J_RIGHT){load_map_right(map6);current_map=6;}
       if(dir==J_DOWN) {load_map_down(map8); current_map=8;}
       if(dir==J_UP) {  load_map_up(map2);   current_map=2;}
       if(dir==J_LEFT) {load_map_left(map4); current_map=4;}
 break;
 case 6:
       if(dir==J_LEFT) {load_map_left(map5); current_map=5;}
       if(dir==J_DOWN) {load_map_down(map9); current_map=9;}
       if(dir==J_UP) {  load_map_up(map3);   current_map=3;}
 break;
 case 7:
       if(dir==J_UP) {  load_map_up(map4);   current_map=4;}
       if(dir==J_RIGHT){load_map_right(map8);current_map=8;}
 break;
 case 8:
       if(dir==J_UP) {  load_map_up(map5);   current_map=5;}
       if(dir==J_RIGHT){load_map_right(map9);current_map=9;}
       if(dir==J_LEFT) {load_map_left(map7); current_map=7;}
 break;
 case 9:
       if(dir==J_UP) {  load_map_up(map6);   current_map=6;}
       if(dir==J_LEFT) {load_map_left(map8); current_map=8;}
 break;
 default:break;
}


}


#endif

