
const unsigned char IKEY_SRAM[]="KEYCHAN IS A KEY FROM SAVE XD";

extern unsigned char KEY_SRAM[128];

#include"mylibs/storage_doors.c"


int VER_BATERY(void) {
for(i=0;i<28;i++){
if(KEY_SRAM[i]!=IKEY_SRAM[i]){return 0;}
}
return 1;
}

void SAVE_BATERY(void);

void INI_BATERY(void) {
for(i=0;i<28;i++){KEY_SRAM[i]=IKEY_SRAM[i];}
}


void DEL_BATERY(void) {
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
for(i=0;i<28;i++){KEY_SRAM[i]=0x00;}
DISABLE_RAM_MBC5;
}


void LOAD_BATERY(void) {
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
if(VER_BATERY()==0){
INI_BATERY();
SWITCH_ROM_MBC5 (4);
generateRandomLevel();
create_rand_doors();
load_doors_in_map();
save_doors();
delay(1000);
}
else{
SWITCH_ROM_MBC5 (4);
load_level(current_room);
load_doors();
//print_text("SUCCESSFUL LOAD");
delay(1000);
}
DISABLE_RAM_MBC5;
}

void SAVE_BATERY(void) {
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
INI_BATERY();
SWITCH_ROM_MBC5 (4);
storage_level();
save_doors();
DISABLE_RAM_MBC5;
}
