

extern Door_conection storage_Doors [];
extern UBYTE storage_doors_conected;

void save_doors(void) {
ENABLE_RAM_MBC5;
SWITCH_RAM_MBC5 (0);
storage_doors_conected=doors_conected;
for(i=0;i<doors_conected;i++) {
//in_door
storage_Doors[i].in_door.room_id=Doors[i].in_door.room_id;
storage_Doors[i].in_door.part_id=Doors[i].in_door.part_id;
storage_Doors[i].in_door.x_pos=Doors[i].in_door.x_pos;
storage_Doors[i].in_door.y_pos=Doors[i].in_door.y_pos;
storage_Doors[i].in_door.rot=Doors[i].in_door.rot;
//out_door
storage_Doors[i].out_door.room_id=Doors[i].out_door.room_id;
storage_Doors[i].out_door.part_id=Doors[i].out_door.part_id;
storage_Doors[i].out_door.x_pos=Doors[i].out_door.x_pos;
storage_Doors[i].out_door.y_pos=Doors[i].out_door.y_pos;
storage_Doors[i].out_door.rot=Doors[i].out_door.rot;
} 
DISABLE_RAM_MBC5;
}



void load_doors(void) {
ENABLE_RAM_MBC5; 
SWITCH_RAM_MBC5 (0);
doors_conected=storage_doors_conected;
for(i=0;i<doors_conected;i++) {
//in_door
Doors[i].in_door.room_id=storage_Doors[i].in_door.room_id;
Doors[i].in_door.part_id=storage_Doors[i].in_door.part_id;
Doors[i].in_door.x_pos=storage_Doors[i].in_door.x_pos;
Doors[i].in_door.y_pos=storage_Doors[i].in_door.y_pos;
Doors[i].in_door.rot=storage_Doors[i].in_door.rot;
//out_door
Doors[i].out_door.room_id=storage_Doors[i].out_door.room_id;
Doors[i].out_door.part_id=storage_Doors[i].out_door.part_id;
Doors[i].out_door.x_pos=storage_Doors[i].out_door.x_pos;
Doors[i].out_door.y_pos=storage_Doors[i].out_door.y_pos;
Doors[i].out_door.rot=storage_Doors[i].out_door.rot;
} 
DISABLE_RAM_MBC5;
} 