
unsigned char bar_tiles[4];



void show_bars(UBYTE x,UBYTE y,UBYTE val){
UINT8 ii;

for(ii=0;ii<4;ii++){bar_tiles[ii]= 0x1B ;
}


if(val>0x00 && val<0x40){bar_tiles[0]+=(val%64)/16;}
if(val>0x40 && val<0x80){bar_tiles[1]+=(val%64)/16;}
if(val>0x80 && val<0xC0){bar_tiles[2]+=(val%64)/16;}
if(val>0xC0 && val<0xFF){bar_tiles[3]+=(val%64)/16;}


if(val>0x3F){bar_tiles[0]=0x1F;}
if(val>0x7F){bar_tiles[1]=0x1F;}
if(val>0xBF){bar_tiles[2]=0x1F;}
//fix
if(val==0xFF){bar_tiles[3]=0x1F;}


set_win_tiles(x,y,4,1,bar_tiles);
}