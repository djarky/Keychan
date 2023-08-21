#include<stdio.h>
#include<gb/gb.h>
#include<stdlib.h>
#include<rand.h>

#include"mylibs/colider.h"

#include"mylibs/sound.h"

//jump values
#define vertical_velocity 2
#define  max_jump_height  64
extern UBYTE jump_height;

//player posision
extern unsigned char player_pos_x;
extern unsigned char player_pos_y;
extern unsigned char player_rot;

//platform moves 
#define BACK_WAY  J_LEFT
#define FRONT_WAY J_RIGHT
extern unsigned char player_dir;



extern unsigned char player_pos_x_abs;
extern unsigned char player_pos_y_abs;

extern unsigned char player_col;

extern unsigned char player_hp;

#define MAP_WHITH 10
#define player_pos_xy (player_pos_y*MAP_WHITH)+player_pos_x
#define TILE_SOLID 0x01

extern unsigned char i;
extern unsigned char k;


extern unsigned char tile_index;




void player_calcule_xy(void) {
    if ((player_pos_x_abs & 15) == 0) {
        player_pos_x = player_pos_x_abs >> 4;
    }
    if ((player_pos_y_abs & 15) == 0) {
        player_pos_y = player_pos_y_abs >> 4;
    }
}



/*
this is like mario galaxy or similar
player rotacion was determinate by head orientacion ie 
player_rot=J_UP -> floor on down , move left and right , normal platform
player_rot=J_DOWN -> floor on up , gravity on up
player_rot=J_LEFT ->floor on right, move up and down , gravity sideways etc

sprites rotation -> (S_FLIPX|S_FLIPY) = 180 degrades 
*/

void player_rotate_sp0(void){
for(i=0;i<8;i++){set_sprite_prop(i,get_sprite_prop(i) &~ (S_FLIPX|S_FLIPY));}
}
void player_rotate_sp180(void){
for(i=0;i<8;i++){set_sprite_prop(i,get_sprite_prop(i) |  (S_FLIPX|S_FLIPY));}
}











//init player sprites  in horizontal rotation


/*
[0][1]
[2][3]
[4][5]
*/


void player_init_hor(void){



for(i=0;i<8;i++){set_sprite_tile(i,  i+( player_dir == BACK_WAY ? 0x00 : 0x08)   );}




if(player_rot==J_UP){


for(i=0;i<6;i++){
move_sprite( i ,player_pos_x_abs + (i%2==0 ? 8:16 ), player_pos_y_abs+( (i/2)*8)+8  );//8 is offset
}


//fix sprite double color
move_sprite(6,player_pos_x_abs+20,player_pos_y_abs+11 );//key
move_sprite(7,player_pos_x_abs+13,player_pos_y_abs+16 );//face


/* 
to calcule fix key_poS = pos_sprite_1 + (4,3) and face_Pos = pos_sprite_2 +(5,0)
move_sprite(6,player_pos_x_abs +(16+4),player_pos_y_abs +(8 +3) );
move_sprite(7,player_pos_x_abs +(8 +5),player_pos_y_abs +(16+0) );
*/


}


if(player_rot==J_DOWN){


for(i=0;i<6;i++){
move_sprite(5-i,player_pos_x_abs + (i%2==0 ? 8:16 ), player_pos_y_abs + ((i/2)*8)+16  );//offset
}


//fix sprite double color
move_sprite(6,player_pos_x_abs+4,player_pos_y_abs+29);//key
move_sprite(7,player_pos_x_abs+11,player_pos_y_abs+24);//face

/* 
to calcule fix key_poS = pos_sprite_1 + (-4,-3) and face_Pos = pos_sprite_2 +(-5,0)
*/


}


SHOW_SPRITES;

}



//init player sprites in vertical rotation 

/*
[1][3][5]
[0][2][3]
*/

void player_init_ver(void){


for(i=0;i<8;i++){set_sprite_tile(i,  i+( player_dir == BACK_WAY ? 0x40 : 0x48)   );}



if(player_rot==J_LEFT){


for(i=0;i<6;i++){
move_sprite( i , player_pos_x_abs+( (i/2)*8) ,player_pos_y_abs + (i%2==0 ? 16:8 )+8 );
}

//fix sprite double color
move_sprite(6,player_pos_x_abs+3,player_pos_y_abs+12 );//key
move_sprite(7,player_pos_x_abs+8,player_pos_y_abs+19 );//face

/*
to calcule fix key_poS = pos_sprite_1 + (3,-4) and face_Pos = pos_sprite_2 +(0,-5)
*/

}
if(player_rot==J_RIGHT){

for(i=0;i<6;i++){
move_sprite(5-i, player_pos_x_abs + ((i/2)*8)+8  , player_pos_y_abs + (i%2==0 ? 16:8 )+8 );
}

//fix sprite double color
move_sprite(6,player_pos_x_abs+21,player_pos_y_abs+28 );//key
move_sprite(7,player_pos_x_abs+16,player_pos_y_abs+21 );//face

/*
to calcule fix key_poS = pos_sprite_1 + (-3,+4) and face_Pos = pos_sprite_2 +(0,+5)
*/

}

SHOW_SPRITES;

}


//init player sprite for any posicion and rotation
void player_init(void){



//fix double color 6 tile is key 7 is a face
set_sprite_prop(6,S_PALETTE);
set_sprite_prop(7,S_PALETTE);


switch(player_rot){
 case J_UP:   player_rotate_sp0();  player_init_hor();break;
 case J_DOWN: player_rotate_sp180();player_init_hor();break;
 case J_LEFT: player_rotate_sp0();  player_init_ver();break;
 case J_RIGHT:player_rotate_sp180();player_init_ver();break;
 default:break;
}


}



void player_rotate90(void){

switch(player_rot){
 case J_UP:   player_rot=J_LEFT; break;
 case J_DOWN: player_rot=J_RIGHT;break;
 case J_LEFT: player_rot=J_DOWN; break;
 case J_RIGHT:player_rot=J_UP;   break;
 default:break;
}

player_init();
}



//--scroll 

void player_scrollex(BYTE x_pos,BYTE y_pos){
for(k=0;k<8;k++){scroll_sprite(k,x_pos,y_pos);}
player_pos_x_abs+=x_pos;
player_pos_y_abs+=y_pos;
}






void player_walk_ani(UBYTE frame_ani){

tile_index=(frame_ani*2)+0x10;
tile_index += (player_dir == BACK_WAY ? 0x00 : 0x08);
tile_index += (player_rot == J_UP || player_rot == J_DOWN ? 0x00 : 0x40); 
 
set_sprite_tile(4,tile_index);
set_sprite_tile(5,tile_index+1);
}




//moves left-right platform---- horizontal 

void player_move_front(void){
if(player_rot==J_UP  ){player_dir = FRONT_WAY;}
if(player_rot==J_DOWN){player_dir = BACK_WAY; }
player_init();
player_scrollex(1,0);
player_walk_ani(((sys_time >> 3) %4));
}



void player_move_back(void){
if(player_rot==J_UP  ){player_dir = BACK_WAY;  }
if(player_rot==J_DOWN){player_dir = FRONT_WAY; }
player_init();
player_scrollex(-1,0);
player_walk_ani(((sys_time >> 3) %4));
}



//moves up-down rotated platform--- sideways vertical

void player_move_front_side(void){
if(player_rot==J_LEFT  ){player_dir = FRONT_WAY;}
if(player_rot==J_RIGHT){ player_dir = BACK_WAY; }
player_init();
player_scrollex(0,-1);
player_walk_ani(((sys_time >> 3) %4));
}


void player_move_back_side(void){
if(player_rot==J_LEFT  ){player_dir = BACK_WAY;  }
if(player_rot==J_RIGHT){ player_dir = FRONT_WAY; }
player_init();
player_scrollex(0,1);
player_walk_ani(((sys_time >> 3) %4));
}




//----- jumping 

void player_jump(void){


switch(player_rot){
 case J_UP:   
   if(!(player_col & COL_U) && jump_height<max_jump_height){
 	player_scrollex(0,-vertical_velocity);jump_height+=2;
   }
 break;
 case J_DOWN:
   if(!(player_col & COL_D) && jump_height<max_jump_height){
 	player_scrollex(0, vertical_velocity);jump_height+=2;
   }
 break;
 case J_LEFT:
   if(!(player_col & COL_L) && jump_height<max_jump_height){
	 player_scrollex(-vertical_velocity,0);jump_height+=2;
   }
 break;
 case J_RIGHT:
   if(!(player_col & COL_R) && jump_height<max_jump_height){
	player_scrollex( vertical_velocity,0);jump_height+=2;
   }
 break;
 default:break;
}


}



void player_gravity(UBYTE joy){



switch(player_rot){

 case J_UP:
   if(!(player_col & COL_D) || player_pos_y_abs%16 !=0 ){ 

      if(  (player_col & COL_DR) && ( (joy & J_RIGHT) && !(player_col & COL_R) ) ){

            if(player_pos_y_abs%16==0){player_scrollex(0,-1);}
            else{player_scrollex(-1,0);}

      }
      if(  (player_col & COL_DL) && ( (joy & J_LEFT) && !(player_col & COL_L) )  ){

            if(player_pos_y_abs%16==0){player_scrollex(0,-1);}
            else{player_scrollex(1,0);}
      }
      
      player_scrollex(0,1);
   }
 break;
 case J_DOWN:
   if(!(player_col & COL_U) ||  player_pos_y_abs%16 !=0  ){ 

      if(  (player_col & COL_UR) && ( (joy & J_RIGHT) && !(player_col & COL_R) ) ){

            if(player_pos_y_abs%16==0){player_scrollex(0,1);}
            else{player_scrollex(-1,0);}

      }
      if(  (player_col & COL_UL) && ( (joy & J_LEFT) && !(player_col & COL_L) )  ){

            if(player_pos_y_abs%16==0){player_scrollex(0,1);}
            else{player_scrollex(1,0);}
      }


	player_scrollex(0,-1);
   }
 break;

 case J_LEFT:
   if(!(player_col & COL_R) ||  player_pos_x_abs%16 !=0  ){ 


      if(  (player_col & COL_UR) && ( (joy & J_UP) && !(player_col & COL_U) ) ){

            if(player_pos_x_abs%16==0){player_scrollex(-1,0);}
            else{player_scrollex(0,1);}

      }
      if(  (player_col & COL_DR) && ( (joy & J_DOWN) && !(player_col & COL_D) )  ){

            if(player_pos_x_abs%16==0){player_scrollex(-1,0);}
            else{player_scrollex(0,-1);}
      }





	player_scrollex(1,0);
   }
 break;
 case J_RIGHT:
   if(!(player_col & COL_L) || player_pos_x_abs%16 !=0  ){ 


      if(  (player_col & COL_UL) && ( (joy & J_UP) && !(player_col & COL_U) ) ){

            if(player_pos_x_abs%16==0){player_scrollex(1,0);}
            else{player_scrollex(0,1);}

      }
      if(  (player_col & COL_DL) && ( (joy & J_DOWN) && !(player_col & COL_D) )  ){

            if(player_pos_x_abs%16==0){player_scrollex(1,0);}
            else{player_scrollex(0,-1);}
      }




	player_scrollex(-1,0);
   }
 break;
 default:break;
}


}


// --- other

void player_power_up(void){
player_rotate90();
delay(100);
}



//   ---   main inputt controll         ----&&!(!(player_col & COL_D)&&player_col & COL_DR)



void player_inputt(UBYTE joy,UBYTE mapa[]){


player_calcule_xy();
player_col=nine_col(player_pos_x,player_pos_y,mapa);


if(joy & J_A){
if(jump_height==0){play_sound_C1(0x62, 0x87, 0x8D, 0x32 ,0xC1);}
player_jump();  
player_calcule_xy();
player_col=nine_col(player_pos_x,player_pos_y,mapa);
}
else{if(jump_height>0){jump_height--;}}


if(joy & J_B){player_power_up();}

switch(player_rot){
 case J_UP   :
 	if( (joy & J_RIGHT) && (!(player_col & COL_R)||player_pos_x_abs%16 !=0) ){player_move_front();    }
 	if( (joy & J_LEFT)  && (!(player_col & COL_L)||player_pos_x_abs%16 !=0) ){player_move_back();     }
 break;
 case J_DOWN :
 	if( (joy & J_RIGHT) && (!(player_col & COL_R)||player_pos_x_abs%16 !=0) ){player_move_front();    }
 	if( (joy & J_LEFT)  && (!(player_col & COL_L)||player_pos_x_abs%16 !=0) ){player_move_back();     }
 break;
 case J_LEFT :
	if( (joy & J_UP)   && (!(player_col & COL_U)||player_pos_y_abs%16 !=0) ){player_move_front_side();}
	if( (joy & J_DOWN) && (!(player_col & COL_D)||player_pos_y_abs%16 !=0) ){player_move_back_side(); }
 break;
 case J_RIGHT:
	if( (joy & J_UP)   && (!(player_col & COL_U)||player_pos_y_abs%16 !=0) ){player_move_front_side();}
	if( (joy & J_DOWN) && (!(player_col & COL_D)||player_pos_y_abs%16 !=0) ){player_move_back_side(); }
 break;

}



//recalcule new x y and collision
player_calcule_xy();
player_col=nine_col(player_pos_x,player_pos_y,mapa);
player_gravity(joy);

//fix colider or rare posicion
if(mapa[player_pos_xy]==TILE_SOLID || (player_col & COL_D && player_col & COL_U && player_col & COL_R && player_col & COL_L)  ){


switch(player_rot){
 case J_UP   :player_scrollex(0,-vertical_velocity);
 break;
 case J_DOWN :player_scrollex(0, vertical_velocity);
 break;
 case J_LEFT :player_scrollex(-vertical_velocity,0);
 break;
 case J_RIGHT:player_scrollex( vertical_velocity,0);
 break;
}


}
//fix out of map
if(player_pos_x_abs>160){player_pos_x_abs=80;}
if(player_pos_y_abs>144){player_pos_y_abs=80;}


}




