void SHOW_NUME(UBYTE POSX,UBYTE POSY,UBYTE NUM){
switch(NUM/100){
case 0x00:set_win_tiles(POSX,POSY,1,1,"0");break;
case 0x01:set_win_tiles(POSX,POSY,1,1,"1");break;
case 0x02:set_win_tiles(POSX,POSY,1,1,"2");break;
case 0x03:set_win_tiles(POSX,POSY,1,1,"3");break;
}
switch((NUM/10)%10){
case 0x00:set_win_tiles(POSX+1,POSY,1,1,"0");break;
case 0x01:set_win_tiles(POSX+1,POSY,1,1,"1");break;
case 0x02:set_win_tiles(POSX+1,POSY,1,1,"2");break;
case 0x03:set_win_tiles(POSX+1,POSY,1,1,"3");break;
case 0x04:set_win_tiles(POSX+1,POSY,1,1,"4");break;
case 0x05:set_win_tiles(POSX+1,POSY,1,1,"5");break;
case 0x06:set_win_tiles(POSX+1,POSY,1,1,"6");break;
case 0x07:set_win_tiles(POSX+1,POSY,1,1,"7");break;
case 0x08:set_win_tiles(POSX+1,POSY,1,1,"8");break;
case 0x09:set_win_tiles(POSX+1,POSY,1,1,"9");break;
}
switch(NUM%10){
case 0x00:set_win_tiles(POSX+2,POSY,1,1,"0");break;
case 0x01:set_win_tiles(POSX+2,POSY,1,1,"1");break;
case 0x02:set_win_tiles(POSX+2,POSY,1,1,"2");break;
case 0x03:set_win_tiles(POSX+2,POSY,1,1,"3");break;
case 0x04:set_win_tiles(POSX+2,POSY,1,1,"4");break;
case 0x05:set_win_tiles(POSX+2,POSY,1,1,"5");break;
case 0x06:set_win_tiles(POSX+2,POSY,1,1,"6");break;
case 0x07:set_win_tiles(POSX+2,POSY,1,1,"7");break;
case 0x08:set_win_tiles(POSX+2,POSY,1,1,"8");break;
case 0x09:set_win_tiles(POSX+2,POSY,1,1,"9");break;
}

}
