#define MAP_WIDTH 10
#define MAP_HEIGHT 9
#define playerRow 1


extern unsigned char col;
extern unsigned char row;


extern unsigned char map1[];
extern unsigned char map2[];
extern unsigned char map3[];
extern unsigned char map4[];
extern unsigned char map5[];
extern unsigned char map6[];
extern unsigned char map7[];
extern unsigned char map8[];
extern unsigned char map9[];


void generateRandomLevel_part(UBYTE map[]) {

  







for ( col = 0; col < 90 ; col++) {

hash =rand() % 10;

switch(hash){
case 0:map[col] =template8[col];break;
case 1:map[col] =template1[col];break;
case 2:map[col] =template2[col];break;
case 3:map[col] =template3[col];break;
case 4:map[col] =template4[col];break;
case 5:map[col] =template5[col];break;
case 6:map[col] =template6[col];break;
case 7:map[col] =template7[col];break;
case 8:map[col] =template8[col];break;
default:map[col]= hash ;break;
}

}







for ( i = 0; i < MAP_WIDTH * MAP_HEIGHT ; i++) {
	if(map[i]>0x02){map[i]=0x01;}
        
}



  for ( row = 0; row < MAP_HEIGHT ; row++) {
    map[row * MAP_WIDTH] = 0x01; // Primera columna
    map[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x01; // Última columna
  }
  

  
  for ( col = 0; col < MAP_WIDTH ; col++) {
    map[0 * MAP_WIDTH + col] = 0x01;
    map[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x01;
  }

 //gatillos(no son gatos pequeños xd) consistencia cambio de mapa
    map[MAP_WIDTH+2]=0x00;map[MAP_WIDTH+7]=0x00;
    map[MAP_WIDTH+1]=0x00;map[MAP_WIDTH+8]=0x00;
    map[7*MAP_WIDTH+2]=0x00;map[7*MAP_WIDTH+7]=0x00;
    map[7*MAP_WIDTH+1]=0x00;map[7*MAP_WIDTH+8]=0x00;

 hash =0;
}



void generateRandomLevel_room(){

generateRandomLevel_part(map1);
generateRandomLevel_part(map2);
generateRandomLevel_part(map3);
generateRandomLevel_part(map4);
generateRandomLevel_part(map5);
generateRandomLevel_part(map6);
generateRandomLevel_part(map7);
generateRandomLevel_part(map8);
generateRandomLevel_part(map9);


for ( row = 2; row < 7 ; row++) {
    // Primera columna
    map2[row * MAP_WIDTH] = 0x00;
    map3[row * MAP_WIDTH] = 0x00;
    map5[row * MAP_WIDTH] = 0x00;
    map6[row * MAP_WIDTH] = 0x00;
    map8[row * MAP_WIDTH] = 0x00;
    map9[row * MAP_WIDTH] = 0x00;
    // segunda columna
    map2[row * MAP_WIDTH+1] = 0x00;
    map3[row * MAP_WIDTH+1] = 0x00;
    map5[row * MAP_WIDTH+1] = 0x00;
    map6[row * MAP_WIDTH+1] = 0x00;
    map8[row * MAP_WIDTH+1] = 0x00;
    map9[row * MAP_WIDTH+1] = 0x00;
    // ultima columna
    map1[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x00; 
    map2[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x00; 
    map4[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x00; 
    map5[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x00; 
    map7[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x00; 
    map8[row * MAP_WIDTH + MAP_WIDTH - 1] = 0x00; 
    // penultima columna
    map1[row * MAP_WIDTH + MAP_WIDTH - 2] = 0x00; 
    map2[row * MAP_WIDTH + MAP_WIDTH - 2] = 0x00; 
    map4[row * MAP_WIDTH + MAP_WIDTH - 2] = 0x00; 
    map5[row * MAP_WIDTH + MAP_WIDTH - 2] = 0x00; 
    map7[row * MAP_WIDTH + MAP_WIDTH - 2] = 0x00; 
    map8[row * MAP_WIDTH + MAP_WIDTH - 2] = 0x00; 
}
for ( col = 3; col < 7 ; col++) {
    // Primera fila
    map4[0 * MAP_WIDTH + col] = 0x00;
    map5[0 * MAP_WIDTH + col] = 0x00;
    map6[0 * MAP_WIDTH + col] = 0x00;
    map7[0 * MAP_WIDTH + col] = 0x00;
    map8[0 * MAP_WIDTH + col] = 0x00;
    map9[0 * MAP_WIDTH + col] = 0x00;
    // segunda fila
    map4[1 * MAP_WIDTH + col] = 0x00;
    map5[1 * MAP_WIDTH + col] = 0x00;
    map6[1 * MAP_WIDTH + col] = 0x00;
    map7[1 * MAP_WIDTH + col] = 0x00;
    map8[1 * MAP_WIDTH + col] = 0x00;
    map9[1 * MAP_WIDTH + col] = 0x00;
    // ultima fila
    map1[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x00;
    map2[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x00;
    map3[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x00;
    map4[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x00;
    map5[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x00;
    map6[(MAP_HEIGHT - 1) * MAP_WIDTH + col] = 0x00;
    // penultima fila
    map1[(MAP_HEIGHT - 2) * MAP_WIDTH + col] = 0x00;
    map2[(MAP_HEIGHT - 2) * MAP_WIDTH + col] = 0x00;
    map3[(MAP_HEIGHT - 2) * MAP_WIDTH + col] = 0x00;
    map4[(MAP_HEIGHT - 2) * MAP_WIDTH + col] = 0x00;
    map5[(MAP_HEIGHT - 2) * MAP_WIDTH + col] = 0x00;
    map6[(MAP_HEIGHT - 2) * MAP_WIDTH + col] = 0x00;
}




}


