#define MAP_WIDTH 10
#define MAP_HEIGHT 9


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

extern Door_conection Doors[];