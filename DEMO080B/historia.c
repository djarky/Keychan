#include"assets/historia_assets.h"

#include"mylibs/fade.c"

#define len k


const unsigned char a_blank_space[]=
{0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};




void perform_delay(UBYTE retraso){
if(joypad()!=J_START){waitpadup();}
for(x=0;x<retraso;x++){
len=rand();
wait_vbl_done();
if(joypad()){break;}
}
}






int my_strlen(UBYTE TEXT[]){
len=0x00;
while(TEXT[len]!=0x00&&len<0x90){
len++;
if(((TEXT[len]>0x5A||TEXT[len]<0x30)&& TEXT[len]!=0x20&& TEXT[len]!='n')){break;}
}
return len;
}


void print_text(UBYTE TEXT[]){
set_bkg_tiles(1,0x0E,18,1,a_blank_space);
set_bkg_tiles(1,0x0F,18,1,a_blank_space);
set_bkg_tiles(1,0x10,18,1,a_blank_space);
SWITCH_ROM_MBC5(12);
set_bkg_data(0xD0,0x2B,his_fonts);
for(i=0;i<0x40;i++){temp_ram[i]=0xFF;}
for(i=0;i<my_strlen(TEXT);i++){
if(TEXT[i]==0x20){temp_ram[i]=0xFF;}else{temp_ram[i]= TEXT[i]+0xA0;}
}
set_bkg_tiles(1,0x0F,18,4,temp_ram);
play_sound_C1(0x38, 0x56, 0xEB, temp_ram[6] ,0xC3);
perform_delay(200);
}


void load_picture(UBYTE pics_data[],UBYTE banco){

for(i=0;i<20;i++){
 for(k=0;k<18;k++){
   set_bkg_tiles(i,k,1,1,a_blank_space);
 }
}

//HIDE_BKG;
fadeout();


SWITCH_ROM_MBC5(12);
set_bkg_tiles(2,1,16,16,HIS_tilemap);
SWITCH_ROM_MBC5(banco);
set_bkg_data(0,255,pics_data);

//SHOW_BKG;
fadein();
play_sound_C1(0x38, 0x56, 0xEB, pics_data[6] ,0xC3);
perform_delay(100);
}



const unsigned char big_sprite_map[]=
{
0,2,8,10,
1,3,9,11,
4,6,12,14,
5,7,13,15
};


void load_big_sprite(){
HIDE_SPRITES;
for(i=0;i<0x10;i++){set_sprite_prop(i,S_PALETTE);}

for(i=0;i<4;i++){
for(k=0;k<4;k++){
move_sprite((k+(i*4)),k*8,i*8);
delay(100);
}
}
for(i=0;i<0x10;i++){scroll_sprite(i,72,64);}
SHOW_SPRITES;

}




void big_sprite_animation(UBYTE ani_frame){

for(i=0;i<0x10;i++){set_sprite_tile(i,big_sprite_map[i]+(ani_frame*0x10));}


}






void hist_part(UBYTE his_index){


switch(his_index){
case 0:
play_sound_C4(0x2E,0xF0,0xD0,0x80);
load_picture(five_tiledata,14);
print_text("  IN THE ANCIENT       WORLD OF ");
print_text("     NEKOMORI");
perform_delay(200);
play_sound_C4(0x2E,0xF0,0xC0,0x80);
break;
case 1:
load_picture(two_tiledata,13);
print_text(" A LEGEND EMERGES");
print_text("     ABOUT A");
play_sound_C4(0x2E,0xF0,0xB0,0x80);
break;
case 2:
load_picture(one_tiledata,12);
play_sound_C4(0x2E,0xF0,0xD0,0x80);
print_text(" MYSTERIOUS ENTITY");
play_sound_C4(0x38,0xCF,0x10,0x80);
print_text("     KNOWN AS");
NR50_REG=0x00;
NR51_REG=0x00;
NR52_REG=0x00;
break;
case 3:
big_sprite_animation(0);
load_big_sprite();
load_picture(black_bkg_tiledata,14);
play_sound_C1(0x2E, 0x45,0xEB, 0x08 ,0xC2);
print_text("     KEYCHAN");
play_sound_C4(0x2E,0xF0,0xC0,0x80);
perform_delay(200);
break;
case 4:
play_sound_C1(0x0D, 0x45,0xEB, 0x08 ,0xC2);
print_text("    THIS BEING");
play_sound_C4(0x2E,0xF0,0xD0,0x80);
print_text("WHO HAS TAKEN THE FORM OF A GHOST   CAT GIRL");
print_text("POSSESSES THE     POWER OF DARKNESS");
play_sound_C1(0x2E, 0x45, 0xEB, 0x08 ,0xC1);
for(i=0;i<0x10;i++){set_sprite_prop(i,0);}
perform_delay(200);
break;
case 5:
for(i=0;i<0x10;i++){set_sprite_prop(i,S_PALETTE);}
print_text("AND THE ABILITY TOCHANGE GRAVITY");
NR50_REG=0x00;
NR51_REG=0x00;
NR52_REG=0x00;
for(x=0;x<40;x++){
big_sprite_animation(x%8);
play_sound_C1(0x2E,0x48,0xFB,x,0xC7);
delay(100);
}
HIDE_SPRITES;
break;
case 6:
print_text("GRANTED BY THE    MOON GODDESS");
load_picture(zero_tiledata,12);
play_sound_C4(0x2E,0xF0,0xD0,0x80);
print_text("     TSUKUYOMI");
perform_delay(255);
play_sound_C4(0x2E,0xF0,0xC0,0x80);
break;
case 7:
load_picture(tree_tiledata,13);
play_sound_C4(0x2E,0xF0,0xD0,0x80);
print_text("ACCORDING TO      JAPANESE MYTHOLOGY");
print_text("KEYCHAN IS A      TSUGUMOMO");
play_sound_C4(0x2E,0xF0,0xC0,0x80);
play_sound_C1(0x0D, 0x45, 0xEB, 0x08 ,0xC3);
break;
case 8:
load_picture(four_tiledata,13);
print_text("     A SPIRIT");
print_text(" THAT FEEDS ON     NEGATIVITY");
play_sound_C4(0x2E,0xF0,0xE0,0x80);
play_sound_C1(0x0D, 0x45, 0xEB, 0x08 ,0xC3);
print_text(" AND THE FEARS OF  HUMANS");
play_sound_C4(0x2E,0xF0,0xF0,0x80);
play_sound_C1(0x0D, 0x45, 0xEB, 0x08 ,0xC2);
break;




}



}






void historia(){

//load sprite
SWITCH_ROM_MBC5(13);
set_sprite_data(0,128,big_key_rotacion);
set_bkg_data(255,1,a_blank_space);




load_picture(year20_tiledata,12);
SHOW_BKG;
DISPLAY_ON;
delay(1000);



for(y=0;y<9;y++){
hist_part(y);
if(joypad()==J_START){break;}
}

NR50_REG=0x00;
NR51_REG=0x00;
NR52_REG=0x00;
play_sound_C1(0x0D, 0x45, 0xEB, 0x08 ,0xC2);


for(i=0;i<0x10;i++){set_sprite_prop(i,0);move_sprite(i,0xFF,0xFF);}

}





