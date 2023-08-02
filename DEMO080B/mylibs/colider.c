




/*--------

[UL][U ][UR]
[ L][  ][ R]
[DL][D ][DR]


COL_UL B10000000 bit8
COL_U  B01000000 bit7
COL_UR B00100000 bit6
COL_L  B00010000 bit5
COL_R  B00001000 bit4
COL_DL B00000100 bit3
COL_D  B00000010 bit2
COL_DR B00000001 bit1

-----------*/


#define COL_UL  0x80
#define COL_U   0x40
#define COL_UR  0x20
#define COL_L   0x10
#define COL_R   0x08
#define COL_DL  0x04
#define COL_D   0x02
#define COL_DR  0x01



#define MAP_WHITH 10
#define TILE_SOLID 0x01


UBYTE COLISION =0x00;

#define CPOS (c_y_pos*MAP_WHITH+c_x_pos)


UBYTE nine_col(UBYTE c_x_pos,UBYTE c_y_pos,UBYTE mapa[]){
COLISION =0x00;
if(mapa[CPOS-MAP_WHITH-1]==TILE_SOLID){COLISION=COLISION|COL_UL;}
if(mapa[CPOS-MAP_WHITH  ]==TILE_SOLID){COLISION=COLISION|COL_U; }
if(mapa[CPOS-MAP_WHITH+1]==TILE_SOLID){COLISION=COLISION|COL_UR;}
if(mapa[CPOS-1]          ==TILE_SOLID){COLISION=COLISION|COL_L; }
if(mapa[CPOS+1]          ==TILE_SOLID){COLISION=COLISION|COL_R; }
if(mapa[CPOS+MAP_WHITH-1]==TILE_SOLID){COLISION=COLISION|COL_DL;}
if(mapa[CPOS+MAP_WHITH  ]==TILE_SOLID){COLISION=COLISION|COL_D; }
if(mapa[CPOS+MAP_WHITH+1]==TILE_SOLID){COLISION=COLISION|COL_DR;}
return COLISION;
}