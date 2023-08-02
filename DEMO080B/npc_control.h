unsigned char npc_index=0x00;

unsigned char npc_pos_x[6];
unsigned char npc_pos_y[6];
unsigned char npc_rot[]={J_UP,J_DOWN,J_LEFT,J_RIGHT,J_UP,J_UP};

//platform moves 
#define BACK_WAY  J_LEFT
#define FRONT_WAY J_RIGHT
#define DEAD_WAY  0xFF
unsigned char npc_dir[]={BACK_WAY,BACK_WAY,BACK_WAY,BACK_WAY,BACK_WAY,BACK_WAY};

unsigned char npc_pos_x_abs[]={32,32,80,80};
unsigned char npc_pos_y_abs[]={32,40,64,80};

#define MAP_WHITH 10
#define npc_pos_xy (npc_pos_y[npc_index]*MAP_WHITH)+npc_pos_x[npc_index]
#define TILE_SOLID 0x01

unsigned char npc_joy=0;
unsigned char npc_col=0;


void npc_calcule_xy();

void npc_walk_ani(UBYTE frame_ani);

void npc_init();

void npc_rotate90();

void npc_scrollex(BYTE x_pos,BYTE y_pos);

void npc_inputt(UBYTE joy);

void init_all_npc();



/*-----control npcs-------*/

void control_all_npc(UBYTE p_pos_x,UBYTE p_pos_y,UBYTE p_rot,UBYTE mapa[]);

void npc_spawn();