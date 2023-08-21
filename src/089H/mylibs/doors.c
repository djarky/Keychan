
typedef struct {

UBYTE room_id;
UBYTE part_id;
UBYTE x_pos;
UBYTE y_pos;
UBYTE rot;

}Door;



typedef struct {

Door in_door;
Door out_door;

}Door_conection;



#define num_rooms 9
#define num_parts 9

#define max_doors 36
#define max_conections max_doors/2

Door_conection Doors[max_conections];
UBYTE doors_conected=0;//count a number of conections 

/*
extern unsigned char current_room;
extern unsigned char current_part;
*/

//verify if a room is conected 
BOOLEAN check_conection[num_rooms];

//count doors in a room
UBYTE   count_doors[]={0,0,0,0,0,0,0,0,0};



BOOLEAN check_part_avalible[num_rooms][num_parts];




UBYTE diferent_rand(UBYTE val,UBYTE range){
	UBYTE rand_value=val;
	while(rand_value==val){rand_value=rand()%range;}
	return rand_value;
}

void create_new_door_node(UBYTE init_part,UBYTE destine_room,UBYTE destine_part){
	Doors[doors_conected].in_door.room_id=current_room;
	Doors[doors_conected].in_door.part_id=init_part;
	Doors[doors_conected].out_door.room_id=destine_room;
	Doors[doors_conected].out_door.part_id=destine_part;
	doors_conected++;
	check_conection[current_room]=1;
	current_room=destine_room;current_part=destine_part;
	check_conection[destine_room]=1;
	
}


void create_rand_conection(void) {
	UBYTE diferent_part_in = diferent_rand(current_part,num_parts);
	UBYTE diferent_room_out = diferent_rand(current_room,num_rooms);
	UBYTE diferent_part_out = diferent_rand(current_part,num_parts);
	count_doors[current_room]++;
	count_doors[diferent_room_out]++;
	if(count_doors[diferent_room_out]<4 && check_part_avalible[diferent_room_out][diferent_part_out] && check_part_avalible[current_room][diferent_part_in]){
		check_part_avalible[diferent_room_out][diferent_part_out]=0;
		check_part_avalible[current_room][diferent_part_in]=0;
		create_new_door_node(diferent_part_in,diferent_room_out,diferent_part_out);
	}

}


BOOLEAN check_all_conection(void) {
	UBYTE ii=0;
	for(ii=0;ii<num_rooms;ii++){
		if(!check_conection[ii]){return 0;}
	}

	return 1;
}



void create_rand_conections(void) {
	UBYTE ii=0;UBYTE kk=0;
	for(ii=0;ii<num_rooms;ii++){
		for(kk=0;kk<num_parts;kk++){
			check_part_avalible[ii][kk]=1;
		}
	}

	while(doors_conected<max_conections && !check_all_conection()){
		create_rand_conection();
	}
	
}

void create_rand_posisions(void) {
	UBYTE ii=0;
	for(ii=0;ii<doors_conected;ii++){
		Doors[ii].in_door.x_pos= rand_pos_x();
		Doors[ii].in_door.y_pos= rand_pos_y();		
		Doors[ii].in_door.rot= rand_rot();		
		Doors[ii].out_door.x_pos= rand_pos_x();
		Doors[ii].out_door.y_pos= rand_pos_y();		
		Doors[ii].out_door.rot= rand_rot();	
	}
}





void create_rand_doors(void) {

	create_rand_conections();	
	create_rand_posisions();
}

