#define MAP_WHITH 10
#define player_pos_xy (player_pos_y*MAP_WHITH)+player_pos_x

void draw_map_s(UBYTE part_i) {
SWITCH_ROM_MBC5(4);
switch(part_i) {
case 0:draw_map(map1) ;break ;
case 1:draw_map(map2) ;break ;
case 2:draw_map(map3) ;break ;
case 3:draw_map(map4) ;break ;
case 4:draw_map(map5) ;break ;
case 5:draw_map(map6) ;break ;
case 6:draw_map(map7) ;break ;
case 7:draw_map(map8) ;break ;
case 8:draw_map(map9) ;break ;
} 

} 


void player_calcule_xy_abs(void) {
player_pos_x_abs=player_pos_x *16;
player_pos_y_abs=player_pos_y *16;
} 


int door_teleport(UBYTE door_idx) {



if(Doors[door_idx].in_door.x_pos == player_pos_x && Doors[door_idx].in_door.y_pos == player_pos_y) {
fadeout() ;
HIDE_SPRITES;
player_pos_x=Doors[door_idx].out_door.x_pos;
player_pos_y=Doors[door_idx].out_door.y_pos;
player_rot=Doors[door_idx].out_door.rot;
player_calcule_xy_abs() ;
SWITCH_ROM_MBC5(4); 
load_level(Doors[door_idx].out_door.room_id+1);
current_room=Doors[door_idx].out_door.room_id;
current_part=Doors[door_idx].out_door.part_id;
draw_map_s(current_part) ;
current_map=current_part+1;
SWITCH_ROM_MBC5(2);
player_init();
fadein() ;
SHOW_SPRITES;
return 1;
} 

if(Doors[door_idx].out_door.x_pos == player_pos_x && Doors[door_idx].out_door.y_pos == player_pos_y) {
fadeout() ;
HIDE_SPRITES;
player_pos_x=Doors[door_idx].in_door.x_pos;
player_pos_y=Doors[door_idx].in_door.y_pos;
player_rot=Doors[door_idx].in_door.rot;
player_calcule_xy_abs() ;
SWITCH_ROM_MBC5(4); 
load_level(Doors[door_idx].in_door.room_id+1);
current_room=Doors[door_idx].in_door.room_id;
current_part=Doors[door_idx].in_door.part_id;
draw_map_s(current_part) ;
current_map=current_part+1;
SWITCH_ROM_MBC5(2); 
player_init(); 
fadein();
SHOW_SPRITES;
return 1;
} 


return 0;
}

#define sp_cursor 32
#define sp_cursor_tile 0x70


void show_cursor_sprite(void) {
switch (player_rot) {
case J_UP:					
set_sprite_tile(sp_cursor, sp_cursor_tile ) ;
move_sprite(sp_cursor,player_pos_x_abs+12, player_pos_y_abs - 3);
break ;
case J_DOWN:
set_sprite_tile(sp_cursor, sp_cursor_tile +1 ) ;
move_sprite(sp_cursor,player_pos_x_abs+12, player_pos_y_abs + 42);
break ;
case J_LEFT:
set_sprite_tile(sp_cursor, sp_cursor_tile +2) ;
move_sprite(sp_cursor,player_pos_x_abs - 10, player_pos_y_abs +18);
break ;
case J_RIGHT:
set_sprite_tile(sp_cursor, sp_cursor_tile +3) ;
move_sprite(sp_cursor,player_pos_x_abs +32 , player_pos_y_abs +18);
break ;

} 

} 

void hide_cursor_sprite(void) {
set_sprite_tile(sp_cursor, 0xFF ) ;
move_sprite(sp_cursor,0xFF,0xFF);
} 




void check_door(UBYTE mapa[]) {
	if (mapa[player_pos_xy] >0x0F){
		show_cursor_sprite() ;
		if(joy_pad == player_rot) {door_teleport(mapa[player_pos_xy]-0x10 ) ;waitpadup() ;} 

	}
	else{
		if(get_sprite_tile(sp_cursor!=0xFF) ){hide_cursor_sprite() ;}
	} 
} 