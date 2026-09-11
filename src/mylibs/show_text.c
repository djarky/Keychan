#ifndef _ARKY_SHOW_TEXT_C
#define _ARKY_SHOW_TEXT_C



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
if(y>10){set_bkg_data(0xD0,0x2B,splat_fonts);}
for(i=0;i<0x40;i++){temp_ram[i]=0xFF;}
for(i=0;i<my_strlen(TEXT);i++){
if(TEXT[i]==0x20){temp_ram[i]=0xFF;}else{temp_ram[i]= TEXT[i]+0xA0;}
}
set_bkg_tiles(1,0x0F,18,4,temp_ram);
play_sound_C1(0x38, 0x56, 0xEB, temp_ram[6] ,0xC3);
perform_delay(200);
}



#endif