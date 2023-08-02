#define MAP_WIDTH 10
#define MAP_HEIGHT 9
#define playerRow 1


unsigned char current_room=1;



//to copy maps 
void copy_map(UBYTE mapa1[],UBYTE mapa2[]);



//load and save a single room 
void load_level(UBYTE room_index);
void save_level(UBYTE room_index);




//generate a level (9 rooms)
void generateRandomLevel();

//save a level(9 rooms)
void storage_level();