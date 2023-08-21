

void calcule_hash(UBYTE U,UBYTE mapa[]){
hash=0x00;
 if(mapa[U]==0x01){
  if(mapa[U-1]==0x00||mapa[U-1]>0x0F){ hash+=J_LEFT;}
  if(mapa[U+1]==0x00||mapa[U+1]>0x0F){ hash+=J_RIGHT;}
  if(mapa[U+10]==0x00||mapa[U+10]>0x0F){hash+=J_DOWN;}
  if(mapa[U-10]==0x00||mapa[U-10]>0x0F){hash+=J_UP;}
}

  //fix for indexoff 
  if(U<10)  {hash=hash&~J_UP;}
  if(U>0x50 && U<0x5A){hash=hash&~J_DOWN;}
  if(U%10==0){ hash=hash&~J_LEFT;}
  if(U%10==9){ hash=hash&~J_RIGHT;}

  
 if(mapa[U]==0x00){hash=0xFF;}
 if(mapa[U]==0x02){hash=J_A;}

}



void draw_hash(UBYTE X,UBYTE Y,UBYTE U,UBYTE mapa[]){
calcule_hash(U,mapa);
switch(hash){
 case J_LEFT+J_UP:   set_bkg_tiles(X*2,Y*2,2,2,Tile_A);break;
 case J_UP+J_RIGHT:  set_bkg_tiles(X*2,Y*2,2,2,Tile_B);break;
 case J_RIGHT+J_DOWN:set_bkg_tiles(X*2,Y*2,2,2,Tile_C);break;
 case J_DOWN+J_LEFT: set_bkg_tiles(X*2,Y*2,2,2,Tile_D);break;
 case J_UP:          set_bkg_tiles(X*2,Y*2,2,2,Tile_E);break;
 case J_DOWN:        set_bkg_tiles(X*2,Y*2,2,2,Tile_F);break;
 case J_LEFT:        set_bkg_tiles(X*2,Y*2,2,2,Tile_G);break;
 case J_RIGHT:       set_bkg_tiles(X*2,Y*2,2,2,Tile_H);break;
 case J_RIGHT+J_LEFT+J_UP:  set_bkg_tiles(X*2,Y*2,2,2,Tile_I);break;
 case J_RIGHT+J_LEFT+J_DOWN:set_bkg_tiles(X*2,Y*2,2,2,Tile_J);break;
 case J_UP+J_DOWN+J_LEFT:   set_bkg_tiles(X*2,Y*2,2,2,Tile_K);break;
 case J_UP+J_DOWN+J_RIGHT:  set_bkg_tiles(X*2,Y*2,2,2,Tile_L);break;
 case J_UP+J_DOWN:   set_bkg_tiles(X*2,Y*2,2,2,Tile_M);break;
 case J_LEFT+J_RIGHT:   set_bkg_tiles(X*2,Y*2,2,2,Tile_N);break;
 case J_DOWN+J_UP+J_LEFT+J_RIGHT:set_bkg_tiles(X*2,Y*2,2,2,Tile_O);break;
 case 0x00:set_bkg_tiles(X*2,Y*2,2,2,Tile_P);break;
 case 0xFF:set_bkg_tiles(X*2,Y*2,2,2,PSY_MOS);break;
 case J_A:set_bkg_tiles(X*2,Y*2,2,2,Tile_Hueso);break;
 }
}

extern unsigned char current_room;

void draw_map(UBYTE mapa[]){
//LOAD_PSY_BKG(rand()%0x0A);
LOAD_PSY_BKG(current_room) ;
for(i=0;i<90;i++){
 draw_hash(i%10,i/10,i,mapa);
}
draw_doors(mapa);
}