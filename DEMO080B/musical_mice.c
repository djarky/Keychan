#include<stdio.h>
#include<gb/gb.h>
#include<gb/drawing.h>
#include<time.h>
#include<stdlib.h>
#include<rand.h>


void play_sound_C1(UBYTE R1,UBYTE R2,UBYTE R3,UBYTE R4,UBYTE R5);
void play_sound_C2(UBYTE R1,UBYTE R2,UBYTE R3,UBYTE R4);
void play_sound_C4(UBYTE R1,UBYTE R2,UBYTE R3,UBYTE R4);




extern  unsigned char npc_index;


extern unsigned char npc_pos_x[];
extern unsigned char npc_pos_y[];
extern unsigned char npc_rot[];

extern unsigned char player_rot;

extern unsigned char player_hp;


//platform moves 
#define BACK_WAY  J_LEFT
#define FRONT_WAY J_RIGHT
#define DEAD_WAY  0xFF

extern unsigned char npc_dir[];


extern unsigned char npc_pos_x_abs[];
extern unsigned char npc_pos_y_abs[];








extern unsigned char i;
extern unsigned char k;



extern unsigned char npc_joy;
extern unsigned char npc_col;





void play_mice_melody_normal(){



k= ((sys_time >> 3) %32);


switch(k){
case 1:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0x84);play_sound_C4(0x30,0x8F,0x70,0xC0);
}
break;
case 2:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0xC4);
break;
case 3:
break;
case 4:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
}
break;
case 5:
break;
case 6:
break;
case 7:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 8:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC4);
}
break;
case 9:
break;
case 10:

if(npc_dir[0]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC4);
}

break;
case 11:
break;
case 12:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 13:

if(npc_dir[2]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}

break;
case 14:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 15:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 16:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC3);
}
break;
case 17:
break;
case 18:play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
break;
case 19:
break;
case 20:

if(npc_dir[3]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}

break;
case 21:
break;
case 22:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}
break;
case 23:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 24:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
break;
case 25:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 26:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[2] ,0xC5);
}
break;
case 27:
break;
case 28:
break;
case 29:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 30:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
break;
case 31:
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
case 32:
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
}


}


void play_mice_melody_inverted(){



k= ((sys_time >> 3) %32);


switch(k){
case 32:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0x84);
}
break;
case 31:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0xC4);
break;
case 30:
break;
case 29:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
}
break;
case 28:
break;
case 27:
break;
case 26:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 25:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC4);
}
break;
case 24:
break;
case 23:

if(npc_dir[0]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC4);
}

break;
case 22:
break;
case 21:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 20:

if(npc_dir[2]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}

break;
case 19:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 18:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 17:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC3);
}
break;
case 16:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC3);
break;
case 15:play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
break;
case 14:
break;
case 13:

if(npc_dir[3]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}

break;
case 12:
break;
case 11:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}
break;
case 10:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 9:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
break;
case 8:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 7:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[2] ,0xC5);
}
break;
case 6:
break;
case 5:
break;
case 4:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 3:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
break;
case 2:
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
case 1:play_sound_C4(0x30,0x8F,0x70,0xC0);
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
}


}



void play_mice_melody_side_L(){



k= ((sys_time >> 3) %32);


switch(k){
case 1:play_sound_C4(0x30,0x8F,0x70,0xC0);
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0x84);
}
break;
case 32:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0x84);
break;
case 3:
break;
case 30:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
}
break;
case 5:
break;
case 28:
break;
case 7:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 26:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0x84);
}
break;
case 9:
break;
case 24:

if(npc_dir[0]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0x84);
}

break;
case 11:
break;
case 22:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 13:

if(npc_dir[2]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}

break;
case 20:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 15:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 18:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC3);
}
break;
case 17:
break;
case 16:play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
break;
case 19:
break;
case 14:
if(npc_dir[3]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}

break;
case 21:
break;
case 12:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}
break;
case 23:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 10:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
break;
case 25:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 8:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[2] ,0x84);
}
break;
case 27:
break;
case 6:
break;
case 29:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 4:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
break;
case 31:
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
case 2:
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
}


}

void play_mice_melody_side_R(){



k= ((sys_time >> 3) %32);


switch(k){
case 2:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0x84);
}
break;
case 31:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[0] ,0x84);
break;
case 4:
break;
case 29:
if(npc_dir[0]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0x84);
}
break;
case 6:
break;
case 27:
break;
case 8:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC4);
break;
case 25:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0x84);
}
break;
case 10:
break;
case 23:

if(npc_dir[0]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0x84);
}

break;
case 12:
break;
case 21:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 14:

if(npc_dir[2]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}

break;
case 19:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 16:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC3);
break;
case 17:
if(npc_dir[1]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[1] ,0xC3);
}
break;
case 18:
break;
case 15:play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[0] ,0xC5);
break;
case 20:
break;
case 13:
if(npc_dir[3]==DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}

break;
case 22:
break;
case 11:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
}
break;
case 24:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 9:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
break;
case 26:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 7:
if(npc_dir[2]!=DEAD_WAY){
play_sound_C2( 0x73, 0xD7, npc_pos_y_abs[2] ,0x84);
}
break;
case 28:
break;
case 5:
break;
case 30:play_sound_C4(0x3B,0x51,0xB8,0xC0);
break;
case 3:play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[2] ,0x84);
break;
case 32:
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
case 1:
play_sound_C4(0x30,0x8F,0x70,0xC0);
if(npc_dir[3]!=DEAD_WAY){
play_sound_C2( 0x36, 0xA1, npc_pos_x_abs[3] ,0x84);
}
break;
}


}




void play_dubstep_normal() {
k = ((sys_time >> 3) % 32);
	switch(k) {
	case 1:
	play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
	break;
	case 2:
	play_sound_C1(0x10, 0x43, 0x86, 0x88, 0xC4);
	break;
	case 3:
	play_sound_C1(0x0E, 0x43, 0x86, 0x89, 0xC5);
	break;
	case 4:
	if(npc_dir[3]!=DEAD_WAY){
	play_sound_C1(0x0B, 0x43, 0x86, 0x8A, 0xC6);
	}
	break;
	case 5:
	play_sound_C1(0x08, 0x43, 0x86, 0x8B, 0xC7);
	break;
	case 6:
	if(npc_dir[2]!=DEAD_WAY){
	play_sound_C2(0x32, 0x52, npc_pos_x_abs[0], 0xC4);
	}
	break;
	case 7:
	play_sound_C2(0x30, 0x52, npc_pos_x_abs[1], 0xC4);
	break;
	case 8:
	play_sound_C2(0x2E, 0x52, npc_pos_x_abs[2], 0xC4);
	break;
	case 9:
	play_sound_C2(0x2C, 0x52, npc_pos_x_abs[3], 0xC4);
	break;
	case 10:
	play_sound_C2(0x2A, 0x52, npc_pos_x_abs[0], 0xC4);
	break;
	case 11:
	play_sound_C4(0x30, 0x8F, 0x70, 0xC0);
	break;
	case 12:
	if(npc_dir[0]==DEAD_WAY){
	play_sound_C4(0x2E, 0x8F, 0x70, 0xC0);
	}
	break;
	case 13:
	play_sound_C4(0x2C, 0x8F, 0x70, 0xC0);
	break;
	case 14:
	play_sound_C4(0x2A, 0x8F, 0x70, 0xC0);
	break;
	case 15:
	if(npc_dir[1]==DEAD_WAY){
	play_sound_C4(0x28, 0x8F, 0x70, 0xC0);
	}
	break;
	case 16:
	play_sound_C1(0x15, 0x43, 0x86, 0x8C, 0xC8);
	break;
	case 17:
	play_sound_C1(0x17, 0x43, 0x86, 0x8D, 0xC9);
	break;
	case 18:
	play_sound_C1(0x19, 0x43, 0x86, 0x8E, 0xCA);
	break;	
	case 19:
	play_sound_C1(0x1C, 0x43, 0x86, 0x8F, 0xCB);
	break;
	case 20:
	if(npc_dir[3]==DEAD_WAY){
	play_sound_C1(0x1F, 0x43, 0x86, 0x90, 0xCC);
	}
	break;
	case 21:
	play_sound_C2(0x36, 0x52, npc_pos_y_abs[0], 0xC4);
	break;
	case 22:
	play_sound_C2(0x38, 0x52, npc_pos_y_abs[1], 0xC4);
	break;
	case 23:
	if(npc_dir[1]!=DEAD_WAY){
	play_sound_C2(0x3A, 0x52, npc_pos_y_abs[2], 0xC4);
	}
	break;
	case 24:
	play_sound_C2(0x3C, 0x52, npc_pos_y_abs[3], 0xC4);
	break;
	case 25:
	play_sound_C2(0x3E, 0x52, npc_pos_y_abs[3], 0xC4);
	break;
	case 26:
	play_sound_C4(0x28, 0x8F, 0x70, 0xC0);
	break;
	case 27:
	play_sound_C4(0x26, 0x8F, 0x70, 0xC0);
	break;
	case 28:
	play_sound_C4(0x24, 0x8F, 0x70, 0xC0);
	break;
	case 29:
	if(npc_dir[0]!=DEAD_WAY){
	play_sound_C4(0x22, 0x8F, 0x70, 0xC0);
	}
	break;
	case 30:
	play_sound_C4(0x20, 0x8F, 0x70, 0xC0);
	break;
	case 31:
	play_sound_C1(0x22, 0x43, 0x86, 0x91, 0xCD);
	break;
	case 32:
	play_sound_C1(0x20, 0x43, 0x86, 0x92, 0xCE);
	break;
	}
}





void play_dubstep_inverted() {
k = ((sys_time >> 3) % 32);
	switch(k) {
	case 32:
	play_sound_C1(0x12, 0x43, 0x86, 0x87, 0xC3);
	break;
	case 31:
	play_sound_C1(0x10, 0x43, 0x86, 0x88, 0xC4);
	break;
	case 30:
	play_sound_C1(0x0E, 0x43, 0x86, 0x89, 0xC5);
	break;
	case 29:
	if(npc_dir[3]!=DEAD_WAY){
	play_sound_C1(0x0B, 0x43, 0x86, 0x8A, 0xC6);
	}
	break;
	case 28:
	play_sound_C1(0x08, 0x43, 0x86, 0x8B, 0xC7);
	break;
	case 27:
	if(npc_dir[2]!=DEAD_WAY){
	play_sound_C2(0x32, 0x52, npc_pos_x_abs[0], 0xC4);
	}
	break;
	case 26:
	play_sound_C2(0x30, 0x52, npc_pos_x_abs[1], 0xC4);
	break;
	case 25:
	play_sound_C2(0x2E, 0x52, npc_pos_x_abs[2], 0xC4);
	break;
	case 24:
	play_sound_C2(0x2C, 0x52, npc_pos_x_abs[3], 0xC4);
	break;
	case 23:
	play_sound_C2(0x2A, 0x52, npc_pos_x_abs[0], 0xC4);
	break;
	case 22:
	play_sound_C4(0x30, 0x8F, 0x70, 0xC0);
	break;
	case 21:
	if(npc_dir[0]==DEAD_WAY){
	play_sound_C4(0x2E, 0x8F, 0x70, 0xC0);
	}
	break;
	case 20:
	play_sound_C4(0x2C, 0x8F, 0x70, 0xC0);
	break;
	case 19:
	play_sound_C4(0x2A, 0x8F, 0x70, 0xC0);
	break;
	case 18:
	if(npc_dir[1]==DEAD_WAY){
	play_sound_C4(0x28, 0x8F, 0x70, 0xC0);
	}
	break;
	case 17:
	play_sound_C1(0x15, 0x43, 0x86, 0x8C, 0xC8);
	break;
	case 16:
	play_sound_C1(0x17, 0x43, 0x86, 0x8D, 0xC9);
	break;
	case 15:
	play_sound_C1(0x19, 0x43, 0x86, 0x8E, 0xCA);
	break;	
	case 14:
	play_sound_C1(0x1C, 0x43, 0x86, 0x8F, 0xCB);
	break;
	case 13:
	if(npc_dir[3]==DEAD_WAY){
	play_sound_C1(0x1F, 0x43, 0x86, 0x90, 0xCC);
	}
	break;
	case 12:
	play_sound_C2(0x36, 0x52, npc_pos_y_abs[0], 0xC4);
	break;
	case 11:
	play_sound_C2(0x38, 0x52, npc_pos_y_abs[1], 0xC4);
	break;
	case 10:
	if(npc_dir[1]!=DEAD_WAY){
	play_sound_C2(0x3A, 0x52, npc_pos_y_abs[2], 0xC4);
	}
	break;
	case 9:
	play_sound_C2(0x3C, 0x52, npc_pos_y_abs[3], 0xC4);
	break;
	case 8:
	play_sound_C2(0x3E, 0x52, npc_pos_y_abs[3], 0xC4);
	break;
	case 7:
	play_sound_C4(0x28, 0x8F, 0x70, 0xC0);
	break;
	case 6:
	play_sound_C4(0x26, 0x8F, 0x70, 0xC0);
	break;
	case 5:
	play_sound_C4(0x24, 0x8F, 0x70, 0xC0);
	break;
	case 4:
	if(npc_dir[0]!=DEAD_WAY){
	play_sound_C4(0x22, 0x8F, 0x70, 0xC0);
	}
	break;
	case 3:
	play_sound_C4(0x20, 0x8F, 0x70, 0xC0);
	break;
	case 2:
	play_sound_C1(0x22, 0x43, 0x86, 0x91, 0xCD);
	break;
	case 1:
	play_sound_C1(0x20, 0x43, 0x86, 0x92, 0xCE);
	break;
	}
}






void play_glitch_melody_normal() {
  k = ((sys_time >> 3) % 32);

  switch (k) {
    case 1:
      play_sound_C1(0x16, 0x43, 0x86, 0x87, 0xC3);
      break;
    case 2:
      if(npc_dir[3]!=DEAD_WAY){
      play_sound_C1(0x15, 0x43, 0x86, 0x88, 0xC4);
      }
      break;
    case 3:
      play_sound_C1(0x13, 0x43, 0x86, 0x89, 0xC5);
      break;
    case 4:
      if(npc_dir[3]==DEAD_WAY){
      play_sound_C1(0x11, 0x43, 0x86, 0x8A, 0xC6); 
      }
      break;
    case 5:
      play_sound_C1(0x0F, 0x43, 0x86, 0x8B, 0xC7);
      break;
    case 6:
      play_sound_C1(0x0D, 0x43, 0x86, 0x8C, 0xC8);
      break;
    case 7:
      play_sound_C1(0x0B, 0x43, 0x86, 0x8D, 0xC9);
      break;
    case 8:
      play_sound_C1(0x0A, 0x43, 0x86, 0x8E, 0xCA);
      break;
    case 9:
      play_sound_C1(0x08, 0x43, 0x86, 0x8F, 0xCB);
      break;
    case 10:
      play_sound_C1(0x07, 0x43, 0x86, 0x90, 0xCC);
      break;
    case 11:
      play_sound_C1(0x05, 0x43, 0x86, 0x91, 0xCD);
      break;
    case 12:
      if(npc_dir[2]!=DEAD_WAY){
      play_sound_C1(0x04, 0x43, 0x86, 0x92, 0xCE);
      }
      break;
    case 13:
      play_sound_C1(0x02, 0x43, 0x86, 0x93, 0xCF);
      break;
    case 14:
      if(npc_dir[2]==DEAD_WAY){
      play_sound_C1(0x01, 0x43, 0x86, 0x94, 0xD0);
      }
      break;
    case 15:
      play_sound_C2(0x36, 0x52, npc_pos_x_abs[0], 0xC4);
      break;
    case 16:
      play_sound_C2(0x35, 0x52, npc_pos_x_abs[1], 0xC4);
      break;
    case 17:
      play_sound_C2(0x34, 0x52, npc_pos_x_abs[2], 0xC4);
      break;
    case 18:
      play_sound_C2(0x33, 0x52, npc_pos_x_abs[3], 0xC4);
      break;
    case 19:
      play_sound_C2(0x32, 0x52, npc_pos_y_abs[0], 0xC4);
      break;
    case 20:
      play_sound_C2(0x31, 0x52, npc_pos_y_abs[1], 0xC4);
      break;
    case 21:
      play_sound_C2(0x30, 0x52, npc_pos_y_abs[2], 0xC4);
      break;
    case 22:
      play_sound_C2(0x2F, 0x52, npc_pos_y_abs[3], 0xC4);
      break;
    case 23:
      play_sound_C2(0x2E, 0x52, npc_pos_x_abs[0], 0xC4);
      break;
    case 24:
      play_sound_C2(0x2D, 0x52, npc_pos_x_abs[1], 0xC4);
      break;
    case 25:
      if(npc_dir[1]!=DEAD_WAY){
      play_sound_C2(0x2C, 0x52, npc_pos_x_abs[2], 0xC4);
      }
      break;
    case 26:
      play_sound_C2(0x2B, 0x52, npc_pos_x_abs[3], 0xC4);
      break;
    case 27:
      play_sound_C2(0x2A, 0x52, npc_pos_y_abs[0], 0xC4);
      break;
    case 28:
      if(npc_dir[1]==DEAD_WAY){
      play_sound_C2(0x29, 0x52, npc_pos_y_abs[1], 0xC4);
      }
      break;
    case 29:
      play_sound_C2(0x28, 0x52, npc_pos_y_abs[2], 0xC4);
      break;
    case 30:
      play_sound_C4(0x3B, 0x51, 0xB8, 0xC0);
      break;
    case 31:
      play_sound_C4(0x3A, 0x51, 0xB8, 0xC0);
      break;
    case 32:
      play_sound_C4(0x39, 0x51, 0xB8, 0xC0);
      break;
  }
}



void play_glitch_melody_inverted() {
  k = ((sys_time >> 3) % 32);

  switch (k) {
    case 32:
      play_sound_C1(0x16, 0x43, 0x86, 0x87, 0xC3);
      break;
    case 31:
      if(npc_dir[3]!=DEAD_WAY){
      play_sound_C1(0x15, 0x43, 0x86, 0x88, 0xC4);
      }
      break;
    case 30:
      play_sound_C1(0x13, 0x43, 0x86, 0x89, 0xC5);
      break;
    case 29:
      if(npc_dir[3]==DEAD_WAY){
      play_sound_C1(0x11, 0x43, 0x86, 0x8A, 0xC6); 
      }
      break;
    case 28:
      play_sound_C1(0x0F, 0x43, 0x86, 0x8B, 0xC7);
      break;
    case 27:
      play_sound_C1(0x0D, 0x43, 0x86, 0x8C, 0xC8);
      break;
    case 26:
      play_sound_C1(0x0B, 0x43, 0x86, 0x8D, 0xC9);
      break;
    case 25:
      play_sound_C1(0x0A, 0x43, 0x86, 0x8E, 0xCA);
      break;
    case 24:
      play_sound_C1(0x08, 0x43, 0x86, 0x8F, 0xCB);
      break;
    case 23:
      play_sound_C1(0x07, 0x43, 0x86, 0x90, 0xCC);
      break;
    case 22:
      play_sound_C1(0x05, 0x43, 0x86, 0x91, 0xCD);
      break;
    case 21:
      if(npc_dir[2]!=DEAD_WAY){
      play_sound_C1(0x04, 0x43, 0x86, 0x92, 0xCE);
      }
      break;
    case 20:
      play_sound_C1(0x02, 0x43, 0x86, 0x93, 0xCF);
      break;
    case 19:
      if(npc_dir[2]==DEAD_WAY){
      play_sound_C1(0x01, 0x43, 0x86, 0x94, 0xD0);
      }
      break;
    case 18:
      play_sound_C2(0x36, 0x52, npc_pos_x_abs[0], 0xC4);
      break;
    case 17:
      play_sound_C2(0x35, 0x52, npc_pos_x_abs[1], 0xC4);
      break;
    case 16:
      play_sound_C2(0x34, 0x52, npc_pos_x_abs[2], 0xC4);
      break;
    case 15:
      play_sound_C2(0x33, 0x52, npc_pos_x_abs[3], 0xC4);
      break;
    case 14:
      play_sound_C2(0x32, 0x52, npc_pos_y_abs[0], 0xC4);
      break;
    case 13:
      play_sound_C2(0x31, 0x52, npc_pos_y_abs[1], 0xC4);
      break;
    case 12:
      play_sound_C2(0x30, 0x52, npc_pos_y_abs[2], 0xC4);
      break;
    case 11:
      play_sound_C2(0x2F, 0x52, npc_pos_y_abs[3], 0xC4);
      break;
    case 10:
      play_sound_C2(0x2E, 0x52, npc_pos_x_abs[0], 0xC4);
      break;
    case  9:
      play_sound_C2(0x2D, 0x52, npc_pos_x_abs[1], 0xC4);
      break;
    case  8:
      if(npc_dir[1]!=DEAD_WAY){
      play_sound_C2(0x2C, 0x52, npc_pos_x_abs[2], 0xC4);
      }
      break;
    case  7:
      play_sound_C2(0x2B, 0x52, npc_pos_x_abs[3], 0xC4);
      break;
    case  6:
      play_sound_C2(0x2A, 0x52, npc_pos_y_abs[0], 0xC4);
      break;
    case  5:
      if(npc_dir[1]==DEAD_WAY){
      play_sound_C2(0x29, 0x52, npc_pos_y_abs[1], 0xC4);
      }
      break;
    case  4:
      play_sound_C2(0x28, 0x52, npc_pos_y_abs[2], 0xC4);
      break;
    case  3:
      play_sound_C4(0x3B, 0x51, 0xB8, 0xC0);
      break;
    case  2:
      play_sound_C4(0x3A, 0x51, 0xB8, 0xC0);
      break;
    case  1:
      play_sound_C4(0x39, 0x51, 0xB8, 0xC0);
      break;
  }
}







void musical_mice(){

if(player_hp<0x80){

switch(player_rot){
case J_UP:   play_dubstep_normal();         break;
case J_LEFT: play_glitch_melody_normal();   break;
case J_DOWN: play_dubstep_inverted();       break;
case J_RIGHT:play_glitch_melody_inverted(); break;
}

}
else{

switch(player_rot){
case J_UP:   play_mice_melody_normal();  break;
case J_DOWN: play_mice_melody_inverted();break;
case J_RIGHT:play_mice_melody_side_R();  break;
case J_LEFT: play_mice_melody_side_L();break;

}

}

}