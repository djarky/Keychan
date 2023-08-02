#define MAP_WIDTH 10
#define MAP_HEIGHT 9
#define playerRow 1


extern unsigned char current_room;




extern unsigned char ROOM_A_A[90];
extern unsigned char ROOM_A_B[90];
extern unsigned char ROOM_A_C[90];
extern unsigned char ROOM_A_D[90];
extern unsigned char ROOM_A_E[90];
extern unsigned char ROOM_A_F[90];
extern unsigned char ROOM_A_G[90];
extern unsigned char ROOM_A_H[90];
extern unsigned char ROOM_A_I[90];

extern unsigned char ROOM_B_A[90];
extern unsigned char ROOM_B_B[90];
extern unsigned char ROOM_B_C[90];
extern unsigned char ROOM_B_D[90];
extern unsigned char ROOM_B_E[90];
extern unsigned char ROOM_B_F[90];
extern unsigned char ROOM_B_G[90];
extern unsigned char ROOM_B_H[90];
extern unsigned char ROOM_B_I[90];

extern unsigned char ROOM_C_A[90];
extern unsigned char ROOM_C_B[90];
extern unsigned char ROOM_C_C[90];
extern unsigned char ROOM_C_D[90];
extern unsigned char ROOM_C_E[90];
extern unsigned char ROOM_C_F[90];
extern unsigned char ROOM_C_G[90];
extern unsigned char ROOM_C_H[90];
extern unsigned char ROOM_C_I[90];

extern unsigned char ROOM_D_A[90];
extern unsigned char ROOM_D_B[90];
extern unsigned char ROOM_D_C[90];
extern unsigned char ROOM_D_D[90];
extern unsigned char ROOM_D_E[90];
extern unsigned char ROOM_D_F[90];
extern unsigned char ROOM_D_G[90];
extern unsigned char ROOM_D_H[90];
extern unsigned char ROOM_D_I[90];

extern unsigned char ROOM_E_A[90];
extern unsigned char ROOM_E_B[90];
extern unsigned char ROOM_E_C[90];
extern unsigned char ROOM_E_D[90];
extern unsigned char ROOM_E_E[90];
extern unsigned char ROOM_E_F[90];
extern unsigned char ROOM_E_G[90];
extern unsigned char ROOM_E_H[90];
extern unsigned char ROOM_E_I[90];

extern unsigned char ROOM_F_A[90];
extern unsigned char ROOM_F_B[90];
extern unsigned char ROOM_F_C[90];
extern unsigned char ROOM_F_D[90];
extern unsigned char ROOM_F_E[90];
extern unsigned char ROOM_F_F[90];
extern unsigned char ROOM_F_G[90];
extern unsigned char ROOM_F_H[90];
extern unsigned char ROOM_F_I[90];

extern unsigned char ROOM_G_A[90];
extern unsigned char ROOM_G_B[90];
extern unsigned char ROOM_G_C[90];
extern unsigned char ROOM_G_D[90];
extern unsigned char ROOM_G_E[90];
extern unsigned char ROOM_G_F[90];
extern unsigned char ROOM_G_G[90];
extern unsigned char ROOM_G_H[90];
extern unsigned char ROOM_G_I[90];

extern unsigned char ROOM_H_A[90];
extern unsigned char ROOM_H_B[90];
extern unsigned char ROOM_H_C[90];
extern unsigned char ROOM_H_D[90];
extern unsigned char ROOM_H_E[90];
extern unsigned char ROOM_H_F[90];
extern unsigned char ROOM_H_G[90];
extern unsigned char ROOM_H_H[90];
extern unsigned char ROOM_H_I[90];

extern unsigned char ROOM_I_A[90];
extern unsigned char ROOM_I_B[90];
extern unsigned char ROOM_I_C[90];
extern unsigned char ROOM_I_D[90];
extern unsigned char ROOM_I_E[90];
extern unsigned char ROOM_I_F[90];
extern unsigned char ROOM_I_G[90];
extern unsigned char ROOM_I_H[90];
extern unsigned char ROOM_I_I[90];






void copy_map(UBYTE mapa1[],UBYTE mapa2[]){
for(i=0;i<90;i++){mapa1[i]=mapa2[i];}
}






void load_level(UBYTE room_index){
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
switch(room_index){
case 1:
	copy_map(map1,ROOM_A_A);copy_map(map2,ROOM_A_B);copy_map(map3,ROOM_A_C);
	copy_map(map4,ROOM_A_D);copy_map(map5,ROOM_A_E);copy_map(map6,ROOM_A_F);
	copy_map(map7,ROOM_A_G);copy_map(map8,ROOM_A_H);copy_map(map9,ROOM_A_I);
break;
case 2:
	copy_map(map1,ROOM_B_A);copy_map(map2,ROOM_B_B);copy_map(map3,ROOM_B_C);
	copy_map(map4,ROOM_B_D);copy_map(map5,ROOM_B_E);copy_map(map6,ROOM_B_F);
	copy_map(map7,ROOM_B_G);copy_map(map8,ROOM_B_H);copy_map(map9,ROOM_B_I);
break;
case 3:
	copy_map(map1,ROOM_C_A);copy_map(map2,ROOM_C_B);copy_map(map3,ROOM_C_C);
	copy_map(map4,ROOM_C_D);copy_map(map5,ROOM_C_E);copy_map(map6,ROOM_C_F);
	copy_map(map7,ROOM_C_G);copy_map(map8,ROOM_C_H);copy_map(map9,ROOM_C_I);
break;
case 4:
	copy_map(map1,ROOM_D_A);copy_map(map2,ROOM_D_B);copy_map(map3,ROOM_D_C);
	copy_map(map4,ROOM_D_D);copy_map(map5,ROOM_D_E);copy_map(map6,ROOM_D_F);
	copy_map(map7,ROOM_D_G);copy_map(map8,ROOM_D_H);copy_map(map9,ROOM_D_I);
break;
case 5:
	copy_map(map1,ROOM_E_A);copy_map(map2,ROOM_E_B);copy_map(map3,ROOM_E_C);
	copy_map(map4,ROOM_E_D);copy_map(map5,ROOM_E_E);copy_map(map6,ROOM_E_F);
	copy_map(map7,ROOM_E_G);copy_map(map8,ROOM_E_H);copy_map(map9,ROOM_E_I);
break;
case 6:
	copy_map(map1,ROOM_F_A);copy_map(map2,ROOM_F_B);copy_map(map3,ROOM_F_C);
	copy_map(map4,ROOM_F_D);copy_map(map5,ROOM_F_E);copy_map(map6,ROOM_F_F);
	copy_map(map7,ROOM_F_G);copy_map(map8,ROOM_F_H);copy_map(map9,ROOM_F_I);
break;
case 7:
	copy_map(map1,ROOM_G_A);copy_map(map2,ROOM_G_B);copy_map(map3,ROOM_G_C);
	copy_map(map4,ROOM_G_D);copy_map(map5,ROOM_G_E);copy_map(map6,ROOM_G_F);
	copy_map(map7,ROOM_G_G);copy_map(map8,ROOM_G_H);copy_map(map9,ROOM_G_I);
break;
case 8:
	copy_map(map1,ROOM_H_A);copy_map(map2,ROOM_H_B);copy_map(map3,ROOM_H_C);
	copy_map(map4,ROOM_H_D);copy_map(map5,ROOM_H_E);copy_map(map6,ROOM_H_F);
	copy_map(map7,ROOM_H_G);copy_map(map8,ROOM_H_H);copy_map(map9,ROOM_H_I);
break;
case 9:
	copy_map(map1,ROOM_I_A);copy_map(map2,ROOM_I_B);copy_map(map3,ROOM_I_C);
	copy_map(map4,ROOM_I_D);copy_map(map5,ROOM_I_E);copy_map(map6,ROOM_I_F);
	copy_map(map7,ROOM_I_G);copy_map(map8,ROOM_I_H);copy_map(map9,ROOM_I_I);
break;


}

DISABLE_RAM_MBC5;

}




void save_level(UBYTE room_index){
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
switch(room_index){
case 1:
	copy_map(ROOM_A_A,map1);copy_map(ROOM_A_B,map2);copy_map(ROOM_A_C,map3);
	copy_map(ROOM_A_D,map4);copy_map(ROOM_A_E,map5);copy_map(ROOM_A_F,map6);
	copy_map(ROOM_A_G,map7);copy_map(ROOM_A_H,map8);copy_map(ROOM_A_I,map9);
break;
case 2:
	copy_map(ROOM_B_A,map1);copy_map(ROOM_B_B,map2);copy_map(ROOM_B_C,map3);
	copy_map(ROOM_B_D,map4);copy_map(ROOM_B_E,map5);copy_map(ROOM_B_F,map6);
	copy_map(ROOM_B_G,map7);copy_map(ROOM_B_H,map8);copy_map(ROOM_B_I,map9);
break;
case 3:
	copy_map(ROOM_C_A,map1);copy_map(ROOM_C_B,map2);copy_map(ROOM_C_C,map3);
	copy_map(ROOM_C_D,map4);copy_map(ROOM_C_E,map5);copy_map(ROOM_C_F,map6);
	copy_map(ROOM_C_G,map7);copy_map(ROOM_C_H,map8);copy_map(ROOM_C_I,map9);
break;
case 4:
	copy_map(ROOM_D_A,map1);copy_map(ROOM_D_B,map2);copy_map(ROOM_D_C,map3);
	copy_map(ROOM_D_D,map4);copy_map(ROOM_D_E,map5);copy_map(ROOM_D_F,map6);
	copy_map(ROOM_D_G,map7);copy_map(ROOM_D_H,map8);copy_map(ROOM_D_I,map9);
break;
case 5:
	copy_map(ROOM_E_A,map1);copy_map(ROOM_E_B,map2);copy_map(ROOM_E_C,map3);
	copy_map(ROOM_E_D,map4);copy_map(ROOM_E_E,map5);copy_map(ROOM_E_F,map6);
	copy_map(ROOM_E_G,map7);copy_map(ROOM_E_H,map8);copy_map(ROOM_E_I,map9);
break;
case 6:
	copy_map(ROOM_F_A,map1);copy_map(ROOM_F_B,map2);copy_map(ROOM_F_C,map3);
	copy_map(ROOM_F_D,map4);copy_map(ROOM_F_E,map5);copy_map(ROOM_F_F,map6);
	copy_map(ROOM_F_G,map7);copy_map(ROOM_F_H,map8);copy_map(ROOM_F_I,map9);
break;
case 7:
	copy_map(ROOM_G_A,map1);copy_map(ROOM_G_B,map2);copy_map(ROOM_G_C,map3);
	copy_map(ROOM_G_D,map4);copy_map(ROOM_G_E,map5);copy_map(ROOM_G_F,map6);
	copy_map(ROOM_G_G,map7);copy_map(ROOM_G_H,map8);copy_map(ROOM_G_I,map9);
break;
case 8:
	copy_map(ROOM_H_A,map1);copy_map(ROOM_H_B,map2);copy_map(ROOM_H_C,map3);
	copy_map(ROOM_H_D,map4);copy_map(ROOM_H_E,map5);copy_map(ROOM_H_F,map6);
	copy_map(ROOM_H_G,map7);copy_map(ROOM_H_H,map8);copy_map(ROOM_H_I,map9);
break;
case 9:
	copy_map(ROOM_I_A,map1);copy_map(ROOM_I_B,map2);copy_map(ROOM_I_C,map3);
	copy_map(ROOM_I_D,map4);copy_map(ROOM_I_E,map5);copy_map(ROOM_I_F,map6);
	copy_map(ROOM_I_G,map7);copy_map(ROOM_I_H,map8);copy_map(ROOM_I_I,map9);
break;


}

DISABLE_RAM_MBC5;

}



//to show progress
void show_bars(UBYTE x,UBYTE y,UBYTE val);

void generateRandomLevel(){

move_win(0,0);
SHOW_BKG;
SHOW_WIN;
DISPLAY_ON;

for(current_room=1;current_room<10;current_room++){
show_bars(8,2,(current_room*16));
generateRandomLevel_room();
save_level(current_room);
}
for(i=144;i<255;i++){
show_bars(8,2,i);delay(10);
}
current_room=1;
}



void storage_level(){
for(current_room=1;current_room<10;current_room++){
save_level(current_room);
}
current_room=1;
}
