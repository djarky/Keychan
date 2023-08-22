
void load_picture_s(UBYTE pics_data[],UBYTE banco){

for(i=0;i<20;i++){
 for(k=0;k<18;k++){
   set_bkg_tiles(i,k,1,1,a_blank_space);
 }
}
HIDE_BKG;

SWITCH_ROM_MBC5(banco);
set_bkg_tiles(2,1,16,16,keychan_title_tilemap);
set_bkg_data(0,256,pics_data);
SHOW_BKG;
}