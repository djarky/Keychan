#include<stdio.h>
#include<gb/gb.h>
#include<stdlib.h>
#include<rand.h>

#include"mylibs/colider.h"

#include"mylibs/sound.h"



extern unsigned char npc_index;

#define first_npc_oam 8


//player posision
extern unsigned char player_pos_x;
extern unsigned char player_pos_y;
extern unsigned char player_rot;

extern unsigned char player_hp;


extern unsigned char tile_index;

extern unsigned char npc_pos_x[];
extern unsigned char npc_pos_y[];
extern unsigned char npc_rot[];



//platform moves 
#define BACK_WAY  J_LEFT
#define FRONT_WAY J_RIGHT
#define DEAD_WAY  0xFF
extern unsigned char npc_dir[];


extern unsigned char npc_pos_x_abs[];
extern unsigned char npc_pos_y_abs[];


#define MAP_WHITH 10
#define npc_pos_xy (npc_pos_y[npc_index]*MAP_WHITH)+npc_pos_x[npc_index]
#define TILE_SOLID 0x01




extern unsigned char i;
extern unsigned char k;



extern unsigned char npc_joy;
extern unsigned char npc_col;



int npc_sprite_cal(void) {
    return first_npc_oam + (npc_index << 2);
}



void npc_calcule_xy(void) {
    if ((npc_pos_x_abs[npc_index] & 15) == 0) {
        npc_pos_x[npc_index] = npc_pos_x_abs[npc_index] >> 4;
    }
    if ((npc_pos_y_abs[npc_index] & 15) == 0) {
        npc_pos_y[npc_index] = npc_pos_y_abs[npc_index] >> 4;
    }
}







/*
this is like mario galaxy or similar
npc rotacion was determinate by head orientacion ie 
npc_rot=J_UP -> floor on down , move left and right , normal platform
npc_rot=J_DOWN -> floor on up , gravity on up
npc_rot=J_LEFT ->floor on right, move up and down , gravity sideways etc

sprites rotation -> (S_FLIPX|S_FLIPY) = 180 degrades 
*/

void npc_rotate_sp0(void){
for(i=0;i<4;i++){
set_sprite_prop(npc_sprite_cal()+i,get_sprite_prop(npc_sprite_cal()+i) &~ (S_FLIPX|S_FLIPY));}
}
void npc_rotate_sp180(void){
for(i=0;i<4;i++){
set_sprite_prop(npc_sprite_cal()+i,get_sprite_prop(npc_sprite_cal()+i) |  (S_FLIPX|S_FLIPY));}
}
void npc_flipx_off(void){
for(i=0;i<4;i++){
set_sprite_prop(npc_sprite_cal()+i,get_sprite_prop(npc_sprite_cal()+i) &~ S_FLIPX );}
}
void npc_flipx_on(void){
for(i=0;i<4;i++){
set_sprite_prop(npc_sprite_cal()+i,get_sprite_prop(npc_sprite_cal()+i) | S_FLIPX );}
}
void npc_flipy_off(void){
for(i=0;i<4;i++){
set_sprite_prop(npc_sprite_cal()+i,get_sprite_prop(npc_sprite_cal()+i) &~ S_FLIPY);}
}
void npc_flipy_on(void){
for(i=0;i<4;i++){
set_sprite_prop(npc_sprite_cal()+i,get_sprite_prop(npc_sprite_cal()+i) | S_FLIPY );}
}



const unsigned char npc_map_flip[] ={2,3,0,1} ;





void npc_walk_ani(UBYTE frame_ani){

tile_index=(frame_ani*4)+0x20;
tile_index += (npc_rot[npc_index] == J_UP || npc_rot[npc_index] == J_DOWN ? 0x00 : 0x40); 
 
for(k=0;k<4;k++){set_sprite_tile(npc_sprite_cal()+k,tile_index+k);}
}




//init npc sprites  in horizontal rotation


/*
[0][2]
[1][3]
*/


void npc_init_hor(void){

npc_walk_ani(((sys_time >> 3) %4));

for(i=0;i<4;i++){

if(npc_rot[npc_index]==J_UP){
if(npc_dir[npc_index]==BACK_WAY) {
move_sprite( npc_sprite_cal()+i , npc_pos_x_abs[npc_index]+( (i/2)*8)+8 , npc_pos_y_abs[npc_index] + (i%2==0 ? 8:16 )+8  );
} 
else{
move_sprite( npc_sprite_cal()+npc_map_flip[i] , npc_pos_x_abs[npc_index]+( (i/2)*8)+8 , npc_pos_y_abs[npc_index] + (i%2==0 ? 8:16 )+8  );
} 
}


if(npc_rot[npc_index]==J_DOWN){
if(npc_dir[npc_index]==FRONT_WAY) {
move_sprite(npc_sprite_cal()+npc_map_flip[3-i] , npc_pos_x_abs[npc_index] + ((i/2)*8)+8 ,npc_pos_y_abs[npc_index] + (i%2==0 ? 8:16 )+8 );
}
else{
move_sprite( npc_sprite_cal()+(3-i) , npc_pos_x_abs[npc_index]+( (i/2)*8)+8 , npc_pos_y_abs[npc_index] + (i%2==0 ? 8:16 )+8  );
} 
}


}

SHOW_SPRITES;

}



//init npc sprites in vertical rotation 

/*
[2][3]
[0][1]
*/

void npc_init_ver(void){

npc_walk_ani(((sys_time >> 3) %4));

for(i=0;i<4;i++){

if(npc_rot[npc_index]==J_LEFT){
if(npc_dir[npc_index]==BACK_WAY) {
move_sprite(npc_sprite_cal()+(3-i) ,  npc_pos_x_abs[npc_index] + (i%2==0 ? 16:8 ),npc_pos_y_abs[npc_index] + ((i/2)*8)+16 );
} 
else{
move_sprite(npc_sprite_cal()+npc_map_flip[3-i] ,  npc_pos_x_abs[npc_index] + (i%2==0 ? 16:8 ),npc_pos_y_abs[npc_index] + ((i/2)*8)+16 );
} 
}

if(npc_rot[npc_index]==J_RIGHT){
if(npc_dir[npc_index]==FRONT_WAY) {
move_sprite( npc_sprite_cal()+npc_map_flip[i]  , npc_pos_x_abs[npc_index] + (i%2==0 ? 16:8 ) ,npc_pos_y_abs[npc_index]+( (i/2)*8)+16 );
} 
else{
move_sprite( npc_sprite_cal()+i  , npc_pos_x_abs[npc_index] + (i%2==0 ? 16:8 ) ,npc_pos_y_abs[npc_index]+( (i/2)*8)+16 );
} 
}

}

SHOW_SPRITES;

}


//init npc sprite for any posicion and rotation
void npc_init(void){

npc_calcule_xy();

switch(npc_rot[npc_index]){
 case J_UP:   npc_rotate_sp0();  npc_init_hor();break;
 case J_DOWN: npc_rotate_sp180();npc_init_hor();break;
 case J_LEFT: npc_rotate_sp0();  npc_init_ver();break;
 case J_RIGHT:npc_rotate_sp180();npc_init_ver();break;
 default:break;
}


if(npc_dir[npc_index]==FRONT_WAY){

if(npc_rot[npc_index]==J_UP   ) {npc_flipx_on() ; } 
if(npc_rot[npc_index]==J_LEFT ) {npc_flipy_on() ; } 
if(npc_rot[npc_index]==J_DOWN ) {npc_flipx_off() ;} 
if(npc_rot[npc_index]==J_RIGHT) {npc_flipy_off() ;} 

}



}



void npc_rotate90(void){
if(npc_pos_x_abs[npc_index]%16==0 && npc_pos_y_abs[npc_index]%16==0){
switch(npc_rot[npc_index]){
 case J_UP:   npc_rot[npc_index]=J_LEFT; break;
 case J_DOWN: npc_rot[npc_index]=J_RIGHT;break;
 case J_LEFT: npc_rot[npc_index]=J_DOWN; break;
 case J_RIGHT:npc_rot[npc_index]=J_UP;   break;
 default:break;
}

npc_init();
}

}



//--scroll 

void npc_scrollex(BYTE x_pos,BYTE y_pos){
for(k=0;k<4;k++){scroll_sprite(npc_sprite_cal()+k,x_pos,y_pos);}
npc_pos_x_abs[npc_index]+=x_pos;
npc_pos_y_abs[npc_index]+=y_pos;
}






//moves left-right platform---- horizontal 

void npc_move_front(void){
if(npc_rot[npc_index]==J_UP   && npc_dir[npc_index]==BACK_WAY){npc_dir[npc_index] = FRONT_WAY;npc_init();}
if(npc_rot[npc_index]==J_DOWN && npc_dir[npc_index]==FRONT_WAY){npc_dir[npc_index] = BACK_WAY;npc_init();}
npc_scrollex(1,0);
npc_walk_ani(((sys_time >> 3) %4));
}



void npc_move_back(void){
if(npc_rot[npc_index]==J_UP   && npc_dir[npc_index]==FRONT_WAY){npc_dir[npc_index] = BACK_WAY;npc_init(); }
if(npc_rot[npc_index]==J_DOWN && npc_dir[npc_index]==BACK_WAY){npc_dir[npc_index] = FRONT_WAY;npc_init(); }
npc_scrollex(-1,0);
npc_walk_ani(((sys_time >> 3) %4));
}



//moves up-down rotated platform--- sideways vertical

void npc_move_front_side(void){
if(npc_rot[npc_index]==J_LEFT  && npc_dir[npc_index]==BACK_WAY){  npc_dir[npc_index] = FRONT_WAY;npc_init();}
if(npc_rot[npc_index]==J_RIGHT && npc_dir[npc_index]==FRONT_WAY){ npc_dir[npc_index] = BACK_WAY; npc_init();}
npc_scrollex(0,-1);
npc_walk_ani(((sys_time >> 3) %4));
}


void npc_move_back_side(void){
if(npc_rot[npc_index]==J_LEFT  && npc_dir[npc_index]==FRONT_WAY){npc_dir[npc_index] = BACK_WAY; npc_init(); }
if(npc_rot[npc_index]==J_RIGHT && npc_dir[npc_index]==BACK_WAY){ npc_dir[npc_index] = FRONT_WAY;npc_init(); }
npc_scrollex(0,1);
npc_walk_ani(((sys_time >> 3) %4));
}





//-- gravity



void npc_gravity(void){


switch(npc_rot[npc_index]){

 case J_UP:
   if(!(npc_col & COL_D) ){ 
   npc_scrollex(0,1);
   }
 break;
 case J_DOWN:
   if(!(npc_col & COL_U) ){ 
   npc_scrollex(0,-1);
   }
 break;

 case J_LEFT:
   if(!(npc_col & COL_R) ){ 
   npc_scrollex(1,0);
   }
 break;
 case J_RIGHT:
   if(!(npc_col & COL_L) ){ 
   npc_scrollex(-1,0);
   }
 break;
 default:break;
}


}




//  inputt controll for npc_index


void npc_inputt(UBYTE joy){

if(joy & J_B){npc_rotate90();}

switch(npc_rot[npc_index]){
 case J_UP   :
	if( (joy & J_RIGHT) && !(npc_col & COL_R) && (npc_col & COL_D)   ){npc_move_front();     }
	if( (joy & J_LEFT)  && !(npc_col & COL_L) && (npc_col & COL_D)   ){npc_move_back();      }
 break;
 case J_DOWN :
	if( (joy & J_RIGHT) && !(npc_col & COL_R) && (npc_col & COL_U)  ){npc_move_front();      }
	if( (joy & J_LEFT)  && !(npc_col & COL_L) && (npc_col & COL_U)  ){npc_move_back();       }
 break;
 case J_LEFT :
	if( (joy & J_UP)    && !(npc_col & COL_U)  && (npc_col & COL_R)  ){npc_move_front_side();}
	if( (joy & J_DOWN)  && !(npc_col & COL_D)  && (npc_col & COL_R)  ){npc_move_back_side(); }
 break;
 case J_RIGHT:
	if( (joy & J_UP)    && !(npc_col & COL_U)  && (npc_col & COL_L)  ){npc_move_front_side(); }
	if( (joy & J_DOWN)  && !(npc_col & COL_D)  && (npc_col & COL_L)  ){npc_move_back_side();  }
 break;
 default:break;
}



}




void init_all_npc(void){
for(npc_index=0;npc_index<4;npc_index++){
npc_init();
}
npc_index=0;
}





/*-----control npcs-------*/

void control_all_npc(UBYTE p_pos_x,UBYTE p_pos_y,UBYTE p_rot,UBYTE mapa[]){

for(npc_index=0;npc_index<4;npc_index++){


if(p_pos_x==npc_pos_x[npc_index]&&p_pos_y==npc_pos_y[npc_index]){


if(p_rot==npc_rot[npc_index]){
npc_rot[npc_index]=J_UP;
npc_init();
npc_walk_ani(4);
while(npc_pos_xy<90){
npc_calcule_xy();
npc_scrollex(0,-1);delay(20);
}
npc_dir[npc_index]=DEAD_WAY;
}
else{
if(player_hp!=0){player_hp--;}
if(((sys_time >> 3) %4)==2){play_sound_C1(0x11,0x2A,0xF0,0x0D,0xC1);}
if(((sys_time >> 3) %4)==3){play_sound_C1(0x11,0x2A,0xF0,0x0D,0xC2);}
}



}





//calcule posicion and collision
npc_calcule_xy();
npc_col = nine_col(npc_pos_x[npc_index],npc_pos_y[npc_index],mapa);

npc_joy=0;


if(p_pos_x < npc_pos_x[npc_index]){
if(!(npc_col & COL_R) ){npc_joy+=J_RIGHT;}else{npc_joy+=J_LEFT;}
}
if(p_pos_x > npc_pos_x[npc_index]){
if(!(npc_col & COL_L) ){npc_joy+=J_LEFT; }else{npc_joy+=J_RIGHT;}
}
if(p_pos_y < npc_pos_y[npc_index]){
if(!(npc_col & COL_D) ){npc_joy+=J_DOWN;}else{npc_joy+=J_UP;}
}
if(p_pos_y > npc_pos_y[npc_index]){
if(!(npc_col & COL_U) ){npc_joy+=J_UP; }else{npc_joy+=J_DOWN;}  
}



if(joypad()& J_B){npc_joy=J_B;}

if(npc_dir[npc_index]!=DEAD_WAY){
npc_inputt(npc_joy);
//calcule new posicion and collision
npc_calcule_xy();
npc_col = nine_col(npc_pos_x[npc_index],npc_pos_y[npc_index],mapa);
npc_gravity();
}





}

npc_index=0;


}



/*----spawn-------*/



void npc_spawn(void){
for(npc_index=0;npc_index<4;npc_index++){
npc_dir[npc_index]=FRONT_WAY;
}
npc_pos_x_abs[0]=32; npc_pos_y_abs[0]=16;
npc_pos_x_abs[1]=112;npc_pos_y_abs[1]=16;
npc_pos_x_abs[2]=32; npc_pos_y_abs[2]=112;
npc_pos_x_abs[3]=112;npc_pos_y_abs[3]=112;
init_all_npc();
}






