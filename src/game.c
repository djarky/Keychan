

/*
this is like mario galaxy or similar
player rotacion was determinate by head orientacion ie 
player_rot=J_UP -> floor on down , move left and right , normal
player_rot=J_DOWN -> floor on up , gravity on up
player_rot=J_LEFT ->floor on right etc , move up and down , gravity sideways etc
*/


void game_setup(void) {
HIDE_BKG;
DISPLAY_OFF;




//load sprite player
SWITCH_ROM_MBC5(5);
set_sprite_data(0x00,0x08,player_L_frame0);
set_sprite_data(0x08,0x08,player_R_frame0);
//load sprite player animation
set_sprite_data(0x10,0x08,player_L_walk);
set_sprite_data(0x18,0x08,player_R_walk);
//load sprite npc
set_sprite_data(0x20,0x14,npc_mice);
//load bars
set_bkg_data(0x1A,6,bars_tiles);

//load arrows (only test)
set_sprite_data(0x70,0x08,arrows);






move_win(0,0);
SHOW_BKG;
SHOW_WIN;
DISPLAY_ON;
//init rotaded sprites
for(i=0x00;i<0x30;i++){

  get_sprite_data(i,1,temp_ram);
  rotate_sprite(temp_ram);
  set_sprite_data(0x40+i,1,temp_ram);

  show_bars(8,0,(i*5));

}
fadeout();
//load level tiles
SWITCH_ROM_MBC5(4);
set_bkg_data(0,10,Tile_Dat);

SWITCH_ROM_MBC5(6);
set_bkg_data(0x30,43,my_fonts);

SWITCH_ROM_MBC5(6);
set_bkg_data(0x80,42,doors_rotated);
set_bkg_data(0xC0,8,lock_tiles);

SWITCH_ROM_MBC5(4);
draw_map(map5);
SWITCH_ROM_MBC5(3);
npc_spawn();
SHOW_BKG;
current_map=5;
HIDE_WIN;
SWITCH_ROM_MBC5(2);
player_init();

fadein();

SHOW_BKG;
SHOW_SPRITES;
DISPLAY_ON;
}


unsigned char pre_score=0xFE;


void update_hud(void) {


get_win_tiles(0,0,20,1,temp_ram);



show_bars(6,0,player_hp);

if(Deadmaus!=pre_score){  //prev value
SHOW_NUME(18,0,temp_score);
SHOW_NUME(15,0,Deadmaus);
pre_score=Deadmaus;      //update value
}


if(temp_ram[1]<0x20 || temp_ram[1]==0xFF){
set_win_tiles(0,0,6,1,"HEALTH");
set_win_tiles(10,0,5,1,"SCORE");
SHOW_NUME(18,0,temp_score);
SHOW_NUME(15,0,Deadmaus);
move_win(0x07,0x88);
SHOW_WIN;
}


}


void game_loop(UBYTE mapa[]){

SWITCH_ROM_MBC5(8);
musical_mice();

joy_pad=joypad();


check_door(mapa);

SWITCH_ROM_MBC5(2);
player_inputt(joy_pad,mapa);
SWITCH_ROM_MBC5(3);
control_all_npc(player_pos_x,player_pos_y,player_rot,mapa);
update_hud();
wait_vbl_done();



if(player_pos_y==8){

if(player_rot==J_UP || (joy_pad & J_DOWN && player_rot!=J_DOWN ) ){
SWITCH_ROM_MBC5(4);
manage_maps(J_DOWN); 
player_pos_y_abs=0;
SWITCH_ROM_MBC5(2);
player_init();
SWITCH_ROM_MBC5(3);
npc_spawn();
SWITCH_ROM_MBC5(2);
for(x=0;x<16;x++){player_scrollex(0,1);wait_vbl_done();}
}

}



if(player_pos_x==9){

if(player_rot==J_LEFT || (joy_pad & J_RIGHT && player_rot!=J_RIGHT)  ){
SWITCH_ROM_MBC5(4);
manage_maps(J_RIGHT);
player_pos_x_abs=0;
SWITCH_ROM_MBC5(2);
player_init();
SWITCH_ROM_MBC5(3);
npc_spawn();
SWITCH_ROM_MBC5(2);
for(x=0;x<16;x++){player_scrollex(1,0);wait_vbl_done();}
}

}



if(player_pos_y==0){


if(player_rot==J_DOWN || (joy_pad & J_UP && player_rot!=J_UP ) ){
SWITCH_ROM_MBC5(4);
manage_maps(J_UP);   
player_pos_y_abs=128;
SWITCH_ROM_MBC5(2);
player_init();
SWITCH_ROM_MBC5(3);
npc_spawn();
SWITCH_ROM_MBC5(2);
for(x=0;x<16;x++){player_scrollex(0,-1);wait_vbl_done();}
}


}


if(player_pos_x==0){

if(player_rot==J_RIGHT || (joy_pad & J_LEFT && player_rot!=J_LEFT ) ){
SWITCH_ROM_MBC5(4);
manage_maps(J_LEFT); 
player_pos_x_abs=144;
SWITCH_ROM_MBC5(2);
player_init();
SWITCH_ROM_MBC5(3);
npc_spawn();
SWITCH_ROM_MBC5(2);
for(x=0;x<16;x++){player_scrollex(-1,0);wait_vbl_done();}

}

}




}
