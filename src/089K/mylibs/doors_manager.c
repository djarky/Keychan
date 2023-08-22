

extern UBYTE doors_conected;

extern unsigned char current_room;
extern unsigned char current_part;

extern unsigned char map1[];
extern unsigned char map2[];
extern unsigned char map3[];
extern unsigned char map4[];
extern unsigned char map5[];
extern unsigned char map6[];
extern unsigned char map7[];
extern unsigned char map8[];
extern unsigned char map9[];


void load_subpart(UBYTE part[], UBYTE U, UBYTE d_rot) {
part[U]=k+0x10;
switch(d_rot) {
case J_UP:
part[U+1]=0x00;
part[U -1]=0x00;
part[U+MAP_WIDTH] =0x01;
part[U-MAP_WIDTH] =0x00;
break;
case J_DOWN:
part[U+1]=0x00;
part[U -1]=0x00;
part[U-MAP_WIDTH] =0x01;
part[U+MAP_WIDTH] =0x00;
break;
case J_RIGHT:
part[U+MAP_WIDTH]=0x00;
part[U-MAP_WIDTH]=0x00;
part[U-1] =0x01;
part[U+1] =0x00;
break;
case J_LEFT:
part[U+MAP_WIDTH]=0x00;
part[U-MAP_WIDTH]=0x00;
part[U+1] =0x01;
part[U-1] =0x00;
break;
} 
} 


void load_supart_in(UBYTE part[]){


load_subpart(part,Doors[k].in_door.x_pos + MAP_WIDTH*Doors[k].in_door.y_pos, Doors[k].in_door.rot) ;
}

void load_supart_out(UBYTE part[]){

load_subpart(part,Doors[k].out_door.x_pos + MAP_WIDTH*Doors[k].out_door.y_pos, Doors[k].out_door.rot) ;

}




void load_doors_in_map(void) {
ENABLE_RAM_MBC5;
for(k=0;k<doors_conected;k++){

load_level(Doors[k].in_door.room_id +1);
switch(Doors[k].in_door.part_id){
case 0:load_supart_in(map1);break;
case 1:load_supart_in(map2);break;
case 2:load_supart_in(map3);break;
case 3:load_supart_in(map4);break;
case 4:load_supart_in(map5);break;
case 5:load_supart_in(map6);break;
case 6:load_supart_in(map7);break;
case 7:load_supart_in(map8);break;
case 8:load_supart_in(map9);break;
}
save_level(Doors[k].in_door.room_id +1);

load_level(Doors[k].out_door.room_id +1);
switch(Doors[k].out_door.part_id){
case 0:load_supart_out(map1);break;
case 1:load_supart_out(map2);break;
case 2:load_supart_out(map3);break;
case 3:load_supart_out(map4);break;
case 4:load_supart_out(map5);break;
case 5:load_supart_out(map6);break;
case 6:load_supart_out(map7);break;
case 7:load_supart_out(map8);break;
case 8:load_supart_out(map9);break;
}
save_level(Doors[k].out_door.room_id +1);



}


DISABLE_RAM_MBC5;

}


