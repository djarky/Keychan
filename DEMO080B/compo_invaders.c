#include<stdio.h>
#include<gb/gb.h>
#include<gb/drawing.h>
#include<time.h>
#include<rand.h>
#include"invaders_sprite.c"
#include"compo_logo.h"


extern unsigned char i;
extern unsigned char k;

extern unsigned char x;
extern unsigned char y;



extern unsigned char temp_ram[];



#define posXX x
#define posYY y

#define c temp_ram[0]
#define r temp_ram[1]


#define bunniesX temp_ram
#define bunniesY temp_ram
#define bunniesZ temp_ram
#define ballX temp_ram
#define ballY temp_ram





void update_sprites();
void inputt(UBYTE joy);

void shot(UBYTE X);
void ia_bunnies();


void pumm();


void ini_sound_reg(){
NR52_REG = 0xF8U;
NR51_REG = 0x00U;
NR50_REG = 0x77U;
}
void play_sound_effect_uno(){
NR10_REG = 0x30;;
NR11_REG = 0x80U;;
NR12_REG = 0xF0U;
NR13_REG = 0x00U;
NR14_REG = 0xC1U;
NR51_REG |=0x11;
}
void play_sound_effect_dos(){
NR41_REG = 0x03;;
NR42_REG = 0xF0U;;
NR43_REG = 0x22U;
NR44_REG = 0xC0U;
NR51_REG |=0xFF;
}









void shoter_game(){
ini_sound_reg();

posXX=80;
posYY=136;

for(i=0;i<10;i++){bunniesX[i+10]=0x00;}
for(i=0;i<18;i++){set_bkg_tiles(0,i,20,1,bunniesX);}

for(i=0;i<40;i++){set_sprite_tile(i,0x7F);}
set_bkg_data(0,81,compo_tiledata);
set_bkg_tiles(5,5,10,8,compo_tilemap);



set_sprite_data(0,9,spr_tiles);
set_bkg_data(0x50,4,spr_tiles);

SHOW_BKG;
DISPLAY_ON;




for(i=0;i<0x09;i++){
set_sprite_tile(i,4);
set_sprite_tile(i+0x10,8);
bunniesX[i+10]=rand();
bunniesY[i+20]=rand();
ballX[i+40]=0x00;ballY[i+50]=0x00;
if(bunniesX[i+10]<144){bunniesX[i+10]+=144;}
if(bunniesY[i+20]<160){bunniesY[i+20]+=160;}
move_sprite(i+1,bunniesX[i+10],bunniesY[i+20]);
move_sprite(i+0x10,0x00,0x00);
}

set_sprite_tile(0,6);


delay(500);

SHOW_BKG;
SHOW_SPRITES;
DISPLAY_ON;
move_sprite(0,posXX,posYY+24);
for(i=0;i<24;i++){scroll_sprite(0,0,-1);delay(50);}

while(1){
ia_bunnies();
update_sprites();
inputt(joypad());
scroll_bkg(0,-1);
wait_vbl_done();
r=0x00;
pumm();
if(r==0xFF){play_sound_effect_dos();break;}
}

initarand(DIV_REG);


for(i=0;i<40;i++){move_sprite(i,255,255);}


move_bkg(0,0);
HIDE_SPRITES;
DISPLAY_OFF;


}




void update_sprites(){
for(i=0;i<0x09;i++){
bunniesY[i+20]++;
move_sprite(i+1,bunniesX[i+10],bunniesY[i+20]);
if(c==0x00){
set_sprite_tile(i+1,5);
c=0xFF;
}
else{
set_sprite_tile(i+1,4);
c=0x00;
}
if(ballX[i+40]!=0x00&&ballY[i+50]!=0x00){
if(i==0){ballY[i+50]-=2;}
else{ballY[i+50]+=2;}
move_sprite(i+0x10,ballX[i+40],ballY[i+50]);
}
}
move_sprite(0,posXX,posYY);
SHOW_SPRITES;
}

void inputt(UBYTE joy){

if(joy & J_RIGHT){posXX++;}
if(joy & J_LEFT) {posXX--;}
if(joy & J_UP)   {posYY--;}
if(joy & J_DOWN) {posYY++;}

if(joy & J_A){shot(0);}


}

void ia_bunnies(){
for(i=1;i<9;i++){
if(rand()==0x00){bunniesZ[i+30]=rand()%4;}
switch ( bunniesZ[i+30]){
case 0x00: bunniesX[i+10]--;break;
case 0x01: bunniesX[i+10]++;break;
case 0x02: bunniesY[i+20]--;break;
case 0x03: bunniesY[i+20]++;break;
}
if(rand()==0x01){shot(i);}
}
}

void shot(UBYTE X){
if(X==0x00){
move_sprite(0x10,posXX,posYY-8);
ballX[0+40]=posXX;ballY[0+50]=posYY-8;
}
else{
move_sprite(X+0x11,bunniesX[X+10],bunniesY[X+20]+8);
ballX[X+1+40]=bunniesX[X+10];
ballY[X+1+50]=bunniesY[X+20]+8;
}
play_sound_effect_uno();
}

void pumm(){
for(i=0;i<0x09;i++){
for(k=0;k<0x09;k++){
if((bunniesX[i+10]<(ballX[k+40]+8)&&bunniesX[i+10]>(ballX[k+40]-8))&&(bunniesY[i+20]<(ballY[k+50]+8)&&bunniesY[i+20]>(ballY[k+50]-8))){
bunniesX[i+10]=rand();bunniesY[i+20]=rand();
if(bunniesX[i+10]<144){bunniesX[i+10]+=144;}
if(bunniesY[i+20]<160){bunniesY[i+20]+=160;}
ballX[k+40]=0x00;ballY[k+50]=0x00;
move_sprite(k+0x10,ballX[k+40],ballY[k+50]);
play_sound_effect_dos();
}
}
}

for(i=0;i<0x09;i++){
if((posXX<(bunniesX[i+10]+8)&&posXX>(bunniesX[i+10]-8))&&(posYY<bunniesY[i+20]+8&&posYY>bunniesY[i+20]-8)){r=0xFF;}
if((posXX<ballX[i+40]+8&&posXX>ballX[i+40]-8)&&(posYY<ballY[i+50]+8&&posYY>ballY[i+50]-8)){r=0xFF;}
}

}

