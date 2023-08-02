
const unsigned char IKEY_SRAM[]="KEYCHAN IS A KEY FROM SAVE XD";

extern unsigned char KEY_SRAM[128];



int VER_BATERY(){
for(i=0;i<28;i++){
if(KEY_SRAM[i]!=IKEY_SRAM[i]){return 0;}
}
return 1;
}

void SAVE_BATERY();

void INI_BATERY(){
for(i=0;i<28;i++){KEY_SRAM[i]=IKEY_SRAM[i];}
}

void LOAD_BATERY(){
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
if(VER_BATERY()==0){
INI_BATERY();
SWITCH_ROM_MBC5 (4);
generateRandomLevel();
printf("created new file");
delay(1000);
}
else{
SWITCH_ROM_MBC5 (4);
load_level(current_room);
printf("load file");
delay(1000);
}
DISABLE_RAM_MBC5;
}

void SAVE_BATERY(){
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
INI_BATERY();
SWITCH_ROM_MBC5 (4);
storage_level();
DISABLE_RAM_MBC5;
}
