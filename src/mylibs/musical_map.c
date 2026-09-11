#ifndef _ARKY_MUSICAL_MAP_C
#define _ARKY_MUSICAL_MAP_C



#define MAP_WIDTH 10
#define MAP_HEIGHT 9
#define playerRow 1



extern unsigned char player_rot;
extern unsigned char player_hp;
extern unsigned char current_map;

void play_sound_C1(UBYTE R1,UBYTE R2,UBYTE R3,UBYTE R4,UBYTE R5);
void play_sound_C2(UBYTE R1,UBYTE R2,UBYTE R3,UBYTE R4);
void play_sound_C4(UBYTE R1,UBYTE R2,UBYTE R3,UBYTE R4);



void musical_map(void){



k= ((sys_time >> 3) %8);

if(player_hp>0x80){

 	switch(player_rot){
	case J_UP:
		switch(k){
		case 1:play_sound_C2( 0x73, 0xD7, temp_ram[5] ,0xC5);
		break;
		case 2:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 3:play_sound_C2( 0x36, 0xA1, temp_ram[8] ,0x84);
		break;
		case 4:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 5:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 6:play_sound_C2( 0x36, 0xA1, temp_ram[10] ,0x84);
		break;
		case 7:
		play_sound_C2( 0x36, 0xA1, temp_ram[6] ,0x84);
		break;
		case 8:
		play_sound_C2( 0x36, 0xA1, temp_ram[12] ,0x84);
		break;
		}
	break;
	case J_DOWN:
		switch(k){
		case 8:play_sound_C2( 0x73, 0xD7, temp_ram[5] ,0xC5);
		break;
		case 7:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 6:play_sound_C2( 0x36, 0xA1, temp_ram[8] ,0x84);
		break;
		case 5:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 4:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 3:play_sound_C2( 0x36, 0xA1, temp_ram[10] ,0x84);
		break;
		case 2:
		play_sound_C2( 0x36, 0xA1, temp_ram[6] ,0x84);
		break;
		case 1:
		play_sound_C2( 0x36, 0xA1, temp_ram[12] ,0x84);
		break;
		}
	break;
	case J_LEFT:
		switch(k){
		case 1:play_sound_C2( 0x73, 0xD7, temp_ram[5] ,0xC5);
		break;
		case 8:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 3:play_sound_C2( 0x36, 0xA1, temp_ram[8] ,0x84);
		break;
		case 6:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 5:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 4:play_sound_C2( 0x36, 0xA1, temp_ram[10] ,0x84);
		break;
		case 7:
		play_sound_C2( 0x36, 0xA1, temp_ram[6] ,0x84);
		break;
		case 2:
		play_sound_C2( 0x36, 0xA1, temp_ram[12] ,0x84);
		break;
		}
	break;
	case J_RIGHT:
		switch(k){
		case 2:play_sound_C2( 0x73, 0xD7, temp_ram[5] ,0xC5);
		break;
		case 7:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 4:play_sound_C2( 0x36, 0xA1, temp_ram[8] ,0x84);
		break;
		case 5:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 6:play_sound_C4(0x3B,0x51,0xB8,0xC0);
		break;
		case 3:play_sound_C2( 0x36, 0xA1, temp_ram[10] ,0x84);
		break;
		case 8:
		play_sound_C2( 0x36, 0xA1, temp_ram[6] ,0x84);
		break;
		case 1:
		play_sound_C2( 0x36, 0xA1, temp_ram[12] ,0x84);
		break;
		}
	break;
	}

}
else{

	switch(player_rot){
	case J_UP:
		switch(k){
		case 1:play_sound_C1(0x15, 0x43, 0x86, 0x8C, 0xC8);
		break;
		case 2:play_sound_C1(0x17, 0x43, 0x86, 0x8D, 0xC9);
		break;
		case 3:play_sound_C2( 0x36, 0xA1, temp_ram[8] ,0x84);
		break;
		case 4:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 5:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 6:play_sound_C2(0x36, 0x52, temp_ram[6], 0xC4);
		break;
		case 7:
		play_sound_C2(0x3C, 0x52, temp_ram[7], 0xC4);
		break;
		case 8:
		play_sound_C1(0x12, 0x43, 0x86, temp_ram[8], 0xC3);
		break;
		}
	break;
	case J_DOWN:
		switch(k){
		case 8:play_sound_C1(0x15, 0x43, 0x86, 0x8C, 0xC8);
		break;
		case 7:play_sound_C1(0x17, 0x43, 0x86, 0x8D, 0xC9);
		break;
		case 6:play_sound_C2( 0x36, 0xA1, temp_ram[8] ,0x84);
		break;
		case 5:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 4:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 3:play_sound_C2(0x36, 0x52, temp_ram[6], 0xC4);
		break;
		case 2:
		play_sound_C2(0x3C, 0x52, temp_ram[7], 0xC4);
		break;
		case 1:
		play_sound_C1(0x12, 0x43, 0x86, temp_ram[8], 0xC3);
		break;
		}
	break;
	case J_LEFT:
		switch(k){
		case 1:play_sound_C2(0x35, 0x52, temp_ram[8], 0xC4);
		break;
		case 8:play_sound_C2(0x34, 0x52, temp_ram[7], 0xC4);
		break;
		case 3:play_sound_C2(0x33, 0x52, temp_ram[9], 0xC4);
		break;
		case 6:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 5:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 4:play_sound_C2(0x2F, 0x52, temp_ram[5], 0xC4);
		break;
		case 7:
		play_sound_C2(0x2E, 0x52, temp_ram[11], 0xC4);
		break;
		case 2:
		play_sound_C2(0x2D, 0x52, temp_ram[4], 0xC4);
		break;
		}
	break;
	case J_RIGHT:
		switch(k){
		case 2:play_sound_C2(0x35, 0x52, temp_ram[8], 0xC4);
		break;
		case 7:play_sound_C2(0x34, 0x52, temp_ram[7], 0xC4);
		break;
		case 4:play_sound_C2(0x33, 0x52, temp_ram[9], 0xC4);
		break;
		case 5:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 6:play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
		break;
		case 3:play_sound_C2(0x2F, 0x52, temp_ram[5], 0xC4);
		break;
		case 8:
		play_sound_C2(0x2E, 0x52, temp_ram[11], 0xC4);
		break;
		case 1:
		play_sound_C2(0x2D, 0x52, temp_ram[4], 0xC4);
		break;
		}
	break;
	}

 }

}


#endif
