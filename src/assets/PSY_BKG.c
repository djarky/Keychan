#include"PSY/psyko0.c"
#include"PSY/psyko1.c"
#include"PSY/psyko2.c"
#include"PSY/psyko3.c"
#include"PSY/psyko4.c"
#include"PSY/psyko5.c"
#include"PSY/psyko6.c"
#include"PSY/psyko7.c"
#include"PSY/psyko8.c"
#include"PSY/psyko9.c"
#include"PSY/psyko10.c"


const unsigned char PSY_MOS[]={0x0A,0x0C,0x0B,0x0D};

void LOAD_PSY_BKG(UBYTE X){
switch(X){
 case 0x00:set_bkg_data(0x0A,4,PSY0); break;
 case 0x01:set_bkg_data(0x0A,4,PSY1); break;
 case 0x02:set_bkg_data(0x0A,4,PSY2); break;
 case 0x03:set_bkg_data(0x0A,4,PSY3); break;
 case 0x04:set_bkg_data(0x0A,4,PSY4); break;
 case 0x05:set_bkg_data(0x0A,4,PSY5); break;
 case 0x06:set_bkg_data(0x0A,4,PSY6); break;
 case 0x07:set_bkg_data(0x0A,4,PSY7); break;
 case 0x08:set_bkg_data(0x0A,4,PSY8); break;
 case 0x09:set_bkg_data(0x0A,4,PSY9); break;
 case 0x0A:set_bkg_data(0x0A,4,PSY10);break;
}
}